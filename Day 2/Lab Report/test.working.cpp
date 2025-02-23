#include <bits/stdc++.h>
using namespace std;

const int WRAP_COUNT = 4;
const int BINARY_COUNT = 1024;

string ones_complement(string binary)
{
    for (char &bit : binary)
    {
        bit = (bit == '0') ? '1' : '0';
    }
    return binary;
}

string convert_binary_to_padded_bits(long long num)
{

    int level = ceil(log2(num + 1));
    int binary_size = (1 << level);
    string sum_bit = bitset<BINARY_COUNT>(num).to_string();
    sum_bit = sum_bit.substr(BINARY_COUNT - binary_size);
    return sum_bit;
}

string add_binary(string A, string B)
{
    if (A.length() > B.length())
        return add_binary(B, A);

    int diff = B.length() - A.length();

    string padding;
    for (int i = 0; i < diff; i++)
        padding.push_back('0');

    A = padding + A;
    string res;
    char carry = '0';

    for (int i = A.length() - 1; i >= 0; i--)
    {
        if (A[i] == '1' && B[i] == '1')
        {
            if (carry == '1')
                res.push_back('1'), carry = '1';
            else
                res.push_back('0'), carry = '1';
        }

        else if (A[i] == '0' && B[i] == '0')
        {
            if (carry == '1')
                res.push_back('1'), carry = '0';
            else
                res.push_back('0'), carry = '0';
        }

        else if (A[i] != B[i])
        {
            if (carry == '1')
                res.push_back('0'), carry = '1';
            else
                res.push_back('1'), carry = '0';
        }
    }

    if (carry == '1')
        res.push_back(carry);
    reverse(res.begin(), res.end());

    int index = 0;
    while (index + 1 < res.length() &&
           res[index] == '0')
        index++;
    return (res.substr(index));
}

string wrap_sum(string a, string b)
{
    string sum = add_binary(a, b);
    if (sum.size() > WRAP_COUNT)
    {
        string last_4 = sum.substr(sum.size() - WRAP_COUNT);
        string the_rest = sum.substr(0, sum.size() - WRAP_COUNT);
        return wrap_sum(last_4, the_rest);
    }
    return sum;
}

void checksum_validator(vector<int> inp, string checksum)
{
    string binary = string(WRAP_COUNT, '0');

    for (int i = 0; i < inp.size(); i++)
    {
        int num = inp[i];
        string num_binary = convert_binary_to_padded_bits(num);
        binary = wrap_sum(binary, num_binary);
    }

    binary = wrap_sum(binary, checksum);
    string one_s_binary = ones_complement(binary);

    string target = string(WRAP_COUNT, '0');
    if (one_s_binary == target)
        cout << "Message sent is okay";
    else
        cout << "Message sent is not okay";
    cout << endl;
}

int main()
{
    vector<int> inp;
    int i = 0;
    cout << "Enter the number of elements:";
    cin >> i;
    inp.resize(i);
    for (int &x : inp)
    {
        cin >> x;
    }
    long long sum = accumulate(inp.begin(), inp.end(), 0);
    string sum_bit = convert_binary_to_padded_bits(sum);
    string one_s_sum = ones_complement(sum_bit);

    checksum_validator(inp, one_s_sum);
    return 0;
}
