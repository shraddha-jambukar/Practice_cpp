#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class doublelinkedlist
{
    node *head;

public:

    doublelinkedlist()
    {
        head = NULL;
    }

    void insert(int val)
    {
        node *p = new node(val);

        if(head == NULL)
        {
            head = p;
        }
        else
        {
            node *q = head;

            while(q->next != NULL)
            {
                q = q->next;
            }

            q->next = p;
            p->prev = q;
        }
    }

    void remove(int val)
    {
        if(head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        node *p = head;

        while(p != NULL && p->data != val)
        {
            p = p->next;
        }

        if(p == NULL)
        {
            cout << "Value not found\n";
            return;
        }

        if(p->prev != NULL)
        {
            p->prev->next = p->next;
        }
        else
        {
            head = p->next;
        }

        if(p->next != NULL)
        {
            p->next->prev = p->prev;
        }

        delete p;
    }

    void displayforward()
    {
        node *q = head;

        cout << "Forward: ";

        while(q != NULL)
        {
            cout << q->data << "<->";
            q = q->next;
        }

        cout << "NULL\n";
    }

    void displaybackward()
    {
        if(head == NULL)
        {
            cout << "Backward: NULL\n";
            return;
        }

        node *q = head;

        while(q->next != NULL)
        {
            q = q->next;
        }

        cout << "Backward: ";

        while(q != NULL)
        {
            cout << q->data << "<->";
            q = q->prev;
        }

        cout << "NULL\n";
    }
};

int main()
{
    doublelinkedlist list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    list.displayforward();
    list.displaybackward();

    list.remove(20);

    list.displayforward();
    list.displaybackward();

    return 0;
}