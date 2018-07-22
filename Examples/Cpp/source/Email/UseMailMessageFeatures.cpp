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
#include <system/enum_helpers.h>
#include <system/date_time.h>
#include <SaveOptions.h>
#include <MailSensitivity.h>
#include <MailPriority.h>
#include <MailMessage.h>
#include <MailAddressCollection.h>
#include <MailAddress.h>
#include <EmlSaveOptions.h>
#include <DeliveryNotificationOptions.h>

#include "Examples.h"

using namespace Aspose::Email;

void UseMailMessageFeatures()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // ExStart:MailMessageFeatures
    // Create a new message
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    message->set_From(u"sender@gmail.com");
    message->set_To(u"receiver@gmail.com");
    message->set_Subject(u"Using MailMessage Features");
    
    // Specify message date
    message->set_Date(System::DateTime::get_Now());
    
    // Specify message priority
    message->set_Priority(Aspose::Email::MailPriority::High);
    
    // Specify message sensitivity
    message->set_Sensitivity(Aspose::Email::MailSensitivity::Normal);
    
    // Specify options for delivery notifications
    message->set_DeliveryNotificationOptions(Aspose::Email::DeliveryNotificationOptions::OnSuccess);
    // ExEnd:MailMessageFeatures
    
    message->Save(dataDir + u"UseMailMessageFeatures_out.eml", SaveOptions::get_DefaultEml());
}






