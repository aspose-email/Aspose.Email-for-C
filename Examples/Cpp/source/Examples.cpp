#include "Examples.h"

#include <system/string.h>
#include <system/object_ext.h>
#include <system/io/path.h>
#include <system/io/directory_info.h>
#include <system/io/directory.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <system/array.h>
#include <cstdint>

#include <Licensing/License.h>

using namespace Aspose::Email;
using namespace System;

void LoadLicense(const String& licFile)
{
    SharedPtr<License> license = System::MakeObject<License>();
    license->SetLicense(licFile);
    bool licensed = license->get_IsLicensed(); // return true if license is correctly identified
    //assert(licensed);
}

void RunExamples()
{
    Console::WriteLine(L"Open Examples.cpp \nIn RunExamples() function uncomment the example that you want to run.");
    Console::WriteLine(L"=====================================================");

    //LoadLicense(L"Aspose.lic");

    // Uncomment the one you want to try out

    // =====================================================
    // =====================================================
    // Email
    // =====================================================
    // =====================================================
    //AddEmailAttachments();
    //AddNewTNEFAttachments();
    //BayesianSpamAnalyzer();
    //ChangeEmailAddress();
    //CheckBouncedMessage();
    //ConvertMHTMLWithOptionalSettings();
    //CreateNewEmail();
    //CreateNewMailMessage();
    //CreateTNEFEMLFromMSG();
    //CreatingTNEFFromMSG();
    //DetectDifferentFileFormats();
    //DetectMessageIsTNEF();
    //DetermineAttachmentEmbeddedMessage();
    //DisplayAttachmentFileName();
    //DisplayEmailInformation();
    //DraftAppointmentRequest();
    //EmbeddedObjects();
    //ExportEmailToEML();
    //ExportEmailToMHTWithCustomTimezone();
    //ExtractAttachments();
    //ExtractEmbeddedObjects();
    //ExtractEmbeddedObjectsFromEmail();
    //ExtractingEmailHeaders();
    //ExtractMSGEmbeddedAttachment();
    //GetDecodedHeaderValues();
    //GetDeliveryStatusNotificationMessages();
    //IdentifyInlineAndRegularAttachments();
    //LoadAndSaveFileAsEML();
    //LoadingEMLAndSavingToMSG();
    //LoadMessageWithLoadOptions();
    //PreserveEmbeddedMSGFormatDuringLoad();
    //PreserveOriginalBoundaries();
    //PreserveTNEFAttachment();
    //PreservingEmbeddedMsgFormat();
    //ReadMessageByPreservingTNEFAttachments();
    //RemoveAttachments();
    //RenderingCalendarEvents();
    //RetrieveContentDescriptionFromAttachment();
    //SaveMailMessageAsMHTML();
    //SaveMessageAsOFT();
    //SavingMSGWithPreservedDates();
    //SetAlternateText();
    //SetDefaultTextEncoding();
    //SetEmailHeaders();
    //SetHTMLBody();
    //SetParticipantStatusOfAppointmentAttendees();
    //UpdateTNEFAttachments();
    //UseMailMessageFeatures();


    /// / =====================================================
    /// / =====================================================
    /// / Outlook
    /// / =====================================================
    /// / =====================================================

    //NewPSTAddSubfolders();
    //CreateSaveOutlookFiles();
    //DeleteBulkItemsFromPSTFile();
    //UpdateBulkMessagesInPSTFile();
    //LoadMSGFiles();
    //LoadingFromStream();
    //GetMAPIProperty();
    //SetMAPIProperties();
    //ReadNamedMAPIProperties();
    //ReadiNamedMAPIPropertyFromAttachment();
    //ReadingNamedMAPIPropertyFromAttachment();
    //RemovePropertiesFromMSGAndAttachments();
    //ConvertEMLToMSG();
    //ReadAndWritingOutlookTemplateFile();
    //SetFollowUpflag();
    //SetFollowUpForRecipients();
    //MarkFollowUpFlagAsCompleted();
    //RemoveFollowUpflag();
    //ReadFollowupFlagOptionsForMessage();
    //CreateAndSaveOutlookContact();
    //CreatingAndSavingOutlookTasks();
    //AddReminderInformationToMapiTask();
    //AddAttachmentsToMapiTask();
    //AddRecurrenceToMapiTask();
    //CreatAndSaveAnOutlookNote();
    //ReadMapiNote();
    //ConvertMIMEMessagesFromMSGToEML();
    //ConvertMIMEMessageToEML();
    //SetColorCategories();
    //SetReminderByAddingTags();
    //CreateAndSaveCalendaritems();
    //AddDisplayReminderToACalendar();
    //AddAudioReminderToCalendar();
    //ManageAttachmentsFromCalendarFiles();
    //CreatePollUsingMapiMessage();
    //ReadVotingOptionsFromMapiMessage();
    //AddVotingButtonToExistingMessage();
    //DeleteVotingButtonFromMessage();
    //CreateAndSaveDistributionList();
    //CreatReplyMessage();
    //CreateForwardMessage();
    //EndAfterNoccurrences();
    //WeeklyEndAfterNoccurrences();
    //EndAfterNoccurrenceSelectMultipleDaysInweek();
    //MonthlyEndAfterNoccurrences();
    //YearlyEndAfterNoccurrences();
    //GenerateRecurrenceFromRecurrenceRule();
    //ExposeProperties();
    //GetTheTextAndRTFBodies();
    //CreateNewMapiCalendarAndAddToCalendarSubfolder();
    //ParseOutlookMessageFile();
    //ConvertMSGToMIMEMessage();
    //CreatingAndSavingOutlookMessages();
    //CreatingMSGFilesWithRTFBody();
    //SavingMessageInDraftStatus();
    //SetBodyCompression();
    //ReadingVotingOptions();
    //SetAdditionalMAPIProperties();
    //SaveAttachmentsFromOutlookMSGFile();
    //RemoveAttachmentsFromFile();
    //DestroyAttachment();
    //EmbedMessageAsAttachment();
    //ReadEmbeddedMessageFromAttachment();
    //InsertMSGAttachmentAtSpecificlocation();
    //ReplaceEmbeddedMSGAttachmentContents();
    //LoadingContactFromMSG();
    //LoadingContactFromVCard();
    //LoadingContactFromVCardWithSpecifiedEncoding();
    //ReadingMapiTask();
    //ReadingVToDoTask();
    //SavingTheCalendarItemAsMSG();
    //DisplayRecipientsStatusFromMeetingRequest();
    //CreateMapiCalendarTimeZoneFromStandardTimezone();
    //ReadingDistributionListFromPST();
    //SetDailyOccurrenceCount();
    //SetRecurrenceEveryDay();
    //SetDailyNeverEndRecurrence();
    //SetWeeklyRecurrenceMultipleDaysInWeekWithInterval();
    //SetWeeklyEndAfterDateRecurrence();
    //SetWeeklyNeverEndRecurrence();
    //SetMonthlyEndAfterDateRecurrence();
    //SetMonthlyNeverEndRecurrence();
    //YearlyEndAfterDate();
    //SetYearlyNeverEndRecurrence();

    //Working with Outlook Personal Storage (PST) files

    //SplitSinglePSTInToMultiplePST();
    //MergeMultiplePSTsInToSinglePST();
    //MergeFolderFromAnotherPSTFile();
    //ConvertOSTToPST();
    //ExtractNumberOfMessages();
    //ExtractAttachmentsFromPSTMessages();
    //AddMessagesToPSTFiles();
    //ReadandConvertOSTFiles();
    //SaveCalendarItems();
    //RetreiveParentFolderInformationFromMessageInfo();
    //ParseSearchableFolders();
    //AccessContactInformation();
    //GetMessageInformation();
    //ChangeFolderContainerClass();
    //CheckPasswordProtection();
    //SetPasswordOnPST();
    //CreateNewPSTFileAndAddingSubfolders();
    //CreateNewMapiContactAndAddToContactsSubfolder();
    //ExtractMessagesFromPSTFile();
    //RemovingPaswordProperty();
    //AddMapiTaskToPST();
    //CreateNewMapiJournalAndAddToSubfolder();
    //AddAttachmentsToMapiJournal();
    //AddMapiCalendarToPST();
    //CreateDistributionListInPST();
    //SaveMessagesDirectlyFromPSTToStream();
    //SearchStringInPSTWithIgnoreCaseParameter();
    //AddFilesToPST();
    //SearchMessagesAndFoldersInPST();
    //MoveItemsToOtherFolders();
    //AddMapiNoteToPST();
    //UpdatePSTCustomProperites();
    //SaveContactInformation();
    //DisplayInformationOfPSTFile();
    //SpecificCriterionSplitPST();
    //AddMessagesFromOtherPST();
    //DeleteMessagesFromPSTFiles();
    //MergeFolderFromAnotherPSTFile();
    //LoadingPSTFile();
    //ModifyDeleteOccurrenceInRecurrence();



   
    printf("\n\nProgram Finished. Press any key to exit....");
    getchar();
}

System::String GetDataDir_Email()
{
    return System::IO::Path::GetFullPath(GetDataDir_Data() + u"Email/");
}

System::String GetDataDir_Outlook()
{
    return System::IO::Path::GetFullPath(GetDataDir_Data() + u"Outlook/");
}

System::String dataDir = u"../Data/";

System::String GetDataDir_Data()
{
    if (dataDir != nullptr)
    {
        return dataDir;
    }
    
    auto parent = System::IO::Directory::GetParent(System::IO::Directory::GetCurrentDirectory())->get_Parent();
    System::String startDirectory;
    if (parent != nullptr)
    {
        auto directoryInfo = parent->get_Parent();
        if (directoryInfo != nullptr)
        {
            startDirectory = directoryInfo->get_FullName();
        }
    }
    else
    {
        startDirectory = parent->get_FullName();
    }
    return startDirectory != nullptr ? System::IO::Path::Combine(startDirectory, u"Data\\") : nullptr;
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        dataDir = String::FromUtf8(argv[1]);
    }

    try
    {
        RunExamples();
    }
    catch (Exception& e)
    {
        Console::WriteLine(System::String(L"Examples execution error:") + e.ToString());
    }


    return 0;
}
