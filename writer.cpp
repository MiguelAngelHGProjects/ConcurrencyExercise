#include "writer.h"
#include <iostream>
#include <chrono>
#include <thread>

Writer::Writer(Database& db, int id) : db_(db), id_(id) {}

void Writer::run() {
    for (int i = 0; i < 5; ++i) {
        db_.write(id_);
        std::cout << "Writer " << id_ << " is writing..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
