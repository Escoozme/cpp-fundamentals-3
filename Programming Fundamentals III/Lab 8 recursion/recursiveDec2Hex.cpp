//Write a recursive function that converts a decimal number into a hex number as a string.
#include <iostream>
#include <string>

using namespace std;

string decimalToHex(int value) {
    static string hexStr;
    string letterStr = "";
    int modValue = value % 16;
    if(value > 0) {
        if(modValue <= 9) {
            hexStr.insert(0, to_string(modValue));
        }
        else {
            hexStr.insert(0, letterStr.assign(1, (char)(modValue + 55)));
        }
        return decimalToHex(value / 16);
    }
    else
        return hexStr;
}

int main() {
    int decimal;

    cout << "Enter a decimal number: ";
    cin >> decimal;
    cout << endl;

    cout << decimalToHex(decimal);

    cout << "\n\nCode by Jacob Smetana\n";
    return 0;
}
