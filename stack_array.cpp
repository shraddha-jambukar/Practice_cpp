#include<iostream>
using namespace std;

const int MAX = 5;

class stack{
    private:
    int a[MAX];
    int top;

    public:
    stack(){
        top = -1;
    }

    void push(int x){
        top++;
        a[top] = x;
    }

    int pop(){
        int x = a[top];
        top--;
        return x;
    }

    int peek(){
        cout<<"The peek value is:"<<a[top];
    }

    int full(){
        if(top == MAX-1){
            return 1;
        }
        else{
            return 0;
        }
    }

    int empty(){
        if(top == -1){
            return 1;
        }
        else{
            return 0;
        }
    }

    void display(){
        for(int i=top; i>=0; i--){
            cout<<endl<<a[i];
        }
    }
};


int main(){
    int x;
    stack s;

    if(!s.full()) s.push(12);
    if(!s.full()) s.push(45);
    if(!s.full()) s.push(23);
    if(!s.full()) s.push(78);
    if(!s.full()) s.push(45);

    s.display();

    if(!s.empty()){
        x = s.pop();
        cout<<"Removed element is:"<<x;
    }

    s.display();

    if(!s.empty()){
        x= s.peek();
        cout<<endl<<"top element is:"<<x;
    }

    return 0;
}
