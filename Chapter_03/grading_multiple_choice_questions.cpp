#include <iostream>
#include <vector>

int main()
{
    const std::vector<char> answer_key = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};
    const std::vector<std::vector<char>> student_answers = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}};

    for (std::size_t student = 0; student < student_answers.size(); ++student)
    {
        int correct_answers = 0;

        for (std::size_t question = 0; question < answer_key.size(); ++question)
        {
            if (student_answers[student][question] == answer_key[question])
            {
                ++correct_answers;
            }
        }

        std::cout << "Student " << student << ": " << correct_answers
                  << " correct answers\n";
    }

    return 0;
}