#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/details/dispose_guard.h>
#include <Mapi/MapiMessage.h>

using namespace Aspose::Email::Mapi;

void SaveMsgAsTemplate()
{
    /// <summary>
    /// This example shows how to save an Outlook MSG file to Outlook Template  using the MapiMessage API
    /// Available from Aspose.Email for .NET 6.4.0 onwards
    /// MapiMessage.SaveAsTemplate(Stream stream) - Saves to the specified stream as Outlook File Template(OFT format).
    /// MapiMessage.SaveAsTemplate(string fileName) - Saves to the specified file as Outlook File Template(OFT format).
    /// </summary>
    
    // ExStart: SaveMsgAsTemplate
    {
        System::SharedPtr<MapiMessage> mapi = System::MakeObject<MapiMessage>(u"test@from.to", u"test@to.to", u"template subject", u"Template body");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ mapi});
        // ------------------------------------------
        
        try
        {
            System::String oftMapiFileName = u"mapiToOft.msg";
            mapi->SaveAsTemplate(oftMapiFileName);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd: SaveMsgAsTemplate
}

