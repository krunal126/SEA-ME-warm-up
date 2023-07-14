#include <iostream>
#include <string>

// Abstract base class representing a Car
class Car
{
private:
    std::string make;  // Make of the car
    std::string model; // Model of the car
    int year;          // Year of the car

public:
    // Constructor
    Car(const std::string &make, const std::string &model, int year)
        : make(make), model(model), year(year)
    {
    }

    // Pure virtual functions to be overridden by derived classes
    virtual void drive() = 0; // Pure virtual function for driving the car
    virtual void honk() = 0;  // Pure virtual function for honking the car

    // Getter functions
    std::string getMake() const
    {
        return make;
    }

    std::string getModel() const
    {
        return model;
    }

    int getYear() const
    {
        return year;
    }

    // Virtual destructor to allow polymorphic deletion
    virtual ~Car()
    {
    }
};

// Derived class representing a Sports Car
class SportsCar : virtual public Car
{
private:
    int topSpeed; // Top speed of the sports car

public:
    // Constructor
    SportsCar(const std::string &make, const std::string &model, int year, int topSpeed)
        : Car(make, model, year), topSpeed(topSpeed)
    {
    }

    // Overridden function to drive the sports car
    void drive() override
    {
        std::cout << "Driving " << getMake() << " " << getModel() << " " << getYear() << " edition." << std::endl;
        std::cout << "Top Speed: " << topSpeed << " mph" << std::endl;
    }

    // Overridden function to honk the sports car
    void honk() override
    {
        std::cout << "Car sound: Roar!" << std::endl;
    }

    int getTopSpeed() const
    {
        return topSpeed;
    }
};

// Derived class representing an Electric Car
class ElectricCar : virtual public Car
{
private:
    int topSpeed; // Top speed of the electric car

public:
    // Constructor
    ElectricCar(const std::string &make, const std::string &model, int year, int topSpeed)
        : Car(make, model, year), topSpeed(topSpeed)
    {
    }

    // Overridden function to drive the electric car
    void drive() override
    {
        std::cout << "Driving " << getMake() << " " << getModel() << " " << getYear() << " edition." << std::endl;
        std::cout << "Top Speed: " << topSpeed << " mph" << std::endl;
    }

    // Overridden function to honk the electric car
    void honk() override
    {
        std::cout << "Car sound: Vroom Vroom!" << std::endl;
    }
};

// Derived class representing a Sports Electric Car, combining features of both sports car and electric car
class SportElectricCar : public SportsCar, public ElectricCar
{
public:
    // Constructor
    SportElectricCar(const std::string &make, const std::string &model, int year, int topSpeed)
        : Car(make, model, year), SportsCar(make, model, year, topSpeed), ElectricCar(make, model, year, topSpeed)
    {
    }

    // Overridden function to drive the sports electric car
    void drive() override
    {
        std::cout << "Driving Sport Electric Car: " << getMake() << " " << getModel() << " " << getYear() << " edition." << std::endl;
        std::cout << "Top Speed: " << SportsCar::getTopSpeed() << " mph" << std::endl;
    }

    // Overridden function to honk the sports electric car
    void honk() override
    {
        std::cout << "Car sound: Roar! Vroom Vroom!" << std::endl;
    }
};

int main()
{
    // Create an instance of SportElectricCar
    SportElectricCar sportElectricCar("Tesla", "Model S", 2023, 250);

    std::cout << "Car Details:" << std::endl;
    std::cout << "Make: " << sportElectricCar.getMake() << std::endl;
    std::cout << "Model: " << sportElectricCar.getModel() << std::endl;
    std::cout << "Year: " << sportElectricCar.getYear() << std::endl;

    std::cout << std::endl;

    // Call the drive() and honk() functions of SportElectricCar
    sportElectricCar.drive();
    sportElectricCar.honk();

    return 0;
}
