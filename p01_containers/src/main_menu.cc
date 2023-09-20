// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 14/09/2023


#include "main_menu.h"


void MainMenu::Case1(const std::string& file_path) {
  single_grade_ = SingleGrade(file_path);
  for (const auto& element : single_grade_) {
    std::cout << element.first << " " << element.second << std::endl;
  }
}

void MainMenu::Case2(const std::string& file_path) {
  multiple_grades_ = MultipleGrade(file_path);
  for (const auto& elements : multiple_grades_) {
    std::cout << elements.first;
    for (const auto& grades : elements.second){
      std::cout << " " << grades;
    }
    std::cout << std::endl;
  }
}

void MainMenu::MenuElements() {
    int number = 0;
    do {menu
              ·Press 1 to add elements
              ·Press 2 print the container
              ·Press 3 to exit the current action)";
      if (!is_single_) {
        std::cout << std::endl << "·Press 4 to search a grade";
      }
      std::cout << std::endl; 
      std::cin >> number;

      switch (number) {
        case 1:
          if (is_single_) {
            AddSingle();
            
            break;
          } else {
            AddMultiple();
            break;
          }
        case 2:
          if (is_single_) {
            for (const auto& elements : single_grade_) {
              std::cout << elements.first << ' ' << elements.second << std::endl;
            }
            break;
          } else {
            for (const auto& elements : multiple_grades_) {
              std::cout << elements.first;
              for (const auto& grade : elements.second) {
                std::cout << ' ' << grade;
              }
              std::cout << std::endl;
            }
            break;
          }
        
        case 4:
          if (!is_single_) {
            SearchGrade();
            break;
          } 
          break;

        case 3:
          return;  
      }
    } while (number != 3);
  }



void MainMenu::AddSingle() {
  std::string alu;
  double grade;
  std::cout << "Introduce the key: " << std::endl;
  std::cin >> alu;
  std::cout << "Introduce the grade: " << std::endl;
  std::cin >> grade;
  if (!single_grade_.count(alu)) {
    single_grade_.emplace(alu, grade);
  } else if (grade > single_grade_.at(alu)) {
    single_grade_.at(alu) = grade;
  }
  
}

void MainMenu::AddMultiple() {
  char end_input;
  std::string alu;
  double grade;
  std::vector<double> grades;
  std::cout << "Introduce the key: " << std::endl;
  std::cin >> alu;
  std::cout << "Introduce a series of grades(press q to end input): " << std::endl;
  while (std::cin >> grade) {
    grades.emplace_back(grade);
  }
  std::cin.clear();
  std::cin >> end_input;
  if (!multiple_grades_.count(alu)) {
    multiple_grades_.emplace(alu, grades);
  } else {
    for (const auto& grade : grades) {
      multiple_grades_.at(alu).emplace_back(grade);
    }
  }
}

void MainMenu::SearchGrade() {
  double nota;
  std::cout << "Introduce una nota para buscar: ";
  std::cin >> nota;
  std::cout << std::endl;
  for (const auto& elements : multiple_grades_) {
    bool check = true;
    for (const auto& grades : elements.second){
      if (grades == nota && check) {
        check = false;
        std::cout << elements.first << std::endl << std::endl;
      }
    }
  }
}
