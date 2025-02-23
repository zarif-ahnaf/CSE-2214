#include <bits/stdc++.h>
using namespace std;

void receiver(int arr[],int n){
    int _sum = 0;
    cout << "Receiving Data:[";
    for(int i =0;i<n-1;i++){
        cout << arr[i];
        if(i!=n-2) cout << ",";
    }
    cout << "]";
    cout << endl;

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
void sender(int arr[],int n){
    int sum = 0 ;
    int new_arr[n+1];

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
    receiver(new_arr,n+1);
}



int main(){
    int arr[] = {7,23,5,17,10};
    sender(arr,5);

}


