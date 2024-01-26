#include "database.h"
#include <iostream>

Database::Database()
    : freeReaders_(1), freeWriters_(1), mutex_(1), waitingReaders_(0), waitingWriters_(0), readers_(0), writers_(0)
{}

void Database::read(int id) {
    mutex_.acquire();
    if (writers_ > 0) {
        waitingReaders_.release();
        mutex_.release();
        waitingReaders_.acquire();
    }
    readers_++;
    if (waitingReaders_.available() > 0) {
        waitingReaders_.acquire(waitingReaders_.available());
    }
    mutex_.release();

    std::cout << "Reader " << id << " is reading. Readers: " << readers_ << ", Writers: " << writers_ << ", Waiting Readers: " << waitingReaders_.available() << ", Waiting Writers: " << waitingWriters_.available() << std::endl;

    mutex_.acquire();
    readers_--;
    if (readers_ == 0 && waitingWriters_.available() > 0) {
        waitingWriters_.acquire(waitingWriters_.available());
    }
    mutex_.release();
}

void Database::write(int id) {
    mutex_.acquire();
    if (readers_ > 0 || writers_ > 0) {
        waitingWriters_.release();
        mutex_.release();
        waitingWriters_.acquire();
    }
    writers_++;
    mutex_.release();

    std::cout << "Writer " << id << " is writing. Readers: " << readers_ << ", Writers: " << writers_ << ", Waiting Readers: " << waitingReaders_.available() << ", Waiting Writers: " << waitingWriters_.available() << std::endl;

    mutex_.acquire();
    writers_--;
    if (waitingWriters_.available() > 0) {
        waitingWriters_.acquire(waitingWriters_.available());
    } else if (waitingReaders_.available() > 0) {
        waitingReaders_.acquire(waitingReaders_.available());
    }
    mutex_.release();
}
