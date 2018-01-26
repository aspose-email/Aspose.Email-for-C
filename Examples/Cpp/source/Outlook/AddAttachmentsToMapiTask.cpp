/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/text/encoding.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/array.h>
#include <Formats/Outlook/Mapi/TaskSaveFormat.h>
#include <Formats/Outlook/Mapi/MapiTask.h>
#include <Formats/Outlook/Mapi/MapiAttachmentCollection.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email::Outlook;


void AddAttachmentsToMapiTask()
{
    // ExStart:AddAttachmentsToMapiTask
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    System::String attachmentContent = L"Test attachment body";
    System::String attachmentName = L"Test attachment name";
    
    System::SharedPtr<MapiTask> testTask = System::MakeObject<MapiTask>(L"Task with attacment", L"Test body of task with attacment", System::DateTime::get_Now(), System::DateTime::get_Now().AddHours(1));
    testTask->get_Attachments()->Add(attachmentName, System::Text::Encoding::get_Unicode()->GetBytes(attachmentContent));
    testTask->Save(dataDir + L"AddAttachmentsToMapiTask_out", Aspose::Email::Outlook::TaskSaveFormat::Msg);
    // ExEnd:AddAttachmentsToMapiTask
}







