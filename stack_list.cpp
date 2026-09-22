#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class stack
{
private:
    node *top;

public:

    stack()
    {
        top = NULL;
    }

    int empty()
    {
        if(top == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push(int x)
    {
        node *p = new node(x);

        p->next = top;
        top = p;
    }

    int pop()
    {
        if(empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        int x = top->data;

        node *p = top;
        top = top->next;

        delete p;

        return x;
    }

    int peek()
    {
        if(empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->data;
    }

    void display()
    {
        node *q = top;

        cout << "Stack elements:";

        while(q != NULL)
        {
            cout << endl << q->data;
            q = q->next;
        }

        cout << endl;
    }
};

int main()
{
    int x;
    stack s;

    s.push(80);
    s.push(56);
    s.push(34);
    s.push(46);
    s.push(657);
    s.push(457);

    s.display();

    if(!s.empty())
    {
        x = s.pop();
        cout << "Removed: " << x << endl;
    }

    s.display();

    if(!s.empty())
    {
        x = s.peek();
        cout << "The top element is: " << x << endl;
    }

    return 0;
}