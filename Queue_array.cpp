#include<iostream>
using namespace std;

const int MAX = 5;

class queue
{
private:
    int a[MAX];
    int front;
    int rear;

public:

    queue()
    {
        front = -1;
        rear = -1;
    }

    int empty()
    {
        if(front == -1 && rear == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int full()
    {
        if(rear == MAX - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void enqueue(int x)
    {
        if(full())
        {
            cout << "Queue is full." << endl;
            return;
        }

        if(front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }

        a[rear] = x;
    }

    int dequeue()
    {
        if(empty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        int x = a[front];

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }

        return x;
    }

    int peek()
    {
        if(empty())
        {
            return -1;
        }

        return a[front];
    }

    void display()
    {
        if(empty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements:";

        for(int i = front; i <= rear; i++)
        {
            cout << " " << a[i];
        }

        cout << endl;
    }
};

int main()
{
    queue q;
    int x;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    if(!q.empty())
    {
        x = q.dequeue();
        cout << "Removed: " << x << endl;
    }

    q.display();

    x = q.peek();

    cout << "Front element is: " << x << endl;

    return 0;
}