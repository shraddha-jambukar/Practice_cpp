#include <conio.h>
#include <iostream>
using namespace std;

class addition{
    int a=10;
    int b=20;
    int add;

    public:
    void sample(){
    add = a+b;
    cout<<"The sum is:" << add;
}
};

int main(){
addition a1;
a1.sample();
return 0;
}