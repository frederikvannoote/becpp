#include "threadedprime.h"
#include <QDebug>


ThreadedPrime::ThreadedPrime(Journal &journal, QObject *parent):
    QThread(parent),
    m_prime(journal)
{
}

ThreadedPrime::~ThreadedPrime()
{
    stop();
}

void ThreadedPrime::stop()
{
    if (isRunning())
    {
        wait();
    }
}

void ThreadedPrime::run()
{
    m_prime.setObjectName(objectName());
    m_prime.start();
}
