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
private:
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

    void deleteAtStart()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node<T> *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

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