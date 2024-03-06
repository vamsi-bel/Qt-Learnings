#include <QCoreApplication>
#include <QStorageInfo>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStorageInfo root = QStorageInfo::root();
    qInfo() << "Root:" << root.rootPath();
    QDir dir(root.rootPath());
    foreach(QFileInfo fi, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        qInfo() << fi.filePath();
    }

    qInfo() << "\n-------------\n";
    foreach(QStorageInfo storage, QStorageInfo::mountedVolumes())
    {
        qInfo() << "Name:" << storage.displayName();
        qInfo() << "Type:" << storage.fileSystemType();
        qInfo() << "Total:" << storage.bytesTotal()/1024/1024 << "MB";
        qInfo() << "Available:" << storage.bytesAvailable()/1024/1024 << "MB";
        qInfo() << "Device:" << storage.device();
        qInfo() << "Root:" << storage.isRoot();
        qInfo() << "\n";
    }


    return a.exec();
}
