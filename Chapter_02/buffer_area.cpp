#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
struct Point {
    int id;
    double x;
    double y;
};

// Calculate Euclidean distance between two points
double calculateDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    // Define the central location
    Point center = {0, 0.0, 0.0};

    // Define buffer radii to evaluate
     vector<double> bufferRadii = {1.0, 2.5, 5.0};

    // Sample set of points to check
    vector<Point> points = {
        {1, 0.5, 0.5},   // Distance ~0.71
        {2, 1.5, 2.0},   // Distance ~2.50
        {3, 3.0, 4.0},   // Distance 5.00
        {4, 4.0, 4.0}    // Distance ~5.66 (Outside all buffers)
    };

    cout << "Center Point: (" << center.x << ", " << center.y << ")\n\n";

    // Evaluate points for each buffer radius
    for (double radius : bufferRadii) {
        cout << "--- Buffer Radius: " << radius << " units ---\n";
        
        bool foundAny = false;
        for (const auto& pt : points) {
            double dist = calculateDistance(center, pt);
            
            // Check if the point falls within or on the buffer boundary
            if (dist <= radius) {
                cout << "  Point " << pt.id << " (" << pt.x << ", " << pt.y 
                          << ") - Distance: " << fixed << setprecision(2) << dist << "\n";
                foundAny = true;
            }
        }

        if (!foundAny) {
            cout << "  No points found within this buffer.\n";
        }
        cout << "\n";
    }

    return 0;
}