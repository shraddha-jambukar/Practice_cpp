#include<iostream>
using namespace std;

void bubble_sort(int a[], int n){
    for(int i = 0; i < n-1; i++){
       for(int j =0; j <  n-1; j++){
        if( a[j] > a[j+1]){
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
       }
    }
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

    bubble_sort(a, n);

    cout << " The sorted array is:";
    for(int i= 0; i < n; i++){
       cout << a[i] << " ";
    }

    return 0;
} 