
// Constructor definitions
Car::Car() : model("Unknown"), year(0), engineSize(0.0f) {}

Car::Car(std::string m, int y, float eSize) : model(m), year(y), engineSize(eSize) {}

// Getter and setter for model
std::string Car::getModel() const {
    return model;
}

void Car::setModel(const std::string& m) {
    model = m;
}

// Display information
void Car::displayInfo() const {
    std::cout << "Model: " << model << ", Year: " << year << ", Engine size: " << engineSize << " liters\n";
}

// Template class implementations
template<typename EngineType>
CarTemplate<EngineType>::CarTemplate() : model("Unknown"), year(0), engineSize(EngineType()) {}

template<typename EngineType>
CarTemplate<EngineType>::CarTemplate(std::string m, int y, EngineType eSize) : model(m), year(y), engineSize(eSize) {}

template<typename EngineType>
std::string CarTemplate<EngineType>::getModel() const {
    return model;
}

template<typename EngineType>
void CarTemplate<EngineType>::setModel(const std::string& m) {
    model = m;
}

template<typename EngineType>
EngineType CarTemplate<EngineType>::getEngineSize() const {
    return engineSize;
}

template<typename EngineType>
void CarTemplate<EngineType>::setEngineSize(const EngineType& eSize) {
    engineSize = eSize;
}

template<typename EngineType>
void CarTemplate<EngineType>::displayInfo() const {
    std::cout << "Model: " << model << ", Year: " << year << ", Engine size: " << engineSize << "\n";
}

