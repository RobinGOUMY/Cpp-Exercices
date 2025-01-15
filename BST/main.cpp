#include "header.h"

// Function to preload cars into the system
// Inputs: None
// Output: None
void PreloadCars(){
    // Preload 4 cars
    Car car1("Toyota", 1263, "New", 2021, 100000);
    Car car2("BMW", 5712, "Occasion", 2019, 200000);
    Car car3("Mercedes", 9, "New", 2023, 300000);
    Car car4("Mercedes", 4479, "Occasion", 2021, 400000);

    insertNewCar(car1);
    insertNewCar(car2);
    insertNewCar(car3);
    insertNewCar(car4);


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
