#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/io/file.h>
#include <system/environment.h>
#include <system/console.h>
#include <Formats/Outlook/Pst/PersonalStorage.h>
#include <Formats/Outlook/Pst/Ndb/Structures/FileFormatVersion.h>
#include <Formats/Outlook/Pst/Messaging/FolderInfo.h>

#include "Examples.h"


using namespace Aspose::Email;
using namespace Aspose::Email::Outlook::Pst;


void NewPSTAddSubfolders()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::String dst = dataDir + L"PersonalStorage.pst";
    
    if (System::IO::File::Exists(dst))
    {
        System::IO::File::Delete(dst);
    }
    
    // Create new PST
    System::SharedPtr<PersonalStorage> pst = PersonalStorage::Create(dst, Aspose::Email::Outlook::Pst::FileFormatVersion::Unicode);
    
    // Add new folder "Inbox"
    pst->get_RootFolder()->AddSubFolder(L"Inbox");
    
    System::Console::WriteLine(System::Environment::get_NewLine() + L"PST saved successfully at " + dst);
}







