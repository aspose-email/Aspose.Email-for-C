#define USE_ASPOSE_WORDS

#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTextBrowser>
#include <QFileDialog>
#include <QLabel>
#include <QTabWidget>
#include <QComboBox>
#include <QFileInfo>
#include <QMessageBox>

std::string ConvertMailMessageToHtml(const std::string& fileName);
void Convert(const std::string& fileName, const std::string& outputFileName, const std::string& outputType);
void SetLicense();


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextBrowser *tb = new QTextBrowser();
    tb->setOpenExternalLinks(false);
    tb->setReadOnly(true);

    QWidget *ui = new QWidget();

    QVBoxLayout *vboxLayout = new QVBoxLayout();
    QLabel *label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    vboxLayout->addWidget(label);
    label->setText("Upload MSG, PST, OST, MBOX or EML files to view the contents.");
    label->setStyleSheet(QString::fromUtf8("font: 16pt; font-weight: 600; color: blue;"));

    QHBoxLayout *hLayout = new QHBoxLayout;
    QLineEdit *txtFileName = new QLineEdit();
    QPushButton *loadButton = new QPushButton("...");
    QObject::connect(loadButton, &QPushButton::clicked, [txtFileName]() {
        txtFileName->setText(QFileDialog::getOpenFileName());
    });
    QPushButton *showButton = new QPushButton("Show");
    QObject::connect(showButton, &QPushButton::clicked, [txtFileName, tb]() {
        QString html = QString::fromStdString(ConvertMailMessageToHtml(txtFileName->text().toStdString()));
        tb->setHtml(html);
    });

    hLayout->addWidget(txtFileName);
    hLayout->addWidget(loadButton);
    hLayout->addWidget(showButton);

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addLayout(vboxLayout);
    vLayout->addLayout(hLayout);

    QTabWidget *tabWidget = new QTabWidget();
    tabWidget->addTab(tb, "View");

    // create widget for "Convert" tab
    QComboBox *formatCombo = new QComboBox();
    formatCombo->addItems({
        "EML",
        "MSG",
        "MBOX",
        "PST",
        "MHT",
        "HTML",
        "RTF",
        "TXT",
#ifdef USE_ASPOSE_WORDS
        "PDF",
#endif
        });
    QPushButton *convertButton = new QPushButton("Convert");
    QObject::connect(convertButton, &QPushButton::clicked, [txtFileName, formatCombo]() {
        QString fileName = txtFileName->text();
        QString outputType = formatCombo->currentText();
        QFileInfo info(fileName);
        QString outputFile = info.path() + "/" + info.completeBaseName() + "." + outputType;
        if (outputFile == fileName)
            return;
        outputFile = QFileDialog::getSaveFileName(nullptr, "Select converted file name", outputFile);
        Convert(txtFileName->text().toStdString(), outputFile.toStdString(), outputType.toLower().toStdString());
        QMessageBox::information(nullptr, "Information", QString("File %1 Converted into %2").arg(fileName, outputFile));
        });
    QHBoxLayout *hConvertLayout = new QHBoxLayout;

    hConvertLayout->addWidget(new QLabel("Save As"));
    hConvertLayout->addWidget(formatCombo);
    hConvertLayout->addWidget(convertButton);

    QWidget* convertWidget = new QWidget();
    convertWidget->setLayout(hConvertLayout);
    
    tabWidget->addTab(convertWidget, "Convert");

    vLayout->addWidget(tabWidget);

    ui->setLayout(vLayout);
    ui->setWindowTitle("Aspose.Email for C++ sample Qt application");
    ui->show();

    SetLicense();

    return a.exec();
}
