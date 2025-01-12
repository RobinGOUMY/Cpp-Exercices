#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to convert a string to lowercase
void toLowerCase(string& str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return tolower(c);
    });
}

class Car {

public:
    string brand;
    int ID;
    string state;
    int factoryYear;
    int price;

    Car(string carBrand = "", int carID = 0, string carState = "", int carFactoryYear = 0, int carPrice = 0){
        this->brand = carBrand;
        this->ID = carID;
        this->state = carState;
        this->factoryYear = carFactoryYear;
        this->price = carPrice;
    }

    void display(string title = ""){
        
        cout << "\n---------------------------------" << endl;
        cout << title << endl;
        cout << "-----------\n" << endl;
        cout << "Brand: " << brand << endl;
        cout << "ID: " << ID << endl;
        cout << "State: " << state << endl;
        cout << "Factory Year: " << factoryYear << endl;
        cout << "Price: " << price << endl;
    }
};

vector<Car> Cars;


void DisplayCars(vector<Car>& Car_list){
    string title;
    for (int i = 0; i < Car_list.size(); i++){
        title = "Car " + to_string(i+1) + " details";
        Car_list[i].display(title);
    }
}

vector <Car> binarySearch(vector<Car>& myCars, int low, int high, int searchID) {

    vector<Car> searchResults;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (searchID == myCars[mid].ID){
            searchResults.push_back(myCars[mid]);
            return searchResults;
        }

        if (searchID > myCars[mid].ID){
            low = mid + 1;
        }

        if (searchID < myCars[mid].ID){
            high = mid - 1;
        }

    }

    Car emptyFlagCar;
    emptyFlagCar.ID = -1;
    searchResults.push_back(emptyFlagCar);
    return searchResults;

}


void SearchByCommonAttribute(string Car::*attribute, string attributeName) {

    string searchValue;
    cout << "\nEnter the " << attributeName << " to search for: " << flush;
    cin >> searchValue;
    toLowerCase(searchValue);

    vector<Car> searchResults;
    string attributeValue;
    for (int i = 0; i < Cars.size(); i++) {
        attributeValue = Cars[i].*attribute;
        toLowerCase(attributeValue);
        if (attributeValue == searchValue) {
            searchResults.push_back(Cars[i]);
        }
    }

    DisplayCars(searchResults);
}

void SearchByCommonAttribute(int Car::*attribute, string attributeName) {

    int searchValue;
    cout << "\nEnter the " << attributeName << " to search for: " << flush;
    cin >> searchValue;

    vector<Car> searchResults;
    for (int i = 0; i < Cars.size(); i++) {
        if (Cars[i].*attribute == searchValue) {
            searchResults.push_back(Cars[i]);
        }
    }

    DisplayCars(searchResults);
}

void SearchByID() {

    int searchValue;
    cout << "Enter the ID to search for: " << flush;
    cin >> searchValue;

    vector <Car> searchResults;
    searchResults = binarySearch(Cars, 0, Cars.size() - 1, searchValue);

    if (searchResults[0].ID == -1){
        cout << "\nCar not found" << endl;
        return;
    } else {
        cout << "\nCar found : \n" << endl;
        DisplayCars(searchResults);
    }
}

void Search(){

    cout << "\n\nSelect search option" << endl;
    cout << "1. Search by brand" << endl;
    cout << "2. Search by ID" << endl;
    cout << "3. Search by state" << endl;
    cout << "4. Search by factory year" << endl;
    cout << "5. Search by price" << endl;
    cout << "Choose an option :" << flush;

    int option;
    cin >> option;

    vector <Car> searchResults;

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

void DeleteCar(){

    int searchValue;
    cout << "Enter the ID of the car to delete: " << endl;
    cin >> searchValue;

    for (int i = 0; i < Cars.size(); i++) {
        if (Cars[i].ID == searchValue) {
            Cars.erase(Cars.begin() + i);
            cout << "Car deleted successfully" << endl;
            return;
        }
    }

    cout << "Car not found" << endl;
    
}

void EditCar(){
    int searchValue;
    cout << "Enter the ID of the car to edit: " << endl;
    cin >> searchValue;

    for (int i = 0; i < Cars.size(); i++) {
        if (Cars[i].ID == searchValue) {
            cout << "Enter the new brand: " << endl;
            cin >> Cars[i].brand;
            cout << "Enter the new ID: " << endl;
            cin >> Cars[i].ID;
            cout << "Enter the new state: " << endl;
            cin >> Cars[i].state;
            cout << "Enter the new factory year: " << endl;
            cin >> Cars[i].factoryYear;
            cout << "Enter the new price: " << endl;
            cin >> Cars[i].price;
            cout << "Car edited successfully" << endl;
            return;
        }
    }

    cout << "Car not found" << endl;
    
}

void merge(vector<Car>& myCars, int lowerB, int mid, int UpperB) {
    int sizeLeft = mid - lowerB + 1;
    int sizeRight = UpperB - mid;

    vector<Car> leftArray(sizeLeft);
    vector<Car> rightArray(sizeRight);

    for (int i = 0; i < sizeLeft; ++i) {
        leftArray[i] = myCars[lowerB + i];
    }
    for (int i = 0; i < sizeRight; ++i) {
        rightArray[i] = myCars[mid + 1 + i];
    }

    int i = 0, j = 0, k = lowerB;

    while ((i < sizeLeft) && (j < sizeRight)) {
        if (leftArray[i].ID <= rightArray[j].ID) {
            myCars[k] = leftArray[i];
            ++i;
        } else {
            myCars[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < sizeLeft) {
        myCars[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < sizeRight) {
        myCars[k] = rightArray[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<Car>& myCars, int lowerB, int upperB){

    if (lowerB >= upperB){
        return;
    }

    int mid = lowerB + (upperB - lowerB) / 2;
    mergeSort(myCars, lowerB, mid);
    mergeSort(myCars, mid + 1, upperB);
    merge(myCars, lowerB, mid, upperB);
}

void AddCar(){

    Car temp_car;
    
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
    cout << "Add car's mileage" << endl;

    Cars.push_back(temp_car);

    mergeSort(Cars, 0, Cars.size() - 1);
    
    cout << "Car added successfully" << endl;

}

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

    int option = 0;

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
