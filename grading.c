#include <stdio.h>

int main() {
    // 2D array storing answers for 8 students and 10 questions
    char answers[8][10] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 0
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'}, // Student 1
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'}, // Student 2
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'}, // Student 3
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 4
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 5
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 6
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}  // Student 7
    };

    // 1D array storing the correct answer key
    char key[10] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    // Outer loop through each student
    for (int i = 0; i < 8; i++) {
        int correctCount = 0;

        // Inner loop through each question for the current student
        for (int j = 0; j < 10; j++) {
            if (answers[i][j] == key[j]) {
                correctCount++;
            }
        }

        // Display the grading result for the current student
        printf("Student %d's correct count is %d\n", i, correctCount);
    }

    return 0;
}