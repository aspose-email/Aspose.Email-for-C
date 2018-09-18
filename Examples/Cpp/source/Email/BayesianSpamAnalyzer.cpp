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
#include <system/io/directory.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <system/array.h>
#include <MailMessage.h>
#include <cstdint>
#include <AntiSpam/SpamAnalyzer.h>

#include "Examples.h"

using namespace Aspose::Email;
using namespace Aspose::Email::AntiSpam;

void TeachAndCreateDatabase(System::String hamFolder, System::String spamFolder, System::String dataBaseFile)
{
    System::ArrayPtr<System::String> hamFiles = System::IO::Directory::GetFiles(hamFolder, u"*.eml");
    System::ArrayPtr<System::String> spamFiles = System::IO::Directory::GetFiles(spamFolder, u"*.eml");
    
    System::SharedPtr<SpamAnalyzer> analyzer = System::MakeObject<SpamAnalyzer>();
    
    for (int32_t i = 0; i < hamFiles->get_Length(); i++)
    {
        System::SharedPtr<MailMessage> hamMailMessage;
        try
        {
            hamMailMessage = MailMessage::Load(hamFiles[i]);
        }
        catch (System::Exception& )
        {
            continue;
        }
        
        
        System::Console::WriteLine(i);
        analyzer->TrainFilter(hamMailMessage, false);
    }
    
    for (int32_t i = 0; i < spamFiles->get_Length(); i++)
    {
        System::SharedPtr<MailMessage> spamMailMessage;
        try
        {
            spamMailMessage = MailMessage::Load(spamFiles[i]);
        }
        catch (System::Exception& )
        {
            continue;
        }
        
        
        System::Console::WriteLine(i);
        analyzer->TrainFilter(spamMailMessage, true);
    }
    
    analyzer->SaveDatabase(dataBaseFile);
}

void PrintResult(double probability)
{
    if (probability < 0.05)
    {
        System::Console::WriteLine(u"This is ham)");
    }
    else if (probability > 0.95)
    {
        System::Console::WriteLine(u"This is spam)");
    }
    else
    {
        System::Console::WriteLine(u"Maybe spam)");
    }
}


void BayesianSpamAnalyzer()
{
    // ExStart:BayesianSpamAnalyzer
    System::String hamFolder = GetDataDir_Email() + u"/hamFolder";
    System::String spamFolder = GetDataDir_Email() + u"/Spam";
    System::String testFolder = GetDataDir_Email();
    System::String dataBaseFile = GetDataDir_Email() + u"SpamFilterDatabase.txt";

    TeachAndCreateDatabase(hamFolder, spamFolder, dataBaseFile);
    System::ArrayPtr<System::String> testFiles = System::IO::Directory::GetFiles(testFolder, u"*.eml");
    System::SharedPtr<SpamAnalyzer> analyzer = System::MakeObject<SpamAnalyzer>(dataBaseFile);

    {
        for (int i_ = 0; i_ < testFiles->Count(); ++i_)
        {
            System::String file = testFiles[i_];
            {
                System::SharedPtr<MailMessage> msg = MailMessage::Load(file);
                System::Console::WriteLine(msg->get_Subject());
                double probability = analyzer->Test(msg);
                PrintResult(probability);
            }
        }
    }
    // ExEnd:BayesianSpamAnalyzer
}




