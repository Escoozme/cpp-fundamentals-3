//(Generic heap sort)  Write a test program that invokes the generic sort function
//to sort an array of int values, an array of double values, and an array of strings.

//Tell me what heap sort does. Thanks.
//Nodes are confusing, no thanks.

#include <iostream>

using namespace std;

template<typename T>
T buildHeap(T arr[], int arraySize, int currentNode) {
    int root = currentNode;
    int left = 2 * currentNode + 1;
    int right = 2 * currentNode + 2;

    if (left < arraySize && arr[left] > arr[root]) {
        root = left;
    }

    if (right < arraySize && arr[right] > arr[root]) {
        root = right;
    }

    if (root != currentNode) {
        swap(arr[currentNode], arr[root]);
        buildHeap(arr, arraySize, root);
    }
}

template<typename T>
T heapSort(T arr[], int arraySize) {
    for (int i = arraySize / 2 - 1; i >= 0; --i) {
        buildHeap(arr, arraySize, i);
    }

    for (int i = arraySize - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        buildHeap(arr, i, 0);
    }
}

int main() {
    int intArray[] = {56, 707, 12, 3, 909, 808, 7, 123, 1337, 505, 69};
    double doubleArray[] = {5.6, 70.7, 12.5, 12.4, 12.3, 12.2, 9.09, 13.37,
                            12.1, 505.4, 505.1, 69.69, 6.55, 6.54};
    string strArray[] = {"Madagascar", "Texas", "Machu Picchu", "Sri Lanka", "Denver",
                         "Apples", "Xylophone", "Zimbabwe", "Jambalaya", "Lamppost",
                         "Emperor", "Jackie", "Soviet", "Jelly", "France",
                         "Water", "Russia", "Crayon", "Bobs", "Aardvark"};
//--------------------------------------------------
    int sizeOfArray = sizeof(intArray)/sizeof(intArray[0]);
    heapSort(intArray, sizeOfArray);

    for(int i = 0; i < sizeOfArray; ++i) {
        cout << intArray[i] << " ";
    }
    cout << "\n\n";
//--------------------------------------------------
    sizeOfArray = sizeof(doubleArray)/sizeof(doubleArray[0]);
    heapSort(doubleArray, sizeOfArray);

    for(int i = 0; i < sizeOfArray; ++i) {
        cout << doubleArray[i] << " ";
    }
    cout << "\n\n";
//--------------------------------------------------
    sizeOfArray = sizeof(strArray)/sizeof(strArray[0]);
    heapSort(strArray, sizeOfArray);

    for(int i = 0; i < sizeOfArray; ++i) {
        cout << strArray[i];
        if(i != sizeOfArray - 1)
            cout << ", ";
    }
    cout << "\n\n";
//--------------------------------------------------

    cout << "\nCode by Jacob Smetana\n";
    return 0;
}
