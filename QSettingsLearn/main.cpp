#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationName("GrokkingCloud");
    QCoreApplication::setOrganizationDomain("vamsi7894.hashnode.dev");
    QCoreApplication::setApplicationName("LearningQSettings");

    QSettings settings(QCoreApplication::organizationName(),QCoreApplication::applicationName());
    if(settings.contains("name"))
    {
        qInfo() << "Hello" << settings.value("name").toString();
        settings.sync();
    }
    else
    {
        QTextStream qin(stdin);
        qInfo() << "Enter your name: ";
        QString name = qin.readLine();
        settings.setValue("name",name);
        qInfo() << "Close this application and re-open it";
    }

    return a.exec();
}
