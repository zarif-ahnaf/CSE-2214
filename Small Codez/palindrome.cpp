#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "101";
    string rev;
    reverse(s.begin(), s.end());
    if (s == rev)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not a palindrome" << endl;
    }
}