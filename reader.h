#define READER_H

#include "database.h"
#include <QObject>

class Reader : public QObject {
    Q_OBJECT

public:
    Reader(Database& db, int id);

public slots:
    void run();

private:
    Database& db_;
    int id_;
};
