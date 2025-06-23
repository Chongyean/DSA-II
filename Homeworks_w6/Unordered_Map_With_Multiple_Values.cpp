#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<string, vector<int>> studentScores;

    // Task 1 : Add student scores
    studentScores["Dara"] = {85, 90, 88};
    studentScores["Sokha"] = {92, 95, 89};

    // Task 2 : Calculate and print avg scores for each student
    cout << "====== Student Average Scores ======" << endl;
    for (const auto& element : studentScores) {
        const string& studentName = element.first;
        const vector<int>& scores = element.second;
        double sum = 0;
        for (int score : scores) {
            sum += score;
        }
        double average = sum / scores.size();
        cout << studentName << " : " << average << endl;
    }

    // Task 3 : Add a new score 93 for Dara
    studentScores["Dara"].push_back(93);
    cout << "====== Updated Scores for Dara ======" << endl;
    for (int score : studentScores["Dara"]) {
        cout << score << "| ";
    }

    // Task 4 : Print number of scores for each student
    cout << "\n====== Number of Scores for Each Student ======" << endl;
    for (const auto& element : studentScores) {
        const string& studentName = element.first;
        int numScores = element.second.size();
        cout << studentName << " has " << numScores << " scores." << endl;
    }

    return 0;
}