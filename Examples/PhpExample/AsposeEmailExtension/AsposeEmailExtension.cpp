#include "php.h"
#include "AsposeEmailConvetor.h"


ZEND_BEGIN_ARG_INFO_EX(arginfo_aspose_convert_email, 0, 0, 1)
ZEND_ARG_INFO(0, input_file)
ZEND_END_ARG_INFO()

// void Convert(const std::string& fileName, const std::string& outputFileName, const std::string& outputType);
PHP_FUNCTION(aspose_email_convert)
{
    char *str = 0;
    size_t str_len = 0;
    char *str2 = 0;
    size_t str_len2 = 0;
    char *str3 = 0;
    size_t str_len3 = 0;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_STRING(str, str_len)
        Z_PARAM_STRING(str2, str_len2)
        Z_PARAM_STRING(str3, str_len3)
        ZEND_PARSE_PARAMETERS_END();

    std::string first_param(str, str_len);
    std::string second_param(str2, str_len2);
    std::string third_param(str3, str_len3);

    char buffer[1024];
    snprintf(buffer, 1024, "aspose_email_convert parameters: %s %s %s", first_param.c_str(), second_param.c_str(), third_param.c_str());

    std::string result = ConvertMailMessageFile(first_param, second_param, third_param);

    RETURN_STRING(result.c_str());
}

ZEND_BEGIN_ARG_INFO_EX(arginfo_convert_mail_message_to_html, 0, 0, 1)
ZEND_ARG_INFO(0, input_file)
ZEND_END_ARG_INFO()


// std::string ConvertMailMessageToHtml(const std::string& fileName);
PHP_FUNCTION(convert_mail_message_to_html)
{
    char *str = 0;
    size_t str_len = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(str, str_len)
        ZEND_PARSE_PARAMETERS_END();

    std::string first_param(str, str_len);

    std::string result = ConvertMailMessageToHtml(first_param);

    char buffer[1024];
    snprintf(buffer, 1024, "convert_mail_message_to_html parameter: %s result: %s", first_param.c_str(), result.c_str());

    RETURN_STRING(result.c_str());
}




const zend_function_entry test_functions[] = {
    PHP_FE(aspose_email_convert, arginfo_aspose_convert_email)
    PHP_FE(convert_mail_message_to_html, arginfo_convert_mail_message_to_html)
    PHP_FE_END

};

static PHP_MINIT_FUNCTION(aspose_email_init);


zend_module_entry aspose_email_extension_module_entry = {
    STANDARD_MODULE_HEADER,
    "aspose_email_extension",
    test_functions,
    PHP_MINIT(aspose_email_init),
    NULL,
    NULL,
    NULL,
    NULL,
    "0.1",
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(aspose_email_extension)

static PHP_MINIT_FUNCTION(aspose_email_init)
{
    zval val;
    ZVAL_STRING(&val, "aspose_email_license");
    auto v = cfg_get_entry_ex(Z_STR(val));
    convert_to_string(v);
    std::string licensePath(Z_STRVAL(*v));

    if (licensePath.length() > 0)
    {
        std::string result = LoadLicense(licensePath);
        if (result != "OK")
        {
            char buffer[1024];
            snprintf(buffer, 1024, "Failed to load Aspose.Email for C++ license from file %s: %s", licensePath.c_str(), result.c_str());
            php_error(E_WARNING, buffer);
        }
    }

    return SUCCESS;
}
