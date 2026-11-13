// Autori: Meris Bilalovic, SV1/2023
// Datum poslednje izmene : 15.02.2025.

#include "Items.hpp"



// Konstruktor FogWar
// Kreira predmet "magla rata" na zadatoj poziciji sa zadatim tipom celije.
// Ulazni argumenti:
//   - newX: X koordinata predmeta
//   - newY: Y koordinata predmeta
//   - newCellType: karakter koji oznacava tip celije ('P')
// Povratna vrednost: nema
FogWar::FogWar(unsigned int newX, unsigned int newY, char newCellType)
    : Cell(newX, newY, newCellType), duration(4) {
    setType("fogWar");
}

// Podrazumevani konstruktor FogWar
// Kreira predmet "magla rata" na poziciji (0,0) sa podrazumevanim trajanjem.
// Ulazni argumenti: nema
// Povratna vrednost: nema
FogWar::FogWar() : Cell(0, 0, 'P'), duration(4) { setType("fogWar"); }

// Funkcija getType za FogWar
// Vraca string koji oznacava tip predmeta ("fogWar").
// Ulazni argumenti: nema
// Povratna vrednost: string
std::string FogWar::getType() const { return "fogWar"; }


// Konstruktor Sword
// Kreira predmet "mac" na zadatoj poziciji sa zadatim tipom celije.
// Ulazni argumenti:
//   - newX: X koordinata predmeta
//   - newY: Y koordinata predmeta
//   - newCellType: karakter koji oznacava tip celije ('P')
// Povratna vrednost: nema
Sword::Sword(unsigned int newX, unsigned int newY, char newCellType)
    : Cell(newX, newY, newCellType), duration(4) {
    setType("sword");
}

// Podrazumevani konstruktor Sword
// Kreira predmet "mac" na poziciji (0,0) sa podrazumevanim trajanjem.
// Ulazni argumenti: nema
// Povratna vrednost: nema
Sword::Sword() : Cell(0, 0, 'P'), duration(4) { setType("sword"); }

// Funkcija getType za Sword
// Vraca string koji oznacava tip predmeta ("sword").
// Ulazni argumenti: nema
// Povratna vrednost: string
std::string Sword::getType() const { return "sword"; }

// Konstruktor Shield
// Kreira predmet "stit" na zadatoj poziciji sa zadatim tipom celije.
// Ulazni argumenti:
//   - newX: X koordinata predmeta
//   - newY: Y koordinata predmeta
//   - newCellType: karakter koji oznacava tip celije ('P')
// Povratna vrednost: nema
Shield::Shield(unsigned int newX, unsigned int newY, char newCellType)
    : Cell(newX, newY, newCellType), duration(4) {
    setType("shield");
}

// Podrazumevani konstruktor Shield
// Kreira predmet "stit" na poziciji (0,0) sa podrazumevanim trajanjem.
// Ulazni argumenti: nema
// Povratna vrednost: nema
Shield::Shield() : Cell(0, 0, 'P'), duration(4) { setType("shield"); }

// Funkcija getType za Shield
// Vraca string koji oznacava tip predmeta ("shield").
// Ulazni argumenti: nema
// Povratna vrednost: string
std::string Shield::getType() const { return "shield"; }

// Konstruktor Hummer
// Kreira predmet "cekic" na zadatoj poziciji sa zadatim tipom celije.
// Ulazni argumenti:
//   - newX: X koordinata predmeta
//   - newY: Y koordinata predmeta
//   - newCellType: karakter koji oznacava tip celije ('P')
// Povratna vrednost: nema
Hummer::Hummer(unsigned int newX, unsigned int newY, char newCellType)
    : Cell(newX, newY, newCellType), duration(4) {
    setType("hummer");
}

// Podrazumevani konstruktor Hummer
// Kreira predmet "cekic" na poziciji (0,0) sa podrazumevanim trajanjem.
// Ulazni argumenti: nema
// Povratna vrednost: nema
Hummer::Hummer() : Cell(0, 0, 'P'), duration(4) { setType("hummer"); }

// Funkcija getType za Hummer
// Vraca string koji oznacava tip predmeta ("hummer").
// Ulazni argumenti: nema
// Povratna vrednost: string
std::string Hummer::getType() const { return "hummer"; }

