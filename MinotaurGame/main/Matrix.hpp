// Autori: Meris Bilalovic, SV1/2023
// Datum poslednje izmene : 15.02.2025.

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include "Cell.hpp"
#include <random>
#include <tuple>
#include "Robot.hpp"

#include <fstream>

using namespace std;

// Klasa Matrix predstavlja lavirint (matricu) u igri.
// Sadrzi privatne atribute za broj redova i kolona, pokazivac na dinamicki alociranu matricu pokazivaca na objekte klase
// Cell ili njenih izvedenih klasa, nasumicne brojeve za generisanje ulaza, izlaza i Minotaura, vektor koji cuva putanju 
// kroz lavirint i broj celija u putanji.
// Klasa ima konstruktor sa argumentima za inicijalizaciju dimenzija lavirinta, kao i podrazumevani konstruktor i 
// destruktor.
// Omogucava kretanje robota po X i Y osi, generisanje i ispis lavirinta, ispis lavirinta sa maglom rata, kao i 
// generisanje rezultata igre u fajl.
// Sadrzi getere za broj redova, kolona, velicinu putanje i samu putanju, kao i funkcije za pronalazenje pozicije 
// odredjenog karaktera i proveru da li je polje deo putanje.
// Operator [] je preklopljen za pristup redovima matrice lavirinta.
// Svi atributi su privatni, dok su konstruktor, destruktor, geteri, seteri, funkcije clanice i operator [] javni.

class Matrix {
private:
	int rows;
	int cols;
	Cell*** matrix;
	int randomNumber;
	int startRandomNumber;
	int endRandomNumber;
	std::vector <std::pair<int, int>> path;
	int pathSize;

	void allocateMemory(int rows, int cols);
	void createPath(int startX, int startY, int endX, int endY);
	void freeMemory();

public:
	Matrix(int newRows, int newCols);
	Matrix();
	~Matrix();
	int getRows() const;
	int getCols() const;
	int getPathSize() const;
	void printPath() const;
	std::vector <std::pair<int, int>> getPath() const;
	void printRandomNumber() const;
	bool findInPath(int x, int y) const;
	tuple<int, int> findPosition(char c);
	Cell** operator[](int index);
	friend ostream& operator<<(ostream& os, const Matrix& matrix);
	void printFogWarMatrix(ostream& os, Robot& robot);
	bool moveElementPerX(Robot& robot, int newPositionX, int oldPositionX, int oldPositionY, bool& end);
	bool moveElementPerY(Robot& robot, int newPositionY, int oldPositionX, int oldPositionY, bool& end);
	Cell* const* operator[](int index) const;
};
#endif // !MATRIX_HPP
