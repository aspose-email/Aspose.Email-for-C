SET PHP_PATH="C:\soft\Php\php-7.4.18-nts-Win32-vc15-x64\"
set PATH=.;%PHP_PATH%;%PATH%

php -n -e -S localhost:8000 -c AsposeEmailExtension.ini
:php -n -e -c AsposeEmailExtension.ini -r " echo aspose_email_convert('BodyRtfMsg.msg','BodyRtfMsg.html','html');"
:php -n -e -c AsposeEmailExtension.ini -r " echo convert_mail_message_to_html('BodyRtfMsg.msg');"
:php -n -e -c AsposeEmailExtension.ini -r " echo test_aspose_email();"