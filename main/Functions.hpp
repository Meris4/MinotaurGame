// Autori: Meris Bilalovic, SV1/2023
// Datum poslednje izmene : 15.02.2025.

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP


#pragma once
#include "Matrix.hpp"
#include "Robot.hpp"
#include <random>


// Sadrzi deklaracije glavnih slobodnih funkcija za unos podataka, popunjavanje lavirinta predmetima i pokretanje igre.
// Omogucava interaktivni unos dimenzija i broja predmeta, inicijalizaciju i popunjavanje lavirinta.

bool inputStartingData(bool& rowsBool, bool& colsBool, bool& itemBool, int& rows, int& cols, int& item);
void fillMatrix(Matrix& matrix, int item, int& rows, int& cols, std::mt19937& gen);

#endif // !FUNCTIONS_HPP