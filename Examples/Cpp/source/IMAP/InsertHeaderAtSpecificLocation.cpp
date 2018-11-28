﻿/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <Mime/HeaderCollection.h>
#include <MailMessage.h>

#include "Examples.h"

using namespace Aspose::Email::Mime;
using namespace Aspose::Email;

void InsertHeaderAtSpecificLocation()
{
    //ExStart:InsertHeaderAtSpecificLocation
    // The path to the File directory.
    System::String dataDir = GetDataDir_IMAP();
    System::String loadFile = dataDir + u"InsertHeaders.eml";
    System::SharedPtr<MailMessage> eml = MailMessage::Load(loadFile);
    eml->get_Headers()->Insert(u"secret-header", u"mystery1");
    eml->Save(dataDir + u"Updated-MessageHeaders_out.eml");
    //ExEnd:InsertHeaderAtSpecificLocation
}

