#include <bits/stdc++.h>
using namespace std;

const int WRAP_COUNT = 4;

long long sum_of_vector(vector<int> inp)
{
    long long sum = 0;
    for (auto p : inp)
    {
        sum += p;
    }
    return sum;
}
string ones_complement(string binary)
{
    for (char &bit : binary)
    {
        bit = (bit == '0') ? '1' : '0';
    }
    return binary;
}
int binary_to_decimal(string n)
{
    string num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

string dec_to_binary(long long n)
{
    if (n == 0)
    {
        return "0";
    }
    string bin = "";

    while (n > 0)
    {
        int bit = n % 2;
        bin.push_back('0' + bit);
        n /= 2;
    }

    reverse(bin.begin(), bin.end());
    return bin;
}

string add_binary(string A, string B)
{
    if (A.length() > B.length())
        std::swap(A, B);

    A.insert(A.begin(), B.length() - A.length(), '0');

    string result;
    char carry = '0';

    for (int i = A.length() - 1; i >= 0; i--)
    {
        int sum = (A[i] - '0') + (B[i] - '0') + (carry - '0');
        result.push_back((sum % 2) + '0');
        carry = (sum > 1) ? '1' : '0';
    }

    if (carry == '1')
        result.push_back('1');

    reverse(result.begin(), result.end());

    long long first_one = result.find_first_not_of('0');
    return (first_one == std::string::npos) ? "0" : result.substr(first_one);
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

void receiver(vector<int> inp)
{
    string binary = string(WRAP_COUNT, '0');

    for (int i = 0; i < inp.size(); i++)
    {
        int num = inp[i];
        string num_binary = dec_to_binary(num);
        binary = wrap_sum(binary, num_binary);
    }

    string one_s_binary = ones_complement(binary);

    bool ok = true;
    for (auto p : one_s_binary)
    {
        if (p != '0')
        {
            ok = false;
        }
    }

    if (ok)
        cout << "Message sent is okay";
    else
        cout << "Message sent is not okay";
    cout << endl;
}
void sender(vector<int> &inp)
{
    int i = 0;
    cout << "Enter the number of elements:";
    cin >> i;
    inp.resize(i);
    for (int &x : inp)
    {
        cin >> x;
    }
}

int main()
{
    vector<int> inp;
    sender(inp);

    long long sum = sum_of_vector(inp);

    string sum_bit = dec_to_binary(sum);
    string one_s_sum = ones_complement(sum_bit);

    inp.push_back(binary_to_decimal(one_s_sum));

    receiver(inp);
    return 0;
}
