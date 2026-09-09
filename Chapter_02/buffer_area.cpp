#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Point {
    double lat;
    double lon;
    std::string name;
};

const double EARTH_R = 6371.0;

double toRad(double deg) {
    return deg * M_PI / 180.0;
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dlat = toRad(lat2 - lat1);
    double dlon = toRad(lon2 - lon1);
    double a = sin(dlat/2)*sin(dlat/2) +
               cos(toRad(lat1)) * cos(toRad(lat2)) *
               sin(dlon/2)*sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EARTH_R * c;
}

std::map<double, std::vector<std::pair<Point, double>>>
getPointsInBuffers(Point center, std::vector<double> radii, std::vector<Point> points) {
    std::sort(radii.begin(), radii.end());
    std::map<double, std::vector<std::pair<Point, double>>> result;
    for (double r : radii) result[r] = {};
    for (auto &p : points) {
        double dist = haversine(center.lat, center.lon, p.lat, p.lon);
        for (double r : radii) {
            if (dist <= r) result[r].push_back({p, dist});
        }
    }
    return result;
}

int main() {
    Point center = {0.3359, 32.5687, "Makerere, Kampala"};
    std::vector<double> buffers = {1.0, 3.0, 5.0};
    std::vector<Point> points = {
        {0.3365, 32.5710, "Wandegeya Market"},
        {0.3476, 32.5825, "Kampala Road"},
        {0.3136, 32.5811, "Kabalagala"},
        {0.3400, 32.5690, "Makerere Main"}
    };
    auto result = getPointsInBuffers(center, buffers, points);
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Center: " << center.name << "\n";
    for (auto &pair : result) {
        std::cout << "\n--- Buffer " << pair.first << " km : " << pair.second.size() << " points ---\n";
        for (auto &item : pair.second) {
            std::cout << " - " << item.first.name << " -> " << item.second << " km\n";
        }
    }
    return 0;
}