
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <map>
#include <iostream>
#include <vector>

#include "container.h"

class MainMenu {
 public:
  void Start {
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
  }



 private:
};

#endif
