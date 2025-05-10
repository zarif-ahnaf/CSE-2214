#include <bits/stdc++.h>
using namespace std;

int counter(int num)
{
    int c = 0;
    while (num != 0)
    {
        c++;
        num /= 10;
    }
    return c;
}

int main()
{
    int div, divisor;
    cin >> div >> divisor;
    int bit = counter(divisor);
    cout << "\n Total bits of divisor:" << bit;
    int module = 1;
    for (int i = 0; i < bit - 1; i++)
    {
        module *= 10;
    }
    div *= module;
    cout << "\n Final Div is :" << div << endl;
}