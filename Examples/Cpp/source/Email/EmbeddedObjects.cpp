#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/environment.h>
#include <system/console.h>
#include <Mail/MimeParts/LinkedResourceCollection.h>
#include <Mail/MimeParts/LinkedResource.h>
#include <Mail/MimeParts/AlternateViewCollection.h>
#include <Mail/MimeParts/AlternateView.h>
#include <Mail/Mime/MediaTypeNames.h>
#include <Mail/MailMessage/SaveOptions/SaveOptions.h>
#include <Mail/MailMessage/SaveOptions/MsgSaveOptions.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailAddressCollection.h>
#include <Mail/MailAddress.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;
using namespace Aspose::Email::Mime;


void EmbeddedObjects()
{
    // ExStart:EmbeddedObjects
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    System::String dstEmail = dataDir + L"EmbeddedImage.msg";
    
    // Create an instance of the MailMessage class and Set the addresses and Set the content
    System::SharedPtr<MailMessage> mail = System::MakeObject<MailMessage>();
    mail->set_From(System::MakeObject<MailAddress>(L"test001@gmail.com"));
    mail->get_To()->Add(L"test001@gmail.com");
    mail->set_Subject(L"This is an email");
    
    // Create the plain text part It is viewable by those clients that don't support HTML
    System::SharedPtr<AlternateView> plainView = AlternateView::CreateAlternateViewFromString(L"This is my plain text content", nullptr, L"text/plain");
    
    /* Create the HTML part.To embed images, we need to use the prefix 'cid' in the img src value.
                The cid value will map to the Content-Id of a Linked resource. Thus <img src='cid:barcode'> will map to a LinkedResource with a ContentId of //'barcode'. */
    System::SharedPtr<AlternateView> htmlView = AlternateView::CreateAlternateViewFromString(L"Here is an embedded image.<img src=cid:barcode>", nullptr, L"text/html");
    
    // Create the LinkedResource (embedded image) and Add the LinkedResource to the appropriate view
    System::SharedPtr<LinkedResource> barcode = [&]{ auto tmp_0 = System::MakeObject<LinkedResource>(dataDir + L"1.jpg", MediaTypeNames::Image::Jpeg); tmp_0->set_ContentId(L"barcode"); return tmp_0; }();
    mail->get_LinkedResources()->Add(barcode);
    mail->get_AlternateViews()->Add(plainView);
    mail->get_AlternateViews()->Add(htmlView);
    mail->Save(dataDir + L"EmbeddedImage_out.msg", SaveOptions::get_DefaultMsgUnicode());
    // ExEnd:EmbeddedObjects
    System::Console::WriteLine(System::Environment::get_NewLine() + L"Message saved with embedded objects successfully at " + dstEmail);
}






