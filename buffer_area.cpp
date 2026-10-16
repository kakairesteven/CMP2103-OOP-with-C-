#include <iostream>
#include <cmath>

// Structure to define a coordinate point
struct Point {
    double x;
    double y;
};

// Function to calculate the Euclidean distance between two points 
double calculateDistance(Point p1, Point p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

int main() {
    // 1. Define the specific center point coordinate
    Point centerPoint = {0.0, 0.0};

    // 2. Define a given set of points to check
    Point pointSet[] = {
        {0.5, 0.5},
        {1.2, 1.0},
        {2.0, 2.5},
        {3.1, 4.0}
    };
    int totalPoints = sizeof(pointSet) / sizeof(pointSet[0]);

    // 3. Define the different buffer sizes to test
    double bufferSizes[] = {1.0, 3.0, 5.0};
    int totalBuffers = sizeof(bufferSizes) / sizeof(bufferSizes[0]);

    // 4. Check which points lie inside each buffer size
    for (int i = 0; i < totalBuffers; i++) {
        double currentBuffer = bufferSizes[i];
        std::cout << "Points within a buffer size of " << currentBuffer << ":\n";

        for (int j = 0; j < totalPoints; j++) {
            double distance = calculateDistance(centerPoint, pointSet[j]);
            
            // If distance is less than or equal to the buffer size, it lies inside
            if (distance <= currentBuffer) {
                std::cout << " - Point at (" << pointSet[j].x << ", " << pointSet[j].y << ")\n";
            }
        }
        std::cout << "\n";
    }

    return 0;
}