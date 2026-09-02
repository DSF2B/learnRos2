#include <QApplication>
#include <QLabel>
#include <QString>

int main(int argc,char** argv)
{
   QApplication app(argc,argv);
   QLabel* label = new QLabel();
   QString string = QString::fromStdString("hello qt");
   label->setText(string);
   label->show();
   app.exec();
   return 0;
}