#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {

    //Task 1 : Add student Grades
    map<string, float> studentGrades;
    studentGrades["Dara"] = 85.5;
    studentGrades["Sokha"] = 92.0;
    studentGrades["Bopha"] = 78.5;
    studentGrades["Thida"] = 90.0;

    //Task 2 : Update Dara's grade to 88.5
    studentGrades["Dara"] = 88.5;
    cout << "====== Updated Student Grades ======" << endl;

    // auto& to auto infers the type of the elements in the map
    for (const auto& element : studentGrades) {
        cout << element.first << " : " << element.second << endl;
    }
    
    // show student grades
    cout << "====== Student Grades ======" << endl;
    for (const auto& element : studentGrades) {
        cout << element.first << " : " << element.second << endl;
    }

    //Task 4 : Check if student "Thida" exists

    auto it = studentGrades.find("Thida");
    if (it == studentGrades.end()) {
        cout << "====== Student does not exist ======" << endl;
        cout << "Thida does not exist." << endl;
    } else {
        cout << "====== Check if student exists ======" << endl;
        cout << "Thida exists with grade: " << it->second << endl;
    }
    
    return 0;

}