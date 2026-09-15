#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Define a structure to easily manage Point coordinates
struct Point {
    double x;
    double y;
};

// Function to find which points fall within each buffer size
void analyzeBuffers(Point center, const std::vector<double>& bufferSizes, const std::vector<Point>& targetPoints) {
    
    // Loop through each buffer size
    for (double size : bufferSizes) {
        std::cout << "Points within buffer size " << size << ":\n";
        bool foundAny = false;

        // Check every point against the current buffer size
        for (const auto& pt : targetPoints) {
            // Calculate Euclidean distance between the center and the current target point
            double distance = std::sqrt(std::pow(pt.x - center.x, 2) + std::pow(pt.y - center.y, 2));

            // If the distance is less than or equal to the buffer size, it is inside
            if (distance <= size) {
                std::cout << "  (" << pt.x << ", " << pt.y << ") [Distance: " << distance << "]\n";
                foundAny = true;
            }
        }

        if (!foundAny) {
            std::cout << "  None\n";
        }
        std::cout << "-----------------------------------\n";
    }
}

int main() {
    // 1. Takes a specific point coordinate as the center location
    Point centerPoint = {0.0, 0.0};

    // 2. Creates buffers of different sizes around that point (sorted smallest to largest)
    std::vector<double> bufferSizes = {5.0, 10.0, 15.0};

    // 3. Takes a given set of points
    std::vector<Point> pointsToCheck = {
        {2.0, 2.0},    // Distance ~2.83 -> (Fits in 5, 10, 15)
        {6.0, 0.0},    // Distance = 6.00 -> (Fits in 10, 15)
        {0.0, 12.0},   // Distance = 12.0 -> (Fits in 15 only)
        {20.0, 20.0}   // Distance ~28.28 -> (Outside all buffers)
    };

    // 4 & 5. Determines and returns/prints the points contained in each buffer region
    analyzeBuffers(centerPoint, bufferSizes, pointsToCheck);

    return 0;
}
