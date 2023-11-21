#include <bits/stdc++.h>

using namespace std;

class Vehicle {
public:
    Vehicle(const string& vehicle_number, const string& owner_name, int owner_age, const string& owner_gender, const string& owner_address)
        : vehicle_number(vehicle_number), owner_name(owner_name), owner_age(owner_age), owner_gender(owner_gender), owner_address(owner_address) {}

    void display() const {
        cout << "Vehicle Number: " << vehicle_number << "\n"
             << "Owner: " << owner_name << "\n"
             << "Age: " << owner_age << "\n"
             << "Gender: " << owner_gender << "\n"
             << "Address: " << owner_address << "\n\n";
    }

    const string& getVehicleNumber() const { return vehicle_number; }
    const string& getOwnerName() const { return owner_name; }
    int getOwnerAge() const { return owner_age; }
    const string& getOwnerGender() const { return owner_gender; }
    const string& getOwnerAddress() const { return owner_address; }

    void setOwnerName(const string& new_name) { owner_name = new_name; }
    void setOwnerAge(int new_age) { owner_age = new_age; }
    void setOwnerGender(const string& new_gender) { owner_gender = new_gender; }
    void setOwnerAddress(const string& new_address) { owner_address = new_address; }

private:
    string vehicle_number;
    string owner_name;
    int owner_age;
    string owner_gender;
    string owner_address;
};

struct Person {
    string FirstName;
    string LastName;
    int Age;
    string Gender;
    string Address;
};

class VehicleOwner {
public:
    string Vehicle_Number;
    string FirstName;
    string LastName;
    int Age;
    string Gender;
    string Address;
};

class TrafficDepptment {
public:
    void addVehicle(const Vehicle& vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayAllVehicles() const {
        if (vehicles.empty()) {
            cout << "No vehicles to display.\n";
        } else {
            for (const auto& vehicle : vehicles) {
                vehicle.display();
            }
        }
    }

    void deleteVehicle(const string& vehicle_number) {
        auto it = find_if(vehicles.begin(), vehicles.end(), [&vehicle_number](const Vehicle& v) {
            return v.getVehicleNumber() == vehicle_number;
        });

        if (it != vehicles.end()) {
            vehicles.erase(it);
            cout << "Vehicle with number " << vehicle_number << " deleted successfully.\n";
        } else {
            cout << "Vehicle with number " << vehicle_number << " not found.\n";
        }
    }

    void editVehicleInfo(const string& vehicle_number, const string& new_name, int new_age, const string& new_gender, const string& new_address) {
        auto it = find_if(vehicles.begin(), vehicles.end(), [&vehicle_number](const Vehicle& v) {
            return v.getVehicleNumber() == vehicle_number;
        });

        if (it != vehicles.end()) {
            it->setOwnerName(new_name);
            it->setOwnerAge(new_age);
            it->setOwnerGender(new_gender);
            it->setOwnerAddress(new_address);
            cout << "Vehicle information edited successfully.\n";
        } else {
            cout << "Vehicle with number " << vehicle_number << " not found.\n";
        }
    }

    void readAndStore(const string& filename) {
        fstream f(filename);
        if (!f.is_open()) {
            cerr << "Error while opening file\n";
            return;
        }

        string line;
        getline(f, line); // reading header line

        while (getline(f, line, '\n')) {
            VehicleOwner vo;
            string temp;
            stringstream ss(line);

            getline(ss, temp, ',');
            vo.Vehicle_Number = temp;

            getline(ss, temp, ',');
            temp = "," + temp;
            vo.Vehicle_Number += temp;

            getline(ss, temp, ',');
            vo.FirstName = temp;

            getline(ss, temp, ',');
            vo.LastName = temp;

            getline(ss, temp, ',');
            vo.Age = stoi(temp);

            getline(ss, temp, ',');
            vo.Gender = temp;

            getline(ss, temp, ',');
            vo.Address = temp;

            Vehicle new_vehicle = convertToVehicle(vo);
            addVehicle(new_vehicle);
        }

        f.close();
    }

    Vehicle convertToVehicle(const VehicleOwner& vo) {
        return Vehicle(vo.Vehicle_Number, vo.FirstName + " " + vo.LastName, vo.Age, vo.Gender, vo.Address);
    }

    void userInput() {
        cout << "Enter vehicle information:\n";

        string state_code;
        cout << "State Code (2 capital characters): ";
        cin >> state_code;
        if (state_code.length() != 2 || !isupper(state_code[0]) || !isupper(state_code[1])) {
            cout << "Invalid State Code. Please enter 2 capital characters.\n";
            return;
        }

        int vehicle_number;
        cout << "Vehicle Number (6-digit integer): ";
        cin >> vehicle_number;
        if (cin.fail() || to_string(vehicle_number).length() != 6) {
            cout << "Invalid Vehicle Number. Please enter a 6-digit integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        string owner_name, owner_gender, owner_address;
        int owner_age;

        cout << "Owner Name: ";
        cin.ignore();
        getline(cin, owner_name);

        cout << "Owner Age: ";
        cin >> owner_age;

        cout << "Owner Gender: ";
        cin.ignore();
        getline(cin, owner_gender);

        cout << "Owner Address: ";
        cin.ignore();
        getline(cin, owner_address);

        string vehicle_number_str = state_code + to_string(vehicle_number);

        Vehicle new_vehicle(vehicle_number_str, owner_name, owner_age, owner_gender, owner_address);
        addVehicle(new_vehicle);
        cout << "Vehicle added successfully.\n";
    }

    vector<Vehicle> returnvehicles()
    {
        return vehicles;
    }

private:
    vector<Vehicle> vehicles;
};

class TrafficViolation {
public:
    string vehicle_number;
    string type;
    string location;
};

class TrafficPolice {
public:
    void addViolation(const TrafficViolation& violation) {
        violations.push_back(violation);
    }

    void displayAllViolations() const {
        if (violations.empty()) {
            cout << "No traffic violations to display.\n";
        } else {
            for (const auto& violation : violations) {
                displayViolation(violation);
            }
        }
    }

    void displayViolation(const TrafficViolation& violation) const {
        cout << "Vehicle Number: " << violation.vehicle_number << "\n"
             << "Type: " << violation.type << "\n"
             << "Location: " << violation.location << "\n\n";
    }

    void deleteViolation(const string& vehicle_number) {
        auto it = find_if(violations.begin(), violations.end(), [&vehicle_number](const TrafficViolation& v) {
            return v.vehicle_number == vehicle_number;
        });

        if (it != violations.end()) {
            violations.erase(it);
            cout << "Violation with vehicle number " << vehicle_number << " deleted successfully.\n";
        } else {
            cout << "Violation with vehicle number " << vehicle_number << " not found.\n";
        }
    }

    void editViolation(const string& vehicle_number, const string& new_type, const string& new_location) {
        auto it = find_if(violations.begin(), violations.end(), [&vehicle_number](const TrafficViolation& v) {
            return v.vehicle_number == vehicle_number;
        });

        if (it != violations.end()) {
            it->type = new_type;
            it->location = new_location;
            cout << "Violation information edited successfully.\n";
        } else {
            cout << "Violation with vehicle number " << vehicle_number << " not found.\n";
        }
    }

    void readAndStoreViolations(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        TrafficViolation t;
        string line;
        getline(file, line); // reading header line

        while (getline(file, line, '\n')) {
            stringstream ss(line);
            getline(ss, t.vehicle_number, '"');
            getline(ss, t.vehicle_number, '"');
            getline(ss, t.type, ',');
            getline(ss, t.type, ',');
            getline(ss, t.location);

            size_t endPos = t.location.find_last_not_of(" \t\n\r\f\v");
            if (endPos != std::string::npos)
                t.location.erase(endPos + 1);

            addViolation(t);
        }

        file.close();
    }

    void userInput() {
        cout << "Enter violation information:\n";
        TrafficViolation new_violation;

        cout << "Vehicle Number: ";
        cin >> new_violation.vehicle_number;

        cout << "Violation Type: ";
        cin.ignore();
        getline(cin, new_violation.type);

        cout << "Location: ";
        getline(cin, new_violation.location);

        addViolation(new_violation);
        cout << "Violation added successfully.\n";
    }
    vector<TrafficViolation> returnviolations()
    {
        return violations;
    }

private:
    vector<TrafficViolation> violations;
};

int main() {
    vector<TrafficViolation> TV;
    TrafficPolice TP;
    TP.readAndStoreViolations("A4-Q2.csv");
    TV = TP.returnviolations();

    vector<Vehicle> VO;
    TrafficDepptment td;
    td.readAndStore("A4-Q1.csv");
    VO = td.returnvehicles();

    vector<Person> P;
    fstream f("A4-Q3.csv");
    if(!f.is_open())
    {
        cerr << "error while opening file\n";
    }
    string line;
    getline(f,line);
    while(getline(f,line))
    {
        Person p;
        stringstream ss(line);
        getline(ss, p.FirstName, ',');
        getline(ss, p.LastName, ',');
        getline(ss, line, ',');
        p.Age = stoi(line);
        getline(ss, p.Gender, ',');
        getline(ss, p.Address, ',');

        P.push_back(p);
    }

    f.close();

    cout << "The Probable Address are : \n";

    for (int i = 0; i < TV.size(); i++) {
        for (int j = 0; j < VO.size(); j++) {

            if (TV[i].vehicle_number == VO[j].getVehicleNumber()) {
                for (int k = 0; k < P.size(); k++) {
                    string temp = P[k].FirstName +" "+ P[k].LastName;
                    if ( temp == VO[j].getOwnerName()  && P[k].Age == VO[j].getOwnerAge() &&
                        P[k].Gender == VO[j].getOwnerGender() && P[k].Address != VO[j].getOwnerAddress()) {
                        cout << P[k].FirstName << " " << P[k].LastName << " " << P[k].Age << " " << P[k].Address << "\n";
                    }
                }
            }
        }
    }
    cout<<"\n\n";
    return 0;
}
