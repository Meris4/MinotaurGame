#include "Game.hpp"
#include "Matrix.hpp"
#include "Robot.hpp"
#include "Items.hpp"
#include "functions.hpp"
#include "FileHandler.hpp"
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <tuple>
using namespace std;

// Funkcija runGame
// Funkcija pokrece glavnu petlju igre, omogucava unos podataka, inicijalizuje lavirint i upravlja tokom igre.
// Omogucava kretanje robota, ispisuje stanje lavirinta i proverava kraj igre.
// Ulazni argumenti: nema
// Povratna vrednost: nema

void Game::runGame() {
    std::cout << "Hello World!\n";

    while (true) {
        bool rowsBool = false;
        bool colsBool = false;
        bool itemBool = false;
        int rows;
        int cols;
        int item;

        bool end = false;
        while (true) {

            bool goodStartingData = inputStartingData(rowsBool, colsBool, itemBool, rows, cols, item);
            if (!goodStartingData) {
                continue;
            }

            // Merenje vremena pre kreiranja lavirinta
            auto startTime = chrono::high_resolution_clock::now();
            Matrix matrix(rows, cols);

            std::random_device rd; // Nasumicni uredjaj za inicijalizaciju
            std::mt19937 gen(rd()); // Mersenne Twister generator


            fillMatrix(matrix, item, rows, cols, gen);
            cout << "Broj predmeta provera: " << item << endl;
            cout << "Max broj predmeta provera: " << ((rows - 2) * (cols - 2)) - (2 * (rows + cols)) - 1 - 1 - matrix.getPathSize() << endl;
            // min broj zidova  -  robot-minotaur-put
            if (item >= ((rows - 2) * (cols - 2)) - (2 * (rows + cols)) - 1 - 1 - matrix.getPathSize()) {
                cout << "Broj predmeta koji ste uneli je preveliki za matricu dimenzije1 " << rows << "x" << cols << endl;
                itemBool = false;
                continue;
            }

            // Merenje vremena posle kreiranja lavirinta
            auto endTime = chrono::high_resolution_clock::now();

            chrono::duration<double> duration = endTime - startTime;
            cout << "Vreme potrebno za kreiranje lavirinta: " << duration.count() << " sekundi" << endl;

            int minWallNumber = 2 * (matrix.getRows() + matrix.getCols());
            int wallCounter = 0;
            for (int i = 1; i <= matrix.getRows() - 2; i++) {
                for (int j = 1; j <= matrix.getCols() - 2; j++) {
                    if (matrix[i][j]->getCellType() == '#') {
                        wallCounter += 1;
                    }
                }
            }
            cout << "Min Broj zidova " << minWallNumber << endl;
            cout << "Pravi Broj zidova " << wallCounter << endl;

            if (wallCounter <= minWallNumber) {
                //cout << "Nije dovoljno blokova " << endl;
                int enoughWalls = false;
                // Dodavanje zidova ukoliko ih nema dovoljno
                for (int i = 1; i <= matrix.getRows() - 2; i++) {
                    for (int j = 1; j <= matrix.getCols() - 2; j++) {
                        cout << matrix[i][j]->getCellType() << endl;
                        if (matrix[i][j]->getCellType() == '.') {
                            cout << i << ", " << j << endl;

                            if (matrix.findInPath(i, j)) {
                                //cout << "Trazi 3" << endl;
                                continue;

                            }
                            else {
                                matrix[i][j]->setCellType('#');
                                wallCounter += 1;
                                //cout << "Trazi 4" << endl;
                                if (wallCounter >= minWallNumber) {
                                    enoughWalls = true;
                                    break;
                                }
                            }


                        }
                    }
                    if (enoughWalls) {
                        break;
                    }
                }
            }
            else {
                cout << "Jeste dovoljno blokova " << endl;
            }


            int x, y;
            tie(x, y) = matrix.findPosition('R');
            cout << "Robot: " << x << y << endl;

            Robot robot(x, y, 'R');
            tie(x, y) = matrix.findPosition('U');

            tie(x, y) = matrix.findPosition('I');

            tie(x, y) = matrix.findPosition('M');
            Cell minotaur(x, y, 'M');



            while (true) {
                if (robot.hasEffect("fogWar")) {
                    // Smanjite vidljivost na podmatricu 3x3
                    cout << "Efekat: Magla rata - smanjena vidljivost!" << endl;
                    matrix.printFogWarMatrix(cout, robot);

                }
                else {
                    cout << matrix;
                }

                cout << "Moguce opcije: " << endl;
                cout << "[W] Gore" << endl;
                cout << "[A] Levo" << endl;
                cout << "[S] Dole" << endl;
                cout << "[D] Desno" << endl;
                cout << "[Q] Izlaz" << endl;
                cout << "Izaberite opciju: ";
                string choose;
                cin >> choose;
                transform(choose.begin(), choose.end(), choose.begin(), ::toupper);

                bool goodMove = false;
                if (choose == "W") {
                    goodMove = matrix.moveElementPerX(robot, robot.getX() - 1, robot.getX(), robot.getY(), end);
                    if (!goodMove) {
                        continue;
                    }
                    if (end) {
                        break;
                    }
                }
                else if (choose == "A") {
                    goodMove = matrix.moveElementPerY(robot, robot.getY() - 1, robot.getX(), robot.getY(), end);
                    if (!goodMove) {
                        continue;
                    }
                    if (end) {
                        break;
                    }
                }
                else if (choose == "S") {
                    goodMove = matrix.moveElementPerX(robot, robot.getX() + 1, robot.getX(), robot.getY(), end);
                    if (!goodMove) {
                        continue;
                    }
                    if (end) {
                        break;
                    }
                }
                else if (choose == "D") {
                    goodMove = matrix.moveElementPerY(robot, robot.getY() + 1, robot.getX(), robot.getY(), end);
                    if (!goodMove) {
                        continue;
                    }
                    if (end) {
                        break;
                    }
                }
                else if (choose == "Q") {
                    cout << "Prekinuli ste igru!" << endl;
                    string outcome = "Igra prekinuta!";
                    FileHandler::saveGameResult(matrix, outcome, "rezultat_igre.txt");
                    end = true;
                    break;
                }
                else {
                    cout << "Pogresan unos! Pokusajte ponovo." << endl;
                    continue;
                }

                // Pozivamo updateEffects samo ako je potez uspesan
                if (goodMove) {
                    robot.updateEffects();
                    if (end) break;
                }
                else {
                    continue;
                }

                robot.printEffects();

                if (robot.hasEffect("sword")) {

                    if (robot.getX() == minotaur.getX() && robot.getY() == minotaur.getY()) {
                        cout << "Efekat: Mac - unisten Minotaur!" << endl;
                        matrix[minotaur.getX()][minotaur.getY()]->setCellType('R');
                        end = true;
                        break;
                    }
                }
                if (robot.hasEffect("shield")) {
                    cout << "Efekat: Stit - odbrana od Minotaura!" << endl;
                }
                if (robot.hasEffect("hummer")) {
                    cout << "Efekat: Cekic - prolazak kroz zid!" << endl;
                }

                // Provera da li minotaur ima mogucnosti da se krece (ukoliko je okruzen
                // zidovima sa tri strane i robotom sa cetvrte strane)
                unordered_map<string, int> minotaurBusySides;
                while (true) {
                    std::uniform_int_distribution<> distrib(0, 3);
                    int rollDice;
                    rollDice = distrib(gen);
                    if (rollDice == 0) {
                        minotaurBusySides["side0"] = 0;
                    }
                    else if (rollDice == 1) {
                        minotaurBusySides["side1"] = 1;
                    }
                    else if (rollDice == 2) {
                        minotaurBusySides["side2"] = 2;
                    }
                    else {
                        minotaurBusySides["side3"] = 3;
                    }

                    if (!robot.hasEffect("shield") &&
                        ((std::abs(static_cast<int>(minotaur.getX() - robot.getX())) == 1 &&
                            std::abs(static_cast<int>(minotaur.getY() - robot.getY())) == 0) ||
                            (std::abs(static_cast<int>(minotaur.getX() - robot.getX())) == 0 &&
                                std::abs(static_cast<int>(minotaur.getY() - robot.getY())) == 1))) {


                        matrix[minotaur.getX()][minotaur.getY()]->setCellType('.');
                        matrix[robot.getX()][robot.getY()]->setCellType('M');
                        minotaur.setX(robot.getX());
                        minotaur.setY(robot.getY());



                        if (robot.hasEffect("sword")) {
                            if (robot.getX() == minotaur.getX() && robot.getY() == minotaur.getY()) {
                                cout << "Efekat: Mac - unisten Minotaur!" << endl;

                                matrix[robot.getX()][robot.getY()]->setCellType('R');
                                end = true;
                                break;
                            }
                        }
                        else {
                            cout << "Nazalost, izgubili ste! Minotaur vas je uhvatio!" << endl;
                            string outcome = "Poraz!";
                            //matrix.generateGameResultFile(matrix, outcome, "rezultat_igre.txt");
                            FileHandler::saveGameResult(matrix, outcome, "rezultat_igre.txt");
                            end = true;
                            break;
                        }
                    }
                    else {
                        int newX, newY;
                        if (rollDice == 0) { // dole
                            newX = minotaur.getX() + 1;
                            newY = minotaur.getY();
                            if (newX >= 0 && newX < matrix.getRows() &&
                                newY >= 0 && newY < matrix.getCols() &&
                                matrix[newX][newY]->getCellType() != '#' &&
                                matrix[newX][newY]->getCellType() != 'R' &&
                                matrix[newX][newY]->getCellType() != 'I' &&
                                matrix[newX][newY]->getCellType() != 'U') {
                                matrix[minotaur.getX()][minotaur.getY()]->setCellType('.');
                                matrix[newX][newY]->setCellType('M');
                                minotaur.setX(newX);
                                minotaurBusySides.clear();
                                break;
                            }
                        }
                        else if (rollDice == 1) { // gore
                            newX = minotaur.getX() - 1;
                            newY = minotaur.getY();
                            if (newX >= 0 && newX < matrix.getRows() &&
                                newY >= 0 && newY < matrix.getCols() &&
                                matrix[newX][newY]->getCellType() != '#' &&
                                matrix[newX][newY]->getCellType() != 'R' &&
                                matrix[newX][newY]->getCellType() != 'I' &&
                                matrix[newX][newY]->getCellType() != 'U') {
                                matrix[minotaur.getX()][minotaur.getY()]->setCellType('.');
                                matrix[newX][newY]->setCellType('M');
                                minotaur.setX(newX);
                                minotaurBusySides.clear();
                                break;
                            }
                        }
                        else if (rollDice == 2) { // desno
                            newX = minotaur.getX();
                            newY = minotaur.getY() + 1;
                            if (newX >= 0 && newX < matrix.getRows() &&
                                newY >= 0 && newY < matrix.getCols() &&
                                matrix[newX][newY]->getCellType() != '#' &&
                                matrix[newX][newY]->getCellType() != 'R' &&
                                matrix[newX][newY]->getCellType() != 'I' &&
                                matrix[newX][newY]->getCellType() != 'U') {
                                matrix[minotaur.getX()][minotaur.getY()]->setCellType('.');
                                matrix[newX][newY]->setCellType('M');
                                minotaur.setY(newY);
                                minotaurBusySides.clear();
                                break;
                            }
                        }
                        else if (rollDice == 3) { // levo
                            newX = minotaur.getX();
                            newY = minotaur.getY() - 1;
                            if (newX >= 0 && newX < matrix.getRows() &&
                                newY >= 0 && newY < matrix.getCols() &&
                                matrix[newX][newY]->getCellType() != '#' &&
                                matrix[newX][newY]->getCellType() != 'R' &&
                                matrix[newX][newY]->getCellType() != 'I' &&
                                matrix[newX][newY]->getCellType() != 'U') {
                                matrix[minotaur.getX()][minotaur.getY()]->setCellType('.');
                                matrix[newX][newY]->setCellType('M');
                                minotaur.setY(newY);
                                minotaurBusySides.clear();
                                break;
                            }
                        }

                        if (minotaurBusySides.size() == 4) {
                            cout << "Ponovo ste vi na redu jer minotaur trenutno nema mogucih poteza." << endl;
                            break;
                        }
                    }

                }
                if (end) {
                    break;
                }

            }

            cout << matrix;
            break;
        }

        string playAgain;

        bool exit = false;
        while (true) {
            cout << "Da li zelite da zapocnete novu igru?" << endl;
            cout << "[1] DA" << endl;
            cout << "[2] NE" << endl;
            cin >> playAgain;

            if (playAgain == "1") {
                break;
            }
            else if (playAgain == "2") {
                cout << "Hvala sto ste igrali! Dovidjenja!" << endl;
                exit = true;
                break;
            }
            else {
                cout << "Pogresan odgovar! Pokusajte ponovo." << endl;
            }
        }
        if (exit) {
            break;
        }

    }

}