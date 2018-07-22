#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/environment.h>
#include <system/console.h>
#include <SaveOptions.h>
#include <MsgSaveOptions.h>
#include <Mime/MediaTypeNames.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <LinkedResourceCollection.h>
#include <LinkedResource.h>
#include <AlternateViewCollection.h>
#include <AlternateView.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mime;

void EmbeddedObjects()
{
    // ExStart:EmbeddedObjects
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    System::String dstEmail = dataDir + u"EmbeddedImage.msg";
    
    // Create an instance of the MailMessage class and Set the addresses and Set the content
    System::SharedPtr<MailMessage> mail = System::MakeObject<MailMessage>();
    mail->set_From(System::MakeObject<MailAddress>(u"test001@gmail.com"));
    mail->get_To()->Add(u"test001@gmail.com");
    mail->set_Subject(u"This is an email");
    
    // Create the plain text part It is viewable by those clients that don't support HTML
    System::SharedPtr<AlternateView> plainView = AlternateView::CreateAlternateViewFromString(u"This is my plain text content", nullptr, u"text/plain");
    
    /* Create the HTML part.To embed images, we need to use the prefix 'cid' in the img src value.
                The cid value will map to the Content-Id of a Linked resource. Thus <img src='cid:barcode'> will map to a LinkedResource with a ContentId of //'barcode'. */
    System::SharedPtr<AlternateView> htmlView = AlternateView::CreateAlternateViewFromString(u"Here is an embedded image.<img src=cid:barcode>", nullptr, u"text/html");
    
    // Create the LinkedResource (embedded image) and Add the LinkedResource to the appropriate view
    System::SharedPtr<LinkedResource> barcode = [&]{ auto tmp_0 = System::MakeObject<LinkedResource>(dataDir + u"1.jpg", MediaTypeNames::Image::Jpeg); tmp_0->set_ContentId(u"barcode"); return tmp_0; }();
    mail->get_LinkedResources()->Add(barcode);
    mail->get_AlternateViews()->Add(plainView);
    mail->get_AlternateViews()->Add(htmlView);
    mail->Save(dataDir + u"EmbeddedImage_out.msg", SaveOptions::get_DefaultMsgUnicode());
    // ExEnd:EmbeddedObjects
    System::Console::WriteLine(System::Environment::get_NewLine() + u"Message saved with embedded objects successfully at " + dstEmail);
}






