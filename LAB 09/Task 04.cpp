#include <iostream>
using namespace std;

class WeatherSensor {
    public:
        virtual float readData() = 0;
        virtual void displayReport() = 0;
};

class Thermometer : public WeatherSensor {
    public:
        float temperature;

        Thermometer(float temp) {
            temperature = temp;
        }

        float readData() {
            return temperature;
        }

        void displayReport() {
            cout << "Thermometer Report:" << endl;
            cout << "Temperature: " << temperature << "°C" << endl;
        }
};

class Barometer : public WeatherSensor {
    public:
        float pressure;

        Barometer(float pres) {
            pressure = pres;
        }

        float readData() {
            return pressure;
        }

        void displayReport() {
            cout << "Barometer Report:" << endl;
            cout << "Pressure: " << pressure << " hPa" << endl;
        }
};

int main() {
    cout << "24K-0748\nKHUBAIB UR REHMAN" << endl;

    WeatherSensor* ws1;
    WeatherSensor* ws2;

    Thermometer thermo(27.3);
    Barometer baro(1012.8);

    ws1 = &thermo;
    ws2 = &baro;

    cout << "\n--- Thermometer ---" << endl;
    ws1->displayReport();
    cout << "Sensor Reading: " << ws1->readData() << "°C" << endl;

    cout << "\n--- Barometer ---" << endl;
    ws2->displayReport();
    cout << "Sensor Reading: " << ws2->readData() << " hPa" << endl;

    return 0;
}
    
