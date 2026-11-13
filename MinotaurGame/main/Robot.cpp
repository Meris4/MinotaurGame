// Autori: Meris Bilalovic, SV1/2023
// Datum poslednje izmene : 15.02.2025.

#ifndef ROBOT_CPP
#define ROBOT_CPP

#include "Robot.hpp"
#include "Cell.hpp"
#include "Items.hpp"


#include <ostream>
#include <iostream>
#include <unordered_map>
using namespace std;

// Konstruktor Robot
// Kreira robota na zadatoj poziciji i sa zadatim tipom celije.
// Ulazni argumenti:
//   - x: X koordinata robota
//   - y: Y koordinata robota
//   - type: karakter koji oznacava tip celije ('R')
// Povratna vrednost: nema
Robot::Robot(unsigned int x, unsigned int y, char type) : Cell(x, y, type) {}

// Funkcija applyEffect
// Dodaje efekat robotu i ispisuje poruku o primeni efekta.
// Ulazni argumenti:
//   - effect: naziv efekta (npr. "sword", "shield", "fogWar", "hummer")
// Povratna vrednost: nema
void Robot::applyEffect(Cell* itemCell) {
    //addEffect(effect);
    int duration = 3;

    std::string effect = itemCell->getType();

    if (effect == "fogWar") {           
        //std::cout << "Primena efekta fogWar!" << std::endl;
        duration = static_cast<FogWar*>(itemCell)->duration;
    }
    else if (effect == "sword") {
        //std::cout << "Primena efekta sword!" << std::endl;
        duration = static_cast<Sword*>(itemCell)->duration;
    }
    else if (effect == "shield") {           
        //std::cout << "Primena efekta shield!" << std::endl;
        duration = static_cast<Shield*>(itemCell)->duration;
    }
    else if (effect == "hummer") {
        //std::cout << "Primena efekta hummer!" << std::endl;
        duration = static_cast<Hummer*>(itemCell)->duration;
    }
    addEffect(itemCell->getType(), duration);

    std::cout << "Primena efekta " << itemCell->getType() << "!" << std::endl;
}

// Funkcija updateEffects
// Smanjuje trajanje svih aktivnih efekata za jedan potez i uklanja one kojima je istekao rok.
// Ulazni argumenti: nema
// Povratna vrednost: nema
void Robot::updateEffects() {
    for (auto it = activeEffects.begin(); it != activeEffects.end(); ) {
        if (--it->second == 0) {
            it = activeEffects.erase(it);

        }
        else {
            ++it;
            cout << "Smanjio sam trajanje" << endl;
        }
    }
}

// Funkcija hasEffect
// Proverava da li robot ima aktivan odredjeni efekat.
// Ulazni argumenti:
//   - effect: naziv efekta
// Povratna vrednost: true ako je efekat aktivan, false inace
bool Robot::hasEffect(const string& effect) const {
    return activeEffects.find(effect) != activeEffects.end();
}

// Funkcija addEffect
// Dodaje efekat robotu i postavlja njegovo trajanje na 3 poteza.
// Ulazni argumenti:
//   - effect: naziv efekta
// Povratna vrednost: nema
void Robot::addEffect(const string& effect, int duration) {
    activeEffects[effect] = duration;     // Efekat traje 3 poteza
}

// Funkcija printEffects
// Ispisuje sve aktivne efekte robota i koliko još poteza traju.
// Ulazni argumenti: nema
// Povratna vrednost: nema
void Robot::printEffects() const {
    for (const auto& effect : activeEffects) {
        cout << "Efekat: " << effect.first << " traje jos " << effect.second << " poteza." << endl;
    }
}


#endif // ROBOT_CPP