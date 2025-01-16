
#ifndef MENUS_H 
#define MENUS_H

#include "header.h"

void toLowerCase(string& str) {
    transform(str.begin(), str.end(), str.begin(),::tolower);
}


// Function to display cars
// Inputs: Car_list - list of cars to display, index - specific car index to display (optional)
// Output: None
void DisplayCars(vector<Car>& Car_list, int index=-1){
    string title; // Title for display
    if (index == -1){
        for (int i = 0; i < Car_list.size(); i++){
            title = "Car " + to_string(i+1) + " details";
            Car_list[i].display(title);
        }
    } else {
        title = "Car " + to_string(index) + " details";
        Car_list[index].display(title);
    }
}

// Function to search cars by a common string attribute
// Inputs: attribute - pointer to the car attribute, attributeName - name of the attribute
// Output: None
void SearchByCommonAttribute(string Car::*attribute, string attributeName) {
    string searchValue; // Value to search for
    cout << "\nEnter the " << attributeName << " to search for: " << flush;
    cin >> searchValue;
    toLowerCase(searchValue);

    vector<Car> searchResults; // Vector to store search results
    string attributeValue; // Attribute value of the car
    for (int i = 0; i < Cars.size(); i++) {
        attributeValue = Cars[i].*attribute;
        toLowerCase(attributeValue);
        if (attributeValue == searchValue) {
            searchResults.push_back(Cars[i]);
        }
    }

    DisplayCars(searchResults);
}

// Function to search cars by a common integer attribute
// Inputs: attribute - pointer to the car attribute, attributeName - name of the attribute
// Output: None
void SearchByCommonAttribute(int Car::*attribute, string attributeName) {
    int searchValue; // Value to search for
    cout << "\nEnter the " << attributeName << " to search for: " << flush;
    cin >> searchValue;

    vector<Car> searchResults; // Vector to store search results
    for (int i = 0; i < Cars.size(); i++) {
        if (Cars[i].*attribute == searchValue) {
            searchResults.push_back(Cars[i]);
        }
    }

    DisplayCars(searchResults);
}

// Function to search for a car by ID
// Inputs: None
// Output: None
void SearchByID() {
    int searchValue; // ID to search for
    cout << "Enter the ID to search for: " << flush;
    cin >> searchValue;

    int CarIndex = retrieveBST(BST_IDs_ROOT, searchValue);

    if (CarIndex == -1){
        cout << "\nCar not found" << endl;
        return;
    } else {
        cout << "\nCar found : \n" << endl;
        DisplayCars(Cars, CarIndex);
    }
}

// Function to handle search menu and options
// Inputs: None
// Output: None
void Search(){
    cout << "\n\nSelect search option" << endl;
    cout << "1. Search by brand" << endl;
    cout << "2. Search by ID" << endl;
    cout << "3. Search by state" << endl;
    cout << "4. Search by factory year" << endl;
    cout << "5. Search by price" << endl;
    cout << "Choose an option :" << flush;

    int option; // User's search option
    cin >> option;

    switch (option)
    {
    case 1:
        cout << "Search by brand" << endl;
        SearchByCommonAttribute(&Car::brand, "brand");
        break;
    case 2:
        SearchByID();
        break;
    case 3:
        SearchByCommonAttribute(&Car::state, "state");
        break;
    case 4:
        SearchByCommonAttribute(&Car::factoryYear, "factory year");
        break;
    case 5:
        SearchByCommonAttribute(&Car::price, "price");
        break;
    default:
        cout << "Invalid option" << endl;
        break;
    }
}

// Function to delete a car by ID
// Inputs: None
// Output: None
void DeleteCar(){
    int searchValue; // ID of the car to delete
    cout << "Enter the ID of the car to delete: " << flush;
    cin >> searchValue;

    int CarIndex = 0;

    if (CarIndex == -1){
        cout << "\nCar not found" << endl;
        return;
    } else {
        Cars.erase(Cars.begin() + CarIndex);
        cout << "\nCar deleted successfully" << endl;
    }
}

// Function to edit a car's details
// Inputs: None
// Output: None
void EditCar(){
    int searchValue; // ID of the car to edit
    cout << "Enter the ID of the car to edit: " << flush;
    cin >> searchValue;

    int CarIndex = 0; 

    if (CarIndex == -1){
        cout << "\nCar not found\n" << endl;
        return;
    } else {
        cout << "\nCar found !" << endl;
        cout << "Select an property to change: \n" << endl;
        cout << "1. Edit brand        : " << Cars[CarIndex].brand << endl;
        cout << "2. Edit ID           : " << Cars[CarIndex].ID << endl;
        cout << "3. Edit state        : " << Cars[CarIndex].state << endl;
        cout << "4. Edit factory year : " << Cars[CarIndex].factoryYear << endl;
        cout << "5. Edit price        : " << Cars[CarIndex].price << endl;
        cout << "\nChoose an option   :" << flush;

        int option; // User's edit option
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter new brand: " << flush;
            cin >> Cars[CarIndex].brand;
            break;
        case 2:
            cout << "Enter new ID: " << flush;
            cin >> Cars[CarIndex].ID;
            break;
        case 3:
            cout << "Enter new state: " << flush;
            cin >> Cars[CarIndex].state;
            break;
        case 4:
            cout << "Enter new factory year: " << flush;
            cin >> Cars[CarIndex].factoryYear;
            break;
        case 5:
            cout << "Enter new price: " << flush;
            cin >> Cars[CarIndex].price;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }

        cout << "\nCar edited successfully:" << endl;
        DisplayCars(Cars, CarIndex);
    }
}

void insertNewCar(Car& temp_car){

    int car_index = temp_car.addToCars(Cars);
    pii ID_data = make_pair(Cars[car_index].ID, car_index);
    insertBST(BST_IDs_ROOT, ID_data);

}


// Function to add a new car
// Inputs: None
// Output: None
void AddCar(){
    
    Car temp_car; // Temporary car object to store new car details

    cout << "Add car's brand" << endl;
    cin >> temp_car.brand;

    cout << "Add car's ID" << endl;
    cin >> temp_car.ID;

    cout << "Add car's state" << endl;
    cin >> temp_car.state;

    cout << "Add car's factory year" << endl;
    cin >> temp_car.factoryYear;

    cout << "Add car's price" << endl;
    cin >> temp_car.price;

    insertNewCar(temp_car);

    cout << "Car added successfully" << endl;
}

void balance() {
    //balanceBST(BST_brands_ROOT);
    //balanceBST(BST_states_ROOT);
    //balanceBST(BST_factoryYears_ROOT);
    //balanceBST(BST_prices_ROOT);
    cout << " Before : " << endl;
    displayBST(BST_IDs_ROOT);
    balanceBST(BST_IDs_ROOT);
    cout << " After : " << endl;
    displayBST(BST_IDs_ROOT);
}

#endif

