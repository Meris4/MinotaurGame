//#include <iostream>
//#include "Robot.hpp"
//#include "Matrix.hpp"
//#include "Items.cpp"
//
//#include <cstdlib>
//
//#include <unordered_map>
//
//#include <cctype>
//#include <algorithm>
//
//
//using namespace std;
//
//bool inputStartingData(bool& rowsBool, bool& colsBool, bool& itemBool, int& rows, int& cols, int& item) {
//    if (rowsBool == false) {
//        cout << "Unesite broj redova matrice: ";
//        cin >> rows;
//        if (rows <= 15) {
//            cout << "Broj redova matrice mora biti broj veci od 15! Pokusajte ponovo." << endl;
//            return false;
//            /*continue*/;
//        }
//        rowsBool = true;
//    }
//
//    if (colsBool == false) {
//        cout << "Unesite broj kolona matrice: ";
//        cin >> cols;
//        if (cols <= 15) {
//            cout << "Broj kolona matrice mora biti broj veci od 15! Pokusajte ponovo." << endl;
//            return false;
//            /*continue*/;
//        }
//        colsBool = true;
//    }
//
//    if (itemBool == false) {
//        cout << "Unesite broj predmeta u matrici: ";
//        cin >> item;
//        if (item <= 3) {
//            cout << "Broj predmeta u matrici mora biti broj veci od 3! Pokusajte ponovo." << endl;
//            return false;
//            /*continue*/;
//        }
//        itemBool = true;
//    }
//    return true;
//}
//
//void fillMatrix(Matrix& matrix, int& item, int& rows, int& cols, mt19937& gen) {
//    //std::random_device rd; // Nasumicni uredjaj za inicijalizaciju
//    //std::mt19937 gen(rd()); // Mersenne Twister generator
//    std::uniform_int_distribution<> distrib(0, 3);
//    while (item > 0) {
//        std::uniform_int_distribution<> distribItemX(1, rows - 2);
//        std::uniform_int_distribution<> distribItemY(1, cols - 2);
//        unsigned int itemX;
//        unsigned int itemY;
//
//        int itemRollDice = distrib(gen);
//
//        if (itemRollDice == 0) {
//            itemX = distribItemX(gen);
//            itemY = distribItemY(gen);
//
//
//            matrix[itemX][itemY] = new FogWar(itemX, itemY, 'P');
//        }
//
//        else if (itemRollDice == 1) {
//            itemX = distribItemX(gen);
//            itemY = distribItemY(gen);
//
//
//            matrix[itemX][itemY] = new Sword(itemX, itemY, 'P');
//        }
//        else if (itemRollDice == 2) {
//            itemX = distribItemX(gen);
//            itemY = distribItemY(gen);
//
//
//            matrix[itemX][itemY] = new Shield(itemX, itemY, 'P');
//        }
//        else if (itemRollDice == 3) {
//            itemX = distribItemX(gen);
//            itemY = distribItemY(gen);
//
//
//            matrix[itemX][itemY] = new Hummer(itemX, itemY, 'P');
//        }
//        cout << item << endl;
//
//        item -= 1;
//    }
//
//
//
//    /*int x, y;
//    tie(x, y) = matrix.findPosition('R');
//    cout << "Robot: " << x << y << endl;
//
//    Robot robot(x, y, 'R');
//    tie(x, y) = matrix.findPosition('U');
//
//    tie(x, y) = matrix.findPosition('I');
//
//    tie(x, y) = matrix.findPosition('M');
//    Cell minotaur(x, y, 'M');*/
//}
//
//int main()
//{
//    std::cout << "Hello World!\n";
//
//    bool rowsBool = false;
//    bool colsBool = false;
//    bool itemBool = false;
//    int rows;
//    int cols;
//    int item;
//
//    bool end = false;
//    while (true) {
//
//        bool goodStartingData = inputStartingData(rowsBool, colsBool, itemBool, rows, cols, item);
//        if (!goodStartingData) {
//            continue;
//        }
//
//        /*if (rowsBool == false) {
//            cout << "Unesite broj redova matrice: ";
//            cin >> rows;
//            if (rows <= 15) {
//                cout << "Broj redova matrice mora biti broj veci od 15! Pokusajte ponovo." << endl;
//                continue;
//            }
//            rowsBool = true;
//        }
//
//        if (colsBool == false) {
//            cout << "Unesite broj kolona matrice: ";
//            cin >> cols;
//            if (cols <= 15) {
//                cout << "Broj kolona matrice mora biti broj veci od 15! Pokusajte ponovo." << endl;
//                continue;
//            }
//            colsBool = true;
//        }
//
//        if (itemBool == false) {
//            cout << "Unesite broj predmeta u matrici: ";
//            cin >> item;
//            if (item <= 3) {
//                cout << "Broj predmeta u matrici mora biti broj veci od 3! Pokusajte ponovo." << endl;
//                continue;
//            }
//            itemBool = true;
//        }*/
//        Matrix matrix(rows, cols);
//
//
//
//        std::random_device rd; // Nasumicni uredjaj za inicijalizaciju
//        std::mt19937 gen(rd()); // Mersenne Twister generator
//        fillMatrix(matrix, item, rows, cols, gen);
//        //std::uniform_int_distribution<> distrib(0, 3);
//        //while (item > 0) {
//        //    std::uniform_int_distribution<> distribItemX(1, rows - 2);
//        //    std::uniform_int_distribution<> distribItemY(1, cols - 2);
//        //    unsigned int itemX;
//        //    unsigned int itemY;
//
//        //    int itemRollDice = distrib(gen);
//
//        //    if (itemRollDice == 0) {
//        //        itemX = distribItemX(gen);
//        //        itemY = distribItemY(gen);
//        //        
//
//        //        matrix[itemX][itemY] = new FogWar(itemX, itemY, 'P');
//        //    }
//
//        //    else if (itemRollDice == 1) {
//        //        itemX = distribItemX(gen);
//        //        itemY = distribItemY(gen);
//        //        
//
//        //        matrix[itemX][itemY] = new Sword(itemX, itemY, 'P');
//        //    }
//        //    else if (itemRollDice == 2) {
//        //        itemX = distribItemX(gen);
//        //        itemY = distribItemY(gen);
//        //        
//
//        //        matrix[itemX][itemY] = new Shield(itemX, itemY, 'P');
//        //    }
//        //    else if (itemRollDice == 3) {
//        //        itemX = distribItemX(gen);
//        //        itemY = distribItemY(gen);
//        //        
//
//        //        matrix[itemX][itemY] = new Hummer(itemX, itemY, 'P');
//        //    }
//        //    cout << item << endl;
//
//        //    item -= 1;
//        //}
//
//
//
//        int x, y;
//        tie(x, y) = matrix.findPosition('R');
//        cout << "Robot: " << x << y << endl;
//
//        Robot robot(x, y, 'R');
//        tie(x, y) = matrix.findPosition('U');
//
//        tie(x, y) = matrix.findPosition('I');
//
//        tie(x, y) = matrix.findPosition('M');
//        Cell minotaur(x, y, 'M');
//
//
//        while (true) {
//            if (robot.hasEffect("fogWar")) {
//                // Smanjite vidljivost na podmatricu 3x3
//                cout << "Efekat: Magla rata - smanjena vidljivost!" << endl;
//                matrix.printFogWarMatrix(cout, robot);
//
//            }
//            else {
//                cout << matrix;
//            }
//
//
//            cout << "Moguce opcije: " << endl;
//            cout << "[W] Gore" << endl;
//            cout << "[A] Levo" << endl;
//            cout << "[S] Dole" << endl;
//            cout << "[D] Desno" << endl;
//            cout << "[Q] Izlaz" << endl;
//            cout << "Izaberite opciju: ";
//            string choose;
//            cin >> choose;
//            transform(choose.begin(), choose.end(), choose.begin(), ::toupper);
//            robot.updateEffects();
//
//            bool goodMove;
//            if (choose == "W") {
//
//                goodMove = matrix.moveElementPerX(robot, robot.getX() - 1, robot.getX(), robot.getY(), end);
//                if (!goodMove) {
//                    continue;
//                }
//                if (end) {
//                    break;
//                }
//
//
//                //if (matrix[robot.getX() - 1][robot.getY()]->getCellType() == 'P') {
//                //    string itemType = matrix[robot.getX() - 1][robot.getY()]->getType();
//                //    robot.applyEffect(itemType);
//                //}
//                //if (robot.hasEffect("hummer") &&
//                //    matrix[robot.getX() - 1][robot.getY()]->getCellType() != 'U' &&
//                //    robot.getX() - 1 != 0 && robot.getX() - 1 != rows - 1 &&
//                //    robot.getY() != 0 && robot.getY() != cols - 1) {
//                //    // Omogucite prolazak kroz zid
//                //    cout << "Efekat: Cekic - prolazak kroz zid!" << endl;
//                //    if (matrix[robot.getX() - 1][robot.getY()]->getCellType() == '#') {
//                //        matrix[robot.getX() - 1][robot.getY()]->setCellType('.');
//                //    }
//                //    matrix[robot.getX()][robot.getY()]->setCellType('.');
//                //    matrix[robot.getX() - 1][robot.getY()]->setCellType('R');
//                //    robot.setX(robot.getX() - 1);
//                //}
//                //if (matrix[robot.getX() - 1][robot.getY()]->getCellType() != '#' &&
//                //    matrix[robot.getX() - 1][robot.getY()]->getCellType() != 'U' &&
//                //    !robot.hasEffect("hummer")) {
//                //    if (matrix[robot.getX() - 1][robot.getY()]->getCellType() == 'M' &&
//                //        robot.hasEffect("shield") && !robot.hasEffect("sword")) {
//                //        cout << "Potez koji ste odabrali nije moguce izvrsiti jer imate stit! Pokusajte ponovo." << endl;
//                //        continue;
//                //    }
//                //    matrix[robot.getX()][robot.getY()]->setCellType('.');
//                //    matrix[robot.getX() - 1][robot.getY()]->setCellType('R');
//                //    robot.setX(robot.getX() - 1);
//                //}
//                //if (matrix[robot.getX() - 1][robot.getY()]->getCellType() == 'I') {
//                //    matrix[robot.getX()][robot.getY()]->setCellType('.');
//                //    matrix[robot.getX() - 1][robot.getY()]->setCellType('R');
//                //    robot.setX(robot.getX() - 1);
//                //    end = true;
//                //    cout << "Uspeli ste da stignete do cilja. Cestitamo! " << endl;
//                //    break;
//                //}
//
//            }
//            else if (choose == "A") {
//
//
//                goodMove = matrix.moveElementPerY(robot, robot.getY() - 1, robot.getX(), robot.getY(), end);
//                if (!goodMove) {
//                    continue;
//                }
//                if (end) {
//                    break;
//                }
//
//                //if (matrix[robot.getX()][robot.getY() - 1]->getCellType() == 'P') {
//                //    string itemType = matrix[robot.getX()][robot.getY() - 1]->getType();
//                //    robot.applyEffect(itemType);
//                //}
//                //if (robot.hasEffect("hummer") &&
//                //    matrix[robot.getX()][robot.getY() - 1]->getCellType() != 'U' &&
//                //    robot.getX() != 0 && robot.getX() != rows - 1 &&
//                //    robot.getY() - 1 != 0 && robot.getY() - 1 != cols - 1) {
//                //    // Omogucite prolazak kroz zid
//                //    cout << "Efekat: Cekic - prolazak kroz zid!" << endl;
//                //    if (matrix[robot.getX()][robot.getY() - 1]->getCellType() == '#') {
//                //        matrix[robot.getX()][robot.getY() - 1]->setCellType('.');
//                //    }
//                //    matrix[robot.getX()][robot.getY()]->setCellType('.');
//                //    matrix[robot.getX()][robot.getY() - 1]->setCellType('R');
//                //    robot.setY(robot.getY() - 1);
//                //}
//                //if (matrix[robot.getX()][robot.getY() - 1]->getCellType() != '#' &&
//                //    !robot.hasEffect("hummer")) {
//                //    if (matrix[robot.getX()][robot.getY() - 1]->getCellType() == 'M' &&
//                //        robot.hasEffect("shield") && !robot.hasEffect("sword")) {
//                //        cout << "Potez koji ste odabrali nije moguce izvrsiti jer imate stit! Pokusajte ponovo." << endl;
//                //        continue;
//                //    }
//                //    matrix[robot.getX()][robot.getY()]->setCellType('.');
//                //    matrix[robot.getX()][robot.getY() - 1]->setCellType('R');
//                //    robot.setY(robot.getY() - 1);
//
//                //}
//                //if (matrix[robot.getX()][robot.getY() - 1]->getCellType() == 'I') {
//                //    matrix[robot.getX()][robot.getY()]->setCellType('.');
//                //    matrix[robot.getX()][robot.getY() - 1]->setCellType('R');
//                //    robot.setY(robot.getY() - 1);
//                //    end = true;
//                //    cout << "Uspeli ste da stignete do cilja. Cestitamo! " << endl;
//                //    break;
//                //}
//
//            }
//            else if (choose == "S") {
//
//                goodMove = matrix.moveElementPerX(robot, robot.getX() + 1, robot.getX(), robot.getY(), end);
//                if (!goodMove) {
//                    continue;
//                }
//                if (end) {
//                    break;
//                }
//
//                //if (matrix[robot.getX() + 1][robot.getY()]->getCellType() == 'P') {
//                //    string itemType = matrix[robot.getX() + 1][robot.getY()]->getType();
//                //    robot.applyEffect(itemType);
//                //}
//                //if (robot.hasEffect("hummer") &&
//                //    matrix[robot.getX() + 1][robot.getY()]->getCellType() != 'U' &&
//                //    robot.getX() + 1 != 0 && robot.getX() + 1 != rows - 1 &&
//                //    robot.getY() != 0 && robot.getY() != cols - 1) {
//                //    // Omogucite prolazak kroz zid
//                //    cout << "Efekat: Cekic - prolazak kroz zid!" << endl;
//                //    if (matrix[robot.getX() + 1][robot.getY()]->getCellType() == '#') {
//                //        matrix[robot.getX() + 1][robot.getY()]->setCellType('.');
//                //    }
//                //    matrix[robot.getX()][robot.getY()]->setCellType('.');
//                //    matrix[robot.getX() + 1][robot.getY()]->setCellType('R');
//                //    robot.setX(robot.getX() + 1);
//                //}
//                //if (matrix[robot.getX() + 1][robot.getY()]->getCellType() != '#' &&
//                //    !robot.hasEffect("hummer")) {
//                //    if (matrix[robot.getX() + 1][robot.getY()]->getCellType() == 'M' &&
//                //        robot.hasEffect("shield") && !robot.hasEffect("sword")) {
//                //        cout << "Potez koji ste odabrali nije moguce izvrsiti jer imate stit! Pokusajte ponovo." << endl;
//                //        continue;
//                //    }
//                //    matrix[robot.getX()][robot.getY()]->setCellType('.');
//                //    matrix[robot.getX() + 1][robot.getY()]->setCellType('R');
//                //    robot.setX(robot.getX() + 1);
//                //}
//                //if (matrix[robot.getX() + 1][robot.getY()]->getCellType() == 'I') {
//                //    matrix[robot.getX()][robot.getY()]->setCellType('.');
//                //    matrix[robot.getX() + 1][robot.getY()]->setCellType('R');
//                //    robot.setX(robot.getX() + 1);
//                //    end = true;
//                //    cout << "Uspeli ste da stignete do cilja. Cestitamo! " << endl;
//                //    break;
//                //}
//
//            }
//            else if (choose == "D") {
//
//
//                goodMove = matrix.moveElementPerY(robot, robot.getY() + 1, robot.getX(), robot.getY(), end);
//                if (!goodMove) {
//                    continue;
//                }
//                if (end) {
//                    break;
//                }
//
//                //if (matrix[robot.getX()][robot.getY() + 1]->getCellType() == 'P') {
//                //    string itemType = matrix[robot.getX()][robot.getY() + 1]->getType();
//                //    robot.applyEffect(itemType);
//                //}
//                //if (robot.hasEffect("hummer") &&
//                //    matrix[robot.getX()][robot.getY() + 1]->getCellType() != 'U' &&
//                //    robot.getX() != 0 && robot.getX() != rows - 1 &&
//                //    robot.getY() + 1 != 0 && robot.getY() + 1 != cols - 1) {
//                //    // Omogucen prolazak kroz zid
//                //    cout << "Efekat: Cekic - prolazak kroz zid!" << endl;
//                //    if (matrix[robot.getX()][robot.getY() + 1]->getCellType() == '#') {
//                //        matrix[robot.getX()][robot.getY() + 1]->setCellType('.');
//                //    }
//                //    matrix[robot.getX()][robot.getY()]->setCellType('.');
//                //    matrix[robot.getX()][robot.getY() + 1]->setCellType('R');
//                //    robot.setY(robot.getY() + 1);
//                //}
//                //if (matrix[robot.getX()][robot.getY() + 1]->getCellType() != '#' &&
//                //    !robot.hasEffect("hummer")) {
//                //    if (matrix[robot.getX()][robot.getY() + 1]->getCellType() == 'M' &&
//                //        robot.hasEffect("shield") && !robot.hasEffect("sword")) {
//                //        cout << "Potez koji ste odabrali nije moguce izvrsiti jer imate stit! Pokusajte ponovo." << endl;
//                //        continue;
//                //    }
//                //    matrix[robot.getX()][robot.getY()]->setCellType('.');
//                //    matrix[robot.getX()][robot.getY() + 1]->setCellType('R');
//                //    robot.setY(robot.getY() + 1);
//                //}
//                //if (matrix[robot.getX()][robot.getY() + 1]->getCellType() == 'I') {
//                //    matrix[robot.getX()][robot.getY()]->setCellType('.');
//                //    matrix[robot.getX()][robot.getY() + 1]->setCellType('R');
//                //    robot.setY(robot.getY() + 1);
//                //    end = true;
//                //    cout << "Uspeli ste da stignete do cilja. Cestitamo! " << endl;
//                //    break;
//                //}
//
//            }
//            else if (choose == "Q") {
//                break;
//            }
//            else {
//                cout << "Pogresan unos! Pokusajte ponovo." << endl;
//                continue;
//            }
//
//            /*robot.updateEffects();*/
//            robot.printEffects();
//
//            // Implementacija specijalnih efekata
//            //if (robot.hasEffect("fogWar")) {
//            //    // Smanjite vidljivost na podmatricu 3x3
//            //    cout << "Efekat: Magla rata - smanjena vidljivost!" << endl;
//
//            //}
//            if (robot.hasEffect("sword")) {
//
//                if (robot.getX() == minotaur.getX() && robot.getY() == minotaur.getY()) {
//                    cout << "Efekat: Mac - unisten Minotaur!" << endl;
//                    matrix[minotaur.getX()][minotaur.getY()]->setCellType('R');
//                    end = true;
//                    break;
//                }
//            }
//            if (robot.hasEffect("shield")) {
//                // Omogucite odbranu od Minotaura
//                cout << "Efekat: Stit - odbrana od Minotaura!" << endl;
//            }
//            if (robot.hasEffect("hummer")) {
//                // Omogucite prolazak kroz zid
//                cout << "Efekat: Cekic - prolazak kroz zid!" << endl;
//            }
//
//            // Provera da li minotaur ima mogucnosti da se krece (ukoliko je okruzen
//            // zidovima sa tri strane i robotom sa cetvrte strane)
//            unordered_map<string, int> minotaurBusySides;
//            while (true) {
//
//                std::uniform_int_distribution<> distrib(0, 3);
//
//
//                int rollDice;
//                rollDice = distrib(gen);
//                if (rollDice == 0) {
//                    minotaurBusySides["side0"] = 0;
//                }
//                else if (rollDice == 1) {
//                    minotaurBusySides["side1"] = 1;
//                }
//                else if (rollDice == 2) {
//                    minotaurBusySides["side2"] = 2;
//                }
//                else {
//                    minotaurBusySides["side3"] = 3;
//                }
//
//
//
//                if (!robot.hasEffect("shield") &&
//                    ((std::abs(static_cast<int>(minotaur.getX() - robot.getX())) == 1 &&
//                        std::abs(static_cast<int>(minotaur.getY() - robot.getY())) == 0) ||
//                        (std::abs(static_cast<int>(minotaur.getX() - robot.getX())) == 0 &&
//                            std::abs(static_cast<int>(minotaur.getY() - robot.getY())) == 1))) {
//
//                    /*matrix[minotaur.getX()][minotaur.getY()] = '.';
//                    matrix[robot.getX()][robot.getY()] = 'M';*/
//                    matrix[minotaur.getX()][minotaur.getY()]->setCellType('.');
//                    matrix[robot.getX()][robot.getY()]->setCellType('M');
//                    minotaur.setX(robot.getX());
//                    minotaur.setY(robot.getY());
//
//                    if (robot.hasEffect("sword")) {
//                        if (robot.getX() == minotaur.getX() && robot.getY() == minotaur.getY()) {
//                            cout << "Efekat: Mac - unisten Minotaur!" << endl;
//                            //minotaur.setCellType('.');
//                            matrix[robot.getX()][robot.getY()]->setCellType('R');
//                            end = true;
//                            break;
//                        }
//                    }
//
//                }
//                else {
//                    if (rollDice == 0 && matrix[minotaur.getX() + 1][minotaur.getY()]->getCellType() != '#' &&
//                        matrix[minotaur.getX() + 1][minotaur.getY()]->getCellType() != 'R') {
//                        /*matrix[minotaur.getX()][minotaur.getY()] = '.';
//                        matrix[minotaur.getX() + 1][minotaur.getY()] = 'M';*/
//                        matrix[minotaur.getX()][minotaur.getY()]->setCellType('.');
//                        matrix[minotaur.getX() + 1][minotaur.getY()]->setCellType('M');
//                        minotaur.setX(minotaur.getX() + 1);
//
//                        // restartujemo zauzete strane
//                        minotaurBusySides.clear();
//                        break;
//
//                    }
//                    else if (rollDice == 1 && matrix[minotaur.getX() - 1][minotaur.getY()]->getCellType() != '#' &&
//                        matrix[minotaur.getX() - 1][minotaur.getY()]->getCellType() != 'R') {
//                        /*matrix[minotaur.getX()][minotaur.getY()] = '.';
//                        matrix[minotaur.getX() - 1][minotaur.getY()] = 'M';*/
//                        matrix[minotaur.getX()][minotaur.getY()]->setCellType('.');
//                        matrix[minotaur.getX() - 1][minotaur.getY()]->setCellType('M');
//                        minotaur.setX(minotaur.getX() - 1);
//
//                        // restartujemo zauzete strane
//                        minotaurBusySides.clear();
//                        break;
//                    }
//                    else if (rollDice == 2 && matrix[minotaur.getX()][minotaur.getY() + 1]->getCellType() != '#' &&
//                        matrix[minotaur.getX()][minotaur.getY() + 1]->getCellType() != 'R') {
//                        /*matrix[minotaur.getX()][minotaur.getY()] = '.';
//                        matrix[minotaur.getX()][minotaur.getY() + 1] = 'M';*/
//                        matrix[minotaur.getX()][minotaur.getY()]->setCellType('.');
//                        matrix[minotaur.getX()][minotaur.getY() + 1]->setCellType('M');
//                        minotaur.setY(minotaur.getY() + 1);
//
//                        // restartujemo zauzete strane
//                        minotaurBusySides.clear();
//                        break;
//                    }
//                    else if (rollDice == 3 && matrix[minotaur.getX()][minotaur.getY() - 1]->getCellType() != '#' &&
//                        matrix[minotaur.getX()][minotaur.getY() - 1]->getCellType() != 'R') {
//                        /*matrix[minotaur.getX()][minotaur.getY()] = '.';
//                        matrix[minotaur.getX()][minotaur.getY() - 1] = 'M';*/
//                        matrix[minotaur.getX()][minotaur.getY()]->setCellType('.');
//                        matrix[minotaur.getX()][minotaur.getY() - 1]->setCellType('M');
//                        minotaur.setY(minotaur.getY() - 1);
//
//                        // restartujemo zauzete strane
//                        minotaurBusySides.clear();
//                        break;
//                    }
//
//                    if (minotaurBusySides.size() == 4) {
//                        cout << "Ponovo ste vi na redu jer minotaur trenutno nema mogucih poteza." << endl;
//                        break;
//                    }
//                }
//
//            }
//            if (end) {
//                break;
//            }
//
//        }
//        cout << matrix;
//        break;
//    }
//}
