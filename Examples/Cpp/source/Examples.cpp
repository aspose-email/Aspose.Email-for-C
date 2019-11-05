#include "Examples.h"

#include <system/aspose_cpp_library.h>
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
#include "Gmail/GoogleTestUser.h"
#include "Exchange_EWS/ExchangeTestUser.h"

using namespace Aspose::Email;
using namespace System;

void LoadLicense(const String& licFile)
{
    SharedPtr<License> license = System::MakeObject<License>();
    license->SetLicense(licFile);
}

void RunExamples()
{
    Console::WriteLine(L"Open Examples.cpp \nIn RunExamples() function uncomment the example that you want to run.");
    Console::WriteLine(L"=====================================================");

    //LoadLicense(u"C:\\project\\License\\Aspose.Email.Cpp.lic");

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


    // IMAP
    //AddingNewMessage();
    //BuildingComplexQueries();
    //CaseSensitiveEmailsFiltering();
    //ConnectingWithIMAPServer();
    //CopyMultipleMessagesFromOneFoldertoAnother();
    //DeleteMultipleMessages();
    //DeleteSingleMessage();
    //DeletingAndRenamingFolders();
    //DeletingFolders();
    //FetchEmailMessagesFromIMAPServer();
    //FilteringMessagesFromIMAPMailbox();
    //GetMessageIdUsingImapMessageInfo();
    //GetMessagesWithSpecificCriteria();
    //GettingFoldersInformation();
    //IMAP4ExtendedListCommand();
    //IMAP4IDExtensionSupport();
    //ImapClientActivityLogging();
    //InsertHeaderAtSpecificLocation();
    //InternalDateFilter();
    //ListingMessagesRecursively();
    //ListingMessagesWithPagingSupport();
    //ListingMIMEMessageIdInImapMessageInfo();
    //ListMessagesAsynchronously();
    //ListMessagesWithMaximumNumberOfMessages();
    //MessagesFromIMAPServerToDisk();
    //MoveMessage();
    //ReadMessagesRecursively();
    //RemovingMessageFlags();
    //RenamingFolders();
    //RetreivingServerExtensions();
    //RetrieveExtraParameters();
    //RetrievingMessagesAsynchronously();
    //SavingMessagesFromIMAPServer();
    //SearchWithPagingSupport();
    //SendIMAPasynchronousEmail();
    //SetCustomFlag();
    //SettingMessageFlags();
    //SpecifyEncodingForQueryBuilder();
    //SSLEnabledIMAPServer();
    //SupportIMAPIdleCommand();

    //// Gmail
    //InsertFetchAndUpdateCalendar();
    //DeleteParticularCalendar();
    //AccessColorInfo();
    //AccessGmailContacts();
    //CreateGmailContact();
    //UpdateGmailContact();
    //DeleteGmailContact();
    //SavingContact();



    // POP3
    //ApplyCaseSensitiveFilters();
    //BuildComplexQueries();
    //CancelDeletes();
    //ConnectingToPOP3();
    //DeleteAllEmails();
    //DeleteEmailByIndex();
    //FilterMessagesFromPOP3Mailbox();
    //GetEmailCountIntheMailbox();
    //GetMessagesUsingSpecificCriteria();
    //GetServerExtensionsUsingPop3Client();
    //GettingMailboxInfo();
    //ListMessagesAsynchronouslyWithMailQuery();
    //ParseMessageAndSave();
    //Pop3ClientActivityLogging();
    //RecipientInformation();
    //RetrieveEmailViaPop3ClientProxyServer();
    //RetrieveMessagesAsynchronously();
    //RetrieveMessageSummaryInformationUsingUniqueId();
    //RetrievingEmailHeaders();
    //RetrievingEmailMessages();
    //SaveToDiskWithoutParsing();
    //SSLEnabledPOP3Server();

    // SMTP
    //CustomizingEmailHeader();
    //CustomizingEmailHeaders();
    //DeliveryNotifications();
    //ForwardEmail();
    //ForwardEmailWithoutUsingMailMessage();
    //ImportEML();
    //LoadingEMLFilesFromDisk();
    //MeetingRequests();
    //MultipleRecipients();
    //RetreiveServerExtensions();
    //SendEmailsSynchronously();
    //SendEmailUsingSMTP();
    //SendEmailWithAlternateText();
    //SendingBulkEmails();
    //SendingEmailWithAlternateText();
    //SendingEMLFilesWithSMTP();
    //SendMessageAsTNEF();
    //SendPlainTextEmailMessage();
    //SetEmailInfo();
    //SettingHTMLBody();
    //SettingTextBody();
    //SMTPClientActivityLogging();
    //SSLEnabledSMTPServer();
    //UseSmtpClientFeatures();

    //Exchange_EWS
    //AccessAnotherMailboxUsingExchangeWebServiceClient();
    //AccessCustomFolderUsingExchangeWebServiceClient();
    //AddContactsToExchangeServerUsingEWS();
    //AddingHeadersToEWSRequests();
    //AddMembersToPrivateDistributionList();
    //AddMembersWithoutListing();
    //CaseSensitiveEmailsFilteringUsingEWS();
    //ConnectingToExchangeServerUsingEWS();
    //CopyConversations();
    //CopyingMessageToAnotherFolder();
    //CreateAndSendingMessageWithVotingOptions();
    //CreateFoldersOnExchangeServerMailbox();
    //CreateNewRuleOntheExchangeServer();
    //CreatePrivateDistributionList();
    //CreateREAndFWMessages();
    //CreatUserConfigurations();
    //DeleteContactsFromExchangeServerUsingEWS();
    //DeleteConversations();
    //DeleteExchangeTask();
    //DeleteMembersFromPrivateDistributionList();
    //DeleteMembersWithoutListing();
    //DeleteMessagesFromusingEWS();
    //DeletePrivateDistributionList();
    //DeleteTaskOnExchange();
    //DeleteUserConfiguration();
    //DeleteWithoutListing();
    //DownloadMessagesFromPublicFolders();
    //EnumeratMessagesWithPaginginEWS();
    //ExchangeFoldersBackupToPST();
    //ExchangeServerReadRules();
    //ExpandPublicDistributionList();
    //FetchContactUsingId();
    //FetchMessageUsingEWS();
    //FetchPrivateDistributionList();
    //FilterAppointmentsUsingEWS();
    //FilterMessagesOnCriteriaUsingEWS();
    //FilterMessagesUsingEWS();
    //FilterWithComplexQueriesUsingEWS();
    //FindConversationsOnExchangeServer();
    //GetExchangeMessageInfoFromMessageURI();
    //GetFolderTypeInformationUsingEWS();
    //GetMailboxInformationFromExchangeWebServices();
    //GetMailTips();
    //GetMessageTypeFromExchangeMessageInfo();
    //GettingContactsUsingEWS();
    //GettingUnifiedMessagingConfigurationInformation();
    //IgnoringInvalidSSLCertificates();
    //ListFoldersFromExchangeServer();
    //ListingMessagesFromFolders();
    //ListingMessagesUsingEWS();
    //MoveConversations();
    //MoveMessageFromOneFolderToAnotherusingEWS();
    //PagingSupportForListingFolders();
    //PagingSupportForListingMessages();
    //PreFetchMessageSizeUsingIEWSClient();
    //ProcessExchangeTasksUsingIEWSClient();
    //ReadUserConfiguration();
    //ResolveContactsUsingContactName();
    //RetrieveFolderPermissionsUsingExchangeWebServiceClient();
    //SaveExchangeTaskToDisc();
    //SaveMessagesInMSGFormatExchangeEWS();
    //SaveMessagesToMemoryStreamUsingEWS();
    //SaveMessagesUsingExchangeWebServices();
    //SecondaryCalendarEvents();
    //SendCalendarInvitation();
    //SendEmailMessagesUsingExchangeWebServices();
    //SendEmailToPrivateDistributionList();
    //SendExchangeTask();
    //SendMeetingRequestsUsingEWS();
    //SendTaskRequestUsingIEWSClient();
    //SynchronizeFolderItems();
    //UpdateContactInformationUsingEWS();
    //UpdateRuleOntheExchangeServer();
    //UpdateUserConfiguration();

    printf("\n\nProgram Finished. Press any key to exit....");
    getchar();
}

GoogleTestUser GetGoogleTestUser()
{

    return GoogleTestUser(
        u"test_user",
        u"test_user@gmail.com",
        u"*********",
        u"test_client_id.apps.googleusercontent.com",
        u"test_client_secret",
        u"test_refresh_token");
}

ExchangeTestUser GetExchangeTestUser()
{

    return ExchangeTestUser(
        u"https://your.exchange.server/ews/Exchange.asmx",
        u"username",
        u"password");
}


System::String GetDataDir_Gmail()
{
    return System::IO::Path::GetFullPath(GetDataDir_Data() + u"Gmail/");
}

System::String GetDataDir_POP3()
{
    return System::IO::Path::GetFullPath(GetDataDir_Data() + u"POP3/");
}

System::String GetDataDir_IMAP()
{
    return System::IO::Path::GetFullPath(GetDataDir_Data() + u"IMAP/");
}

System::String GetDataDir_SMTP()
{
    return System::IO::Path::GetFullPath(GetDataDir_Data() + u"SMTP/");
}

System::String GetDataDir_Email()
{
    return System::IO::Path::GetFullPath(GetDataDir_Data() + u"Email/");
}

System::String GetDataDir_Outlook()
{
    return System::IO::Path::GetFullPath(GetDataDir_Data() + u"Outlook/");
}

System::String GetDataDir_Exchange()
{
    return System::IO::Path::GetFullPath(GetDataDir_Data() + u"Exchange/");
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


    System::AsposeCppLibrary::PrepareForUnload();

    return 0;
}
