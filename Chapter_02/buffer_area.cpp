// A buffer region is an area created around a geographic feature at a specified distance.
// For example, a 1 km buffer around a water point represents all areas located within 1 km of that water source.
// Buffers can be created around points, lines, or polygons and are commonly used in GIS for proximity and spatial analysis.

// Write a program that creates buffers of different sizes around a specific point coordinate and returns the points in a given set that lie within each buffer.
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// A simple structure to hold X and Y coordinates
struct Point {
    double x;
    double y;
};

// Function to create a circular buffer around a center point
// center: The original starting point
// radius: How big the buffer zone is
// pointsCount: How many points to use to draw the circle (more points = smoother circle)
std::vector<Point> createBuffer(Point center, double radius, int pointsCount) {
    std::vector<Point> bufferPoints;
    const double PI = 3.14159265358979323846;

    for (int i = 0; i < pointsCount; ++i) {
        // Calculate the angle for this specific point on the circle
        double angle = (2.0 * PI * i) / pointsCount;

        Point p;
        // Use trigonometry (cos and sin) to find the boundary coordinates
        p.x = center.x + (radius * cos(angle));
        p.y = center.y + (radius * sin(angle));

        bufferPoints.push_back(p);
    }

    return bufferPoints;
}

int main() {
    // 1. Define our specific starting coordinate point
    Point centerPoint = {5.0, 5.0}; 
    std::cout << "Center Point: (" << centerPoint.x << ", " << centerPoint.y << ")\n\n";

    // 2. Define the different sizes of buffers we want (radii)
    std::vector<double> bufferSizes = {1.5, 3.0, 5.0}; 
    
    // How detailed we want the circular boundary to be (number of sides)
    int smoothness = 8; 

    // Set output format for clean decimals
    std::cout << std::fixed << std::setprecision(2);

    // 3. Loop through each buffer size and calculate the boundary points
    for (double size : bufferSizes) {
        std::cout << "=========================================\n";
        std::cout << " CREATING BUFFER ZONE WITH SIZE (RADIUS): " << size << "\n";
        std::cout << "=========================================\n";

        std::vector<Point> boundary = createBuffer(centerPoint, size, smoothness);

        // Print out the coordinates for this buffer ring
        for (size_t i = 0; i < boundary.size(); ++i) {
            std::cout << "Boundary Point " << (i + 1) << ": (" 
                      << boundary[i].x << ", " << boundary[i].y << ")\n";
        }
        std::cout << "\n";
    }

    return 0;
}
