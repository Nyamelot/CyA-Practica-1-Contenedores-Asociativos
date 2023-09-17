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

int main(const char* argv[], const int argc) {
  std::map<std::string, std::vector<double>> contenedor = CalificacionMultiple("Example.txt");
  for (const auto& elements : contenedor) {
    std::cout << elements.first;
    for (const auto& grades : elements.second){
      std::cout << " " << grades;
    }
    std::cout << std::endl;
  }
  return 0;
}
