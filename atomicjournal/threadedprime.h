#pragma once

#include <QThread>
#include "prime.h"


class ThreadedPrime : public QThread
{
    Q_OBJECT
    Q_DISABLE_COPY(ThreadedPrime)

public:
    explicit ThreadedPrime(Journal &journal, QObject *parent = nullptr);
    virtual ~ThreadedPrime();

public Q_SLOTS:
    void stop();

protected:
    virtual void run() override;

private:
    Prime m_prime;
};
