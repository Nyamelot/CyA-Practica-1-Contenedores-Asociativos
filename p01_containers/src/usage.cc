// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 14/09/2023

#include <string>
#include <iostream>

const std::string kTitle = "p01-containers";
const std::string kHelpText =
  R"(Como usar: para usar este programa se tendra que ejecutar de esta manera ./a.out file.txt
   >> Parameters:
       - a.out es el ejecutable
       - file.txt: es el archivo que se va a leer)";

void Usage(int argc, char* argv[]) {
  const std::string kHelp = "--help";
  if (argc == 1) {
    std::cerr << argv[0] << std::endl << kTitle << std::endl;
    std::cerr << "Forma de uso: " << argv[0]
              << "archivo.txt"
              << std::endl;
    std::cerr << "Prueba " << argv[0] << "--help para más información."
              << std::endl;
    exit(EXIT_FAILURE);
  }
  if (argv[1] == kHelp) {
    std::cout << kTitle << std::endl;
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if ((argc > 2) && (argv [1] != kHelp)) {
    std::cerr << argv[0] << std::endl << kTitle << std::endl;
    std::cerr << "Forma de uso: " << argv[0]
              << "archivo.txt"
              << std::endl;
    std::cerr << "Prueba " << argv[0] << "--help para más información."
              << std::endl;
    exit(EXIT_FAILURE);
  }
}