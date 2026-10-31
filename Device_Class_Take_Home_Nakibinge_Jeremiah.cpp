#include <iostream>
#include <string>

using namespace std;

class Device {
public:
    string brand;

    void setBrand(string b) {
        brand = b;
    }

    void showBrand() {
        cout << "Brand: " << brand << endl;
    }
};

class Smartphone : public Device {
public:
    int storageGB;

    void setStorage(int s) {
        storageGB = s;
    }

    void showStorage() {
        cout << "Storage: " << storageGB << " GB" << endl;
    }
};

class Smartwatch : public Smartphone {
public:
    bool hasHeartRateSensor;

    void setSensor(bool h) {
        hasHeartRateSensor = h;
    }

    void showSensor() {
        cout << "Has Heart Rate Sensor: " << (hasHeartRateSensor ? "Yes" : "No") << endl;
    }
};

int main() {
    Smartwatch myWatch;

    myWatch.setBrand("Samsung");

      myWatch.setStorage(32);

      myWatch.setSensor(true);

    cout << "--- Smartwatch Details ---" << endl;
    myWatch.showBrand();   
    myWatch.showStorage(); 
    myWatch.showSensor();  

    return 0;
}
