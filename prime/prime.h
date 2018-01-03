#pragma once

#include <QObject>
class Journal;


class Prime: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Prime)

public:
    explicit Prime(Journal &journal, QObject *parent = nullptr);

public Q_SLOTS:
    void start();

private:
    bool isPrime(int number) const;

private:
    Journal &m_journal;
};
