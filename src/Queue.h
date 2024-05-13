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
    int size;

public:
    Queue()
    {
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T data)
    {
        list.insertAtEnd(data);
        size++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return NULL;
        }
        T data = list.deleteAtStart();
        size--;
        return data;
    }
};

#endif