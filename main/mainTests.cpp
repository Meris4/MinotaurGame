#include <iostream>
#include "Robot.hpp"
#include "Matrix.hpp"
#include "Items.cpp"

#include <cstdlib>

#include <unordered_map>
#include <chrono>

#include <cctype>
#include <algorithm>



using namespace std;

bool inputStartingData(bool& rowsBool, bool& colsBool, bool& itemBool, int& rows, int& cols, int& item) {
    if (rowsBool == false) {
        cout << "Unesite broj redova matrice: ";
        cin >> rows;
        if (rows <= 15) {
            cout << "Broj redova matrice mora biti broj veci od 15! Pokusajte ponovo." << endl;
            return false;
            /*continue*/;
        }
        rowsBool = true;
    }

    if (colsBool == false) {
        cout << "Unesite broj kolona matrice: ";
        cin >> cols;
        if (cols <= 15) {
            cout << "Broj kolona matrice mora biti broj veci od 15! Pokusajte ponovo." << endl;
            return false;
            /*continue*/;
        }
        colsBool = true;
    }
    cout << "Max broj predmeta: " << ((rows - 2) * (cols - 2)) - (2 * (rows + cols)) - 1 - 1 - rows - cols << endl;
    if (itemBool == false) {
        cout << "Unesite broj predmeta u matrici: ";
        cin >> item;
        if (item <= 3) {
            cout << "Broj predmeta u matrici mora biti broj veci od 3! Pokusajte ponovo." << endl;
            return false;
            /*continue*/;
        }
        // trebam da oduzmem i duzinu puta !!!!!!!!!!!!!!!!!!!
        /*else if (item >= ((rows-2) * (cols-2)) - (2*(rows + cols)) - 1 - 1 - rows - cols) {
            cout << "Broj predmeta koji ste uneli je preveliki za matricu dimenzije2 " << rows << "x" << cols << endl;
            return false;
        }*/
        itemBool = true;
    }
    return true;
}

void fillMatrix(Matrix& matrix, int  item, int& rows, int& cols, mt19937& gen) {
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
            cout << item << endl;

            item -= 1;
        }


    }



    /*int x, y;
    tie(x, y) = matrix.findPosition('R');
    cout << "Robot: " << x << y << endl;

    Robot robot(x, y, 'R');
    tie(x, y) = matrix.findPosition('U');

    tie(x, y) = matrix.findPosition('I');

    tie(x, y) = matrix.findPosition('M');
    Cell minotaur(x, y, 'M');*/
}


void testMatrixDimensions() {
    Matrix m(20, 30);
    if (m.getRows() == 20 && m.getCols() == 30)
        std::cout << "testMatrixDimensions PASSED\n";
    else
        std::cout << "testMatrixDimensions FAILED\n";
}

void testFindPosition() {
    Matrix m(20, 30);
    auto pos = m.findPosition('R');
    if (std::get<0>(pos) == 1)
        std::cout << "testFindPosition PASSED\n";
    else
        std::cout << "testFindPosition FAILED\n";
}

void testPathExists() {
    Matrix m(20, 30);
    auto path = m.getPath();
    if (!path.empty())
        std::cout << "testPathExists PASSED\n";
    else
        std::cout << "testPathExists FAILED\n";
}

int main() {
    testMatrixDimensions();
    testFindPosition();
    testPathExists();
    // Dodaj još test funkcija po potrebi
    return 0;
}