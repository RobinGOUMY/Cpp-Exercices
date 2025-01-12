# Instruction about WorkShop

<br>

- Build a data type of your choice (class, struct), to represent one real-world set of entities (e.g. Students, Cars, Products, etc.). Think of appropriate attributes in each case (e.g. year of enrolment, name, etc.)
 
- Create instances/objects of your data type and store them in a Data Structure of your choice (e.g. list, vector, BST). Optimally, the data structure should follow your own implementation. Data can be randomly generated.
  
- Implement addition, retrieval, updating and removal functionalities, through a simple console menu.
  
- Implement a version of Merge Sort, to sort your data structure based on a "sortable" attribute (e.g. year of enrolment, name)
  
- Support any function that depends on search (retrieval, updating and removal), with your implementation of Binary Search (or, optionally, a suitable tree structure).
  
- Maintain a public remote repository on GitHub, with just the necessary documentation on how to build and run your code. Include a short description about what your project does and what limitations it may have (bugs, unfinished tasks, etc.).

<br>

# Car Management Program Tutorial

## Getting Started

Compile the program using a C++ compiler (e.g., g++ program.cpp -o program).
Run the program: ./program.

## Menu Options

The program displays a menu with the following options:

### Add Car

Add a new car to the collection by providing:

- Brand
- ID
- State (e.g., "New", "Used")
- Factory Year
- Price
  
### Edit Car

Modify the details of a car by its ID. You can update:

- Brand
- ID
- State
- Factory Year
- Price

### Delete Car

Remove a car by entering its ID.

### Display All Cars

View all cars currently stored in the system.

### Search

Find cars based on:

 - Brand
 - ID
 - State
 - Factory Year
 - Price
  
### Exit

Exit the program.

## Preloaded Data

The program starts with a preloaded list of 4 cars:

- Toyota (ID: 1263, New, 2021, Price: 100,000)
- BMW (ID: 5712, Used, 2019, Price: 200,000)
- Mercedes (ID: 9, New, 2023, Price: 300,000)
- Mercedes (ID: 4479, Used, 2021, Price: 400,000)


## Notes

    Cars are sorted by ID after every addition or deletion.
    Invalid inputs (e.g., non-existent IDs) are handled with appropriate messages.