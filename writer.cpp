#include "writer.h"
#include <unistd.h>

Writer::Writer(int id, Database& db)
    : id_(id), db_(db)
{}

void Writer::run() {
    for (int i = 0; i < 5; ++i) {
        db_.write(id_);
        sleep(1);
    }
}
