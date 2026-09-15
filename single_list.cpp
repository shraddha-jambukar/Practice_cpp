#include<iostream>
using namespace std;

class node{
public:
int data;
node *next;

node(int x){
    data = x;
    next = NULL;
}

};

class linkedlist{
node *head;

public:
linkedlist(){
    head = NULL;
}

void insert(int x){
    node *p = new node(x);

    if(head == NULL){
        head = p;
    }
    else{
        node *q = head;

        while(q->next != NULL){
            q = q->next;
        }

        q->next = p;
    }
}

void remove(int val){
    node *q = head;

    if(q == NULL){
        cout << "\nList is empty.";
        return;
    }

    if(q->data == val){
        head = q->next;
        delete q;
        return;
    }

    while(q->next != NULL){
        if(q->next->data == val){
            node *p = q->next;
            q->next = p->next;
            delete p;
            return;
        }

        q = q->next;
    }

    cout << "\nValue " << val << " not found.";
}

void display(){
    cout << endl << "Linked List: ";

    node *q = head;

    while(q != NULL){
        cout << q->data << "->";
        q = q->next;
    }

    cout << "NULL";
}

};

int main(){
linkedlist list;


list.insert(10);
list.insert(20);
list.insert(30);
list.display();

list.insert(40);
list.insert(50);
list.insert(60);
list.display();

list.remove(40);
list.display();

list.remove(100);
list.display();

return 0;

}
