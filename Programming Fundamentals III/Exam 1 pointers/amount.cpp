#include <iostream>

using namespace std;

const int SIZE = 10;

double* extend(double price[], double quantity[], double amount[]) {
    for(int i = 0; i < SIZE; ++i) {
        amount[i] = price[i] * quantity[i];
    }
    return amount;
}

int main() {
    double price[SIZE] = {10.62, 14.89, 13.21, 16.55, 18.62,
                          9.47, 6.58, 18.32, 12.15, 3.98};
    double quantity[SIZE] = {4, 8.5, 6, 7.35, 9,
                             15.3, 3, 5.4, 2.9, 4.8};
    double amount[SIZE] = { 0 };

    double* pAmount = extend(price, quantity, amount);

    cout << "Values in the \"amount\" array:\n";

    for(int i = 0; i < SIZE; ++i) {
        cout << (pAmount + i);
        if(i < 9) {cout << ", ";}
    }

    cout << "\n\nCode by Jacob Smetana\n";

    return 0;
}
