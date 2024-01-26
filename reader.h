#ifndef READER_H
#define READER_H

#include <QThread>
#include "database.h"

class Reader : public QThread {
public:
    Reader(int id, Database& db);

protected:
    void run() override;

private:
    int id_;
    Database& db_;
};

#endif // READER_H
