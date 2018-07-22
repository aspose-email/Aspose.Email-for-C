#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/io/file.h>
#include <system/environment.h>
#include <system/console.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfo.h>
#include <Storage/Pst/FileFormatVersion.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void NewPSTAddSubfolders()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::String dst = dataDir + u"PersonalStorage.pst";
    
    if (System::IO::File::Exists(dst))
    {
        System::IO::File::Delete(dst);
    }
    
    // Create new PST
    System::SharedPtr<PersonalStorage> pst = PersonalStorage::Create(dst, Aspose::Email::Storage::Pst::FileFormatVersion::Unicode);
    
    // Add new folder "Inbox"
    pst->get_RootFolder()->AddSubFolder(u"Inbox");
    
    System::Console::WriteLine(System::Environment::get_NewLine() + u"PST saved successfully at " + dst);
}

