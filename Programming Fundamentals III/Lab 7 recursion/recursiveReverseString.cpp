//Write a recursive function that displays a string in reverse.
#include <iostream>
#include <string>

using namespace std;

void reverseDisplay(const string& s) {
    if(s.size() > 0) {
        cout << s.back();
        reverseDisplay(s.substr(0, s.size() - 1));
    }
}

int main() {
    string stringy;

    cout << "Enter a string: ";
    getline(cin, stringy);
    cout << endl;

    cout << "Reverse of string: ";
    reverseDisplay(stringy);

    cout << "\n\nCode by Jacob Smetana\n";
    return 0;
}
