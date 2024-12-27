#include "database.cpp"
#include <fstream>
#include <optional>
#include <ostream>
#include <unordered_set>

const std::string COURSES_FILEPATH = "courses.csv";
const std::string STUDENT_COURSES_FILEPATH = "student_courses.csv";

void create_correct_file(Database &db) {
  std::ofstream f("correct_file.csv");
  std::unordered_set<std::string> already_added;
  const std::vector<Class> classes = db.classes();
  for (const auto &class_ : classes) {
    if (already_added.count(class_.title) == 0) {
      f << class_.title << "," << class_.number_of_units << ","
        << class_.quarter << '\n';
      already_added.insert(class_.title);
    }
  }
  f.close();
}

bool files_are_the_same(const std::string &f1, const std::string &f2) {
  std::ifstream file1(f1, std::ifstream::binary | std::ifstream::ate);
  std::ifstream file2(f2, std::ifstream::binary | std::ifstream::ate);

  char buffer1, buffer2;
  while (true) {
    buffer1 = file1.get();
    buffer2 = file2.get();
    if (buffer1 != buffer2) {
      return false;
    }
    if (file1.eof() && file2.eof()) {
      break;
    }
  }
  return true;
}

int main() {
  Database db(COURSES_FILEPATH);
  create_correct_file(db);
  std::unordered_set<std::string> already_added;

  std::ofstream ofile(STUDENT_COURSES_FILEPATH);
  std::fstream f(COURSES_FILEPATH);
  std::string line;
  while (getline(f, line)) {
    auto struct_contents = split(line, ',');
    std::optional<Class> found_class = db.find_class(struct_contents[0]);

    // // STUDENT TODO: add condition to check if optional has a value
    // if (/* How do you check if an optional has a value? */ already_added.count(
    //         struct_contents[0]) == 0) {
    //   ofile << found_class.value().title << ","
    //         << found_class.value().number_of_units << ","
    //         << found_class.value().quarter << '\n';
    // }

    if (found_class.has_value() && already_added.count(struct_contents[0]) == 0) {
        ofile << found_class->title << ","
              << found_class->number_of_units << ","
              << found_class->quarter << '\n';
        already_added.insert(struct_contents[0]);
      }

  }
  f.close();

  if (files_are_the_same("correct_file.csv", "student_courses.csv")) {
    std::cout << "Great job! 🤠✅" << std::endl;
  } else {
    std::cout << "Whoops, the files aren't the same ❌" << std::endl;
  }

  return 0;
}