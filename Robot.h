#pragma once
#include "Segment.h"
#include <iostream>

class Robot {
private:
    static int numOfSegments;
    Segment* segmentPtr;
    char option;

public:
    Robot(int numOfSegmentsIn) {
        segmentPtr = new Segment[numOfSegmentsIn];
    }

    void getNumOfSegments(int numOfSegmentsIn) {
        numOfSegments = numOfSegmentsIn;
    }

    void initializeRobot() {
        for (int i = 0; i < numOfSegments; i++) {
            double tempLength, tempAngle;

            do {
                std::cout << "Enter length and angle (in radians, in relation to positive x-axis) for segment " << (i + 1) << " :" << std::endl;
                std::cin >> tempLength >> tempAngle;
                std::cout << std::endl;
                if (tempLength <= 0) {
                    std::cout << "Invalid length" << std::endl;
                }
            } while (tempLength <= 0);

            if (i == 0) {
                segmentPtr[i] = Segment(tempLength, tempAngle);
            } else {
                segmentPtr[i] = Segment(segmentPtr[i - 1], tempLength, tempAngle);
            }
        }

        std::cout << "Robot initialized successfully" << std::endl;
    }

    void printChainPose() {
        Point* coordinatePtr = new Point[numOfSegments + 1];
        coordinatePtr[0] = Point(0, 0);

        for (int i = 0; i < numOfSegments; i++) {
            coordinatePtr[i + 1] = segmentPtr[i].getEndPoint();
        }

        for (int i = 0; i < numOfSegments + 1; i++) {
            double tempX = coordinatePtr[i].getX();
            double tempY = coordinatePtr[i].getY();
            std::cout << "(" << tempX << ", " << tempY << ")" << std::endl;
        }

        delete[] coordinatePtr;
    }

    void addSegment() {
        Segment* tempPtr = new Segment[numOfSegments + 1];

        for (int i = 0; i < numOfSegments; i++) {
            tempPtr[i] = segmentPtr[i];
        }

        double tempLength, tempAngle;

        do {
            std::cout << "Enter length and angle (in radians, in relation to positive x-axis) for the new segment: " << std::endl;
            std::cin >> tempLength >> tempAngle;
            std::cout << std::endl;
            if (tempLength <= 0) {
                std::cout << "Invalid length" << std::endl;
            }
        } while (tempLength <= 0);

        tempPtr[numOfSegments] = Segment(tempPtr[numOfSegments - 1], tempLength, tempAngle);
        delete[] segmentPtr;
        segmentPtr = tempPtr;
        numOfSegments++;

        std::cout << "Segment successfully added" << std::endl;
    }

    void removeSegment() {
        if (numOfSegments <= 0) {
            std::cout << "No segments to remove." << std::endl;
            return;
        }

        Segment* tempPtr = new Segment[numOfSegments - 1];

        for (int i = 0; i < numOfSegments - 1; i++) {
            tempPtr[i] = segmentPtr[i];
        }

        delete[] segmentPtr;
        segmentPtr = tempPtr;
        numOfSegments--;

        std::cout << "Segment successfully removed" << std::endl;
    }

    void defaultPosition() {
        for (int i = 0; i < numOfSegments; i++) {
            segmentPtr[i].setAngle(0);
        }
        std::cout << "Robot chain reset to default position" << std::endl;
    }

    void forwardKinematics() {
        Point endEffector;
        double tempX = 0, tempY = 0;

        for (int i = 0; i < numOfSegments; i++) {
            double length = segmentPtr[i].getLength();
            double angle = segmentPtr[i].getAngle();
            tempX += length * cos(angle);
            tempY += length * sin(angle);
        }

        endEffector.setX(tempX);
        endEffector.setY(tempY);

        std::cout << "The end effector site's co-ordinates are: " << std::endl;
        endEffector.printPointInfo();
    }

    void getMenu() {
        do {
            std::cout << "Choose an option: " << std::endl;
            std::cout << "1. Print current status of robot chain" << std::endl;
            std::cout << "2. Add segment to robot chain" << std::endl;
            std::cout << "3. Remove segment from robot chain" << std::endl;
            std::cout << "4. Move robot chain to default position" << std::endl;
            std::cout << "5. Perform Forward Kinematics Analysis" << std::endl;
            std::cout << "6. Exit Program" << std::endl;

            std::cin >> option;

            switch (option) {
                case '1': printChainPose(); break;
                case '2': addSegment(); break;
                case '3': removeSegment(); break;
                case '4': defaultPosition(); break;
                case '5': forwardKinematics(); break;
                case '6': std::cout << "Exiting program" << std::endl; break;
                default: std::cout << "Invalid input" << std::endl; break;
            }
        } while (option != '6');
    }

    ~Robot() {
        delete[] segmentPtr;
    }
};

int Robot::numOfSegments = 0;