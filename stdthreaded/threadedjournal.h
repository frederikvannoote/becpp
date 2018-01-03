#pragma once

#include "journal.h"
#include <mutex>


class ThreadedJournal : public Journal
{
    Q_OBJECT
public:
    explicit ThreadedJournal(QObject *parent = nullptr);

    virtual void addEntry(int number) override;

private:
    std::mutex m_mutex;
};
