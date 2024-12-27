
#include <string>
#include <iostream>

class Car {
private:
    std::string model;
    int year;
    float engineSize;

public:
    Car(); // Default constructor
    Car(std::string m, int y, float eSize); // Custom constructor
    std::string getModel() const;
    void setModel(const std::string& m);
    void displayInfo() const;
};

template<typename EngineType>
class CarTemplate {
private:
    std::string model;
    int year;
    EngineType engineSize;

public:
    CarTemplate(); // Default constructor
    CarTemplate(std::string m, int y, EngineType eSize); // Custom constructor
    std::string getModel() const;
    void setModel(const std::string& m);
    EngineType getEngineSize() const;
    void setEngineSize(const EngineType& eSize);
    void displayInfo() const;
};

#include "class.cpp" // Include the implementation file

