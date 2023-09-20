// Universidad de La Laguna
// Escuela Superior de Ingenieríıa y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 14/09/2023

#include <map>
#include <string>
#include <vector>

std::map<std::string, double> SingleGrade(const std::string& file_path);
std::map<std::string, std::vector<double>> MultipleGrade(const std::string& file_path);
