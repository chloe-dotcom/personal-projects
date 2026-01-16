#include <string>
#pragma once

class Rocket {
    private:
        std::string rocketName;
        int rocketSize;
        float rocketSpeed;
        static int rocketCount;

    public:
        // constructors
        Rocket();
        Rocket(const std::string& name, int size, float speed);
        Rocket(const Rocket& other); // copy constructor
        ~Rocket(); // destructor

        // getters
        std::string getRocketName() const;
        int getRocketSize() const;
        float getRocketSpeed() const;
        static int getRocketCount() { return rocketCount; }

        // setters
        void setRocketName(const std::string& name);
        void setRocketSize(int size);
        void setRocketSpeed(float speed);

        // display
        void displayRocketInfo() const;

        bool isEqualTo(const Rocket& other) const;


};


