#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, x3, y3;
    double side1, side2, side3;
    double s, area;

    // Enter the three points
    printf("Enter three points for a triangle: ");
    scanf("%lf %lf %lf %lf %lf %lf",
          &x1, &y1, &x2, &y2, &x3, &y3);

    // Calculate the three sides
    side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));

    side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // Calculate s
    s = (side1 + side2 + side3) / 2;

    // Calculate area
    area = sqrt(s * (s - side1) *
                    (s - side2) *
                    (s - side3));

    // Display the result
    printf("The area of the triangle is %.1f\n", area);

    return 0;
}