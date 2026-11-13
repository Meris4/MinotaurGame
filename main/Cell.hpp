// Autori: Meris Bilalovic, SV1/2023
// Datum poslednje izmene : 15.02.2025.

#ifndef CELL_HPP
#define CELL_HPP

#include <ostream>
using namespace std;


// Osnovna klasa za polje(celiju) u lavirintu.
// Sadrzi atribute za poziciju (x, y), tip celije (zid, prazno, predmet, robot, minotaur, itd.) i dodatni string za tip.
// Omogucava dohvatanje i postavljanje pozicije i tipa celije, kao i poredjenje i ispis celije.
// Klasa je osnova za sve specijalizovane tipove celija u igri (predmeti, robot, minotaur).

class Cell {
protected:
	unsigned int x;
	unsigned int y;
	char cellType;

	string type;

public:
	Cell(unsigned int newX, unsigned int newY, char newCellType);
	Cell();
	virtual ~Cell();
	unsigned int getX();
	void setX(unsigned int newX);
	unsigned int getY();
	void setY(unsigned int newY);
	char getCellType();
	void setCellType(char newCellType);
	virtual string getType() const;
	void setType(string newType);
	Cell& operator=(const Cell& other);
	Cell& operator=(const char& otherChar);
	bool operator!=(const char& otherChar);
	friend ostream& operator<<(ostream& os, const Cell& cell);

};


#endif // !CELL_HPP

