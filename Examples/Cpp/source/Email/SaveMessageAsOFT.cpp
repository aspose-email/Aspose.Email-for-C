#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/details/dispose_guard.h>
#include <SaveOptions.h>
#include <MsgSaveOptions.h>
#include <MailMessage.h>

#include "Examples.h"

using namespace Aspose::Email;

void SaveMessageAsOFT()
{
    
    /// <summary>
    /// This exmpale shows how to save an email as Outlook Template (.OFT) file using the MailMesasge API
    /// MsgSaveOptions.SaveAsTemplate - Set to true, if need to be saved as Outlook File Template(OFT format).
    /// Available from Aspose.Email for .NET 6.4.0 onwards
    /// </summary>
    
    System::String dataDir = GetDataDir_Email();
    
    // ExStart: SaveMessageAsOFT
    {
        System::SharedPtr<MailMessage> eml = System::MakeObject<MailMessage>(u"test@from.to", u"test@to.to", u"template subject", u"Template body");
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ eml});
        // ------------------------------------------
        
        try
        {
            System::String oftEmlFileName = u"EmlAsOft_out.oft";
            System::SharedPtr<MsgSaveOptions> options = SaveOptions::get_DefaultMsgUnicode();
            options->set_SaveAsTemplate(true);
            eml->Save(dataDir + oftEmlFileName, options);
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
    // ExEnd: SaveMessageAsOFT
}






