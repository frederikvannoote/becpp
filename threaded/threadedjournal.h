#pragma once

#include "journal.h"
#include <QBasicMutex>


class ThreadedJournal : public Journal
{
    Q_OBJECT
public:
    explicit ThreadedJournal(QObject *parent = nullptr);

    virtual void addEntry(int number) override;

private:
    QBasicMutex m_mutex;
};
