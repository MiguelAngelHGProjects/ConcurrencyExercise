#ifndef DATABASE_H
#define DATABASE_H

#include <QSemaphore>

class Database {
public:
    Database();

    void read(int id);
    void write(int id);

private:
    QSemaphore freeReaders_;
    QSemaphore freeWriters_;
    QSemaphore mutex_;
    QSemaphore waitingReaders_;
    QSemaphore waitingWriters_;
    int readers_;
    int writers_;
};

#endif // DATABASE_H
