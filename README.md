# Aspose.Email for C++

[Aspose.Email for C++](https://products.aspose.com/email/cpp) is a complete set of Email Processing APIs to create, read and manipulate emails from within your .NET applications. It makes it easier to work with many Outlook email message formats such as MSG, EML, EMLX and MHT files without the need of installing Microsoft Outlook. It also enables you to manage message storage files - Personal Storage Files (PST), Offline Storage Files (OST) along with message sending and receiving capabilities. You can also read and extract Outlook PST file that can be saved to disk in MSG format.

<p align="center">

  <a title="Download complete Aspose.Email for C++ source code" href="https://github.com/aspose-email/Aspose.Email-for-C/archive/master.zip">
	<img src="https://raw.github.com/AsposeExamples/java-examples-dashboard/master/images/downloadZip-Button-Large.png" />
  </a>
</p>

This repository contains [Examples](Examples) for [Aspose.Email for C++](https://products.aspose.com/email/cpp) to help you learn and write your own applications.

Directory | Description
--------- | -----------
[Examples](Examples)  | A collection of C++ examples that help you learn the product features.

# C++ Email Parsing Library

[Aspose.Email for C++](https://products.aspose.com/email/cpp) enables your C++ applications to work with various Outlook® objects including messages, tasks, contacts, calendar and journal items.

## Email File Processing Features

- [Create a new email message](https://docs.aspose.com/display/emailcpp/Creating+and+setting+contents+of+Emails#CreatingandsettingcontentsofEmails-CreateNewEmailMessage) with properties, such as, From, To, Subject, and Body.
- Save the email message in EML, MSG, and MHTML formats.
- Associate [human-friendly names to email addresses](https://docs.aspose.com/display/emailcpp/Creating+and+setting+contents+of+Emails#CreatingandsettingcontentsofEmails-Changingemailaddressestoafriendlyname), to improve accessibility.
- An email can have [HTML as well as Text body](https://docs.aspose.com/display/emailcpp/Creating+and+setting+contents+of+Emails#CreatingandsettingcontentsofEmails-SetMailBody).
- [Set alternate text of email messages](https://docs.aspose.com/display/emailcpp/Creating+and+setting+contents+of+Emails#CreatingandsettingcontentsofEmails-SettingAlternateText) for the Email Readers that cannot display HTML content.
- [Fetch and display email header information](https://docs.aspose.com/display/emailcpp/Extracting+Message+Contents+from+Emails) and email body on screen.
- Save and convert email messages to the [supported file formats](https://docs.aspose.com/display/emailcpp/Supported+File+Formats).
- [Read email messages with TNEF attachments](https://docs.aspose.com/display/emailcpp/Utility+Features+-+MailMessage#UtilityFeatures-MailMessage-MailMessagesContainingTNEFattachments) and modify the contents of the attachment.
- Check if the [email message is regular or a bounced](https://docs.aspose.com/display/emailcpp/Utility+Features+-+MailMessage#UtilityFeatures-MailMessage-CheckBouncedMessages) one.
- Add, remove, display and extract email attachments.
- [Embed objects in emails](https://docs.aspose.com/display/emailcpp/Working+with+Attachments+and+Embedded+Objects#WorkingwithAttachmentsandEmbeddedObjects-EmbeddingObjectsintoanEmail), the size of attachment depends on the email server.
- [Extract embedded objects](https://docs.aspose.com/display/emailcpp/Working+with+Attachments+and+Embedded+Objects#WorkingwithAttachmentsandEmbeddedObjects-ExtractingEmbeddedObjects) from email messages.
- [Export email to MHT with customized time zone](https://docs.aspose.com/display/emailcpp/Loading+and+Saving+Message#LoadingandSavingMessage-ExportingEmailtoMHTwithcustomizedTimeZone).
- [Create distribution list](https://docs.aspose.com/display/emailcpp/Working+with+Distribution+Lists#WorkingwithDistributionLists-CreatingandSavingaDistributionList) of multiple email contacts and save to storage in MSG format.
- Support to [work with MAPI properties](https://docs.aspose.com/display/emailcpp/Working+with+MAPI+Properties).
- Add [display or audio reminder](https://docs.aspose.com/display/emailcpp/Working+with+Outlook+Calendar+Items) to email calendar items.
- So many more [features](https://docs.aspose.com/display/emailcpp/Developer+Guide).

## Read & Write Email Formats

**Microsoft Outlook:** MSG, PST, OST, OFT\
**Other:** EML, EMLX, MBOX, ICS, VCF, HTML, MHTML

## Read Only Email Formats

**Microsoft Outlook:** OLM

## Getting Started with Aspose.Email for C++

Are you ready to give Aspose.Email for C++ a try? Simply execute `Install-Package Aspose.Email.Cpp` from Package Manager Console in Visual Studio to fetch the NuGet package. If you already have Aspose.Email for C++ and want to upgrade the version, please execute `Update-Package Aspose.Email.Cpp` to get the latest version.

## Create New Message & Save in EML & MSG Formats

Try executing the below code snippet to see how Aspose.Email for C++ performs in your environment. You may also check the [GitHub Repository](https://github.com/aspose-email/Aspose.Email-for-C) for other common usage scenarios.

The following code sample shows how to create new email message and save it in EML & MSG formats using C++.

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

## Send Email via Exchange EWS Client using C++

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

[Product Page](https://products.aspose.com/email/cpp) | [Docs](https://docs.aspose.com/display/emailcpp/Home) | [Demos](https://products.aspose.app/email/family) | [API Reference](https://apireference.aspose.com/email/cpp) | [Examples](https://github.com/aspose-email/Aspose.Email-for-C) | [Blog](https://blog.aspose.com/category/email/) | [Free Support](https://forum.aspose.com/c/email) |  [Temporary License](https://purchase.aspose.com/temporary-license)
