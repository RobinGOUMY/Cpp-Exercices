
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

void toLowerCase(string& str) {
    transform(str.begin(), str.end(), str.begin(),::tolower);
}

#include "class.h"
vector<Car> Cars; // Vector to store all cars
#include "binary_search.h"
#include "menus.h"



#endif

