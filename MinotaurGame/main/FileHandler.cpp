#include "FileHandler.hpp"
#include <fstream>
#include <iostream>
using namespace std;


// Funkcija saveGameResultFile
// Generise tekstualni fajl sa ishodom igre i krajnjim stanjem lavirinta.
// Ulazni argumenti:
//   - matrix: referenca na matricu lavirinta
//   - outcome: string sa ishodom igre ("Pobeda!" ili "Poraz!")
//   - fileName: naziv fajla za upis rezultata
// Povratna vrednost: nema
void FileHandler::saveGameResult(const Matrix& matrix, const std::string& outcome, const std::string& fileName) {
    ofstream outFile(fileName);

    if (!outFile.is_open()) {
        cerr << "Greska: Nije moguce otvoriti datoteku za pisanje!" << endl;
        return;
    }

    outFile << "Ishod igre: " << outcome << endl;
    outFile << "-------------------------" << endl;
    outFile << "Krajnji izgled lavirinta:" << endl;
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            outFile << matrix[i][j]->getCellType() << " ";
        }
        outFile << endl;
    }

    outFile.close();
    cout << "Rezultat igre je sacuvan u datoteci: " << fileName << endl;
}