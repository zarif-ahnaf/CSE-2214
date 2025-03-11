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
string leftShiftTillOne(string binary)
{
    while (!binary.empty() && binary[0] != '1')
    {
        binary.erase(0, 1);
    }
    return binary;
}
void divide(string bin, string divisor)
{
    int start = 0;
    int end = divisor.length();
    string str = "";
    string result = "";
    string first = "";

    while (true)
    {

        // First iteration
        if (str.empty())
        {
            first = bin.substr(0, divisor.length());
            // cout << first << endl
            //      << divisor << endl;
            result = xor_Binary_Strings(first, divisor);
            result = leftShiftTillOne(result);
            start += divisor.length();
        }
        // Second iteration
        if (!result.empty())
        {
            int bits_needed = divisor.length() - result.length();
            int end = start + bits_needed;
            if (end > bin.length())
            {
                cout << start << "," << bits_needed << "," << end;
                break;
            }
            first = result + bin.substr(start, start + bits_needed);
            result = xor_Binary_Strings(first, divisor);

            start = end;
        }
    }
    cout << end << endl;
}

void pad_end(int divisor_length, vector<string> &arr)
{
    for (auto &p : arr)
    {
        for (int i = 0; i < divisor_length; i++)
        {
            p += '0';
        }
    }
}

// int main()
// {
//     string divisor = "1000";
//     vector<string> arr = {"110100", "100000"};
//     int divisor_length = divisor.length() - 1;

//     pad_end(divisor_length, arr);

//     for (const auto &p : arr)
//     {
//         cout << p << endl;
//     }

//     return 0;
// }

int main()
{
    divide("110100", "1000");
}