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
#include <system/io/file.h>
#include <system/date_time.h>
#include <system/array.h>
#include <Mapi/MapiJournal.h>
#include <Mapi/MapiAttachmentCollection.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;


using namespace Aspose::Email::Mapi;

void AddAttachmentsToMapiJournal()
{
    // The path to the File directory.
    // ExStart:AddAttachmentsToMapiJournal
    System::String dataDir = GetDataDir_Outlook();
    
    System::ArrayPtr<System::String> attachFileNames = System::MakeArray<System::String>({dataDir + u"Desert.jpg", dataDir + u"download.png"});
    
    System::SharedPtr<MapiJournal> journal = System::MakeObject<MapiJournal>(u"testJournal", u"This is a test journal", u"Phone call", u"Phone call");
    journal->set_StartTime(System::DateTime::get_Now());
    journal->set_EndTime(journal->get_StartTime().AddHours(1));
    journal->set_Companies(System::MakeArray<System::String>({u"company 1", u"company 2", u"company 3"}));
    
    
    {
        for (int i_ = 0; i_ < attachFileNames->Count(); ++i_)
        {
            System::String attach = attachFileNames[i_];
            {
                journal->get_Attachments()->Add(attach, System::IO::File::ReadAllBytes(attach));
            }
        }
    }
    journal->Save(dataDir + u"AddAttachmentsToMapiJournal_out.msg");
    // ExEnd:AddAttachmentsToMapiJournal
}

