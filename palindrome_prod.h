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

#ifndef PALINDROME_PROD_H
#define PALINDROME_PROD_H

struct PalindromeNumber {
    int palindrome_number;
    int first_operand;
    int second_operand;
};

std::vector<PalindromeNumber> 
NumberGenerator(const int kRangeSuperior, int first_operand);
bool IsPalindrome(int palindrome);
void Organize(std::vector<PalindromeNumber>& palindrome_list);
void WriteOnFile(const std::vector<PalindromeNumber> kPalindromeList, 
                 const char *kFile); 


#endif