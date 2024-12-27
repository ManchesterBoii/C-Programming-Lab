/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 2/16/2024.
*/

// TODO: import anything from the STL that might be useful!
#include <iostream>
#include <vector>
#include <fstream> 
#include <numeric> 
#include <functional> 
#include <algorithm>



// TODO: write convert_f_to_c function here. Remember it must be a template function that always returns
// a double.
// [function definition here]
template<typename T>
double convert_f_to_c(T temperatureF) {
    return (static_cast<double>(temperatureF) - 32) * 5.0 / 9.0;
}



template<typename Function>
std::vector<double> get_forecast(std::vector<std::vector<int>> readings, Function fn) {
    std::vector<double> forecast;
    for (const auto& day : readings) {
        // Convert the day's readings to Celsius
        std::vector<double> dayInCelsius;
        std::transform(day.begin(), day.end(), std::back_inserter(dayInCelsius), convert_f_to_c<int>);
        
        forecast.push_back(fn(dayInCelsius));
    }
    return forecast;
}


int main() {
    std::vector<std::vector<int>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };

// Define lambda functions for max, min, and average
    auto maxTemp = [](const std::vector<double>& day) -> double {
        return *std::max_element(day.begin(), day.end());
    };
    auto minTemp = [](const std::vector<double>& day) -> double {
        return *std::min_element(day.begin(), day.end());
    };
    auto avgTemp = [](const std::vector<double>& day) -> double {
        return std::accumulate(day.begin(), day.end(), 0.0) / day.size();
    };

    std::ofstream outputFile("output.txt");

    auto maxTemps = get_forecast(readings, maxTemp);
    auto minTemps = get_forecast(readings, minTemp);
    auto avgTemps = get_forecast(readings, avgTemp);

    // Output max temperatures
    outputFile << "Max Temps: ";
    for (const auto& temp : maxTemps) outputFile << temp << " ";
    outputFile << "\n";

    // Output min temperatures
    outputFile << "Min Temps: ";
    for (const auto& temp : minTemps) outputFile << temp << " ";
    outputFile << "\n";

    // Output average temperatures
    outputFile << "Avg Temps: ";
    for (const auto& temp : avgTemps) outputFile << temp << " ";
    outputFile << "\n";

    outputFile.close();

    return 0;

    return 0;
}