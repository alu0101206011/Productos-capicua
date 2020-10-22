//
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Computabilidad de algoritmia
//
// @author Anabel Díaz Labrador
// @date 17 Sep 2020
// @brief Programa que encuentr números capicúas multiplicando dos números 
// de mismo tamaño
// @email alu0101206011@ull.edu.es
// Versions: Vector stl de structs
//
// @see https://es.wikipedia.org/wiki/Pal%C3%ADndromo
// @see https://es.wikipedia.org/wiki/Capic%C3%BAa
// 
// g++ -std=c++17 -g -Wall -o palindrome_prod palindrome_prod.cc
//


#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

#include "palindrome_prod.h"


int main(int argc, char *argv[]) {
  if (argc != 3 && argc != 2) {
    std::cout << "Too few arguments to function.\n" 
              << "Write ./palindrome_prod --help para mas info\n";
    return 0;
  }
  if ((std::string)argv[1] == "--help" || (std::string)argv[1] == "-h") {
    std::cerr << "Usage: " << argv[0] << " [NATURAL NUMBER] [FILE]" 
              << "\nFor OPTION:\n" 
              << "\t-h,--help\t\tShow this help message\n";
    return 0;
  }
  if (!((int)atoi(argv[1]) > 0)) {
    std::cout << "Valor introducido no valido." 
              << " Introduzca un número natural.\n"
              << "Escriba ./palindrome_prod --help para mas info\n";
    return 0;
  }
  if (argv[2] == NULL) {
    std::cout << "Falta archivo. \n"
              << "Escriba ./palindrome_prod --help para mas info\n";
    return 0;
  }
  const int kSize = atoi(argv[1]);
  const int kRangeSuperior = pow (10, kSize) - 1;
  int selector = pow (10, (kSize - 1));

  std::vector<PalindromeNumber> 
  palindrome_list = NumberGenerator(kRangeSuperior, selector);
  Organize(palindrome_list);
  WriteOnFile(palindrome_list, argv[2]);

  return 0;
}


