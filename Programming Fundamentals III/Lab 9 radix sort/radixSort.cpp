//(Radix sort) Write a program that randomly generates
//10,000 integers and sorts them using radix sort.

//Tell me what radix sort does. Minimum 500 words. Thanks.

#include <iostream>
#include <ctime>

using namespace std;

const int SIZE = 10000;

void countSort(int arr[], int x) {
    int sortedArray[SIZE];
    //Holds count of numbers ending in digits 0 through 9
    int buckets[10] = { 0 };
    int i;

    //Counts number of integers ending in 0 through 9 and places them in appropriate index
    for(i = 0; i < SIZE; ++i) {
        ++buckets[(arr[i]/x)%10];
    }

    //I DON'T KNOW WHAT THIS DOES PLS TO HALP
    for(i = 1; i < 10; ++i) {
        buckets[i] += buckets[i - 1];
    }

    //I DON'T KNOW WHAT THIS DOES PLS TO HALP
    for(i = SIZE - 1; i >= 0; --i) {
        sortedArray[buckets[(arr[i]/x)%10] - 1] = arr[i];
        --buckets[(arr[i]/x)%10];
    }

    //Updates original array with heretofore sorted array
    for(i = 0; i < SIZE; ++i) {
        arr[i] = sortedArray[i];
    }
}

void radixSort(int arr[]) {
    //maxDigits holds biggest number = most digits
    int maxDigits = arr[0];

    for(int i = 1; i < SIZE; ++i) {
        if(arr[i] > maxDigits) {
            maxDigits = arr[i];
        }
    }

    //x = decimal place = 1s, 10s, 100s, 1000s etc
    for(int x = 1; maxDigits/x > 0; x *= 10) {
        countSort(arr, x);
    }
}

int main() {
    //Declare array to be sorted
    int intArray[SIZE];

    //Populate array with 10,000 integers, unsorted
    srand(time(0));
    for(int i = 0; i < SIZE; ++i) {
        intArray[i] = rand();
    }

    //Call function that sorts the array
    radixSort(intArray);

    //Output sorted array
    for(int i = 0; i < SIZE; i += 10) {
        for(int k = i; k < (i + 10); ++k) {
            cout << intArray[k] << " ";
        }
        cout << endl;
    }

    //Claim code as my own making
    cout << "\nCode by Jacob Smetana\n";
    return 0;
}
