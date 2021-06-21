#include <iostream>
#include <string>

using namespace std;

bool IsNumber(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string Integer;

    std::cout << "Welcome to the Credit Card Validation System.";
    std::cout << "\n\n";

    cout << "Type 'exit' to quit the program." << endl;
    std::cout << "\n\n\n";

    while (true) {

        cout << "Please enter a Credit or Debit card number (without spaces and dashes) to validate: " << endl;
        std::cout << "\n";
        cin >> Integer;

        if (Integer == "exit")
            break;

        else if (!IsNumber(Integer)) {
            std::cout << "\n";
            cout << "Please enter only numbers! " << endl;
            std::cout << "\n";
            continue;
        }

        int len = Integer.length();
        int DoubleNumberSum = 0;


        // Step 1

        // Double every second digit, starting from the right. If it results in a
        // two digit number, add both the digits to obtain a single digit number.
        // Then add all the answers to obtain 'doubleEvenSum'. 


        for (int i = len - 2; i >= 0; i = i - 2) {
            int doubleNumber = ((Integer[i] - 48) * 2);
            if (doubleNumber > 9) {
                doubleNumber = (doubleNumber / 10) + (doubleNumber % 10);
            }
            DoubleNumberSum += doubleNumber;
        }

        // Step 2

        // Add every odd placed digit from the right to the value 'doubleEvenSum'.


        for (int i = len - 1; i >= 0; i = i - 2) {
            DoubleNumberSum += (Integer[i] - 48);
        }

        // Step 3

        // Check if the final 'doubleEvenSum' is a multiple of 10.
        // If it is, then it is a valid credit card number. Otherwise, it's not.

        cout << (DoubleNumberSum % 10 == 0 ? "\nThis is a valid credit card.\n\n" : "\nThis is an invalid card number.\n\n") << endl;

        continue;
    }

    return 0;
}