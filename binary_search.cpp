#include<iostream>
using namespace std;

int binary_search(int a[], int n, int x){
    int first = 0;
    int last = n-1;
    int mid;

    while(first <= last){
        mid = (first + last) / 2;

        if (a[mid] == x){
            return mid;
        }
        else if(a[mid] < x){
            first = mid + 1;
        }
        else{
            last = mid - 1;
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

    int location = binary_search(a, n, x);

    if  (location != -1){
        cout << "the element is found at index: " <<location ;
    }
    else{
        cout << "the element is not found." ;
    }
    return 0;
}