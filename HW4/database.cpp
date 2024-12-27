#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <unordered_map>
/* STUDENT TODO: include the optional package! */
#include <optional>

// Forward declarations
std::vector<std::string> split(std::string s, char delim);

// Class struct definiton; should be familiar for assignment 1!
struct Class {
  std::string title;
  std::string number_of_units;
  std::string quarter;

  // You don't have to ignore this anymore! We're defining the '==' operator for
  // the Class struct
  bool operator==(const Class &other) const {
    return title == other.title && number_of_units == other.number_of_units &&
           quarter == other.quarter;
  }
};

void parse_csv(std::string filename, std::vector<Class> &vector_of_classes) {
  std::fstream f(filename);
  std::string line;
  while (getline(f, line)) {
    auto struct_contents = split(line, ',');
    Class new_class{struct_contents[0], struct_contents[1], struct_contents[2]};
    vector_of_classes.push_back(new_class);
  }
  f.close();
}

// This is the database definition!
class Database {
private:
  std::unordered_map<std::string, Class> database_;
  std::vector<Class> classes_;
  std::vector<Class> classes_to_erase;
  int num_time_f_called = 0;

public:
  Database(std::string filename) {
    // This is logic to randomly add classes into the database
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);
    parse_csv(filename, classes_);
    std::vector<Class> classes_to_erase;

    for (const Class &class_ : classes_) {
      if (distrib(gen) == 1) {
        database_.insert(std::make_pair(class_.title, class_));
      } else {
        classes_to_erase.push_back(class_);
      }
    }

    for (auto class_ : classes_to_erase) {
      auto it = std::find(classes_.begin(), classes_.end(), class_);
      classes_.erase(it);
    }
  }

  const std::vector<Class> classes() {
    num_time_f_called++;
    return classes_;
  };

  // STUDENT TODO: Define the get_classes function which retreives from the
  // database
  // ? ? ? ? ? find_class(const std::string class_name) {
  //   /* STUDENT TODO */ }
  std::optional<Class> find_class(const std::string& class_name) {
    auto it = database_.find(class_name);
    if (it != database_.end()) {
        return it->second;
    } else {
        return std::nullopt;
    }
  }
};

std::vector<std::string> split(std::string s, char delim) {
    std::vector<std::string> return_vec;
    std::stringstream ss(s);
    std::string token;
    while (getline(ss, token, delim)) {
      return_vec.push_back(token);
    }
    return return_vec;
}