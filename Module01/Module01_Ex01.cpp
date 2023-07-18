#include <iostream>
#include <string>

// Class representing a car
class Car
{
private:
    std::string make;  // Make of the car
    std::string model; // Model of the car
    int year;          // Year of the car

public:
    // Constructor
    Car(std::string make, std::string model, int year)
    {
        this->make = make;
        this->model = model;
        this->year = year;
    }

    // Member function to drive the car
    void drive()
    {
        std::cout << "Driving " << make << " " << model << " " << year << " edition." << std::endl;
    }
};

// Class representing a sports car, inheriting from Car class
class SportsCar : public Car
{
private:
    int topSpeed; // Top speed of the sports car

public:
    // Constructor with an additional parameter for top speed
    SportsCar(std::string make, std::string model, int year, int topSpeed) : Car(make, model, year)
    {
        this->topSpeed = topSpeed;
    }

    // Function to drive the sports car, overriding the base class function
    void drive()
    {
        drive(); // Call the base class driveBase() function
        std::cout << "Top Speed: " << topSpeed << " mph" << std::endl;
    }
};

int main()
{
    // Create an instance of the SportsCar class using the alternative constructor
    SportsCar mySportsCar("Ferrari", "488 GTB", 2023, 205);

    // Call the drive() function
    mySportsCar.drive();

    return 0;
}
