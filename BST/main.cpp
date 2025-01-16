#include "header.h"



// Function to preload cars into the system
void PreloadCars(){
    Car temp_car;
    temp_car = Car("Toyota", 43, "new", 2021, 20000);
    insertNewCar(temp_car);
    temp_car = Car("BMW", 36, "used", 1998, 30000);
    insertNewCar(temp_car);
    temp_car = Car("Suzuki", 12, "new", 2023, 28000);
    insertNewCar(temp_car);
    temp_car = Car("BMMW", 25, "used", 2010, 15000);
    insertNewCar(temp_car);
    temp_car = Car("Ford", 50, "new", 2022, 22000);
    insertNewCar(temp_car);
    temp_car = Car("Ford", 18, "used", 2005, 12000);
    insertNewCar(temp_car);
    temp_car = Car("Nissan", 30, "new", 2021, 25000);
    insertNewCar(temp_car);
    temp_car = Car("Hyundai", 22, "used", 2015, 17000);
    insertNewCar(temp_car);
    temp_car = Car("Nissan", 40, "new", 2023, 21000);
    insertNewCar(temp_car);
    temp_car = Car("Volkswagen", 28, "used", 2008, 14000);
    insertNewCar(temp_car);
    temp_car = Car("Audi", 35, "new", 2022, 35000);
    insertNewCar(temp_car);
    temp_car = Car("Ford", 45, "used", 2012, 32000);
    insertNewCar(temp_car);
    temp_car = Car("Audi", 20, "new", 2023, 40000);
    insertNewCar(temp_car);
    temp_car = Car("Mazda", 27, "used", 2011, 16000);
    insertNewCar(temp_car);
    temp_car = Car("Mazda", 33, "new", 2022, 23000);
    insertNewCar(temp_car);
    temp_car = Car("Tesla", 10, "new", 2023, 45000);
    insertNewCar(temp_car);
    temp_car = Car("BMW", 15, "used", 2009, 28000);
    insertNewCar(temp_car);
    temp_car = Car("Porsche", 12, "new", 2023, 60000);
    insertNewCar(temp_car);
    temp_car = Car("Tesla", 5, "used", 2000, 75000);
    insertNewCar(temp_car);
    temp_car = Car("Toyota", 8, "used", 2018, 18000);
    insertNewCar(temp_car);




    

}

int main() {
    int option = 0; // User's menu option

    PreloadCars();

    while (option != 7) {
        cout << "\n\n__________________________________________\n" << endl;
        cout << "Menu" << endl;
        cout << "1. Add car" << endl;
        cout << "2. Edit car" << endl;
        cout << "3. Delete car" << endl;
        cout << "4. Display all cars" << endl;
        cout << "5. Search" << endl;
        cout << "6. Balance BSTs" << endl;
        cout << "7. Exit" << endl;
        cout << "Choose an option :" << flush;

        cin >> option;

        switch (option)
        {
        case 1:
            AddCar();
            break;
        case 2:
            //EditCar();
            cout << "Not implemented yet" << endl;
            break;
        case 3:
            //DeleteCar();
            cout << "Not implemented yet" << endl;
            break;
        case 4:
            cout << "\n\n Displaying all cars: \n" << endl;
            cout << "cars size: " << Cars.size() << endl;
            DisplayCars(Cars);
            break;
        case 5:
            //Search();
            SearchByID();
            break;
        case 6:
            balance();
            break;
        case 7:
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}
