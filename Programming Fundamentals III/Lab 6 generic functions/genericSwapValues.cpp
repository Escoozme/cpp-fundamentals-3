//Write a generic function that swaps values in two variables.
//Your function should have two parameters of the same type.
//Test the function with int, double, and string values.
#include <iostream>

using namespace std;

template<typename T>
T swapValues(T& valueA, T& valueB) {
    T temp = valueA;
    valueA = valueB;
    valueB = temp;
}

int main() {
    //integers
    int intOne = 2, intTwo = 56;
    swapValues(intOne, intTwo);
    cout << intOne << " " << intTwo << endl << endl;

    //doubles
    double doubleOne = 3.14, doubleTwo = 7.6;
    swapValues(doubleOne, doubleTwo);
    cout << doubleOne << " " << doubleTwo << endl << endl;

    //strings
    string stringOne = "ABC", stringTwo = "123";
    swapValues(stringOne, stringTwo);
    cout << stringOne << " " << stringTwo << endl << endl;

    cout << "Code by Jacob Smetana" << endl;
    return 0;
}
