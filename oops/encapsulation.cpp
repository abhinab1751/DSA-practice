#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car {
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {}
};

class SportsCar : public Car {
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;
public:
    SportsCar(string b, string m) {
        brand = b;
        model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        tyre = "MRF";
    }

    // getter and setter for currentSpeed to demonstrate encapsulation
    int getCurrentSpeed() {
        return currentSpeed;
    }

    string getTyre() {
        return this->tyre;
    }

    string getTyre(string tyre) {
        this->tyre = tyre;
    }

    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void shiftGear(int gear) {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is Off! Cannot Shift Gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }
};

int main(){
    SportsCar*  mySportsCar = new SportsCar("ford", "Mustang");

    mySportsCar->startEngine();
    mySportsCar->shiftGear(1);
    mySportsCar->accelerate();
    mySportsCar->brake();
    mySportsCar->stopEngine();

    //mySportsCar->currentSpeed = 100; // Directly accessing and modifying the speed (not recommended)
    //cout << "Directly set speed to " << mySportsCar->currentSpeed << " km/h (This breaks encapsulation!)" << endl;

    //cout << "Current Speed (using getter): " << mySportsCar->getCurrentSpeed() << " km/h" << endl; // Accessing speed through getter

    cout << "Current Tyre (using getter): " << mySportsCar->getTyre() << endl; // Accessing tyre through getter
    //mySportsCar->getTyre("Apollo"); // Modifying tyre through setter
    delete mySportsCar;
}