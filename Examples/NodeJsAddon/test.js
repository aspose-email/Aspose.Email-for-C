// Импортируем модуль, созданный с помощью N-API
const mailConverter = require('./build/Release/mail_converter');

function testConvertMailMessageToHtml() {
    try {
        const fileName = 'message.msg';
        const result = mailConverter.convertMailMessageToHtml(fileName);
        console.log('HTML Content:', result);
    } catch (error) {
        console.error('Error in convertMailMessageToHtml:', error.message);
    }
}

function testConvertMailMessageFile() {
    try {
        const fileName = 'message.eml';
        const outputFileName = 'output.html';
        const outputType = 'html'; // Тип вывода (например, HTML или другой формат)
        const result = mailConverter.convertMailMessageFile(fileName, outputFileName, outputType);
        console.log(`File converted successfully! Output: ${result}`);
    } catch (error) {
        console.error('Error in convertMailMessageFile:', error.message);
    }
}

function testLoadLicense() {
    try {
        const licenseFileName = 'license.key';
        const result = mailConverter.loadLicense(licenseFileName);
        console.log('License Loaded:', result);
    } catch (error) {
        console.error('Error in loadLicense:', error.message);
    }
}

// Запускаем тестовые функции
console.log('Testing convertMailMessageToHtml...');
testConvertMailMessageToHtml();

console.log('\nTesting convertMailMessageFile...');
testConvertMailMessageFile();

console.log('\nTesting loadLicense...');
testLoadLicense();
