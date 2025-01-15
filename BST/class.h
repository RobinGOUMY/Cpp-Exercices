
#include "header.h"
#ifndef CLASS_H
#define CLASS_H

class Car {
    
public:
    string brand; // Car brand
    int ID; // Car ID
    string state; // Car state (e.g., new, used)
    int factoryYear; // Year the car was manufactured
    int price; // Price of the car

    // Constructor to initialize a Car object
    // Inputs: carBrand, carID, carState, carFactoryYear, carPrice
    // Output: None
    Car(string carBrand = "", int carID = 0, string carState = "", int carFactoryYear = 0, int carPrice = 0){
        this->brand = carBrand;
        this->ID = carID;
        this->state = carState;
        this->factoryYear = carFactoryYear;
        this->price = carPrice;
    }

    // Function to display car details
    // Input: title - optional title to display
    // Output: None
    void display(string title = ""){
        cout << "\n---------------------------------" << endl;
        cout << title << endl;
        cout << "-------------\n" << endl;
        cout << "Brand: " << brand << endl;
        cout << "ID: " << ID << endl;
        cout << "State: " << state << endl;
        cout << "Factory Year: " << factoryYear << endl;
        cout << "Price: " << price << endl;
    }

    int addToCars(vector<Car>& Cars){
        Cars.push_back(*this);
        return Cars.size() - 1;
    }
};

#endif