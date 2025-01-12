#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to convert a string to lowercase
// Input: string& str - the string to be converted
// Output: None (modifies the input string in place)
void toLowerCase(string& str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return tolower(c);
    });
}

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
};

vector<Car> Cars; // Vector to store all cars

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

// Function to perform binary search on cars by ID
// Inputs: Car_list - list of cars, low - lower bound, high - upper bound, searchID - ID to search for
// Output: Index of the car if found, -1 otherwise
int binarySearch(vector<Car>& Car_list, int low, int high, int searchID) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // Middle index
        if (searchID == Car_list[mid].ID){
            return mid;
        }
        if (searchID > Car_list[mid].ID){
            low = mid + 1;
        }
        if (searchID < Car_list[mid].ID){
            high = mid - 1;
        }
    }
    return -1;
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

    int CarIndex = binarySearch(Cars, 0, Cars.size() - 1, searchValue);

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

    int CarIndex = binarySearch(Cars, 0, Cars.size() - 1, searchValue);

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

    int CarIndex = binarySearch(Cars, 0, Cars.size() - 1, searchValue);

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

// Function to merge two halves of a car list
// Inputs: Car_list - list of cars, lowerB - lower bound, mid - middle index, UpperB - upper bound
// Output: None
void merge(vector<Car>& Car_list, int lowerB, int mid, int UpperB) {
    int sizeLeft = mid - lowerB + 1; // Size of left half
    int sizeRight = UpperB - mid; // Size of right half

    vector<Car> leftArray(sizeLeft); // Left half array
    vector<Car> rightArray(sizeRight); // Right half array

    for (int i = 0; i < sizeLeft; ++i) {
        leftArray[i] = Car_list[lowerB + i];
    }
    for (int i = 0; i < sizeRight; ++i) {
        rightArray[i] = Car_list[mid + 1 + i];
    }

    int i = 0, j = 0, k = lowerB; // Indices for merging

    while ((i < sizeLeft) && (j < sizeRight)) {
        if (leftArray[i].ID <= rightArray[j].ID) {
            Car_list[k] = leftArray[i];
            ++i;
        } else {
            Car_list[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < sizeLeft) {
        Car_list[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < sizeRight) {
        Car_list[k] = rightArray[j];
        ++j;
        ++k;
    }
}

// Function to perform merge sort on a list of cars
// Inputs: Car_list - list of cars, lowerB - lower bound, upperB - upper bound
// Output: None
void mergeSort(vector<Car>& Car_list, int lowerB, int upperB){
    if (lowerB >= upperB){
        return;
    }

    int mid = lowerB + (upperB - lowerB) / 2; // Middle index
    mergeSort(Car_list, lowerB, mid);
    mergeSort(Car_list, mid + 1, upperB);
    merge(Car_list, lowerB, mid, upperB);
}

// Function to add a new car
// Inputs: None
// Output: None
void AddCar(){
    Car temp_car; // Temporary car object

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

    Cars.push_back(temp_car);

    mergeSort(Cars, 0, Cars.size() - 1);

    cout << "Car added successfully" << endl;
}

// Function to preload cars into the system
// Inputs: None
// Output: None
void PreloadCars(){
    // Preload 4 cars
    Car car1("Toyota", 1263, "New", 2021, 100000);
    Car car2("BMW", 5712, "Occasion", 2019, 200000);
    Car car3("Mercedes", 9, "New", 2023, 300000);
    Car car4("Mercedes", 4479, "Occasion", 2021, 400000);

    Cars.push_back(car1);
    Cars.push_back(car2);
    Cars.push_back(car3);
    Cars.push_back(car4);

    mergeSort(Cars, 0, Cars.size() - 1);
}

int main() {
    int option = 0; // User's menu option

    PreloadCars();

    while (option != 6) {
        cout << "\n\n__________________________________________\n" << endl;
        cout << "Menu" << endl;
        cout << "1. Add car" << endl;
        cout << "2. Edit car" << endl;
        cout << "3. Delete car" << endl;
        cout << "4. Display all cars" << endl;
        cout << "5. Search" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option :" << flush;

        cin >> option;

        switch (option)
        {
        case 1:
            AddCar();
            break;
        case 2:
            EditCar();
            break;
        case 3:
            DeleteCar();
            break;
        case 4:
            cout << "\n\n Displaying all cars: \n" << endl;
            cout << "cars size: " << Cars.size() << endl;
            DisplayCars(Cars);
            break;
        case 5:
            Search();
            break;
        case 6:
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}
