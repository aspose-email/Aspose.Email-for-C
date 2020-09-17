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

std::string ConvertMailMessageToHtml(const std::string& fileName);

QWidget* ConvertFormatWidget()
{
    QHBoxLayout *hLayout = new QHBoxLayout;
    QLabel *label = new QLabel("Save As");
    QComboBox *formatCombo = new QComboBox();

    formatCombo->addItems({
        "EML",
        "MSG",
        "MBOX",
        "OST",
        "PST"
        });

/*
eml
msg
mbox
pst
mht
html
svg
tiff
jpg
bmp
png
pdf
doc
ppt
rtf
docx
docm
dotx
dotm
odt
ott
epub
txt
emf
xps
pcl
ps
mhtml
*/

    QPushButton *loadButton = new QPushButton("Convert");

    hLayout->addWidget(label);
    hLayout->addWidget(formatCombo);
    hLayout->addWidget(loadButton);

    QWidget* widget = new QWidget();

    widget->setLayout(hLayout);
    return widget;
}

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
    tabWidget->addTab(ConvertFormatWidget(), "Convert");

    //vLayout->addWidget(tb);
    vLayout->addWidget(tabWidget);

    ui->setLayout(vLayout);
    ui->setWindowTitle("Aspose.Email for C++ sample Qt application");
    ui->show();

    return a.exec();
}
