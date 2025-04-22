#include <iostream>
using namespace std;

class Gadget {
public:
    int id;
    string name;
    bool isActive;
    string place;

    Gadget(int i, string n, bool active, string p) {
        id = i;
        name = n;
        isActive = active;
        place = p;
    }

    void activate() {
        isActive = true;
    }

    void deactivate() {
        isActive = false;
    }

    bool isRunning() {
        return isActive;
    }

    void showDetails() {
        cout << "Gadget ID: " << id << endl;
        cout << "Gadget Name: " << name << endl;
        cout << "Status: " << isActive << endl;
        cout << "Installed At: " << place << endl;
    }
};

class Light : public Gadget {
private:
    int level;
    string mode;
public:
   Light(int i, string n, bool a, string p, int l, string m) : Gadget(i, n, a, p) {
        level = l;
        mode = m;
    }

    void showDetails() {
        cout << "Gadget ID: " << id << endl;
        cout << "Gadget Name: " << name << endl;
        cout << "Status: " << isActive << endl;
        cout << "Installed At: " << place << endl;
        cout << "Brightness: " << level << endl;
        cout << "Color Mode: " << mode << endl;
    }
};

class Thermostat : public Gadget {
private:
    int currentTemp;
    string operationMode;
    int desiredTemp;
public:
    Thermostat(int i, string n, bool a, string p, int curr, string op, int tgt) : Gadget(i, n, a, p) {
        currentTemp = curr;
        operationMode = op;
        desiredTemp = tgt;
    }

    void isRunning() {
        cout << "Current Temp: " << currentTemp << endl;
    }
};

class SecurityCam : public Gadget {
private:
    int pixelQuality;
    bool isRecording;
    bool isNightVisionOn;
public:
    SecurityCam(int i, string n, bool a, string p, int res, bool rec, bool nv) : Gadget(i, n, a, p) {
        pixelQuality = res;
        isRecording = rec;
        isNightVisionOn = nv;
    }

    void activate() {
        isRecording = true;
    }

    void deactivate() {
        isRecording = false;
    }
};

class SmartPlug : public Gadget {
private:
    int energyUsed;
    string timer;
public:
    SmartPlug(int i, string n, bool a, string p, int e, string t) : Gadget(i, n, a, p) {
        energyUsed = e;
        timer = t;
    }

    void deactivate(int newVal) {
        energyUsed = newVal;
    }
};

int main() {
    cout<<"khubaib ur rehman \n 24k-0748"<<endl;

    Light light(1, "Ceiling Light", true, "Bedroom", 75, "Warm");
    Thermostat thermostat(2, "Nest", false, "Hallway", 22, "Cool", 24);
    SecurityCam camera(3, "Outdoor Cam", true, "Porch", 1080, false, true);
    SmartPlug plug(4, "Smart Plug", true, "Kitchen", 50, "10PM");

    light.showDetails();
    cout << endl;
    thermostat.isRunning();
    cout << endl;
    camera.activate();
    plug.deactivate(0);

    return 0;
}

