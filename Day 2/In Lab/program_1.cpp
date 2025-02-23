#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {4,4,9,12,17};
    int sum = 0;

    for(auto p:arr){
        sum+= p;
    };
    cout << sum << endl;
    string bin = bitset<8>(sum).to_string();
    cout << bin;
}