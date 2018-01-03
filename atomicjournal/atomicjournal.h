#pragma once

#include "journal.h"
#include <QAtomicInt>


class AtomicJournal: public Journal
{
    Q_OBJECT
    Q_DISABLE_COPY(AtomicJournal)

public:
    AtomicJournal(QObject *parent = nullptr);

    virtual void addEntry(int number) override;

    virtual int count() const override;

private:
    QAtomicInt m_count;
};
