#include <iostream>
#include <string>

using namespace std;

// Base class representing a car part
class Part
{
protected:
    string name;

public:
    // Constructor
    Part(const string &partName)
        : name(partName)
    {
    }

    // Pure virtual function to print part details
    virtual void print() = 0;
};

// Derived classes representing specific car parts

class Engine : public Part
{
public:
    // Constructor
    Engine(const string &partName = "Engine")
        : Part(partName)
    {
    }

    void print() override
    {
        cout << "Assembling the " << name << endl;
        // Code to assemble the engine
    }
};

class Wheel : public Part
{
public:
    // Constructor
    Wheel(const string &partName = "Wheel")
        : Part(partName)
    {
    }

    void print() override
    {
        cout << "Assembling the " << name << endl;
        // Code to assemble the wheel
    }
};

class Brake : public Part
{
public:
    // Constructor
    Brake(const string &partName = "Brake")
        : Part(partName)
    {
    }

    void print() override
    {
        cout << "Assembling the " << name << endl;
        // Code to assemble the brake
    }
};

class Door : public Part
{
public:
    // Constructor
    Door(const string &partName = "Door")
        : Part(partName)
    {
    }

    void print() override
    {
        cout << "Assembling the " << name << endl;
        // Code to assemble the door
    }
};

// Additional derived classes representing more car parts

class Seat : public Part
{
public:
    // Constructor
    Seat(const string &partName = "Seat")
        : Part(partName)
    {
    }

    void print() override
    {
        cout << "Assembling the " << name << endl;
        // Code to assemble the seat
    }
};

class Dashboard : public Part
{
public:
    // Constructor
    Dashboard(const string &partName = "Dashboard")
        : Part(partName)
    {
    }

    void print() override
    {
        cout << "Assembling the " << name << endl;
        // Code to assemble the dashboard
    }
};

class Transmission : public Part
{
public:
    // Constructor
    Transmission(const string &partName = "Transmission")
        : Part(partName)
    {
    }

    void print() override
    {
        cout << "Assembling the " << name << " part." << endl;
        // Code to assemble the transmission
    }
};

class Suspension : public Part
{
public:
    // Constructor
    Suspension(const string &partName = "Suspension")
        : Part(partName)
    {
    }

    void print() override
    {
        cout << "Assembling the " << name << " part." << endl;
        // Code to assemble the suspension
    }
};

class Window : public Part
{
public:
    // Constructor
    Window(const string &partName = "Window")
        : Part(partName)
    {
    }

    void print() override
    {
        cout << "Assembling the " << name << " part." << endl;
        // Code to assemble the window
    }
};

// Add more derived classes representing additional car parts

class Car
{
private:
    Engine *engine;
    Wheel *wheels;
    Brake *brakes;
    Door *doors;
    Window *windows;
    Suspension *suspensions;
    Seat *seats;
    Dashboard *dashboard;
    Transmission *transmission;

public:
    // Constructor
    Car()
    {
        engine = new Engine();
        wheels = new Wheel[4];
        brakes = new Brake[4];
        doors = new Door[4];
        windows = new Window[6];
        suspensions = new Suspension[2];
        seats = new Seat[4];
        dashboard = new Dashboard();
        transmission = new Transmission();
    }

    // Function to print the assembly of car parts
    void printParts(string &s)
    {
        cout << "Assembling the car "
             << " " << s << endl;

        engine->print();

        for (int i = 0; i < 4; i++)
        {
            wheels[i].print();
            brakes[i].print();
            doors[i].print();
            seats[i].print();
        }

        // Assemble additional parts
        for (int i = 0; i < 2; i++)
        {
            suspensions[i].print();
        }
        transmission->print();
        dashboard->print();
        for (int i = 0; i < 6; i++)
        {
            windows[i].print();
        }

        cout << s << " "
             << " assembly completed!" << endl;
    }

    // Destructor
    ~Car()
    {
        delete engine;
        delete[] wheels;
        delete[] brakes;
        delete[] doors;
        delete[] windows;
        delete[] suspensions;
        delete[] seats;
        delete dashboard;
        delete transmission;
    }
};

int main()
{
    // Create an instance of Car
    Car c1;
    string s1;
    cout << "Enter Car Name that you want to assemble:";
    cin >> s1;

    // Print the assembly of car parts
    c1.printParts(s1);

    return 0;
}
