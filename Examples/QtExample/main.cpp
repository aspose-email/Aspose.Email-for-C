
#include <QtWidgets>
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;

    QLabel *label1 = new QLabel("Email converter for Email files & archives");
    label1->setStyleSheet("QLabel{font-size: 30px;font-family: Arial;color: white;background-color: blue;}");

    QLabel *label2 = new QLabel("Convert email & messages archives to EML, MSG, HTML, PST, MBOX, JPEG, PNG, SVG, BMP, TIFF and MHT files");
    label2->setStyleSheet("QLabel{font-size: 20px;font-family: Arial;color: white;background-color: blue;}");

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addWidget(label1, Qt::AlignCenter);
    vlayout->addWidget(label2, Qt::AlignCenter);

    QLabel *label = new QLabel("Your file:");
    QLineEdit *lineEdit = new QLineEdit();

    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addWidget(label);
    hlayout->addWidget(lineEdit);
    vlayout->addLayout(hlayout);
    
    QStringList emailTypes = { "Arial", "Helvetica", "Times" };
    QComboBox *combo = new QComboBox();
    combo->addItems(emailTypes);
    QPushButton *button = new QPushButton("Convert!");
    QHBoxLayout *hlayout2 = new QHBoxLayout();
    hlayout2->addWidget(combo);
    hlayout2->addWidget(button);
    vlayout->addLayout(hlayout2);


    window.setLayout(vlayout);
    window.setWindowTitle(
        QApplication::translate("windowlayout", "Window layout"));
    window.show();
    return app.exec();
}
