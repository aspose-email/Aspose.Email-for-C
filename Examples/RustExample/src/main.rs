use libloading::{Library, Symbol};
use std::ffi::CStr;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    // Загрузка DLL — необходимо использовать unsafe
    let lib = unsafe { Library::new("aspose_mail_converter.dll")? };

    // Определение типов функций
    type ConvertMailMessageToHtmlFn = unsafe extern "C" fn(file_name: *const i8) -> *const i8;

    let convert_mail_message_to_html: Symbol<ConvertMailMessageToHtmlFn> =
        unsafe { lib.get(b"ConvertMailMessageToHtmlWrapper")? };

    let file_name = std::ffi::CString::new("example.msg")?;

    unsafe {
        // Вызов функции
        let html_result = convert_mail_message_to_html(file_name.as_ptr());
        println!(
            "HTML Result: {}",
            CStr::from_ptr(html_result).to_string_lossy()
        );
    }

    Ok(())
}

