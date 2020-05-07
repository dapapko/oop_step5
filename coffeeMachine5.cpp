#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class CoffeeMachine {

    int pressure; // pressure of pump
    int temperature; // temperature (used for "warming" method)
    string colour; // colour of an instance
    int numberOfCups; // number of cups (usually 1 or 2)
    bool canMakeCappuccino; // an instance can make cappuccino or not
    int price; // price of a machine
    string model; // Model of a machine (ex.: Vitek VT-1525)
    fstream file; // Type of resource for acquisition.

    // Warming the machine
    void warm(int temp) {
        while(temperature < temp) {
            temperature++;
            cout << "Warming. Current temperature is " << temperature << endl;
        }
    }

public:
    // Default constructor
    CoffeeMachine(const char* fileName = "coffee.txt")
    {
        // Resource acquisition (open file)
        file.open(fileName);
        if (file.is_open()) {
            cout << "Initialization from file" << endl;
            // Initialize object using data from file
            file >> pressure;
            file >> temperature;
            file >> colour;
            file >> numberOfCups;
            file >> canMakeCappuccino;
            file >> price;
            file >> model;
        } else {
            // Default values for initialization
            cout << "File not found. Default initialization." << endl;
            canMakeCappuccino = true;
            price = 5000;
            pressure = 15;
            colour = "black";
            temperature = 0;
            numberOfCups = 1;
            model = "Vitek VT-1525";
        }
    }

    // Copying constructor
    CoffeeMachine(const CoffeeMachine& instance):
            pressure(instance.pressure), temperature(instance.temperature),
            colour(instance.colour), numberOfCups(instance.numberOfCups),
            canMakeCappuccino(instance.canMakeCappuccino), price(instance.price),
            model(instance.model)
    {

    }

    // Release qcquired resource while calling destructor
    ~CoffeeMachine(){
        // Close file stream to release resource
        if (file.is_open()) file.close();
    }

    // Make a cup of coffee
    void makeEspresso(bool hot = false) {
        cout << "Process of making coffee started" << endl;
        warm(hot ? 120 : 100);
        // It's just a notification to show how to use fields of class
        if (!canMakeCappuccino) cout << "Attention. This instance can't make cappuccino" << endl;
        cout << "Activating pump" << endl;
        cout << "Deactivating pump" << endl;
        cout << "Your drink is ready" << endl;
    }
    // Definition of a friendly operator function.
    friend ostream &operator<<( ostream &output, const CoffeeMachine& machine );

};

// Friendly operator function
ostream &operator<<(ostream &output, const CoffeeMachine &machine) {
    output << "Pressure: " << machine.pressure << endl;
    output << "Temperature: " << machine.pressure << endl;
    output << "Colour: " << machine.pressure << endl;
    output << "Number of cups: " << machine.numberOfCups << endl;
    output << "Price: " << machine.price << endl;
    output << "Model: " << machine.model << endl;
    output << (machine.canMakeCappuccino ? "This instance can make cappuccino" : "This instance can't make cappuccino" ) << endl;
    return output;
}

int main() {
    // Default constructor
    CoffeeMachine instance1("coffee.txt");
    // Copying constructor
    CoffeeMachine instance2 = instance1;
    // Visualization
    cout << instance1 << endl;
    cout << instance2 << endl;
    // Calling public method of class
    instance1.makeEspresso();
    instance2.makeEspresso(true);
}