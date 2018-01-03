#pragma once

#include <QObject>

class Journal : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Journal)

public:
    explicit Journal(QObject *parent = nullptr);

    virtual void addEntry(int number);

    virtual int count() const;

private:
    QList<int> m_entries;
};
