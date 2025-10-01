/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/FolderInfoCollection.h>
#include <Storage/Pst/FolderInfo.h>
#include <cstdint>
#include <Storage/Pst/PersonalStorageQueryBuilder.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Storage::Pst;

void DisplayInformationOfPSTFile()
{
    // ExStart:DisplayInformationOfPSTFile
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    System::String dst = dataDir + u"test.pst";
    
    // load PST file
    System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(dst);

    //System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(u"test.pst");
    
    // Get the folders information
    System::SharedPtr<FolderInfoCollection> folderInfoCollection = personalStorage->get_RootFolder()->GetSubFolders();
    
    // Browse through each folder to display folder name and number of messages
   
    for (auto&& folderInfo : folderInfoCollection)
    {
      int count = folderInfo->get_ContentCount();
      if (count == 0)
        continue;

      System::Console::WriteLine(System::String(u"Folder: ") + folderInfo->get_DisplayName());
      System::Console::WriteLine(System::String(u"Total items: ") + folderInfo->get_ContentCount());
      System::Console::WriteLine(System::String(u"Total unread items: ") + folderInfo->get_ContentUnreadCount());

      System::Console::WriteLine(u"--- messages from Saqib Razzaq --------");
      // retrive first message from folert
      auto builder = System::MakeObject<PersonalStorageQueryBuilder>();

      builder->get_From()->Contains(u"Saqib Razzaq", true);
      //queryBuilder.From.Contains("Saqib Razzaq", true);


      auto messageInfoCollection = folderInfo->GetContents(builder->GetQuery(), 0, count);
      for (auto&& messageInfo : messageInfoCollection)
      {
        System::Console::WriteLine(System::String(u"Subject: ") + messageInfo->get_Subject());
        System::Console::WriteLine(System::String(u"Sender: ") + messageInfo->get_SenderRepresentativeName());
        System::Console::WriteLine(System::String(u"Recipients: ") + messageInfo->get_DisplayTo());
        System::Console::WriteLine(u"------------------------------");
      }

    }
    // ExEnd:DisplayInformationOfPSTFile
}

