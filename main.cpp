#include <QCoreApplication>
#include "database.h"
#include "reader.h"
#include "writer.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Database db;

    Reader readers[2] = {Reader(0, db), Reader(1, db)};
    Writer writers[2] = {Writer(0, db), Writer(1, db)};

    for (int i = 0; i < 2; ++i) {
        readers[i].start();
    }

    for (int i = 0; i < 2; ++i) {
        writers[i].start();
    }

    for (int i = 0; i < 2; ++i) {
        readers[i].wait();
    }

    for (int i = 0; i < 2; ++i) {
        writers[i].wait();
    }

    return 0;
}
