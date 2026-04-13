#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Car {
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;   

public:
    Car(string b, string m) {
        brand = b;
        model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts!" << endl;
    }

    virtual void shiftGear(int gear) {   
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is Off!" << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Gear " << currentGear << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine off" << endl;
    }

    // PURE VIRTUAL FUNCTIONS (only declaration)
    virtual void accelerate() = 0;
    virtual void brake() = 0;

    virtual ~Car() {}
};

class ManualCar : public Car {
public:
    ManualCar(string b, string m) : Car(b, m) {}

    void shiftGear(int gear) override {   
        cout << brand << " " << model << " : Manual gear " << gear << endl;
    }

    void accelerate() override {
        if (!isEngineOn) {
            cout << brand << " " << model << ": cannot accelerate! Engine is off." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : accelerating to " << currentSpeed << "km/h" << endl;
    }

    void brake() override {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " braking! Speed is now " << currentSpeed << "km/h" << endl;
    } 
};

class ElectricCar : public Car {
private:
    int batteryLevel;

public:
    ElectricCar(string b, string m) : Car(b, m) {
        batteryLevel = 100;
    }

    void chargeBattery() {
        batteryLevel = 100;
        cout << brand << " " << model << " : Battery charged!" << endl;
    }

    void accelerate() override {
        if (!isEngineOn) {
            cout << brand << " " << model << " :Cannot accelerate! Engine off." << endl;
            return;
        }
        if(batteryLevel <= 0){
            cout << brand << " " << model << " :batteryDead! , cannot accelerate." << endl;
            return;
        }
        batteryLevel -= 10;
        currentSpeed +=15;
        cout << brand << " " << model << " : accelerating to " << currentSpeed << "km/h battery at " << batteryLevel << "%" << endl;
    }

    void brake() override {
        currentSpeed -= 15;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Regenerative braking! Speed is now " << currentSpeed << "km/h. battery at " << batteryLevel << "%" << endl;
    }
};

int main() {
    Car* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    

    cout << "---------------------" << endl;

    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->chargeBattery();
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    delete myManualCar;
    delete myElectricCar;

    return 0;
}