#include <bits/stdc++.h>
using namespace std;

void receiver(int arr[],int n){
    int _sum = 0;
    cout << "Receiving Data:[";
    for(int i =0;i<n;i++){
        cout << arr[i];
        if(i!=n-1) cout << ",";
    }
    cout << "]"<<endl;

    for(int i =0;i<n;i++){
        _sum += arr[i];
    }
  
    if(_sum==0){
        cout<<"Yes";
    }else{
        cout << "No";
    }
    cout << endl;
    
}
int* sender(int arr[],int n){
    int sum = 0 ;
    int *new_arr = new int[n+1];
    
    cout << "Sending Data:[";
    for(int i =0;i<n;i++){
        cout << arr[i];
        if(i!=n-1) cout << ",";
    }
    cout << "]";
    cout << endl;

    for(int i =0;i<n;i++){
        new_arr[i] = arr[i];
        sum+= arr[i];
    }

    new_arr[n] = -sum;
    return new_arr;
}



int main(){
    int arr[] = {7,23,5,17,10};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    int *arrr = sender(arr,arr_size);
    receiver(arrr,arr_size+1);
}


