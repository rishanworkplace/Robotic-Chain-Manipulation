#pragma once
#include "Point.h"
#include <cmath>
#include <iostream>

class Segment {
private:
    Point startPoint;
    double length;
    double angle;
    Point endPoint;

    Point calculateEndPoint(const Point& another, double lengthIn, double angleIn) {
        Point setEndPoint;
        setEndPoint.setX(another.getX() + lengthIn * cos(angleIn));
        setEndPoint.setY(another.getY() + lengthIn * sin(angleIn));
        return setEndPoint;
    }

public:
    Segment() : startPoint(), length(0.0), angle(0.0) {
        endPoint = calculateEndPoint(startPoint, length, angle);
    }

    Segment(double lengthIn, double angleIn) : startPoint(0, 0), length(lengthIn), angle(angleIn) {
        endPoint = calculateEndPoint(startPoint, length, angle);
    }

    Segment(const Segment& another, double lengthIn, double angleIn) 
        : startPoint(another.endPoint), length(lengthIn), angle(angleIn) {
        endPoint = calculateEndPoint(startPoint, length, angle);
    }

    void setStartPoint(const Point& another) {
        startPoint = another;
        endPoint = calculateEndPoint(startPoint, length, angle);
    }

    void setAngle(double angleIn) {
        angle = angleIn;
        endPoint = calculateEndPoint(startPoint, length, angle);
    }

    void setLength(double lengthIn) {
        length = lengthIn;
        endPoint = calculateEndPoint(startPoint, length, angle);
    }

    Point getStartPoint() const {
        return startPoint;
    }

    double getLength() const {
        return length;
    }

    double getAngle() const {
        return angle;
    }

    Point getEndPoint() const {
        return endPoint;
    }

    void printSegmentInfo() const {
        std::cout << "Segment Start Point: (" << startPoint.getX() << "," << startPoint.getY() << ")" << std::endl;
        std::cout << "Segment Length: " << length << std::endl;
        std::cout << "Segment Angle (in radians, with reference to x-axis): " << angle << std::endl;
        std::cout << "Segment End Point: (" << endPoint.getX() << "," << endPoint.getY() << ")" << std::endl;
    }
};