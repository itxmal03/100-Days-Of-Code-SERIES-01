#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // 1. Insert at the beginning
    void insertAtHead(int val)
    {
        Node *n = new Node(val);
        if (head == nullptr)
        { // empty list
            head = tail = n;
            return;
        }
        n->next = head; // new node points forward to old head
        head->prev = n; // old head points back to new node
        head = n;       // head moves to new node
    }

    // 2. Insert at the end
    void insertAtTail(int val)
    {
        Node *n = new Node(val);
        if (tail == nullptr)
        { // empty list
            head = tail = n;
            return;
        }
        n->prev = tail; // new node points back to old tail
        tail->next = n; // old tail points forward to new node
        tail = n;       // tail moves to new node
    }

    // 3. Delete a node by value
    void deleteValue(int val)
    {
        Node *temp = head;
        while (temp != nullptr && temp->data != val)
            temp = temp->next;

        if (temp == nullptr)
        { // not found
            cout << val << " not found\n";
            return;
        }

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; // deleting the first node

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; // deleting the last node

        delete temp;
    }

    // 4. Display forward
    void displayForward()
    {
        for (Node *t = head; t != nullptr; t = t->next)
            cout << t->data << " <-> ";
        cout << "NULL\n";
    }

    // 5. Display backward
    void displayBackward()
    {
        for (Node *t = tail; t != nullptr; t = t->prev)
            cout << t->data << " <-> ";
        cout << "NULL\n";
    }

    ~DoublyLinkedList()
    {
        while (head != nullptr)
        {
            Node *t = head;
            head = head->next;
            delete t;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtHead(10);

    list.displayForward();  // 10 <-> 20 <-> 30 <-> NULL
    list.displayBackward(); // 30 <-> 20 <-> 10 <-> NULL

    list.deleteValue(20);
    list.displayForward(); // 10 <-> 30 <-> NULL
}