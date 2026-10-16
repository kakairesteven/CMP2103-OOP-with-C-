#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;
// A simple dataframe-like structure
struct DataFrame
{
    vector<int> values;
    string columnName;
    DataFrame(vector<int> data, string name)
    {
        values = data;
        columnName = name;
    }

     // unique()
    // Returns each value only once
    vector<int> unique()
    {
        vector<int> result;
        for (int value : values)
        {
            bool alreadyExists = false;
            for (int item : result)
            {
                if (item == value)
                {
                    alreadyExists = true;
                    break;
                }
            }
            if (!alreadyExists)
            {
                result.push_back(value);
            }
        }
        return result;
    }
    // value_counts()
    // Counts how many times each unique value appears
    vector<pair<int, int>> value_counts()
    {
        vector<pair<int, int>> counts;
        vector<int> distinct = unique();
        for (int value : distinct)
        {
            int count = 0;
            for (int item : values)
            {
                if (item == value)
                {
                    count++;
                }
            }
            counts.push_back({value, count});
        }
        return counts;
    }
    // frequencies()
    // Calculates the relative frequency of every value
    vector<pair<int, double>> frequencies()
    {
        vector<pair<int, int>> counts = value_counts();
        vector<pair<int, double>> result;
        for (auto entry : counts)
        {
            double frequency =
                static_cast<double>(entry.second) / values.size();
            result.push_back({entry.first, frequency});
        }
        return result;
    }
    // closest_value()
    // Finds the value closest to the supplied target
    int closest_value(int target)
    {
        if (values.empty())
        {
            throw runtime_error("Cannot search an empty dataframe.");
        }
        int closest = values[0];
        int smallestDifference = abs(values[0] - target);
        for (int value : values)
        {
            int difference = abs(value - target);
            if (difference < smallestDifference)
            {
                smallestDifference = difference;
                closest = value;
            }
        }
        return closest;
    }
    // nearest_index()
    // Returns the index of the value closest to target
    int nearest_index(int target)
    {
        if (values.empty())
        {
            throw runtime_error("Cannot search an empty dataframe.");
        }
        int nearest = 0;
        int smallestDifference = abs(values[0] - target);
        for (int i = 1; i < values.size(); i++)
        {
            int difference = abs(values[i] - target);
            if (difference < smallestDifference)
            {
                smallestDifference = difference;
                nearest = i;
            }
        }

        return nearest;
    }
};
// Helper functions for displaying results
void display_unique(const vector<int>& result)
{
    cout << "\nUnique values:\n";
    for (int value : result)
    {
        cout << value << " ";
    }
    cout << endl;
}
void display_value_counts(const vector<pair<int, int>>& result)
{
    cout << "\nValue counts:\n";
    cout << "Value\tCount\n";

    for (auto entry : result)
    {
        cout << entry.first << "\t"
             << entry.second << endl;
    }
}
void display_frequencies(const vector<pair<int, double>>& result)
{
    cout << "\nFrequencies:\n";
    cout << "Value\tFrequency\n";
    for (auto entry : result)
    {
        cout << entry.first << "\t"
             << fixed << setprecision(2)
             << entry.second << endl;
    }
}
int main()
{
    // Sample dataframe column
    vector<int> scores =
    {
        72, 85, 72, 90, 64,
        85, 72, 90, 78, 64
    };
    DataFrame df(scores, "Score");
    cout << "      DATAFRAME UNIQUE VALUES DEMO\n";
    cout << "\nColumn: " << df.columnName << endl;
    cout << "Original values:\n";
    for (int value : df.values)
    {
        cout << value << " ";
    }
    cout << endl;
    // 1. unique()
    vector<int> uniqueValues = df.unique();
    display_unique(uniqueValues);
    // 2. value_counts()
    vector<pair<int, int>> counts = df.value_counts();
    display_value_counts(counts);
    // 3. frequencies()
    vector<pair<int, double>> frequency = df.frequencies();
    display_frequencies(frequency);
    // 4. closest_value()
    int target;
    cout << "\nEnter a value to find the closest value: ";
    cin >> target;
    int closest = df.closest_value(target);
    cout << "Closest value to "
         << target
         << " is "
         << closest
         << endl;
    // 5. nearest_index()
    int index = df.nearest_index(target);
    cout << "Index of the nearest value: "
         << index
         << endl;
    cout << "Program completed successfully.\n";
    return 0;
}