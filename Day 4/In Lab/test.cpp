#include <bits/stdc++.h>
using namespace std;

string xor_Binary_Strings(string &A, string &B)
{
    int len = A.length();
    string result = "";

    for (int i = 0; i < len; i++)
    {
        char currentXOR = ((A[i] - '0') ^ (B[i] - '0')) + '0';
        result += currentXOR;
    }

    return result;
}

string crc_check(string bin, string divisor)
{
    int divisorLen = divisor.length();
    string remainder = bin.substr(0, divisorLen);

    for (int i = divisorLen; i < bin.length(); i++)
    {
        if (remainder[0] == '1')
        {
            remainder = xor_Binary_Strings(remainder, divisor);
        }
        remainder = remainder.substr(1) + bin[i];
    }

    if (remainder.length() >= divisorLen && remainder[0] == '1')
    {
        remainder = xor_Binary_Strings(remainder, divisor);
    }

    return remainder.substr(1);
}

void receiver(string bin, string divisor)
{

    string c = crc_check(bin, divisor);
    bool found = false;
    for (auto p : c)
    {
        if (p != '0')
        {
            found = true;
        }
    }
    if (found)
    {
        cout << "Error";
    }
    else
    {
        cout << "Ok";
    }
    cout << endl;
}

int main()
{
    string data;
    string divisor;

    cout << "Enter Data: ";
    cin >> data;
    cout << "Enter Divisor: ";
    cin >> divisor;
    string data = "11100101";
    string divisor = "11011";
    int divisorLen = divisor.length();

    string paddedData = data + string(divisorLen - 1, '0');
    string remainder = crc_check(paddedData, divisor);

    while (remainder.length() < divisorLen - 1)
    {
        remainder = "0" + remainder;
    }

    receiver(data + remainder, divisor);
    return 0;
}
