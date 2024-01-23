#ifndef DATABASE_H
#define DATABASE_H

#include <mutex>
#include <condition_variable>

class Database {
public:
    Database();

    void read(int id);
    void write(int id);

private:
    std::mutex mutex_;
    std::condition_variable cvReaders_;
    std::condition_variable cvWriters_;
    int readers_ = 0;
    int writers_ = 0;
    bool writing_ = false;
};

#endif // DATABASE_H
