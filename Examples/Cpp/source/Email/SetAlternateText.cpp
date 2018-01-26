/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/shared_ptr.h>
#include <system/object.h>
#include <Mail/MimeParts/AlternateViewCollection.h>
#include <Mail/MimeParts/AlternateView.h>
#include <Mail/MailMessage/MailMessage.h>


using namespace Aspose::Email::Mail;


void SetAlternateText()
{
    // ExStart:SetAlternateText
    // Declare message as MailMessage instance
    System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
    
    // Creates AlternateView to view an email message using the content specified in the //string
    System::SharedPtr<AlternateView> alternate = AlternateView::CreateAlternateViewFromString(L"Alternate Text");
    
    // Adding alternate text
    message->get_AlternateViews()->Add(alternate);
    // ExEnd:SetAlternateText
}






