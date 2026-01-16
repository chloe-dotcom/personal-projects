#include "rocket.h"
#include <iostream>
#include <string>

int Rocket::rocketCount = 0;

// constructors

Rocket::Rocket(): rocketName("Unknown"), rocketSize(0), rocketSpeed(0.0f) {
    rocketCount++;
    std::cout << "Default constructor called. Total rockets: " << rocketCount << std::endl;
}

Rocket::Rocket(const std::string& name, int size, float speed):
    rocketName(name), rocketSize(size), rocketSpeed(speed) {
        rocketCount++;
        std::cout << "Parameterized "<< rocketName <<  " @" << std::hex << this << ". Total rockets: " << rocketCount << std::endl;
}

Rocket::Rocket(const Rocket& other)
    : rocketName(other.rocketName), rocketSize(other.rocketSize), rocketSpeed(other.rocketSpeed) {
        rocketCount++;
        std::cout << "Copy constructor "<< rocketName <<  " @" << std::hex << this <<  ". Total rockets: " << rocketCount << std::endl;
}

// destructor
Rocket::~Rocket(){
    rocketCount--;
    std::cout << "Destructor called for " << rocketName <<  " @" << std::hex << this << ". Remaining rockets: " << rocketCount << std::endl;
}

// int Rocket::getRocketCount() {
//     return rocketCount;
// }

// getters
std::string Rocket::getRocketName() const {
    return rocketName;
}

int Rocket::getRocketSize() const {
    return rocketSize;
}
float Rocket::getRocketSpeed() const {
    return rocketSpeed;
}

// setters
void Rocket::setRocketName(const std::string& name) {
    rocketName = name;
}
void Rocket::setRocketSize(int size) {
    if (size >= 0) {
        rocketSize = size;
    } else {
        std::cout << "Error: Rocket Size cannot be negative!" << std::endl;
    }
}
void Rocket::setRocketSpeed(float speed){
    if (speed >= 0) {
        rocketSpeed = speed;
    } else {
        std::cout << "Error: Rocket Speed cannot be negative!" << std::endl;
    }
}

// display
void Rocket::displayRocketInfo() const {
    std::cout << "======Rocket Information======" << std::endl;
    std::cout << "Name: " << rocketName << std::endl;
    std::cout << "Size: " << rocketSize << "m" << std::endl;
    std::cout << "Speed: " << rocketSpeed << "km/s" << std::endl;
    std::cout << "==============================" << std::endl;
}

bool Rocket::isEqualTo(const Rocket& other) const {
    return (rocketName == other.rocketName && 
            rocketSize == other.rocketSize && 
            rocketSpeed == other.rocketSpeed);
}