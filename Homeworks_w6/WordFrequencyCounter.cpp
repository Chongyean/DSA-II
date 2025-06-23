#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    string text = "the quick brown fox jumps over the lazy dog the fox";
    unordered_map<string, int> wordFreq;

    // Task 1: Count frequency of each word
    string word;
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                wordFreq[word]++;
                word.clear();
            }
        } else {
            word += c;
        }
    }

    // Task 2 : Print words that appear more than once
    cout << "======= Words that appear more than once ========" << endl;
    for (const auto& pair : wordFreq) {
        if (pair.second > 1) {
            cout << pair.first << "  :  " << pair.second << endl;
        }
    }

    // Task 3 : Find the word with highest frequency
    string mostFrequentWord;
    int maxFrequency = 0;
    for (const auto& pair : wordFreq) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    return 0;

}