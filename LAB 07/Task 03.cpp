#include <iostream>
using namespace std;

class Ticket {
public:
    string ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

    Ticket(string id, string name, double p, string d, string dest) {
        ticketID = id;
        passengerName = name;
        price = p;
        date = d;
        destination = dest;
    }

    virtual void reserve() {
    }

    virtual void cancel() {
    }

    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Price: " << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }
};

class FlightTicket : public Ticket {
private:
    string airlineName;
    string flightNumber;
    string seatClass;
public:
    FlightTicket(string id, string name, double p, string d, string dest, string airline, string flight, string seat)
        : Ticket(id, name, p, d, dest) {
        airlineName = airline;
        flightNumber = flight;
        seatClass = seat;
    }

    void displayTicketInfo() {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Seat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
private:
    string trainNumber;
    string coachType;
    string departureTime;
public:
    TrainTicket(string id, string name, double p, string d, string dest, string train, string coach, string time)
        : Ticket(id, name, p, d, dest) {
        trainNumber = train;
        coachType = coach;
        departureTime = time;
    }

    void reserve() {
        cout << "Seat auto-assigned for Train Ticket" << endl;
    }

    void displayTicketInfo() {
        Ticket::displayTicketInfo();
        cout << "Train Number: " << trainNumber << endl;
        cout << "Coach Type: " << coachType << endl;
        cout << "Departure Time: " << departureTime << endl;
    }
};

class BusTicket : public Ticket {
private:
    string busCompany;
    string seatNumber;
public:
    BusTicket(string id, string name, double p, string d, string dest, string company, string seat)
        : Ticket(id, name, p, d, dest) {
        busCompany = company;
        seatNumber = seat;
    }

    void cancel() {
        cout << "Bus ticket cancelled. Refund processed." << endl;
    }

    void displayTicketInfo() {
        Ticket::displayTicketInfo();
        cout << "Bus Company: " << busCompany << endl;
        cout << "Seat Number: " << seatNumber << endl;
    }
};

class ConcertTicket : public Ticket {
private:
    string artistName;
    string venue;
    string seatType;
public:
    ConcertTicket(string id, string name, double p, string d, string dest, string artist, string v, string seat)
        : Ticket(id, name, p, d, dest) {
        artistName = artist;
        venue = v;
        seatType = seat;
    }

    void displayTicketInfo() {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main() {
    cout << "khubaib ur rehman \n24k-0748" << endl;

    FlightTicket f1("F101", "Ali", 50000, "2025-05-01", "Karachi", "PIA", "PK301", "Business");
    TrainTicket t1("T101", "Zain", 1500, "2025-05-03", "Lahore", "GreenLine", "AC", "10:00 AM");
    BusTicket b1("B101", "Khubaib", 800, "2025-05-04", "Islamabad", "Skyways", "21B");
    ConcertTicket c1("C101", "Mehmod", 3000, "2025-05-05", "Expo Center", "Atif Aslam", "Hall A", "VIP");

    cout << "\n--- Flight Ticket ---" << endl;
    f1.displayTicketInfo();

    cout << "\n--- Train Ticket ---" << endl;
    t1.reserve();
    t1.displayTicketInfo();

    cout << "\n--- Bus Ticket ---" << endl;
    b1.cancel();
    b1.displayTicketInfo();

    cout << "\n--- Concert Ticket ---" << endl;
    c1.displayTicketInfo();

    return 0;
}
