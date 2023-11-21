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

class VehicleOwner {
public:
    string Vehicle_Number;
    string FirstName;
    string LastName;
    int Age;
    string Gender;
    string Address;
};

class TrafficDepartment {
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
        getline(file, line);

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

private:
    vector<TrafficViolation> violations;
};

struct Person {
    string firstname;
    string lastname;
    int age;
    string gender;
    string address;
};

struct violation {
    string vehicle_number;
    string type;
    string location;
};

class Evidence {
    vector<Person> witnesses;
    struct violation violation_details;
    string response_text;
    string prior_info;

public:
    Evidence() {}
    Evidence(vector<Person> u, struct violation v, string w, string x) {
        witnesses = u;
        violation_details = v;
        response_text = w;
        prior_info = x;
    }

    void addwitnesses() {
        Person p;
        cout << "Enter first name : ";
        cin >> p.firstname;
        cout << "Enter last name: ";
        cin >> p.lastname;
        cout << "Enter age: ";
        cin >> p.age;
        cout << "Enter gender: ";
        cin >> p.gender;
        cout << "Enter address: ";
        getchar();
        getline(cin, p.address);

        witnesses.push_back(p);
    }

    void addviolationdetails() {
        struct violation v;
        cout << "Enter vehicle number: ";
        cin >> v.vehicle_number;
        cout << "Enter type of violation: ";
        cin >> v.type;
        cout << "Enter location of violation: ";
        getchar();
        getline(cin, v.location);

        violation_details = v;
    }

    void addresponsetext() {
        string s;
        cout << "enter response text: ";
        getchar();
        getline(cin, s);
        response_text = s;
    }

    void addpriorinfo() {
        string s;
        cout << "Enter any prior information about the person: ";
        getchar();
        getline(cin, s);

        prior_info = s;
    }

    vector<Person> getwitnesses() {
        return witnesses;
    }

    struct violation getviolationdetails() {
        return violation_details;
    }

    string getrepsonsetext() {
        return response_text;
    }

    string getpriorinfo() {
        return prior_info;
    }
};

int main() {
    vector<Evidence> e;

    while (1) {
        int x;
        cout << "Enter the number of witnesses for the accident: ";
        cin >> x;
        Evidence E;
        while (x--) {
            E.addwitnesses();
        }
        E.addviolationdetails();
        E.addresponsetext();
        E.addpriorinfo();
        vector<Person> witnesses = E.getwitnesses();
        struct violation violation_details = E.getviolationdetails();
        string response_text = E.getrepsonsetext();
        string prior_info = E.getpriorinfo();

        Evidence copy(witnesses, violation_details, response_text, prior_info);
        e.push_back(copy);

        char choice;
        cout << "for adding more evidence for other accidents press Y/y\n";
        cin >> choice;

        if (choice != 'Y' && choice != 'y')
            break;
    }

    for (int i = 0; i < e.size(); i++) {
        vector<Person> witnesses = e[i].getwitnesses();
        struct violation violation_details = e[i].getviolationdetails();
        string response_text = e[i].getrepsonsetext();
        string prior_info = e[i].getpriorinfo();

        cout << "list of witnesses are\n";
        for (int j = 0; j < witnesses.size(); j++) {
            cout << "first name : " << witnesses[j].firstname << "\n";
            cout << "last name : " << witnesses[j].lastname << "\n";
            cout << "age : " << witnesses[j].age << "\n";
            cout << "gender : " << witnesses[j].gender << "\n";
            cout << "Address : " << witnesses[j].address << "\n";
        }

        cout << "\nViolation details\n";
        cout << "vehicle number : " << violation_details.vehicle_number << "\n";
        cout << "type : " << violation_details.type << "\n";
        cout << "location of violation : " << violation_details.location << "\n";

        cout << "response text : " << response_text << "\n";

        cout << "prior information : " << prior_info << "\n";
    }

    return 0;
}
