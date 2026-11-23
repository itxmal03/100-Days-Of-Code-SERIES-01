#include <iostream>

using namespace std;

class QueueArray
{

private:
    int capacity;
    int rear;
    int front;
    int size;
    int *data;

public:
    QueueArray(int capacity = 6)
    {
        rear = front = -1;
        size = 0;
        this->capacity = capacity;
        data = new int[this->capacity];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void Enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is already full \n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }

        data[rear] = val;
        size++;
    }

    int Dequeue()
    {
        int item = 0;

        if (isEmpty())
        {

            cout << "Queue is already empty \n";
            return -1;
        }

        item = data[front];

        front = (front + 1) % capacity;

        size--;

        if (size == 0)
        {
            front = rear = -1;
        }

        return item;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue Empty \n";
            return;
        }
        cout << "[ ";
        for (int i = 0; i < size; i++)
        {

            int index = (front + i) % capacity;
            cout << data[index] << ", ";
        }

        cout << " ]";
        cout << endl;
        cout << "Size: " << size << endl;
    }
    ~QueueArray()
    {
        if (data != nullptr)
        {
            delete[] data;
            data = nullptr;
        }
    }
};

int main()
{

    QueueArray q1;
    q1.Enqueue(11);
    q1.display();
    q1.Enqueue(15);
    q1.display();
    q1.Enqueue(19);
    q1.display();
    q1.Enqueue(17);
    q1.display();
    q1.Dequeue();
    q1.display();
    q1.Enqueue(11);
    q1.display();
    q1.Enqueue(15);
    q1.display();
    q1.Enqueue(19);
    q1.display();
    q1.Enqueue(12);
    q1.display();

    return 0;
}