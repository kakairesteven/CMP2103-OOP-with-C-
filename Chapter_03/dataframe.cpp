// Moldify the dataframe program in chapter 2 to use vectors

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    vector<vector<int>> dataframe = {
        {100, 120, 80},
        {130, 140, 90},
        {110, 150, 100},
        {100, 105, 95}
    };

    cout << left << setw(8) << "Ind"
         << setw(8) << "ELE"
         << setw(8) << "COMP"
         << setw(8) << "BIO"
         << setw(8) << "Sum"
         << setw(8) << "Mean"
         << "Median" << endl;

    for (size_t row = 0; row < dataframe.size(); ++row) {
        int sum = 0;
        for (int value : dataframe[row]) {
            sum += value;
        }

        vector<int> sortedRow = dataframe[row];
        sort(sortedRow.begin(), sortedRow.end());
        double mean = static_cast<double>(sum) / dataframe[row].size();
        double median = (sortedRow[1] + sortedRow[2]) / 2.0;

        cout << left << setw(8) << row + 1;
        for (int value : dataframe[row]) {
            cout << setw(8) << value;
        }
        cout << setw(8) << sum
             << setw(8) << fixed << setprecision(2) << mean
             << median << endl;
    }

    return 0;
}
