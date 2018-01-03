#include <QCoreApplication>
#include <QDebug>
#include "prime.h"
#include "journal.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Journal journal;

    Prime prime(journal);
    prime.setObjectName("Prime 0");
    prime.start();

    qDebug() << "Got" << journal.count() << "entries.";

    return 0;
}
