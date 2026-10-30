#include <array>
#include <iostream>

int main()
{
    constexpr std::array<char, 10> answer_key = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};
    constexpr std::array<std::array<char, 10>, 8> student_answers = {{
        {{'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}},
        {{'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'}},
        {{'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'}},
        {{'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'}},
        {{'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}},
        {{'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}},
        {{'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}},
        {{'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}}
    }};

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

        std::cout << "Student " << student << " correctly answered "
                  << correct_answers << " questions.\n";
    }

    return 0;
}