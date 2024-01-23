#include "database.h"
#include <iostream>

Database::Database() {}

void Database::read(int id) {
    std::unique_lock<std::mutex> lock(mutex_);
    cvReaders_.wait(lock, [this] { return writers_ == 0; });
    ++readers_;
    std::cout << "Reader " << id << " entered. Readers: " << readers_ << ", Writers: " << writers_ << std::endl;
    --readers_;
    std::cout << "Reader " << id << " exited. Readers: " << readers_ << ", Writers: " << writers_ << std::endl;
    if (readers_ == 0) {
        cvWriters_.notify_one();
    }
}

void Database::write(int id) {
    std::unique_lock<std::mutex> lock(mutex_);
    ++writers_;
    cvReaders_.wait(lock, [this] { return readers_ == 0 && !writing_; });
    writing_ = true;
    std::cout << "Writer " << id << " entered" <<std::endl<< "Readers: " << ""<< readers_ << ", Writers: " << writers_ << std::endl;
    --writers_;
    writing_ = false;
    std::cout << "Writer " << id << " exited."<<std::endl<< "Readers: " <<std::endl<< ""<< readers_ << ", Writers: " << writers_ << std::endl;
    cvReaders_.notify_all();
    cvWriters_.notify_one();
}
