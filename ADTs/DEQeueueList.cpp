#include "DEQeueueList.h"


DEQueueList::DEQueueList():count(0)
{
}

DEQueueList::~DEQueueList()
{
    unit* u;
    while (removeEnd(u))
    {
        delete u;
        u = nullptr;
    }
}

int DEQueueList::getCount()
{
    return count;
}

bool DEQueueList::removeEnd(unit*& pickedUnit)
{
    if (dequeueBack(pickedUnit))
    {
        count--;
        return true;
    }
    return false;
}

bool DEQueueList::removeFront(unit*& pickedUnit)
{
    if (dequeue(pickedUnit))
    {
        count--;
        return true;
    }
    return false;
}

bool DEQueueList::insertEnd(unit* addedUnit)
{
    count++;
    return enqueue(addedUnit);
}

bool DEQueueList::insertFront(unit* addedUnit)
{
    count++;
    return enqueue(addedUnit);
}

bool DEQueueList::backPeek(unit*& peekedUnit)
{
    return peekBack(peekedUnit);
}

bool DEQueueList::frontPeek(unit*& peekedUnit)
{
    return peekFront(peekedUnit);
}

void DEQueueList::print()
{
    Node<unit*>* nextUnit=frontPtr;
    cout << " " << getCount() << " AD [";
    while (nextUnit)
    {
        cout << nextUnit->getItem()->get_id();
        if (nextUnit->getNext())
            cout << ", ";
        nextUnit = nextUnit->getNext();
    }
    cout << "]" << endl;
    cout << "_____________________________________________________\n";
}
