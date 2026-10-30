// A buffer region is an area created around a geographic feature at a specified distance.
// For example, a 1 km buffer around a water point represents all areas located within 1 km of that water source.
// Buffers can be created around points, lines, or polygons and are commonly used in GIS for proximity and spatial analysis.

// Write a program that creates buffers of different sizes around a specific point coordinate and returns the points in a given set that lie within each buffer.
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

// Structure to represent a 2D point coordinate (X, Y)
struct Point {
    std::string name;
    double x;
    double y;
};

// Function to calculate Euclidean distance between two points
double calculateDistance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

// Function to filter points within a specified buffer radius
std::vector<Point> getPointsInBuffer(const Point& center, const std::vector<Point>& points, double radius) {
    std::vector<Point> insideBuffer;
    
    for (const auto& p : points) {
        if (calculateDistance(center, p) <= radius) {
            insideBuffer.push_back(p);
        }
    }
    
    return insideBuffer;
}

int main() {
    // 1. Define the center location (e.g., Water Point at coordinates 0.0, 0.0)
    Point centerPoint = {"Center Source", 0.0, 0.0};

    // 2. Sample dataset of points to evaluate
    std::vector<Point> dataset = {
        {"Point A", 0.5, 0.5},   // Distance ~0.71 units
        {"Point B", 1.2, 0.8},   // Distance ~1.44 units
        {"Point C", 2.0, 1.5},   // Distance ~2.50 units
        {"Point D", -0.3, 0.4},  // Distance ~0.50 units
        {"Point E", 3.0, 4.0}    // Distance ~5.00 units
    };

    // 3. Define different buffer sizes (radii) around the center
    std::vector<double> bufferRadii = {1.0, 2.0, 3.0};

    // 4. Process each buffer size and display the contained points
    std::cout << "--- Buffer Analysis around (" << centerPoint.x << ", " << centerPoint.y << ") ---\n\n";

    for (double radius : bufferRadii) {
        std::cout << "Buffer Radius: " << radius << " units\n";
        
        std::vector<Point> pointsInside = getPointsInBuffer(centerPoint, dataset, radius);

        if (pointsInside.empty()) {
            std::cout << "  No points found within this buffer region.\n";
        } else {
            std::cout << "  Points inside buffer:\n";
            for (const auto& p : pointsInside) {
                double dist = calculateDistance(centerPoint, p);
                std::cout << "   - " << p.name << " (" << p.x << ", " << p.y 
                          << ") | Distance: " << dist << "\n";
            }
        }
        std::cout << "\n----------------------------------------\n";
    }

    return 0;
}