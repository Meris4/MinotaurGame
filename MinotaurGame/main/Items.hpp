// Autori: Meris Bilalovic, SV1/2023
// Datum poslednje izmene : 15.02.2025.

#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <string>
#include "Cell.hpp"

// Svaka klasa predstavlja poseban tip predmeta koji moze imati efekat na robota tokom igre.
// Predmeti nasledjuju klasu Cell i sadrze dodatni atribut duration koji oznacava trajanje efekta.
// Klase omogucavaju kreiranje predmeta na zadatoj poziciji i identifikaciju tipa predmeta.


class FogWar : public Cell {
public:
    int duration;
    FogWar(unsigned int newX, unsigned int newY, char newCellType);
    FogWar();
    std::string getType() const override;
};

class Sword : public Cell {    
public:
    int duration;
    Sword(unsigned int newX, unsigned int newY, char newCellType);
    Sword();
    std::string getType() const override;
};

class Shield : public Cell {
public:
    int duration;
    Shield(unsigned int newX, unsigned int newY, char newCellType);
    Shield();
    std::string getType() const override;
};

class Hummer : public Cell {
public:
    int duration;
    Hummer(unsigned int newX, unsigned int newY, char newCellType);
    Hummer();
    std::string getType() const override;
};

#endif // ITEMS_HPP






































//#ifndef ITEMS_HPP
//#define ITEMS_HPP
//
//#include <iostream>
//#include "Cell.hpp"
//
//using namespace std;
//
//class FogWar : public Cell {
//protected:
//	int duration;
//
//public:
//	FogWar(unsigned int newX, unsigned int newY, char newCellType);
//	FogWar();
//	string getType() const override;
//};
//
//class Sword : public Cell {
//protected:
//	int duration;
//
//public:
//	Sword(unsigned int newX, unsigned int newY, char newCellType);
//	Sword();
//	string getType() const override;
//};
//
//class Shield : public Cell {
//protected:
//	int duration;
//
//public:
//	Shield(unsigned int newX, unsigned int newY, char newCellType);
//	Shield();
//	string getType() const override;
//};
//
//class Hummer : public Cell {
//protected:
//	int duration;
//
//public:
//	Hummer(unsigned int newX, unsigned int newY, char newCellType);
//	Hummer();
//	string getType() const override;
//};
//
//
//#endif // !ITEMS_HPP
