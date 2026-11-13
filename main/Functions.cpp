// Autori: Meris Bilalovic, SV1/2023
// Datum poslednje izmene : 15.02.2025.

#include "functions.hpp"
#include <iostream>
#include <unordered_map>
#include <chrono>
#include <cctype>
#include <algorithm>
#include "Items.hpp"
#include "Matrix.hpp"

using namespace std;


// Funkcija inputStartingData
// Funkcija interaktivno trazi od korisnika unos broja redova, kolona i broja predmeta u lavirintu.
// Proverava da li su uneti podaci validni (npr. da su redovi i kolone veci od 15, a broj predmeta u dozvoljenom opsegu).
// Ulazni argumenti: 
//   - rowsBool, colsBool, itemBool: logicke promenljive koje oznacavaju da li su podaci vec uneti
//   - rows, cols, item: promenljive u koje se upisuje unos korisnika
// Povratna vrednost: 
//   - true ako su svi podaci validni, false ako treba ponoviti unos

bool inputStartingData(bool& rowsBool, bool& colsBool, bool& itemBool, int& rows, int& cols, int& item) {
    if (rowsBool == false) {
        cout << "Unesite broj redova matrice: ";
        cin >> rows;
        if (rows <= 15) {
            cout << "Broj redova matrice mora biti broj veci od 15! Pokusajte ponovo." << endl;
            return false;
         
        }
        rowsBool = true;
    }

    if (colsBool == false) {
        cout << "Unesite broj kolona matrice: ";
        cin >> cols;
        if (cols <= 15) {
            cout << "Broj kolona matrice mora biti broj veci od 15! Pokusajte ponovo." << endl;
            return false;
            
        }
        colsBool = true;
    }

    int minWallNumber = 2 * (rows + cols); // minimalan broj zidova (okvir)
    //int maxItems = (rows - 2) * (cols - 2) - minWallNumber - 2; // -2 za robota i minotaura

    int maxItems = (((rows - 2) * (cols - 2)) - 2 * (2 * (rows + cols)) - 1 - 1 - rows - cols) * 2 / 3;   // duzina puteva (ovo 2 * (2 * (rows + cols)))
    //cout << "Max broj predmeta: " << maxItems  << endl;
    if (itemBool == false) {
        cout << "Unesite broj predmeta u matrici: ";
        cin >> item;
        if (item <= 3) {
            cout << "Broj predmeta u matrici mora biti broj veci od 3! Pokusajte ponovo." << endl;
            return false;
        }
        if (item > maxItems) {
            cout << "Broj predmeta koji ste uneli je preveliki za matricu dimenzije " << rows << "x" << cols << "." << endl;
            cout << "Maksimalan broj predmeta za ove dimenzije je: " << maxItems << endl;
            itemBool = false;
            return false; 
        }
        
        itemBool = true;
    }
    return true;
}



// Funkcija fillMatrix
// Funkcija popunjava matricu lavirinta predmetima na slucajnim pozicijama.
// Predmeti mogu biti magla rata, mac, stit ili cekic.
// Ulazni argumenti:
//   - matrix: referenca na matricu lavirinta
//   - item: broj predmeta koji treba postaviti
//   - rows, cols: dimenzije matrice
//   - gen: generator slucajnih brojeva
// Povratna vrednost: nema

void fillMatrix(Matrix& matrix, int item, int& rows, int& cols, mt19937& gen) {
    //std::random_device rd; // Nasumicni uredjaj za inicijalizaciju
    //std::mt19937 gen(rd()); // Mersenne Twister generator
    std::uniform_int_distribution<> distrib(0, 3);
    while (item > 0) {
        std::uniform_int_distribution<> distribItemX(1, rows - 2);
        std::uniform_int_distribution<> distribItemY(1, cols - 2);
        unsigned int itemX;
        unsigned int itemY;

        int itemRollDice = distrib(gen);

        itemX = distribItemX(gen);
        itemY = distribItemY(gen);

        if (matrix[itemX][itemY]->getCellType() == '.' || matrix[itemX][itemY]->getCellType() == '#') {
            if (itemRollDice == 0) {
                matrix[itemX][itemY] = new FogWar(itemX, itemY, 'P');
            }
            else if (itemRollDice == 1) {
                matrix[itemX][itemY] = new Sword(itemX, itemY, 'P');
            }
            else if (itemRollDice == 2) {
                matrix[itemX][itemY] = new Shield(itemX, itemY, 'P');
            }
            else if (itemRollDice == 3) {
                matrix[itemX][itemY] = new Hummer(itemX, itemY, 'P');
            }
            //cout << "Redni broj predmeta " << item << endl;

            item -= 1;
        }
    }
}
