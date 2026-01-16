#include "rocket.h"
#include <iostream>
#include <vector>

void testDestructor() {
    std::cout << "\n=== Testing Destructor ===" << std::endl;
    Rocket tempRocket("Temp Rocket", 50, 5.0f);
    std::cout << "Inside testDestructor function" << std::endl;
    // tempRocket will be destroyed when function ends
} // Destructor called here!

int main() {
    std::cout << "=== Rocket Management System ===" << std::endl;
    
    // Test constructors and destructor
    Rocket rocket1;
    rocket1.setRocketName("Falcon 9");
    rocket1.setRocketSize(70);
    rocket1.setRocketSpeed(7.8f);
    
    Rocket rocket2("Starship", 120, 11.2f);
    
    // Test static method
    std::cout << "\nCurrent rocket count: " 
              << Rocket::getRocketCount() << std::endl;
    
    // Test copy constructor
    Rocket rocket3 = rocket1;  // Copy constructor
    rocket3.setRocketName("Falcon 9 Clone");
    
    // Test equality (need to add this method to Rocket class)
    std::cout << "\n=== Comparison Test ===" << std::endl;
    std::cout << "rocket1 equals rocket2? " 
              << (rocket1.isEqualTo(rocket2) ? "Yes" : "No") << std::endl;
    
    Rocket rocket4 = rocket1;  // Another copy
    std::cout << "rocket1 equals rocket4? " 
              << (rocket1.isEqualTo(rocket4) ? "Yes" : "No") << std::endl;
    
    
    // Test destructor with local scope
    {
        std::cout << "\n=== Local Scope Test ===" << std::endl;
        Rocket localRocket1("Local Rocket1", 30, 3.0f);
        Rocket localRocket2("Local Rocket2", 30, 3.0f);
        std::cout << "Inside local scope" << std::endl;
    } // localRocket destroyed here
    std::cout << "Exit local scope" << std::endl;

    std::cout << "\n=== Vector Test ===" << std::endl;
    std::vector<Rocket> rockets1;
    std::vector<Rocket> rockets2;
    // without this: vector reallocation results in multiple copies/destructions
    rockets1.reserve(2);
    rockets1.emplace_back("Voyager", 50, 17.0f);
    rockets1.emplace_back("Apollo", 85, 8.5f);
    
    std::cout << "\n=== without reserve ===" << std::endl;
    rockets2.emplace_back("Voyager", 50, 17.0f);
    rockets2.emplace_back("Apollo", 85, 8.5f);
    

    std::cout << "\n=== Display Vector Rockets ===" << std::endl;
    for (const auto& rocket : rockets1) {
        rocket.displayRocketInfo();
    }
    
    // Test destructor function
    testDestructor();
    
    std::cout << "\n=== Final State ===" << std::endl;
    std::cout << "Final rocket count: " 
              << Rocket::getRocketCount() << std::endl;
    
    // All rockets will be destroyed when main() ends
    return 0;
}