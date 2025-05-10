#include <bits/stdc++.h>
using namespace std;

string xor_Binary_Strings(string &A, string &B) {
    int len = A.length();
    string result = "";

    cout << "Performing XOR on " << A << " and " << B << ": ";

    for (int i = 0; i < len; i++) {
        char currentXOR = ((A[i] - '0') ^ (B[i] - '0')) + '0';
        result += currentXOR;
    }

    cout << result << endl;
    return result;
}

string crc_check(string bin, string divisor) {
    cout << "\nStarting CRC check for binary string: " << bin << " with divisor: " << divisor << endl;

    int divisorLen = divisor.length();
    string remainder = bin.substr(0, divisorLen);

    cout << "Initial remainder (first " << divisorLen << " bits): " << remainder << endl;

    for (int i = divisorLen; i < bin.length(); i++) {
        cout << "\nProcessing bit position " << i << " (bit value: " << bin[i] << ")" << endl;
        cout << "Current remainder: " << remainder << endl;

        if (remainder[0] == '1') {
            cout << "First bit is 1, performing XOR with divisor." << endl;
            remainder = xor_Binary_Strings(remainder, divisor);
            cout << "Remainder after XOR: " << remainder << endl;
        } else {
            cout << "First bit is 0, no XOR performed." << endl;
        }

        string prevRem = remainder;
        remainder = remainder.substr(1) + bin[i];
        cout << "After shifting left and appending next bit: " << remainder
             << " (from " << prevRem << " shifted and + " << bin[i] << ")" << endl;
    }

    cout << "\nFinal step after processing all bits." << endl;
    if (remainder.length() >= divisorLen && remainder[0] == '1') {
        cout << "First bit of remainder is 1, performing final XOR with divisor." << endl;
        remainder = xor_Binary_Strings(remainder, divisor);
        cout << "Remainder after final XOR: " << remainder << endl;
    }

    cout << "Final remainder before truncation: " << remainder << endl;
    string result = remainder.substr(1);
    cout << "Truncated remainder (excluding first bit): " << result << endl;

    return result;
}

void receiver(string bin, string divisor) {
    cout << "\nReceiver's CRC check on received message: " << bin << endl;
    string c = crc_check(bin, divisor);

    cout << "Remainder after CRC check: " << c << endl;

    bool found = false;
    for (auto p : c) {
        if (p != '0') {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Error detected in the received message." << endl;
    } else {
        cout << "No errors detected. Received message is correct." << endl;
    }
}

int main() {
    string data, divisor;
    cout << "Enter Data: ";
    cin >> data;
    cout << "Enter Divisor: ";
    cin >> divisor;

    int divisorLen = divisor.length();
    cout << "\nPadding data with " << (divisorLen - 1) << " zeros." << endl;
    string paddedData = data + string(divisorLen - 1, '0');
    cout << "Padded data: " << paddedData << endl;

    cout << "\nComputing CRC remainder..." << endl;
    string remainder = crc_check(paddedData, divisor);
    cout << "\nRaw remainder from CRC computation: " << remainder << endl;

    cout << "Adjusting remainder to " << (divisorLen - 1) << " bits." << endl;
    while (remainder.length() < divisorLen - 1) {
        remainder = "0" + remainder;
    }
    cout << "Adjusted remainder: " << remainder << endl;

    string transmitted = data + remainder;
    cout << "\nTransmitted message (data + remainder): " << transmitted << endl;

    receiver(transmitted, divisor);
    return 0;
}
