Suppose there are eight students and ten questions, and the answers are stored in a two dimensional
list. Each row records a student’s answers to the questions, as shown in the
following illustration

## Students’ Answers to the Questions

| Student   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|-----------|---|---|---|---|---|---|---|---|---|---|
| Student 0 | A | B | A | C | C | D | E | E | A | D |
| Student 1 | D | B | A | B | C | A | E | E | A | D |
| Student 2 | E | D | D | A | C | B | E | E | A | D |
| Student 3 | C | B | A | E | D | C | E | E | A | D |
| Student 4 | A | B | D | C | C | D | E | E | A | D |
| Student 5 | B | B | E | C | C | D | E | E | A | D |
| Student 6 | B | B | A | C | C | D | E | E | A | D |
| Student 7 | E | B | E | C | C | D | E | E | A | D |


The key is stored in a one-dimensional list:
### Key to the Questions

| Key   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|-------|---|---|---|---|---|---|---|---|---|---|
| Answer| D | B | D | C | C | D | A | E | A | D |

Write a program that grades the test and displays the result. To do this, the program compares each
student’s answers with the key, counts the number of correct answers, and displays it.



#include <iostream>
#include <vector>

int main() {
    // 2D vector containing each student's answers (8 students, 10 questions)
    std::vector<std::vector<char>> answers = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 0
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'}, // Student 1
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'}, // Student 2
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'}, // Student 3
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 4
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 5
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}, // Student 6
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}  // Student 7
    };

    // 1D vector containing the correct answer key
    std::vector<char> key = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    // Outer loop iterates through each student
    for (size_t i = 0; i < answers.size(); ++i) {
        int correct_count = 0;

        // Inner loop compares each answer to the key
        for (size_t j = 0; j < key.size(); ++j) {
            if (answers[i][j] == key[j]) {
                correct_count++;
            }
        }

        // Print the result for the student
        std::cout << "Student " << i << "'s correct count is " << correct_count << std::endl;
    }

    return 0;
}