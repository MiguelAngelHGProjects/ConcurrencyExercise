#include "reader.h"
#include <unistd.h>

Reader::Reader(int id, Database& db)
    : id_(id), db_(db)
{}

void Reader::run() {
    for (int i = 0; i < 5; ++i) {
        db_.read(id_);
        sleep(1);
    }
}
