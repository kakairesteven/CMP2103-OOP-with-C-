#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Structure to represent a point
struct Point {
    double x;
    double y;
};

// Function to calculate distance between two points
double calculateDistance(Point center, Point point) {
    return sqrt(
        pow(point.x - center.x, 2) +
        pow(point.y - center.y, 2)
    );
}

int main() {

    // 1. Enter the center point
    Point center;

    cout << "Enter center X coordinate: ";
    cin >> center.x;

    cout << "Enter center Y coordinate: ";
    cin >> center.y;


    // 2. Enter buffer sizes
    int numberOfBuffers;

    cout << "\nEnter number of buffers: ";
    cin >> numberOfBuffers;

    vector<double> buffers(numberOfBuffers);

    for (int i = 0; i < numberOfBuffers; i++) {
        cout << "Enter size of buffer " << i + 1 << " (km): ";
        cin >> buffers[i];
    }


    // 3. Enter the points
    int numberOfPoints;

    cout << "\nEnter number of points: ";
    cin >> numberOfPoints;

    vector<Point> points(numberOfPoints);

    for (int i = 0; i < numberOfPoints; i++) {
        cout << "\nEnter coordinates for Point " << i + 1 << endl;

        cout << "X: ";
        cin >> points[i].x;

        cout << "Y: ";
        cin >> points[i].y;
    }


    // 4. Determine which points fall within each buffer
    cout << "\n========== BUFFER ANALYSIS ==========\n";

    for (int i = 0; i < numberOfBuffers; i++) {

        cout << "\nPoints within " << buffers[i] << " km buffer:\n";

        bool found = false;

        for (int j = 0; j < numberOfPoints; j++) {

            double distance = calculateDistance(center, points[j]);

            if (distance <= buffers[i]) {

                cout << "Point " << j + 1
                     << " (" << points[j].x
                     << ", " << points[j].y << ")";

                cout << " - Distance = "
                     << distance << " km\n";

                found = true;
            }
        }

        if (!found) {
            cout << "No points found in this buffer.\n";
        }
    }

    return 0;
}