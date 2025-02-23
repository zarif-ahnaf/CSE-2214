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
string convert_binary_to_padded_bits(long long num)
{
    if (num == 0)
    {
        return "0";
    }

    int level = ceil(log2(num + 1));
    int binary_size = (1 << level);

    string result;
    long long temp = num;

    while (temp > 0)
    {
        result = (temp % 2 ? '1' : '0') + result;
        temp /= 2;
    }

    while (result.length() < binary_size)
    {
        result = '0' + result;
    }

    return result;
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

void receiver(vector<int> inp, string checksum)
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
    string sum_bit = convert_binary_to_padded_bits(sum);
    string one_s_sum = ones_complement(sum_bit);

    receiver(inp, one_s_sum);
    return 0;
}
