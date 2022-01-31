/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/holder_initializer.h>
#include <system/object.h>
#include <system/io/directory.h>
#include <system/exceptions.h>
#include <system/details/dispose_guard.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <system/array.h>
#include <Storage/Pst/PersonalStorage.h>
#include <Storage/Pst/MessageAddedEventArgs.h>
#include <Storage/Pst/FolderInfo.h>
#include <Mapi/MapiMessage.h>
#include <cstdint>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;
using namespace Aspose::Email::Storage::Pst;

class MapiMessageEnumerator : public System::Collections::Generic::IEnumerator<System::SharedPtr<Aspose::Email::Mapi::MapiMessage>>
{
public:

    const System::SharedPtr<Aspose::Email::Mapi::MapiMessage>& get_Current() const override;

    MapiMessageEnumerator(System::String path);

    bool MoveNext();
    void Reset();
    void Dispose();


private:

    System::ArrayPtr<System::String> files;
    int32_t position;
    mutable System::SharedPtr<Aspose::Email::Mapi::MapiMessage> m_CurrentHolder;


};

class MapiMessageCollection : public System::Collections::Generic::IEnumerable<System::SharedPtr<Aspose::Email::Mapi::MapiMessage>>
{

public:

    MapiMessageCollection(System::String path);

    System::SharedPtr<System::Collections::Generic::IEnumerator<System::SharedPtr<Aspose::Email::Mapi::MapiMessage>>> GetEnumerator();

private:

    System::String path;

};



const System::SharedPtr<Aspose::Email::Mapi::MapiMessage>& MapiMessageEnumerator::get_Current() const
{
    System::HolderInitializer<System::SharedPtr<Aspose::Email::Mapi::MapiMessage>> holder(m_CurrentHolder);

    try
    {
        return holder.HoldIfTemporary(MapiMessage::FromFile(files[position]));
    }
    catch (System::IndexOutOfRangeException&)
    {
        throw System::InvalidOperationException();
    }
}

MapiMessageEnumerator::MapiMessageEnumerator(System::String path)
     : position(-1)
{
    System::String path1 = GetDataDir_Outlook();
    files = System::IO::Directory::GetFiles(path1);
}

bool MapiMessageEnumerator::MoveNext()
{
    position++;
    return (position < files->get_Length());
}

void MapiMessageEnumerator::Reset()
{
    position = -1;
}

void MapiMessageEnumerator::Dispose() { }



MapiMessageCollection::MapiMessageCollection(System::String path)
{
    this->path = path;
}

System::SharedPtr<System::Collections::Generic::IEnumerator<System::SharedPtr<Aspose::Email::Mapi::MapiMessage>>> MapiMessageCollection::GetEnumerator()
{
    return System::MakeObject<MapiMessageEnumerator>(path);
}

static void OnMessageAdded(System::SharedPtr<System::Object> sender, System::SharedPtr<Aspose::Email::Storage::Pst::MessageAddedEventArgs> e)
{
    System::Console::WriteLine(e->get_EntryId());
    System::Console::WriteLine(e->get_Message()->get_Subject());
}



void AddMessagesInBulkMode(System::String fileName, System::String msgFolderName)
{
    {
        System::SharedPtr<PersonalStorage> personalStorage = PersonalStorage::FromFile(fileName);
        // Clearing resources under 'using' statement
        System::Details::DisposeGuard<1> __dispose_guard_0({ personalStorage});
        // ------------------------------------------
        
        try
        {
            System::SharedPtr<FolderInfo> folder = personalStorage->get_RootFolder()->GetSubFolder(u"myInbox");
            folder->MessageAdded.connect(OnMessageAdded);
            folder->AddMessages(System::MakeObject<MapiMessageCollection>(msgFolderName));
        }
        catch(...)
        {
            __dispose_guard_0.SetCurrentException(std::current_exception());
        }
    }
}


void AddingBulkMessagesWithImprovedPerformance()
{
    // ExStart:AddingBulkMessagesWithImprovedPerformance
    // The path to the file directory.
    System::String dataDir = GetDataDir_Outlook();

    // Load the Outlook file
    System::String path = dataDir + u"PersonalStorageFile2.pst";
    AddMessagesInBulkMode(path, u"Contacts");
}

