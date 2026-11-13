// Autori: Meris Bilalovic, SV1/2023
// Datum poslednje izmene : 15.02.2025.

#ifndef ROBOT_HPP
#define ROBOT_HPP


#include "Cell.hpp"
#include <ostream>
#include <unordered_map>
using namespace std;


// Klasa Robot predstavlja robota koji se krece kroz lavirint.
// Nasledjuje klasu Cell i prosiruje je funkcionalnostima za efekte (predmete) koje robot moze da poseduje.
// Sadrzi privatni atribut activeEffects koji mapira naziv efekta na broj preostalih poteza tog efekta.
// Klasa omogucava dodavanje, azuriranje i proveru efekata, kao i ispis svih aktivnih efekata robota.
// Konstruktor omogucava inicijalizaciju robota na zadatoj poziciji i sa zadatim tipom.
// Svi atributi su privatni, dok su konstruktor i funkcije clanice javni.

class Robot : public Cell {
private:
    unordered_map<string, int> activeEffects;

public:
    Robot(unsigned int x, unsigned int y, char type);
    void applyEffect(Cell* itemCell);
    void updateEffects();
    bool hasEffect(const string& effect) const;
    void addEffect(const std::string& effect, int duration);
    void printEffects() const;
};


#endif // !ROBOT_HPP
