#include "class.h"

/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor ❌
 * Must have a default constructor ❌
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ❌
 * Must have public members (functions) ❌
 * Must have at least one getter function ❌
 * Must have at least one setter function ❌
 */


int main() {
    // Using the non-template Car class
    Car myCar("Toyota Corolla", 2020, 1.8f);
    myCar.displayInfo(); // Display the information of myCar

    // Changing the model of the car
    myCar.setModel("Toyota Camry");
    std::cout << "After model change: ";
    myCar.displayInfo(); // Display the information after changing the model

    // Using the template Car class with float as the engine size type
    CarTemplate<float> myTemplateCar("Honda Civic", 2019, 2.0f);
    myTemplateCar.displayInfo(); // Display the information of myTemplateCar

    // Using the template Car class with int as the engine size type
    CarTemplate<int> myOtherTemplateCar("Ford Mustang", 2021, 5);
    myOtherTemplateCar.displayInfo(); // Display the information of myOtherTemplateCar

    return 0;
}