/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
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
#include <Mapi/MapiMessage.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void LoadingFromStream()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::String dst = dataDir + u"PersonalStorage.pst";
    
    // ExStart:LoadingFromStream
    // Create an instance of MapiMessage from file
    System::ArrayPtr<uint8_t> bytes = System::IO::File::ReadAllBytes(dataDir + u"message.msg");
    
    {
        System::SharedPtr<System::IO::MemoryStream> stream = System::MakeObject<System::IO::MemoryStream>(bytes);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ stream});
        // ------------------------------------------
        
        try
        {
            stream->Seek(0, System::IO::SeekOrigin::Begin);
            // Create an instance of MapiMessage from file
            System::SharedPtr<MapiMessage> msg = MapiMessage::FromStream(stream);
            
            // Get subject
            System::Console::WriteLine(System::String(u"Subject:") + msg->get_Subject());
            
            // Get from address
            System::Console::WriteLine(System::String(u"From:") + msg->get_SenderEmailAddress());
            
            // Get body
            System::Console::WriteLine(System::String(u"Body") + msg->get_Body());
            
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd:LoadingFromStream
}

