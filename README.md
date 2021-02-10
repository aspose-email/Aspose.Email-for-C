![Nuget](https://img.shields.io/nuget/v/Aspose.email.Cpp) ![Nuget](https://img.shields.io/nuget/dt/Aspose.email.Cpp) ![GitHub](https://img.shields.io/github/license/aspose-email/Aspose.email-for-C)
# C++ Email Library

[Aspose.Email for C++](https://products.aspose.com/email/cpp) is a complete set of Email Processing APIs to create, read and manipulate emails from within C++ applications. It makes it easier to work with many Outlook email message formats such as MSG, EML, EMLX and MHT files without the need of installing Microsoft Outlook. It also enables you to manage message storage files - Personal Storage Files (PST), Offline Storage Files (OST) along with message sending and receiving capabilities. You can also read and extract Outlook PST file that can be saved to disk in MSG format.

<p align="center">

  <a title="Download complete Aspose.Email for C++ source code" href="https://github.com/aspose-email/Aspose.Email-for-C/archive/master.zip">
	<img src="https://raw.github.com/AsposeExamples/java-examples-dashboard/master/images/downloadZip-Button-Large.png" />
  </a>
</p>

Directory | Description
--------- | -----------
[Examples](Examples)  | A collection of C++ examples that help you learn the product features.


## Email Message Parsing via C++

- [Create a new email message](https://docs.aspose.com/email/cpp/creating-and-setting-contents-of-emails/) with custom header.
- Save email messages in EML, MSG, and MHTML formats.
- Associate human-friendly names to email addresses for better accessibility.
- Have emails with HTML or Text body.
- Set alternate text of email messages for the Email Readers that cannot display HTML content.
- [Fetch and display email header information](https://docs.aspose.com/email/cpp/extracting-message-contents-from-emails/).
- Save and convert email messages to the [more than 12 supported file formats](https://docs.aspose.com/email/cpp/supported-file-formats/).
- [Read email messages with TNEF attachments](https://docs.aspose.com/email/cpp/utility-features-mailmessage/) and modify the contents of the attachment.
- Add, remove, display and extract email attachments.
- [Embed objects in emails](https://docs.aspose.com/email/cpp/working-with-attachments-and-embedded-objects/), or extract objects & attachments.
- [Create distribution list](https://docs.aspose.com/email/cpp/working-with-distribution-lists/) of multiple email contacts and save to storage in MSG format.
- [Work with MAPI properties](https://docs.aspose.com/email/cpp/working-with-mapi-properties/).

## Read & Write Email Formats

**Microsoft Outlook:** MSG, PST, OST, OFT\
**Other:** EML, EMLX, MBOX, ICS, VCF, HTML, MHTML

## Read Only Email Formats

**Microsoft Outlook:** OLM

## Gett Started with Aspose.Email for C++

Are you ready to give Aspose.Email for C++ a try? Simply execute `Install-Package Aspose.Email.Cpp` from Package Manager Console in Visual Studio to fetch the NuGet package. If you already have Aspose.Email for C++ and want to upgrade the version, please execute `Update-Package Aspose.Email.Cpp` to get the latest version.

## Create New Message & Save in EML & MSG Formats

```c++
// create a new instance of MailMessage class
System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();

// set subject of the message
message->set_Subject(u"New message created by Aspose.Email for .NET");

// set HTML body
message->set_IsBodyHtml(true);
message->set_HtmlBody(u"<b>This line is in bold.</b> <br/> <br/><font color=blue>This line is in blue color</font>");

// set sender information
message->set_From(u"from@domain.com");

// add TO recipients
message->get_To()->Add(u"to1@domain.com");
message->get_To()->Add(u"to2@domain.com");

// add CC recipients
message->get_CC()->Add(u"cc1@domain.com");
message->get_CC()->Add(u"cc2@domain.com");

// save message in EML, MSG and MHTML formats
message->Save(dir + u"output.eml", Aspose::Email::SaveOptions::get_DefaultEml());
message->Save(dir + u"output.msg", Aspose::Email::SaveOptions::get_DefaultMsgUnicode());
```

## Send Email via Exchange EWS Client

```c++
// create instance of IEWSClient class by giving credentials
System::SharedPtr<IEWSClient> client = GetExchangeEWSClient(GetExchangeTestUser());

// create instance of type MailMessage
System::SharedPtr<MailMessage> msg = System::MakeObject<MailMessage>();
msg->set_From(MailAddress::to_MailAddress(u"sender@domain.com"));
msg->set_To(MailAddressCollection::to_MailAddressCollection(u"recipient@ domain.com "));
msg->set_Subject(u"Sending message from exchange server");
msg->set_HtmlBody(u"<h3>sending message from exchange server</h3>");

// send the message
client->Send(msg);
```

[Home](https://www.aspose.com/) | [Product Page](https://products.aspose.com/email/cpp) | [Docs](https://docs.aspose.com/email/cpp/) | [Demos](https://products.aspose.app/email/family) | [API Reference](https://apireference.aspose.com/email/cpp) | [Examples](https://github.com/aspose-email/Aspose.Email-for-C) | [Blog](https://blog.aspose.com/category/email/) | [Free Support](https://forum.aspose.com/c/email) |  [Temporary License](https://purchase.aspose.com/temporary-license)
