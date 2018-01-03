#include "threadedjournal.h"
#include <QMutexLocker>


ThreadedJournal::ThreadedJournal(QObject *parent):
    Journal(parent),
    m_mutex()
{}

void ThreadedJournal::addEntry(int number)
{
    QMutexLocker lock(&m_mutex);

    Journal::addEntry(number);
}
