#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

#include <iostream>
#include <LinkedList.h>
using namespace std;

template <class T>
class Queue
{
private:
    LinkedList<T> list;
    int _size;

public:
    Queue()
    {
        _size = 0;
    }

    bool isEmpty()
    {
        return size() == 0;
    }

    int size()
    {
        return _size;
    }

    T front()
    {
        return list->head->data;
    }

    T rear()
    {
        return list->tail->data;
    }

    void enqueue(T data)
    {
        list.insertAtEnd(data);
        _size++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return NULL;
        }
        T data = list.deleteAtStart();
        _size--;
        return data;
    }
};

#endif
