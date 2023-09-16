// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 14/09/2023

#include <iostream>
#include <map>
#include <string>

void CalificacionUnica(std::map<std::string, double> contenedor) {
  std::map<std::string, double> calificacion_unica;
  for (const auto& element : contenedor) {
    std::map<std::string, double>::iterator it;
    it = contenedor.find(element.first);
    if (!(it == contenedor.end())) {
      if (element.second > it -> second) {
        calificacion_unica.emplace(element);
      } else {
        calificacion_unica.emplace(it);
      }
    }
  }
}
