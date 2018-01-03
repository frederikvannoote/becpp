#include "threadedjournal.h"


ThreadedJournal::ThreadedJournal(QObject *parent):
    Journal(parent),
    m_mutex()
{}

void ThreadedJournal::addEntry(int number)
{
    m_mutex.lock();
    Journal::addEntry(number);
    m_mutex.unlock();
}
