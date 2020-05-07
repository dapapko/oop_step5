#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Tiger
{
    int age; // Age of tiger
    int size; // Size of tiger (in metres)
    int speed; // Speed of tiger (metres per second)
    string breed; // Breed (Bengal, Amur or smth like that)
    string skinColour; // Colour of skin (black, white or orange)
    bool isHungry; // A tiger can be hungry or not
    fstream file; // Resource for acquisition

    // running
    void run(int t_speed) {
        speed = t_speed;
        cout << "The tiger is running. Speed: " << t_speed << endl;
    }
    
public:
    // Friendly operator function for output. Definition.
    friend ostream &operator<<( ostream &output, const Tiger& T );
    // hunting
    void hunt(int t_speed = 30) {
        if (!isHungry) cout << "Tiger is not hungry, so he don't hunt" << endl;
        else {
            if (age <2) cout << "Tiger is hungry, he makes known about it tigress" << endl;
            else {
                cout << "Tiger is hungry, it begins to hunt." << endl;
                run(t_speed);
            }
        }
    }

    // Default constructor
    Tiger(const char* fileName="tiger.txt")
    {
        file.open(fileName);
        if (file.is_open()) {
            cout << "Initialization from file" << endl;
            // Initialize object using data from file
            file >> age;
            file >> size;
            file >> speed;
            file >> breed;
            file >> skinColour;
            file >> isHungry;
        } else {
            // Default values for initialization
            cout << "File not found. Default initialization." << endl;
            age = 5;
            size = 10;
            speed = 0;
            breed = "Amur";
            skinColour = "white";
            isHungry = true;
        }
        

    // copying constructor
    Tiger(Tiger const &instance):
            age(instance.age), size(instance.size),
            speed(instance.speed), breed(instance.breed),
            skinColour(instance.skinColour), isHungry(instance.isHungry)
    {}
    ~Tiger() {
        if(file.is_open()) file.close();
    }
};

// Friendly operator function for output. Implementation.
ostream &operator<<( ostream &output, const Tiger& T ) {
    output << "Breed: " << T.breed << endl;
    output << "Colour of skin: " << T.skinColour << endl;
    output << "Age: " << T.age << endl;
    output << "Speed: " << T.speed << endl;
    output << "Size: " << T.size << endl;
    output << (T.isHungry ? "The tiger is hungry" : "The tiger is not hungry") << endl;
    return output;
}


int main() {
    // Calling default constructor
    Tiger t1(10, 5);
    // Calling public function
    t1.hunt();
    // Tiger t2 is a copy of t1
    Tiger t2 = t1;
    // Visualization
    cout << t1 << endl;
    cout << t2;
    // Calling method of the class
    t1.hunt(50);
}
