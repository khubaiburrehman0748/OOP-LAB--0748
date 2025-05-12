#include <iostream>
#include <exception>
using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {};
class QueryTimeoutException : public DatabaseException {};

template<typename T>
class DatabaseConnector {
public:
    void connect(T dbName) {
        if (dbName == "invalid_db")
            throw ConnectionFailedException();
        else if (dbName == "slow_db")
            throw DatabaseException();
    }
};

int main() {
    DatabaseConnector<string> db;
    cout << "Attempting to connect to invalid_db..." << endl;
    try {
        db.connect("invalid_db");
    }
    catch (const exception& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    }
    cout << "Attempting to connect to slow_db..." << endl;
    try {
        db.connect("slow_db");
    }
    catch (const exception& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }
    return 0;
}
