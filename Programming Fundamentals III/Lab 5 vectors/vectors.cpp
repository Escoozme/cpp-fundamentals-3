//Calculate G.P.A. of students using vectors
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    vector<string> courseId;
    vector<int> creditHours;
    vector<char> grades;
    ifstream fin, in;
    int sumHours = 0;
//--------------------------------------------------
//read in course and student files to vectors
    fin.open("course.txt");
    in.open("student.txt");

    string str;
    int num;
    char letter;

    while(fin >> str && fin >> num) {
        if(str.size() > 0) {
            courseId.push_back(str);
            creditHours.push_back(num);
            sumHours += num;
        }
        in >> letter;
        grades.push_back(letter);
    }

    fin.close();
    in.close();
//--------------------------------------------------
//calculate G.P.A.
    double gpa = 0;

    for(unsigned i = 0; i < grades.size(); ++i) {
        if(grades[i] != 'F') {
            gpa += ((double)abs((grades[i] - 69)) * creditHours[i]) / sumHours;
        }
    }
//--------------------------------------------------
//output course id and letter grades, followed by student's G.P.A.
    cout << "Student G.P.A.\n\n";
    cout << "Course ID\tGrade\n\n";

    for(unsigned i = 0; i < courseId.size(); ++i) {
        cout << courseId[i] << "\t" << grades[i] << endl;
    }

    cout << "\nThe Student's GPA is " << fixed << setprecision(2) << gpa << endl;

    return 0;
}
