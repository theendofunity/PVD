#ifndef IDISTRIBUTOR_H
#define IDISTRIBUTOR_H

#include <memory>
#include <QList>

#endif // IDISTRIBUTOR_H

template<class T>
class IDistributor
{
public:
    IDistributor();

    void addConsumer(T* consumer)
    {
        consumers.push_back(consumer);
    }

    template<class Message>
    void notifyConsumers(std::shared_ptr<Message>& message)
    {
        for (auto &item : consumers)
        {
            item.handle(message);
        }
    }

private:
    QList <T*> consumers;
};
