// Autori: Meris Bilalovic, SV1/2023
// Datum poslednje izmene : 15.04.2025.

#include "MyTests.hpp"
#include "Items.hpp"
#include <iostream>
#include "C:\Users\Administrator\Documents\II Godina\OOP2_vezbe\Projekat\MatrixLib\MatrixLib\pch.h"



// Testira da li se dimenzije matrice pravilno postavljaju i cuvaju.
void testMatrixDimensions() {
    Matrix m(20, 30);
    if (m.getRows() == 20 && m.getCols() == 30)
        std::cout << "testMatrixDimensions PASSED\n";
    else
        std::cout << "testMatrixDimensions FAILED\n";
}

// Testira pronalazenje pozicije odredjenog karaktera u matrici
void testFindPosition() {
    Matrix m(20, 30);
    auto pos = m.findPosition('R');
    if (std::get<0>(pos) == 1)
        std::cout << "testFindPosition PASSED\n";
    else
        std::cout << "testFindPosition FAILED\n";
}

// Testira podrazumevani konstruktor klase Matrix
void testMatrixDefaultConstructor() {
    Matrix m;
    std::cout << "testMatrixDefaultConstructor PASSED\n";
}

// Testira setovanje i dohvatanje broja redova i kolona matrice
void testMatrixSetAndGetRowsCols() {
    Matrix m(21, 22);
    if (m.getRows() == 21 && m.getCols() == 22)
        std::cout << "testMatrixSetAndGetRowsCols PASSED\n";
    else
        std::cout << "testMatrixSetAndGetRowsCols FAILED\n";
}

// Testira da li funkcija findInPath ispravno prepoznaje da li je polje deo putanje
void testMatrixFindInPath() {
    Matrix m(20, 30);
    auto path = m.getPath();
    if (!path.empty()) {
        int x = path[4].first;
        int y = path[4].second;
        if (m.findInPath(x, y))
            std::cout << "testMatrixFindInPath PASSED\n";
        else
            std::cout << "testMatrixFindInPath FAILED\n";
    }
    else {
        std::cout << "testMatrixFindInPath SKIPPED (empty path)\n";
    }
}

// Testira dodavanje i proveru efekata kod robota.
void testRobotApplyAndHasEffect() {
    Robot r(1, 1, 'R');
    Shield* shield = new Shield(0, 0, 'P');
    r.applyEffect(shield);
    delete shield;
    if (r.hasEffect("shield"))
        std::cout << "testRobotApplyAndHasEffect PASSED\n";
    else
        std::cout << "testRobotApplyAndHasEffect FAILED\n";
}

// Testira azuriranje trajanja efekata kod robota
void testRobotUpdateEffects() {
    Robot r(1, 1, 'R');
    FogWar* fog = new FogWar(0, 0, 'P');
    r.applyEffect(fog);
    delete fog;
    r.updateEffects();
    if (r.hasEffect("fogWar"))
        std::cout << "testRobotUpdateEffects PASSED\n";
    else
        std::cout << "testRobotUpdateEffects FAILED\n";
}

// Testira da li se ulaz i izlaz nalaze u prvom i poslednjem redu matrice
void testMatrixEntranceExitPosition() {
    Matrix m(20, 30);
    auto entrance = m.findPosition('U');
    auto exit = m.findPosition('I');
    bool entranceInFirstRow = std::get<0>(entrance) == 0;
    bool exitInLastRow = std::get<0>(exit) == m.getRows() - 1;
    if (entranceInFirstRow && exitInLastRow)
        std::cout << "testMatrixEntranceExitPosition PASSED\n";
    else
        std::cout << "testMatrixEntranceExitPosition FAILED\n";
}

// Testira da li je putanja u matrici inicijalizovana i nije prazna
void testMatrixPathNotEmpty() {
    Matrix m(20, 20);
    if (!m.getPath().empty())
        std::cout << "testMatrixPathNotEmpty PASSED\n";
    else
        std::cout << "testMatrixPathNotEmpty FAILED\n";
}

// Testira setovanje i dohvatanje tipa celije
void testCellSetAndGetType() {
    Cell c(2, 3, '.');
    c.setCellType('#');
    if (c.getCellType() == '#')
        std::cout << "testCellSetAndGetType PASSED\n";
    else
        std::cout << "testCellSetAndGetType FAILED\n";
}

// Testira da li su efekti kod robota pravilno postavljeni
void testRobotEffectStacking() {
    Robot r(1, 1, 'R');
    Shield* shield = new Shield(0, 0, 'P');
    Sword* sword = new Sword(0, 0, 'P');
    r.applyEffect(shield);
    r.applyEffect(sword);
    delete shield;
    delete sword;
    if (r.hasEffect("shield") && r.hasEffect("sword"))
        std::cout << "testRobotEffectStacking PASSED\n";
    else
        std::cout << "testRobotEffectStacking FAILED\n";
}

// Pokrece sve test funkcije iz ovog modula
void runAllTests() {
    testMatrixDimensions();
    testFindPosition();
    testMatrixDefaultConstructor();
    testMatrixSetAndGetRowsCols();
    testMatrixFindInPath();
    testRobotApplyAndHasEffect();
    testRobotUpdateEffects();
    testMatrixEntranceExitPosition();
    testMatrixPathNotEmpty();
    testCellSetAndGetType();
    testRobotEffectStacking();

    std::cout << "Svi testovi su zavrseni." << std::endl;
}
