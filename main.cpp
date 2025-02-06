#include <iostream>
#include <cmath>
#include <iomanip>
#include "Point.h"
#include "Segment.h"
#include "Robot.h"

using namespace std;

int main() {
    int numOfSegmentsIn;

    do {
        cout << "Enter number of segments (including root segment): ";
        cin >> numOfSegmentsIn;
        cout << endl;
    } while (numOfSegmentsIn <= 0);

    Robot R1(numOfSegmentsIn);
    R1.getNumOfSegments(numOfSegmentsIn);
    R1.initializeRobot();
    R1.getMenu();

    return 0;
}