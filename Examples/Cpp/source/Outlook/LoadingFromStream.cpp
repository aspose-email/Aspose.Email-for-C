/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/seekorigin.h>
#include <system/io/memory_stream.h>
#include <system/io/file.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/array.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void LoadingFromStream()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::String dst = dataDir + L"PersonalStorage.pst";
    
    // ExStart:LoadingFromStream
    // Create an instance of MapiMessage from file
    System::ArrayPtr<uint8_t> bytes = System::IO::File::ReadAllBytes(dataDir + L"message.msg");
    
    {
        System::SharedPtr<System::IO::MemoryStream> stream = System::MakeObject<System::IO::MemoryStream>(bytes);
        
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard __dispose_guard_0{ stream, ASPOSE_CURRENT_FUNCTION_LINE };
        // ------------------------------------------
        stream->Seek(0, System::IO::SeekOrigin::Begin);
        // Create an instance of MapiMessage from file
        System::SharedPtr<MapiMessage> msg = MapiMessage::FromStream(stream);
        
        // Get subject
        System::Console::WriteLine(System::String(L"Subject:") + msg->get_Subject());
        
        // Get from address
        System::Console::WriteLine(System::String(L"From:") + msg->get_SenderEmailAddress());
        
        // Get body
        System::Console::WriteLine(System::String(L"Body") + msg->get_Body());
        
    }
    // ExEnd:LoadingFromStream
}







