#include <QCoreApplication>
#include <QThread>
#include <QList>
#include <QSharedPointer>
#include <QTimer>
#include <QDebug>
#include "threadedprime.h"
#include "threadedjournal.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for (int i=0; i<10; i++)
    {
        ThreadedJournal journal;

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
    }
    return 0;
}
