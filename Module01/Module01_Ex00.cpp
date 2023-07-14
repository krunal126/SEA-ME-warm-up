#include <iostream> // Include the input/output stream library
#include <string>   // Include the string library for using strings

using namespace std; // Use the std namespace for convenience

// Car class definition
class Car
{
private:
    string name; // Member variable to store the name of the Car
    int speed;   // Member variable to store the speed of the Car

public:
    // Default constructor
    Car()
    {

        name = ""; // Initialize name to an empty string
        speed = 0; // Initialize speed to 0
    }

    // Constructor with parameters
    Car(const string &carName, int carSpeed)
    {
        name = carName;   // Assign the carName to the name member variable
        speed = carSpeed; // Assign the carSpeed to the speed member variable
    }
    // Copy constructor
    Car(const Car &other)
    {

        name = other.name;   // Copy the name from the other Car object
        speed = other.speed; // Copy the speed from the other Car object
    }
    // Copy assignment operator
    Car &operator=(const Car &other)
    {

        name = other.name;   // Copy the name from the other Car object
        speed = other.speed; // Copy the speed from the other Car object

        return *this; // Return the current Car object
    }
    // Destructor
    ~Car()
    {
        cout << "Destroying car: " << name << endl; // Print a message indicating the destruction of the Car object
    }

    // Getter for name
    string getName() const
    {
        return name; // Return the name of the Car object
    }

    // Getter for speed
    int getSpeed() const
    {
        return speed; // Return the speed of the Car object
    }
};

// Main function
int main()
{
    Car car1;                                                                         // Create a Car object using the default constructor
    cout << "Car name: " << car1.getName() << ", Speed: " << car1.getSpeed() << endl; // Print the name and speed of car1

    Car car2("Sports Car", 200);                                                      // Create a Car object using the parameterized constructor
    cout << "Car name: " << car2.getName() << ", Speed: " << car2.getSpeed() << endl; // Print the name and speed of car2

    Car car3 = car2;                                                                  // Create a Car object using the copy constructor and initialize it with car2
    cout << "Car name: " << car3.getName() << ", Speed: " << car3.getSpeed() << endl; // Print the name and speed of car3

    Car car4;                                                                         // Create a Car object using the default constructor
    car4 = car3;                                                                      // Use the copy assignment operator to assign the values of car3 to car4
    cout << "Car name: " << car4.getName() << ", Speed: " << car4.getSpeed() << endl; // Print the name and speed of car4

    return 0; // Exit the program with a success status
}
