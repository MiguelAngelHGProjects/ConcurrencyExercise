#define WRITER_H

#include "database.h"
#include <QObject>

class Writer : public QObject {
    Q_OBJECT

public:
    Writer(Database& db, int id);

public slots:
    void run();

private:
    Database& db_;
    int id_;
};
