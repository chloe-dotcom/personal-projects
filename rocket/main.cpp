#include "rocket.h"
#include <iostream>


void testReferenceVsPointers() {
    std::cout << "\n\n ----- TEST 1: Reference vs Pointers -----" << std::endl;
    Rocket rocket("SpaceX", 110, 9.7f);

    Rocket* rocketPtr = &rocket;
    std::cout << "Pointer: " << rocketPtr->getRocketName() << " at address: " << rocketPtr << std::endl;

    Rocket& rocketRef = rocket;
    std::cout << "Reference: " << rocketRef.getRocketName() << " at same address: " << &rocketRef << std::endl;

    rocketPtr->setRocketName("Tesla (modified by Pointer)");
    std::cout << "After Pointer Modification: " <<rocket.getRocketName() << std::endl;

    rocketRef.setRocketName("Tesla (modified by Reference)");
    std::cout << "After Reference Modification: " << rocket.getRocketName() << std::endl;

    Rocket* nullRocketPtr = nullptr;
    if (!nullRocketPtr) {
        std::cout << "Null pointer checked" << std::endl;
    }

}

int main() {
    testReferenceVsPointers();

    std::cout << "\n------------------------\n" << std::endl;

    return 0;
}