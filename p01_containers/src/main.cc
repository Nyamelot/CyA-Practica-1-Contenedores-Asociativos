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
// Contiene la función main del proyecto que usa las clases MainMenu
// y ElementsMenu que hacen todo el funcionamiento del programa 
// divididos en dos menus.

#include <map>
#include <iostream>
#include <vector>

#include "container.h"
#include "usage.h"
#include "main_menu.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  MainMenu menu;
  menu.Start(argv[1]);
  return 0;
}
