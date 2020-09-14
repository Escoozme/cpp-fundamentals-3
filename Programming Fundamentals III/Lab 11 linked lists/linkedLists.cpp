#include <iostream>
#include "unorderedLinkedList.h"

using namespace std;

int main() {
    int list[] = {34, 65, 27, 89, 12};

    unorderedLinkedList<int> myList, subList;

    for(int i = 0; i < 5; ++i) //Point myList to list with elements
        myList.insertLast(list[i]);

    myList.divideMid(subList); //Divide myList into two sublists

    cout << "myList:  "; myList.print();
    cout << endl;
    cout << "subList: "; subList.print();

    cout << "\n\nCode by Jacob Smetana\n";
    return 0;
}
