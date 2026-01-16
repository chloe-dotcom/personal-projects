#include "rocket.h"
#include <iostream>


void testReferenceVsPointers() {
    std::cout << "\n\n ----- TEST 1: Reference vs Pointers -----" << std::endl;
    Rocket rocket("SpaceX", 110, 9.7f);

    Rocket* rocketPtr = &rocket;
    std::cout << "Pointer: " << rocketPtr->getRocketName() << " at address: " << rocketPtr << std::endl;

    Rocket& rocketRef = rocket;
    std::cout << "Reference: " << rocketRef.getRocketName() << " at same address: " << &rocketRef << std::endl;

}

void testCopyVsMove() {
    std::cout << "\n\n ----- TEST 2: Copy vs Move -----" << std::endl;

    // COPY ASSIGNMENT
    Rocket rocketA("Rocket A", 50, 5.0f);
    Rocket rocketB("Rocket B", 60, 6.0f);
    rocketA = rocketB;  // Copy assignment
    std::cout << "\nAfter copy assignment:" << std::endl;
    std::cout << "@" << &rocketA << ". Rocket A: " << rocketA.getRocketName() << std::endl;
    
    // MOVE ASSIGNMENT
    Rocket rocketC("Rocket C", 70, 7.0f);
    rocketC = std::move(rocketB);  // Move assignment
    std::cout << "\nAfter move assignment:" << std::endl;
    std::cout << "@" << &rocketC << ". Rocket C: " << rocketC.getRocketName() << std::endl;
    std::cout << "@" << &rocketB << ". Rocket B (moved from): " << rocketB.getRocketName() << std::endl;
}

int main() {
    // testReferenceVsPointers();
    testCopyVsMove();

    std::cout << "\n------------------------\n" << std::endl;

    return 0;
}