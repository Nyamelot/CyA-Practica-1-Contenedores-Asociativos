// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 14/09/2023
// Archivo main.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)

#include <map>
#include <iostream>
#include <vector>

#include "container.h"
#include "usage.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  int number = 3;
  std::map<std::string, double> single_grades;
  std::map<std::string, std::vector<double>> multiple_grades;
  std::string alu;
  double grade;
  do {
    std::cout << "Introduce a number to select which action you want to carry out" << std::endl;
    std::cout << R"(
                  ·1 Order the selected file with the highest value of each key
                  ·2 Order the selected file showing all the values of a same key in a consequent order
                  ·0 End the program)";
    std::cout << std::endl;
    std::cin >> number;
    std::cout << std::endl;
    switch(number) {
      default:
        std::cout << "Incorrect number" << std::endl << std::endl;
        break;
    
      case 1:
        single_grades = SingleGrade(argv[1]);
          for (const auto& element : single_grades) {
            std::cout << element.first << " " << element.second << std::endl;
          }
          std::cout << std::endl;
        break;
      
      case 2:
        multiple_grades = MultipleGrade(argv[1]);
          for (const auto& elements : multiple_grades) {
            std::cout << elements.first;
            for (const auto& grades : elements.second){
              std::cout << " " << grades;
            }
          std::cout << std::endl;
        }
        std::cout << std::endl;
        break;

      case 0:
        break;  
        
    } 
  } while(number != 0);
  
  return 0;
}
