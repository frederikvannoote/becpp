#include "prime.h"
#include "journal.h"
#include <QTime>
#include <QDebug>


Prime::Prime(Journal &journal, QObject *parent):
    QObject(parent),
    m_journal(journal)
{
}

void Prime::start()
{
    QTime t;
    t.start();

    for (int current = 2; current<1000000000 && t.elapsed() < 30000; ++current)
    {
        if (isPrime(current))
        {
//            qDebug() << objectName() << ":" << current << "is a prime number.";
            m_journal.addEntry(current);
        }
    }
}

bool Prime::isPrime(int number) const
{
    int i = 0;
    for (i = number-1; i>1; i--)
    {
        if (number % i == 0)
        {
            break;
        }
    }

    return i == 1;
}
