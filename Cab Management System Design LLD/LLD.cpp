#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

// Class representing a cab
class Cab {
private:
    int id;
    bool available;
    pair<int, int> location; // Assuming location is represented by (x, y) coordinates

public:
    // Constructor to initialize the cab
    Cab(int _id) : id(_id), available(true) {}

    // Method to set the location of the cab
    void setLocation(pair<int, int> loc) {
        location = loc;
    }

    // Method to toggle the availability of the cab
    void toggleAvailability() {
        available = !available;
    }

    // Getter method to check if the cab is available
    bool isAvailable() const {
        return available;
    }

    // Getter method to get the location of the cab
    pair<int, int> getLocation() const {
        return location;
    }
};

// Class representing the Cab Management System
class CabManagementSystem {
private:
    unordered_map<int, Cab> cabs; // Mapping of cab_id to Cab object

public:
    // Method to add a new cab to the system
    void addCab(int cab_id) {
        cabs.emplace(cab_id, Cab(cab_id));
    }

    // Method to remove a cab from the system
    void removeCab(int cab_id) {
        auto it = cabs.find(cab_id);
        if (it != cabs.end()) {
            cabs.erase(it);
        }
    }

    // Method to update the location of a cab
    void updateCabLocation(int cab_id, pair<int, int> location) {
        auto it = cabs.find(cab_id);
        if (it != cabs.end()) {
            it->second.setLocation(location);
        }
    }

    // Method to toggle the availability of a cab
    void toggleCabAvailability(int cab_id) {
        auto it = cabs.find(cab_id);
        if (it != cabs.end()) {
            it->second.toggleAvailability();
        }
    }

    // Method to find the nearest available cab from a given location
    int findNearestCab(pair<int, int> location) {
        int nearest_cab_id = -1;
        double min_distance = numeric_limits<double>::max();

        for (const auto& pair : cabs) {
            const Cab& cab = pair.second;
            if (cab.isAvailable()) {
                double distance = calculateDistance(cab.getLocation(), location);
                if (distance < min_distance) {
                    min_distance = distance;
                    nearest_cab_id = pair.first;
                }
            }
        }

        return nearest_cab_id;
    }

    // Helper method to calculate distance between two points
    double calculateDistance(pair<int, int> loc1, pair<int, int> loc2) {
        int dx = loc1.first - loc2.first;
        int dy = loc1.second - loc2.second;
        return sqrt(dx * dx + dy * dy);
    }
};

int main() {
    CabManagementSystem cabSystem;

    // Adding cabs
    cabSystem.addCab(1);
    cabSystem.addCab(2);

    // Updating cab locations
    cabSystem.updateCabLocation(1, make_pair(0, 0));
    cabSystem.updateCabLocation(2, make_pair(3, 4));

    // Toggling cab availability
    cabSystem.toggleCabAvailability(1);

    // Finding nearest cab to a location
    int nearestCabId = cabSystem.findNearestCab(make_pair(2, 2));
    cout << "Nearest cab ID: " << nearestCabId << endl; // Output: 2

    return 0;
}
