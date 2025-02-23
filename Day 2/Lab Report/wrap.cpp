#include <bits/stdc++.h>
using namespace std;

long long sum_of_vector(vector<int> inp)
{
    long long sum = 0;
    for (auto p : inp)
    {
        sum += p;
    }
    return sum;
}

void sender(vector<int> &inp)
{
    int i = 0;
    cout << "Enter the number of elements:";
    cin >> i;
    inp.resize(i);
    for (auto &x : inp)
    {
        cin >> x;
    }
}
void receiver(vector<int> inp)
{
    long long sum = sum_of_vector(inp);
    if (sum == 0)
    {
        cout << "Message sent is okay";
    }
    else
    {
        cout << "Message sent is not okay";
    }
    cout << endl;
}

int main()
{
    vector<int> inp;
    sender(inp);
    long long sum = sum_of_vector(inp);

    inp.push_back(-sum);
    receiver(inp);
}