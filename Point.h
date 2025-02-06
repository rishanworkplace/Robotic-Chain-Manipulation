#pragma once
#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    Point() : x(0), y(0) {}

    Point(double xIn, double yIn) : x(xIn), y(yIn) {}

    void setX(double xIn) {
        x = xIn;
    }

    void setY(double yIn) {
        y = yIn;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    void printPointInfo() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};