#include <bits/stdc++.h>
using namespace std;
int sum_of_digits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = sum_of_digits(n);
    cout << "Sum of digits: " << result << endl;
    return 0;
}