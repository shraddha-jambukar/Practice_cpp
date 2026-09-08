#include<iostream>
using namespace std;

int linear_search(int a[] , int n, int x){
    for(int i = 0; i < n; i++){
        if (a[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    int a[20];
    cout << "Enter the size array element:";
    cin >> n;

    cout << "Enter " << n << " intergers" <<endl;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int x;
    cout << "Enter the element that you want to search:";
    cin >> x;

    int location = linear_search(a, n, x);

    if  (location != -1){
        cout << "the element is found at index: " <<location ;
    }
    else{
        cout << "the element is not found." ;
    }
    return 0;
}