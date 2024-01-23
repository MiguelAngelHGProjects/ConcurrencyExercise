#include "reader.h"
#include <iostream>
#include <chrono>
#include <thread>

Reader::Reader(Database& db, int id) : db_(db), id_(id) {}

void Reader::run() {
    for (int i = 0; i < 5; ++i) {
        db_.read(id_);
        std::cout << "Reader " << id_ << " is reading..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
