#include "journal.h"

Journal::Journal(QObject *parent):
    QObject(parent),
    m_entries()
{
}

void Journal::addEntry(int number)
{
    m_entries << number;
}

int Journal::count() const
{
    return m_entries.count();
}
