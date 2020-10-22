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

// Genera numeros hasta el rango superior descartando los no capicua
std::vector<PalindromeNumber> 
NumberGenerator(const int kRangeSuperior, int first_operand) {
  int result = 0;
  std::vector<PalindromeNumber> palindrome_list(0);
  PalindromeNumber container;
  while (first_operand <= kRangeSuperior) {   
    for (int second_operand = first_operand; second_operand <= kRangeSuperior; 
        ++second_operand) { 
      result = first_operand * second_operand;
      if (IsPalindrome(result)) {
        container.first_operand = first_operand;
        container.second_operand = second_operand;
        container.palindrome_number = result;
        palindrome_list.push_back(container);  // Gracias a esta función no se necesita guardar espacio
      }
    }
    first_operand++;
  }
  return palindrome_list;
}

// Da true si el número dado es capicua
bool IsPalindrome(int palindrome) {  
 bool isPalindrome = true;
 int aux = 0, palindrome_copy = palindrome, compare = 0;
 while (palindrome_copy != 0) {  
    aux = palindrome_copy % 10; 
    palindrome_copy = palindrome_copy / 10; 
    compare = compare * 10 + aux; 
  }
  if (palindrome != compare)
    isPalindrome = false;
  return isPalindrome;
}

// Reorganiza el vector de palindromos por orden ascendente
void Organize(std::vector<PalindromeNumber>& palindrome_list) {
  PalindromeNumber organizador;
  for (unsigned counter = 0; counter < palindrome_list.size(); counter++) 
    for (unsigned actual_number = 0; 
         actual_number < palindrome_list.size() - 1; actual_number++)  
      if (palindrome_list[actual_number].palindrome_number >      
          palindrome_list[actual_number + 1].palindrome_number) {   //Ordena de menor a mayor
        organizador = palindrome_list[actual_number];
        palindrome_list[actual_number] = palindrome_list[actual_number + 1];
        palindrome_list[actual_number + 1] = organizador;
      }
}

// Escribe en el fichero todo lo que se encuentre en el vector
void WriteOnFile(const std::vector<PalindromeNumber> kPalindromeList, 
                 const char *kFile) {
  std::ofstream writer(kFile);
  if (!writer.is_open()) {
    std::cout << "Error opening file.\n";
  } else {
    for (unsigned actual_number = 0; actual_number < kPalindromeList.size(); 
         actual_number++)
      writer << kPalindromeList[actual_number].palindrome_number << " = " 
             << kPalindromeList[actual_number].first_operand << " x " 
             << kPalindromeList[actual_number].second_operand << "\n";
  } 
  writer.close();
 }