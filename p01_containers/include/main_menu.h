// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 14/09/2023

/**
 * @file main_menu.h
 * @brief Header file for the MainMenu class.
 *
 * This file contains the declaration of the MainMenu class, which provides a menu-driven
 * interface for selecting actions related to ordered files and containers.
 */


#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "container.h"

#include <map>
#include <iostream>
#include <vector>

class ElementsMenu;

/**
 * @class MainMenu
 * @brief A class for managing menu-driven actions related to ordered files and containers.
 *
 * The MainMenu class allows the user to choose between different actions related to ordered files
 * and containers, such as ordering files based on key values or displaying values for the same key
 * in a consecutive order.
 */
 
class MainMenu {
 public:
  void Case1(const std::string& file_path);
  void Case2(const std::string& file_path);
  void AddSingle();
  void AddMultiple();
  void MenuElements();
  void SearchGrade();

  inline void Start (const std::string& file_path) {
    int number = 3;
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
          Case1(file_path);
          is_single_ = true;
          MenuElements();
          std::cout << std::endl;
          break;
      
        case 2:
          Case2(file_path);
          is_single_ = false;
          MenuElements();
          std::cout << std::endl;
          break;

      case 0:
        break;  
        
      } 
    } while(number != 0);
  }

 private:
  std::map<std::string, double> single_grade_;
  std::map<std::string, std::vector<double>> multiple_grades_;
  bool is_single_;
};

#endif
