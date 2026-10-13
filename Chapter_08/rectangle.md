# `rectangle.cpp`

## Overview
This program defines a `Rectangle` class that stores a rectangle's width and length, then calculates and displays its area and perimeter.

## OOP Concepts Used
- Classes and objects
- Encapsulation using private data members
- Constructors with default arguments
- Public setter and getter methods
- `const` member functions

## Class Design

### `Rectangle`
- Stores `width` and `length` as private `double` data members.
- Its constructor accepts optional width and length values, both initialized to `0`.
- `setWidth()` and `setLength()` update a dimension only when the supplied value is greater than zero.
- `getWidth()` and `getLength()` are private helper methods used inside the class.
- `getArea()` returns `width * length`.
- `getPerimeter()` returns `2*(width + length)`.

## Algorithm
1. Create a `Rectangle` object with the default dimensions.
2. Set its width to `5.5` and its length to `10.0`,this is under the int main funcion.
3. Calculate and print the area and perimeter.
4. End the program.

## Output
```text
The dimensions of the rectangle 5.5 x 10.0.
Area:55
Perimeter:31
```

## Possible Error Points
- End the class definition with `};` so the declaration is properly terminated.
- Call member functions with parentheses, such as `r.getArea()` and `r.getPerimeter()`.
- The setters ignore values that are zero or negative.