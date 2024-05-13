#ifndef LINKEDLIST_CLASS
#define LINKEDLIST_CLASS

#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node *prev;

    Node(T data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <class T>
class LinkedList
{
protected:
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(T data)
    {
        Node<T> *newNode = new Node<T>(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtStart(T data)
    {
        Node<T> *newNode = new Node<T>(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    T deleteAtStart()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return NULL;
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;
            head->prev = nullptr;
            T data = temp->data;
            delete temp;
            return data;
        }
    }

    T deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return NULL;
        }
        else
        {
            Node<T> *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            T data = temp->data;
            delete temp;
            return data;
        }
    }

    virtual void sort();

    ~LinkedList()
    {
        // delete all nodes to avoid memory leak
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

#endif