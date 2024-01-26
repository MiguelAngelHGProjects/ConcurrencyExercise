#ifndef WRITER_H
#define WRITER_H

#include <QThread>
#include "database.h"

class Writer : public QThread {
public:
    Writer(int id, Database& db);

protected:
    void run() override;

private:
    int id_;
    Database& db_;
};

#endif // WRITER_H
