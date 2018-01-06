#include <QCoreApplication>
#include <QThread>
#include <QList>
#include <QSharedPointer>
#include <QTimer>
#include <QDebug>
#include "threadedprime.h"
#include "atomicjournal.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AtomicJournal journal;

    QList<QSharedPointer<ThreadedPrime>> primes;
    for (int i=0; i<4; i++)
    {
        QSharedPointer<ThreadedPrime> t(new ThreadedPrime(journal));
        t->setObjectName("Prime " + QString::number(i));
        primes << t;

        t->start();

        QTimer::singleShot(30000, t.data(), &ThreadedPrime::stop);
    }
    QTimer::singleShot(30000, &a, &QCoreApplication::quit);

    a.exec();
    qDebug() << "Got" << journal.count() / primes.count() << "entries per calculator.";

    return 0;
}

