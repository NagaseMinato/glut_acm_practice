#include <iostream>
#include <string>

int main() {
	using namespace std;
	string str = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
	string input;
	while (getline(cin,input)) {
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == ' ')
				continue;
			input[i] = str[str.find(input[i]) - 1];
		}
		cout << input<<"\n";
	}
}