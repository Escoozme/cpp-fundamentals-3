//Converts decimal, binary, and hexadecimal numbers into one of the other two bases.
#include <iostream>
#include <string>

using namespace std;

//Converts Decimal to Hexadecimal.
void dec2Hex(const string& number) {
    string tempNumber = number;
    int hexValue[32] = { 0 };
    int quotient = stoi(tempNumber);
    int counter = -1;
    for(int i = 0; quotient > 0; ++i, ++counter) {
        hexValue[i] = quotient % 16;
        quotient /= 16;
    }
    for(int i = counter; i >= 0; --i) {
        if(hexValue[i] > 9) {
            cout << (char)(hexValue[i] + 55);
        } else {
            cout << hexValue[i];
        }
    }
    cout << endl;
}

//Converts Decimal to Binary.
void dec2Bin(const string& number) {
    string tempNumber = number;
    int binaryValue[32] = { 0 };
    int quotient = stoi(tempNumber);
    int counter = -1;
    for(int i = 0; quotient > 0; ++i, ++counter) {
        binaryValue[i] = quotient % 2;
        quotient /= 2;
    }
    for(int i = counter; i >= 0; --i) {
        cout << binaryValue[i];
    }
    cout << endl;
}

//Used in hex2Dec and bin2Dec to convert characters to numbers.
int charToDecimal(char ch) {
    ch = toupper(ch);
    if ('A' <= ch && ch <= 'F') {
        return 10 + ch - 'A';
    } else {
        return ch - '0';
    }
}

//Converts Hexadecimal to Decimal.
int hex2Dec(const string& number) {
    int decimalValue = 0;
    for(unsigned i = 0; i < number.size(); ++i) {
        decimalValue = decimalValue * 16 + charToDecimal(number[i]);
    }
    return decimalValue;
}

//Converts Hexadecimal to Binary.
void hex2Bin(const string& number) {
    string tempNumber = to_string(hex2Dec(number));
    dec2Bin(tempNumber);
}

//Converts Binary to Decimal.
int bin2Dec(const string& number) {
    int decimalValue = 0;
    for(unsigned i = 0; i < number.size(); ++i) {
        decimalValue = decimalValue * 2 + charToDecimal(number[i]);
    }
    return decimalValue;
}

//Converts Binary to Hexadecimal.
void bin2Hex(const string& number) {
    string tempNumber = to_string(bin2Dec(number));
    dec2Hex(tempNumber);
}

int main() {
    string number;
    char letter;

    cout << "This program takes a decimal, binary or hexadecimal \n"
         << "number and converts it to one of the other two bases." << endl << endl;

    cout << "Letters and their corresponding conversions:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "H: Decimal to Hexadecimal" << endl <<
            "B: Decimal to Binary" << endl <<
            "D: Hexadecimal to Decimal" << endl <<
            "X: Hexadecimal to Binary" << endl <<
            "N: Binary to Decimal" << endl <<
            "Y: Binary to Hexadecimal" << endl;
    cout << "--------------------------------------------------" << endl << endl;

    cout << "Enter a number or 0 to end: ";
    cin >> number;

    while(number != "0") {
        cout << "Enter a letter for its conversion: ";
        cin >> letter;
        cout << endl;

        if(letter == 'H') {cout << "Hex of Decimal " << number << ": "; dec2Hex(number);}
        if(letter == 'B') {cout << "Binary of Decimal " << number << ": "; dec2Bin(number);}
        if(letter == 'D') {cout << "Decimal of Hex " << number << ": " << hex2Dec(number) << endl;}
        if(letter == 'X') {cout << "Binary of Hex " << number << ": "; hex2Bin(number);}
        if(letter == 'N') {cout << "Decimal of Binary " << number << ": " << bin2Dec(number) << endl;}
        if(letter == 'Y') {cout << "Hex of Binary " << number << ": "; bin2Hex(number);}

        cout << "----------------------------------------" << endl << endl;
        cout << "Enter a number or 0 to end: ";
        cin >> number;
    }

    cout << endl << "Code by Jacob Smetana" << endl;
    return 0;
}
