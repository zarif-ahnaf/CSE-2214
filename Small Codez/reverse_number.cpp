#include <bits/stdc++.h>
using namespace std;

void reverse_number(int n)
{
    int reversed = 0;
    while (n > 0)
    {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    std::cout << "Reversed number: " << reversed << std::endl;
}

int main(){
    
}