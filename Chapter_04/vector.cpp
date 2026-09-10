#include <iostream>
#include <vector>

int main()
{
    // Create a vector containing integers
    std::vector<int> v = {8, 4, 5, 9};
 
    // Add two more integers to vector
    v.push_back(6);
    v.push_back(9);
    
    // Overwrite element at position 2
    v[2] = -1;
 
    // To print the vector elements, iterate through the vector using a range-based for loop
    for (int n : v)
        std::cout << n << ' ';
    std::cout << '\n';
}