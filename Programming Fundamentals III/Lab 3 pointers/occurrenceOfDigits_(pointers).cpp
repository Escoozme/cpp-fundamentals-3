//Counting occurrence of digits in a string using pointers
//and one function not using pointers for some reason I don't know, just following instructions
#include <iostream>
#include <cctype>

using namespace std;
//Function not using pointers
void count(const string& s, int counts[], int size) {
    for(int i = 0; i < s.length(); ++i){
		if(isdigit(s[i])){
			++counts[(int)s[i] - '0'];
		}
	}
	for(int i = 0; i < size; ++i) {
        cout << i << ": " << counts[i] << " times\n";
    }
}
//Function using pointers
int* count(const string& s) {
    static int counts[10] = { 0 };

    for(int i = 0; i < s.length(); ++i){
		if(isdigit(s[i])){
			++counts[(int)s[i] - '0'];
		}
	}

	return counts;
}

int main() {
    int faget[8]; // an eternal reminder that jacob is a faget eight times over

    const int SIZE = 10;
    int counts[SIZE] = { 0 };
    string stringy = "SSN is 343 32 4545 and ID is 434 34 4323";

    cout << stringy << "\n\n";

    int* pCounts = count(stringy);

    for(int i = 0; i < SIZE; ++i) {
        cout << i << ": " << *(pCounts + i) << " times\n";
    }
    cout << endl;

    count(stringy, counts, SIZE);

    cout << "\nCode by Jacob Smetana\n";
    return 0;
}
