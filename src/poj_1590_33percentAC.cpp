#include <string>
#include <iostream>

using namespace std;

int main() {
    // A hashmap is a better solution
    char reverse_alpha[26] = {'A', 0, 0, 0, '3', 0, 0, 'H', 'I', 'L', 0, 'J', 'M', 0, 'O', 0, 0, 0, '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5'};
    char reverse_num[10] = {0, '1', 'S', 'E', 0, 'Z', 0, 0, '8', 0};

    string str;
    while (cin >> str) {
        bool is_palindrome = true;
        bool is_mirrored = true;

        int i = 0;
        int j = str.length() - 1;
        while (i <= j) {
            if (str[i] != str[j])
                is_palindrome = false;

            char reverse = str[i] >= 'A' ? reverse_alpha[str[i] - 'A'] : reverse_num[str[i] - '0'];
            if (str[j] != reverse)
                is_mirrored = false;

            if (!is_mirrored && !is_palindrome)
                break;

            i++;
            j--;
        }
        
        if (!is_palindrome && !is_mirrored)
            cout << str << " -- is not a palindrome." << endl;
        else if (is_palindrome && !is_mirrored)
            cout << str << " -- is a regular palindrome." << endl;
        else if (!is_palindrome && is_mirrored)
            cout << str << " -- is a mirrored string." << endl;
        else
            cout << str << " -- is a mirrored palindrome." << endl;
        cout << endl;
    }

    return 0;
}
