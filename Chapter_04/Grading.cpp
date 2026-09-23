#include <iostream>
using namespace std;

int main()
{
    char answers[8][10] =
    {
        {'A','B','A','C','C','D','E','E','A','D'},
        {'D','B','A','B','C','A','E','E','A','D'},
        {'E','D','D','A','C','B','E','E','A','D'},
        {'C','B','A','E','D','C','E','E','A','D'},
        {'A','B','D','C','C','D','E','E','A','D'},
        {'B','B','E','C','C','D','E','E','A','D'},
        {'B','B','A','C','C','D','E','E','A','D'},
        {'E','B','E','C','C','D','E','E','A','D'}
    };

    char key[10] = {'D','B','D','C','C','D','A','E','A','D'};

    for(int i = 0; i < 8; i++)
    {
        int correct = 0;

        for(int j = 0; j < 10; j++)
        {
            if(answers[i][j] == key[j])
            {
                correct++;
            }
        }

        cout << "Student " << i
             << " has "
             << correct
             << " correct answers."
             << endl;
    }

    return 0;
}
