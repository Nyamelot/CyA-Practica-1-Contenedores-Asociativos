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
 * @file containers.cpp
 * @brief Implementation file for the main functionality of the program.
 *
 * This file contains the implementation of functions for reading and processing input files
 * to create associative containers with student grades.
 */

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

/**
 * @brief Splits a string into substrings based on a query character.
 *
 * @param input_string The input string to be split.
 * @param query_char The character used for splitting the string.
 * @return A vector of substrings obtained by splitting the input string.
 */
std::vector<std::string> Split(const std::string& input_string, const char querry_char) {
  std::vector<std::string> characters;
  std::stringstream character;
  for (char symbol : input_string) {
    if (symbol != querry_char) {
      character << symbol;
      continue;
    }
    characters.emplace_back(character.str());
    character.str(std::string());
  }
  characters.emplace_back(character.str());
  return characters;
}

/**
 * @brief Reads lines from an input file and stores them in a vector.
 *
 * @param input_files The input file stream to be read.
 * @return A vector of strings, each representing a line from the input file.
 */
std::vector<std::string> FileReader(std::ifstream& input_files) {
  std::vector<std::string> text_file;
  std::string text_line;
  while (!input_files.eof()) {
    std::getline(input_files, text_line);
    text_file.emplace_back(text_line);
  }
  return text_file;
}

/**
 * @brief Processes an input file and creates a map of student IDs to their highest grades.
 *
 * @param file_path The path to the input file.
 * @return A map where keys are student IDs and values are their highest grades.
 * @throws std::runtime_error if the input format is invalid.
 */
std::map<std::string, double> SingleGrade(const std::string& file_path) {
  std::ifstream input_file(file_path);
  const auto lines = FileReader(input_file);
  std::map<std::string, double> result;
  for (const auto& line : lines) {
    const auto line_split = Split(line, ' ');
    if (line_split.size() < 2 || line_split.size() > 2) {
      throw std::runtime_error("Invalid input format");
    }
    std::string alu = line_split[0];
    double marks = std::stod(line_split[1]);
    if (!result.count(alu)) {
      result.emplace(alu, marks);
    } else if (marks > result.at(alu)) {
      result.at(alu) = marks;
    }
  }
  return result;
}

/**
 * @brief Processes an input file and creates a map of student IDs to their grade vectors.
 *
 * @param file_path The path to the input file.
 * @return A map where keys are student IDs and values are vectors of their grades.
 * @throws std::runtime_error if the input format is invalid.
 */
std::map<std::string, std::vector<double>> MultipleGrade(const std::string& file_path) {
  std::ifstream input_file(file_path);
  const auto lines = FileReader(input_file);
  std::map<std::string, std::vector<double>> result;
  for (const auto& line : lines) {
    const auto line_split = Split(line, ' ');
    if (line_split.size() < 2 || line_split.size() > 2) {
      throw std::runtime_error("Invalid input format");
    }
    std::string alu = line_split[0];
    double marks = std::stod(line_split[1]);
    if (!result.count(alu)) {
      result.emplace(alu, std::vector<double>());
    }
    result.at(alu).emplace_back(marks);
  }
  return result;
}