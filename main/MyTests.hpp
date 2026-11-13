// Autori: Meris Bilalovic, SV1/2023
// Datum poslednje izmene : 15.04.2025.

#pragma once
#include <iostream>
#include "Matrix.hpp"

// Sadrzi testove za dimenzije matrice, pronalazenje pozicija, rad sa efektima robota, putanju kroz lavirint i osnovne metode klasa.
// Omogucava automatsko pokretanje svih testova radi provere stabilnosti i tacnosti implementacije.

void testMatrixDimensions();
void testFindPosition();
void testMatrixDefaultConstructor();
void testMatrixSetAndGetRowsCols();
void testMatrixFindInPath();
void testRobotApplyAndHasEffect();
void testRobotUpdateEffects();
void testMatrixEntranceExitPosition();
void testMatrixPathNotEmpty();
void testCellSetAndGetType();
void testRobotEffectStacking();
void runAllTests();

