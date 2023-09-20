/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/enumerator_adapter.h>
#include <system/special_casts.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <system/collections/icollection.h>
#include <Mapi/MapiPropertyCollection.h>
#include <Mapi/MapiProperty.h>
#include <Mapi/MapiNamedProperty.h>
#include <Mapi/MapiMessage.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::Mapi;

void ReadNamedMAPIProperties()
{
    //ExStart:ReadNamedMAPIProperties
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // Load from file
    System::SharedPtr<MapiMessage> message = MapiMessage::Load(dataDir + u"message.msg");
    
    // Get all named MAPI properties
    System::SharedPtr<MapiPropertyCollection> properties = message->get_NamedProperties();
    // Read all properties in foreach loop
    
    {
        for (auto&& mapiNamedProp : System::IterateOver<MapiNamedProperty>(properties->get_Values()))
        {
            // Read any specific property
            {
                const System::String& switch_value_0 = mapiNamedProp->get_NameId();
                do {
                    if (switch_value_0 == u"TEST")
                    {
                        System::Console::WriteLine(u"{0} = {1}", System::ObjectExt::Box<System::String>(mapiNamedProp->get_NameId()), System::ObjectExt::Box<System::String>(mapiNamedProp->GetString()));
                        break;
                    }
                    if (switch_value_0 == u"MYPROP")
                    {
                        System::Console::WriteLine(u"{0} = {1}", System::ObjectExt::Box<System::String>(mapiNamedProp->get_NameId()), System::ObjectExt::Box<System::String>(mapiNamedProp->GetString()));
                        break;
                    }
                    if (true) 
                    {
                        break;
                    }
                } while (false);
            }
        }
    }
    //ExEnd:ReadNamedMAPIProperties
}

