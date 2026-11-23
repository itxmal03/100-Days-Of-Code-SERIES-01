#include <iostream>
using namespace std;

class Node
{

private:
    int data{0};
    Node *next{nullptr};

public:
    Node() = default;

    Node(int data)
    {
        setData(data);
        this->next = nullptr;
    }

    void setData(int data)
    {
        this->data = data;
    }

    int getData()
    {

        return this->data;
    }

    Node *getNext()
    {
        return this->next;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }

    void print()
    {
        cout << "Address of Current Node: " << this;

        cout << "\tData: " << this->data;

        cout << "\tAddress of Next Node: " << this->next << endl;
    }
};


class CircularLinkedList
{
private:
    Node *head{nullptr};
    Node *tail{nullptr};
    int size{0};

public:
    CircularLinkedList() = default;

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insertAtHead(int val)
    {

        Node *newNode = new Node(val);

        // Case 0 : Linked List is empty
        if (isEmpty())
        {
            head = tail = newNode;
            tail->setNext(head);
            size++;
        }

        // Case 1 : Linked List is not empty
        else
        {

            newNode->setNext(head);
            head = newNode;
            tail->setNext(head);
            size++;
        }
    }

    void insertAtTail(int val)
    {

        Node *newNode = new Node(val);

        if (isEmpty())
        {
            head = tail = newNode;
            tail->setNext(head);
            size++;
        }
        else
        {

            tail->setNext(newNode);
            newNode->setNext(head);
            tail = newNode;
            size++;
        }
    }

    void display()
    {

        // we are handling empty list case specially because here we are using do while for printing, so if we don't handle the empty list case here, then it'll create mess when trying to read data from a null pointer in do while loop iteration over empty list.

        if (isEmpty())
        {
            cout << "[ ]" << endl;
            return;
        }

        cout << "[ ";

        Node *temp = head;

        do
        {
            cout << temp->getData() << " " << " ";
            temp = temp->getNext();
        } while (temp != head);

        cout << " ]";
        cout << endl;
    }

    void deleteAtHead()
    {
        if (isEmpty())
        {
            cout << "List is empty \n";
        }
        else if (head == tail)
        {

            delete head;
            head = tail = nullptr;
            size--;
        }
        else
        {
            Node *temp = head;
            tail->setNext(temp->getNext());
            head = tail->getNext();
            delete temp;
            // temp = nullptr ;
            size--;
        }
    }

    void deleteAtTail()
    {
        if (isEmpty())
        {
            cout << "List is empty \n";
        }
        else if (head == tail)
        {

            delete head;
            head = tail = nullptr;
            size--;
        }
        else
        {

            Node *temp = head;
            while (temp->getNext() != tail)
            {

                temp = temp->getNext();
            }

            temp->setNext(head);
            tail->setNext(nullptr);
            delete tail;
            tail = temp;
            temp = nullptr;
            size--;
        }
    }

    void clear()
    {

        while (!isEmpty())
        {
            deleteAtHead();
        }
    }

    ~CircularLinkedList()
    {

        clear();
    }

    void remove(int val)
    {

        if (isEmpty())
        {
            cout << " List is empty \n";
        }

        else
        {

            Node *prev = nullptr;
            Node *temp = head;

            while (temp != tail && temp->getData() != val)
            {
                prev = temp;
                temp = temp->getNext();
            }

            if (temp == tail && temp->getData() == val)
            {
                deleteAtTail();
                return;
            }
            if (temp == head && temp->getData() == val)
            {
                deleteAtHead();
                return;
            }

            if (temp->getData() == val)
            {

                prev->setNext(temp->getNext());
                delete temp;
                temp = nullptr;
                size--;
            }
        }
    }
};


int main()
{

    CircularLinkedList c1;

    c1.insertAtHead(5);
    c1.insertAtHead(3);
    c1.insertAtTail(7);
    c1.insertAtTail(8);
    c1.display();
    c1.deleteAtHead();
    c1.display();
    c1.insertAtHead(2);
    c1.display();
    c1.deleteAtTail();
    c1.display();
    // c1.clear(); // it'll clear thi list before destructor being called even

    c1.display(); // now list will be empty

    c1.insertAtHead(12); // we can again use the same list since its not destroyed yet but it was only cleared
    c1.display();

    c1.remove(5);
    c1.display();
    return 0;
}