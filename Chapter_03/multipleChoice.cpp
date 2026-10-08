#include <iostream>
#include <vector>

using namespace std;

int main(){

    const int STUDENTS = 8;
    const int QUESTIONS = 10;

    //using arrays to store the key and answers
    char CorrectAnswers[10] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    char StudentAnswers[8][10] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
    };
    
    for (int i = 0; i < STUDENTS; i++) {
        int correctCount = 0;
        for (int j = 0; j < QUESTIONS; j++) {
            if (StudentAnswers[i][j] == CorrectAnswers[j]) {
                correctCount++;
            }
        }
        cout << "Student " << i+1 <<"'s "<< "Score: " <<correctCount <<"/" << QUESTIONS << endl << endl;
    }

    return 0;
}