#include "atomicjournal.h"

AtomicJournal::AtomicJournal(QObject *parent):
    Journal(parent),
    m_count(0)
{
}

void AtomicJournal::addEntry(int number)
{
    Q_UNUSED(number);

    m_count.fetchAndAddOrdered(1);
}

int AtomicJournal::count() const
{
    return m_count.load();
}
