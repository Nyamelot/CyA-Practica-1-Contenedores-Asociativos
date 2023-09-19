// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnología
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

void MainMenu::Run() {
    int number = 0;
    do {
      std::cout << "Do you want to add elements to the container?" << std::endl;
      std::cout << R"( 
              ·Press 1 to add elements
              ·Press 2 to exit the current action)";
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
          return;
      }
    } while (number != 2);
  }



void MainMenu::AddSingle() {
  std::string alu;
  
  double grade;
  std::cout << "Introduce the key: " << std::endl;
  std::cin >> alu;
  std::cout << "Introduce the grade: " << std::endl;
  std::cin >> grade;
  single_grade_.emplace(alu, grade);
}

void MainMenu::AddMultiple() {
  std::string alu;
  double grade;
  std::vector<double> grades;
  std::cout << "Introduce the key: " << std::endl;
  std::cin >> alu;
  std::cout << "Introduce a series of grades(with spaces, dont press enter): " << std::endl;
  while (std::cin >> grade) {
    grades.emplace_back(grade);
  }
  multiple_grades_.emplace(alu, grades);
}
