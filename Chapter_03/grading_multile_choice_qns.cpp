#include <iostream>
#include <vector>

int main()
{
    const int NUM_STUDENTS = 8;
    const int NUM_QUESTIONS = 10;
    // 2D array storing student answers (8 students x 10 questions)
    char answers[NUM_STUDENTS][NUM_QUESTIONS] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}};

    // 1D array storing the answer key
    char key[NUM_QUESTIONS] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    // Grade each student's test
    for (int student = 0; student < NUM_STUDENTS; student++)
    {
        int correctCount = 0;
        for (int question = 0; question < NUM_QUESTIONS; question++)
        {
            if (answers[student][question] == key[question])
            {
                correctCount++;
            }
        }
        std::cout << "Student " << student << "'s correct count is " << correctCount << std::endl;
    }

    return 0;
}