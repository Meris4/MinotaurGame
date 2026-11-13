// Autori: Meris Bilalovic, SV1/2023
// Datum poslednje izmene : 15.02.2025.

//#ifndef CELL_CPP
//#define CELL_CPP

//#include "pch.h"
#include "Cell.hpp"
#include <ostream>
#include <iostream>


// Konstruktor Cell
// Kreira novu celiju na zadatoj poziciji i sa zadatim tipom.
// Ulazni argumenti:
//   - newX: X koordinata celije
//   - newY: Y koordinata celije
//   - newCellType: karakter koji oznacava tip celije ('#', '.', 'R', 'M', 'P')
// Povratna vrednost: nema
Cell::Cell(unsigned int newX, unsigned int newY, char newCellType) : x(newX), y(newY), cellType(newCellType) {}

// Podrazumevani konstruktor Cell
// Kreira praznu celiju na poziciji (0,0) i sa praznim tipom.
// Ulazni argumenti: nema
// Povratna vrednost: nema
Cell::Cell() : x(0), y(0), cellType(' ') {}

// Destruktor ~Cell
// Unistava objekat celije. Virtuelan zbog nasledjivanja.
// Ulazni argumenti: nema
// Povratna vrednost: nema
Cell::~Cell() {} \

// Funkcija getX
// Vraca X koordinatu celije.
// Ulazni argumenti: nema
// Povratna vrednost: X koordinata (unsigned int)
unsigned int Cell::getX() {
	return x;
}

// Funkcija setX
// Postavlja X koordinatu celije.
// Ulazni argumenti: newX - nova X koordinata
// Povratna vrednost: nema
void Cell::setX(unsigned int newX) {
	x = newX;
}

// Funkcija getY
// Vraca Y koordinatu celije.
// Ulazni argumenti: nema
// Povratna vrednost: Y koordinata (unsigned int)
unsigned int Cell::getY() {
	return y;
}

// Funkcija setY
// Postavlja Y koordinatu celije.
// Ulazni argumenti: newY - nova Y koordinata
// Povratna vrednost: nema
void Cell::setY(unsigned int newY) {
	y = newY;
}

// Funkcija getCellType
// Vraca karakter koji oznacava tip celije.
// Ulazni argumenti: nema
// Povratna vrednost: karakter tipa celije (char)
char Cell::getCellType() {
	return cellType;
}

// Funkcija setCellType
// Postavlja karakter koji oznacava tip celije.
// Ulazni argumenti: newCellType - novi tip celije
// Povratna vrednost: nema
void Cell::setCellType(char newCellType) {
	cellType = newCellType;
}

// Funkcija getType
// Vraca string koji oznacava tip celije (osnovni ili izvedeni tip).
// Ulazni argumenti: nema
// Povratna vrednost: string sa tipom
string Cell::getType() const {
	return "base";
}

// Funkcija setType
// Postavlja string koji oznacava tip celije.
// Ulazni argumenti: newType - novi string tipa
// Povratna vrednost: nema
void Cell::setType(string newType) {
	type = newType;
}

// Operator dodele (=) za Cell
// Omogucava dodelu vrednosti iz druge celije.
// Ulazni argumenti: other - referenca na drugu celiju
// Povratna vrednost: referenca na ovu celiju
Cell& Cell::operator=(const Cell& other) {
	if (this != &other) {
		this->x = other.x;
		this->y = other.y;
		this->cellType = other.cellType;
	}

	return *this;
}

// Operator dodele (=) za karakter
// Postavlja tip celije na zadati karakter.
// Ulazni argumenti: otherChar - karakter tipa celije
// Povratna vrednost: referenca na ovu celiju
Cell& Cell::operator=(const char& otherChar) {
	this->cellType = otherChar;
	return *this;
}

// Operator nejednakosti (!=)
// Proverava da li se tip celije razlikuje od zadatog karaktera.
// Ulazni argumenti: otherChar - karakter za poredjenje
// Povratna vrednost: true ako su razliciti, false ako su isti
bool Cell::operator!=(const char& otherChar) {
	if (this->cellType != otherChar) {
		return true;
	}
	return false;
}

// Operator <<
// Ispisuje tip celije na izlazni tok.
// Ulazni argumenti: os - izlazni tok, cell - referenca na celiju
// Povratna vrednost: referenca na izlazni tok
ostream& operator<<(ostream& os, const Cell& cell) {
	os << cell.cellType;
	return os;
}



//#endif // CELL_CPP