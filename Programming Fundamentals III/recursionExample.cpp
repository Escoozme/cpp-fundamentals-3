//Example of recursion with factorials
#include <iostream>

using namespace std;

long long factorial(int n) {            //Return factorial for specified index
    if(n == 0)
        return 1;                       //Base case
    else
        return n * factorial(n - 1);    //Recursive call
}

int main() {
    int n;

    cout << "Enter a non-negative integer: ";
    cin >> n;

    cout << "\nFactorial of " << n << " is " << factorial(n) << endl; //Display factorial

    return 0;
}
