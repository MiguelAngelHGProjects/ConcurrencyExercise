#include "database.h"
#include "reader.h"
#include "writer.h"
#include <QCoreApplication>
#include <QThread>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Database db;

    QThread readerThread[3];
    QThread writerThread[2];

    Reader readers[3] = {Reader(db, 0), Reader(db, 1), Reader(db, 2)};
    Writer writers[2] = {Writer(db, 0), Writer(db, 1)};

    for (int i = 0; i < 3; ++i) {
        readers[i].moveToThread(&readerThread[i]);
        QObject::connect(&readerThread[i], &QThread::started, &readers[i], &Reader::run);
        readerThread[i].start();
    }

    for (int i = 0; i < 3; ++i) {
        readerThread[i].wait();
    }

    for (int i = 0; i < 2; ++i) {
        writers[i].moveToThread(&writerThread[i]);
        QObject::connect(&writerThread[i], &QThread::started, &writers[i], &Writer::run);
        writerThread[i].start();
    }


    for (int i = 0; i < 2; ++i) {
        writerThread[i].wait();
    }

    return a.exec();
}
