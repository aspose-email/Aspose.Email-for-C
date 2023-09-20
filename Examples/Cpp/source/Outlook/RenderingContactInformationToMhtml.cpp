/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/io/memory_stream.h>
#include <system/enum_helpers.h>
#include <MhtSaveOptions.h>
#include <MhtFormatOptions.h>
#include <Mapi/MapiMessage.h>
#include <Mapi/MapiContact.h>
#include <Mapi/MailConversionOptions.h>
#include <Mapi/ContactSaveFormat.h>
#include <MailMessage.h>
#include <cstdint>
#include <ContactFieldsSet.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void RenderingContactInformationToMhtml()
{
    // ExStart:RenderingContactInformationToMhtml
    System::String dataDir = GetDataDir_Outlook();
    
    //Load VCF Contact and convert to MailMessage for rendering to MHTML
    System::SharedPtr<MapiContact> contact = MapiContact::FromVCard(dataDir + u"Contact.vcf");
    
    System::SharedPtr<System::IO::MemoryStream> ms = System::MakeObject<System::IO::MemoryStream>();
    contact->Save(ms, Aspose::Email::Mapi::ContactSaveFormat::Msg);
    ms->set_Position(0);
    System::SharedPtr<MapiMessage> msg = MapiMessage::Load(ms);
    System::SharedPtr<MailConversionOptions> op = System::MakeObject<MailConversionOptions>();
    System::SharedPtr<MailMessage> eml = msg->ToMailMessage(op);
    
    //Prepare the MHT format options
    System::SharedPtr<MhtSaveOptions> mhtSaveOptions = System::MakeObject<MhtSaveOptions>();
    mhtSaveOptions->set_CheckBodyContentEncoding(true);
    mhtSaveOptions->set_PreserveOriginalBoundaries(true);
    MhtFormatOptions formatOp = Aspose::Email::MhtFormatOptions::WriteHeader | Aspose::Email::MhtFormatOptions::RenderVCardInfo;
    mhtSaveOptions->set_RenderedContactFields(Aspose::Email::ContactFieldsSet::NameInfo | Aspose::Email::ContactFieldsSet::PersonalInfo | Aspose::Email::ContactFieldsSet::Telephones | Aspose::Email::ContactFieldsSet::Events);
    mhtSaveOptions->set_MhtFormatOptions(formatOp);
    eml->Save(dataDir + u"ContactMhtml_out.mhtml", mhtSaveOptions);
    // ExEnd:RenderingContactInformationToMhtml
}

