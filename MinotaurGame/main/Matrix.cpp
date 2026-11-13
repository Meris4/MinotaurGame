// Autori: Meris Bilalovic, SV1/2023
// Datum poslednje izmene : 15.02.2025.

//#ifndef MATRIX_CPP
//#define MATRIX_CPP

#include "Matrix.hpp"
#include <iostream>
#include "Cell.hpp"
#include <random>
#include <tuple>
#include "Robot.hpp"
#include "FileHandler.hpp"


#include <fstream>

using namespace std;


// Funkcija allocateMemory
// Alocira i inicijalizuje matricu lavirinta, postavlja zidove, prazna polja, ulaz, izlaz, robota i minotaura.
// Ulazni argumenti:
//   - rows: broj redova matrice
//   - cols: broj kolona matrice
// Povratna vrednost: nema
void Matrix::allocateMemory(int rows, int cols) {
	if (rows <= 2 || cols <= 2) {
		matrix = nullptr;
		return;
	}

	// Kreiranje generatora nasumicnih brojeva
	std::random_device rd; // Nasumicni uredjaj za inicijalizaciju
	std::mt19937 gen(rd()); // Mersenne Twister generator
	std::uniform_int_distribution<> distrib(0, 1);
	


	if (rows > 0 && cols > 0) {

		matrix = new Cell** [rows];
		for (int i = 0; i < rows; i++) {

			matrix[i] = new Cell* [cols];
			for (int j = 0; j < cols; j++) {
				if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
					matrix[i][j] = new Cell(i, j, '#');
				}
				else if (distrib(gen) == 1) {
					matrix[i][j] = new Cell(i, j, '#');
				}
				else {
					matrix[i][j] = new Cell(i, j, '.');
				}

			}
		}


		std::uniform_int_distribution<> distrib(1, cols - 2); // Uniformna distribucija u opsegu [min, max]
		startRandomNumber = distrib(gen);
		
		matrix[0][startRandomNumber]->setCellType('U');
		matrix[1][startRandomNumber]->setCellType('R');

		endRandomNumber = distrib(gen);
		
		matrix[rows - 1][endRandomNumber]->setCellType('I');

		// Kreiranje puta

		createPath(1, startRandomNumber, rows - 2, endRandomNumber);
		matrix[rows - 2][endRandomNumber]->setCellType('.');

		std::uniform_int_distribution<> distribX(1, rows - 2);
		std::uniform_int_distribution<> distribY(1, cols - 2);
		int startMinoutaurX = distribX(gen);
		int startMinoutaurY = distribY(gen);
		
		matrix[startMinoutaurX][startMinoutaurY]->setCellType('M');

		createPath(2, startRandomNumber, startMinoutaurX - 1, startMinoutaurY);

	}
	else {
		matrix = nullptr;
	}
}

// Funkcija createPath
// Kreira putanju kroz lavirint od zadate pocetne do krajnje koordinate, postavljajuci prazna polja.
// Ulazni argumenti:
//   - startX, startY: pocetna koordinata
//   - endX, endY: krajnja koordinata
// Povratna vrednost: nema
void Matrix::createPath(int startX, int startY, int endX, int endY) {
	int x = startX;
	int y = startY;
	std::random_device rd;
	std::mt19937 gen(rd());

	while (x != endX || y != endY) {
		bool moveX = false;
		if (x != endX && y != endY) {
			std::uniform_int_distribution<> distrib(0, 1);
			moveX = distrib(gen) == 0;
		}
		else if (x != endX) {
			moveX = true;
		}
		

		if (moveX) {
			if (x < endX) x++;
			else if (x > endX) x--;
		}
		else {
			if (y < endY) y++;
			else if (y > endY) y--;
		}

		if (x < 0 || x >= rows || y < 0 || y >= cols)
			break;

		if (matrix[x][y]->getCellType() != 'U' && matrix[x][y]->getCellType() != 'I') {
			if (matrix[x][y]->getCellType() != '.') {
				matrix[x][y]->setCellType('.');
			}
			path.push_back({ x, y });
			pathSize++;
		}
	}
}


// Funkcija freeMemory
// Oslobadja dinamicki alociranu memoriju za matricu lavirinta.
// Ulazni argumenti: nema
// Povratna vrednost: nema
void Matrix::freeMemory() {
	if (matrix != nullptr) {
		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				delete matrix[i][j];
			}
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = nullptr;
	}
}

// Konstruktor Matrix(int newRows, int newCols)
// Kreira matricu lavirinta zadatih dimenzija i inicijalizuje je.
// Ulazni argumenti:
//   - newRows: broj redova
//   - newCols: broj kolona
// Povratna vrednost: nema
Matrix::Matrix(int newRows, int newCols) : rows(newRows), cols(newCols), pathSize(0) {
	allocateMemory(newRows, newCols);
}

// Podrazumevani konstruktor Matrix()
// Kreira praznu matricu lavirinta.
// Ulazni argumenti: nema
// Povratna vrednost: nema
Matrix::Matrix() : rows(0), cols(0), pathSize(0) {
	allocateMemory(rows, cols);
}

// Destruktor ~Matrix()
// Oslobadja memoriju zauzetu matricom lavirinta.
// Ulazni argumenti: nema
// Povratna vrednost: nema
Matrix::~Matrix() {
	freeMemory();
}

// Funkcija getRows
// Vraca broj redova matrice lavirinta.
// Ulazni argumenti: nema
// Povratna vrednost: broj redova (int)
int Matrix::getRows() const{
	return rows;
}

// Funkcija getCols
// Vraca broj kolona matrice lavirinta.
// Ulazni argumenti: nema
// Povratna vrednost: broj kolona (int)
int Matrix::getCols() const {
	return cols;
}

// Funkcija getPathSize
// Vraca broj polja u putanji kroz lavirint.
// Ulazni argumenti: nema
// Povratna vrednost: broj polja u putanji (int)
int Matrix::getPathSize() const {
	return pathSize;
}

// Funkcija getPath
// Vraca vektor sa koordinatama putanje kroz lavirint.
// Ulazni argumenti: nema
// Povratna vrednost: vektor parova (x, y)
std::vector <std::pair<int, int>> Matrix::getPath() const {
	return path;
}

// Funkcija printPath
// Ispisuje koordinate putanje kroz lavirint na standardni izlaz.
// Ulazni argumenti: nema
// Povratna vrednost: nema
void Matrix::printPath() const {
	for (const auto& p : path) {
		cout << "(" << p.first << ", " << p.second << ") ";
	}
	cout << endl;
}

// Funkcija findInPath
// Proverava da li se zadate koordinate nalaze u putanji kroz lavirint.
// Ulazni argumenti:
//   - x: red
//   - y: kolona
// Povratna vrednost: true ako je polje deo putanje, false inace
bool Matrix::findInPath(int x, int y) const {
	for (const auto& p : path) {
		if (p.first == x && p.second == y) {
			return true; // Pronadjen je trazeni par (x, y)
		}
	}
	return false; // Par nije pronadjen
}
	
// Funkcija printRandomNumber
// Ispisuje nasumicni broj (koristi se za debug).
// Ulazni argumenti: nema
// Povratna vrednost: nema
void Matrix::printRandomNumber() const {
	cout << randomNumber << " Meris" << endl;
}

// Funkcija findPosition
// Vraca koordinate prve pojave zadatog karaktera u matrici lavirinta.
// Ulazni argumenti:
//   - c: karakter koji se trazi
// Povratna vrednost: par (x, y) koordinata
tuple<int, int> Matrix::findPosition(char c) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j]->getCellType() == c) {
				return { i, j };
			}
		}
	}
	return { 1, 1 }; // vraca nevalidnu poziciju ako karakter nije pronadjen
}


// Operator []
// Omogucava pristup redovima matrice lavirinta preko indeksa.
// Ulazni argumenti:
//   - index: indeks reda
// Povratna vrednost: niz pokazivaca na celije (Cell**)
Cell** Matrix::operator[](int index) {
	if (index < 0 || index >= rows) {
		throw ("Indeks koji ste uneli nije validan!");
	}
	return matrix[index];

}

// Operator <<
// Ispisuje celu matricu lavirinta na izlazni tok.
// Ulazni argumenti:
//   - os: izlazni tok
//   - matrix: referenca na matricu
// Povratna vrednost: referenca na izlazni tok
ostream& operator<<(ostream& os, const Matrix& matrix) {
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.cols; j++) {
			os << *matrix.matrix[i][j] << " ";
		}
		os << "\n";
	}
	return os;
}

// Funkcija printFogWarMatrix
// Ispisuje podmatricu 3x3 oko robota (efekat magle rata).
// Ulazni argumenti:
//   - os: izlazni tok
//   - robot: referenca na robota
// Povratna vrednost: nema
void Matrix::printFogWarMatrix(ostream& os, Robot& robot) {
	int startX = max(0, static_cast<int>(robot.getX() - 1));
	int endX = min(rows - 1, static_cast<int>(robot.getX() + 1));
	int startY = max(0, static_cast<int>(robot.getY() - 1));
	int endY = min(cols - 1, static_cast<int>(robot.getY() + 1));

	for (int i = startX; i <= endX; i++) {
		for (int j = startY; j <= endY; j++) {
			os << *matrix[i][j] << " ";
		}
		os << "\n";
	}
}

// Funkcija moveElementPerX
// Pokusava da pomeri robota po X osi (gore/dole), proverava validnost poteza i efekte predmeta.
// Ulazni argumenti:
//   - robot: referenca na robota
//   - newPositionX: nova X pozicija
//   - oldPositionX: stara X pozicija
//   - oldPositionY: stara Y pozicija
//   - end: referenca na bool koji oznacava kraj igre
// Povratna vrednost: true ako je potez uspesan, false ako nije dozvoljen
bool Matrix::moveElementPerX(Robot& robot, int newPositionX, int oldPositionX, int oldPositionY, bool& end) {
	// Provera granica
	if (newPositionX < 0 || newPositionX >= rows) {
		std::cout << "Nevalidan potez: izlazite van matrice!" << std::endl;
		return false;
	}
	// Provera zida
	if (this->matrix[newPositionX][oldPositionY]->getCellType() == '#' && !robot.hasEffect("hummer")) {
		std::cout << "Ne mozete proci kroz zid bez cekica!" << std::endl;
		return false;
	}
	// Provera ulaza
	if (this->matrix[newPositionX][oldPositionY]->getCellType() == 'U') {
		std::cout << "Ne mozete stati na ulaz!" << std::endl;
		return false;
	}

	bool goodMove = true;

	
	if (this->matrix[newPositionX][oldPositionY]->getCellType() == 'M') {
		
		if (robot.hasEffect("shield") && !robot.hasEffect("sword")) {
			std::cout << "Ne mozete napasti Minotaura dok imate samo stit!" << std::endl;
			return false;
		}
		if (robot.hasEffect("sword")) {
			std::cout << "Efekat: Mac - unisten Minotaur!" << std::endl;
			this->matrix[oldPositionX][oldPositionY]->setCellType('.');
			this->matrix[newPositionX][oldPositionY]->setCellType('R');
			robot.setX(newPositionX);
			end = true;
			string outcome = "Pobeda!";
			//generateGameResultFile(*this, outcome, "rezultat_igre.txt");
			FileHandler::saveGameResult(*this, outcome, "rezultat_igre.txt");
			return true;
		}
		else {
			this->matrix[oldPositionX][oldPositionY]->setCellType('.');
			robot.setX(newPositionX);
			end = true;
			cout << "Nazalost, izgubili ste! Minotaur vas je uhvatio! " << endl;
			string outcome = "Poraz!";
			FileHandler::saveGameResult(*this, outcome, "rezultat_igre.txt");
			return true;
		}
	}

	if (this->matrix[newPositionX][oldPositionY]->getCellType() == 'I') {
		this->matrix[oldPositionX][oldPositionY]->setCellType('.');
		this->matrix[newPositionX][oldPositionY]->setCellType('R');
		robot.setX(newPositionX);
		end = true;
		cout << "Uspeli ste da stignete do cilja. Cestitamo! " << endl;
		if (end) {
			string outcome = "Pobeda!"; 
			FileHandler::saveGameResult(*this, outcome, "rezultat_igre.txt");
			
		}
		
		return goodMove;
	}

	if (this->matrix[newPositionX][oldPositionY]->getCellType() == 'P') {
		robot.applyEffect(this->matrix[newPositionX][oldPositionY]);
		
	}
	if (robot.hasEffect("hummer") &&
		this->matrix[newPositionX][oldPositionY]->getCellType() != 'U' &&
		newPositionX != 0 && newPositionX != rows - 1 &&
		oldPositionY != 0 && oldPositionY != cols - 1) {
		
		cout << "Efekat: Cekic - prolazak kroz zid!" << endl;
		if (this->matrix[newPositionX][oldPositionY]->getCellType() == '#') {
			this->matrix[newPositionX][oldPositionY]->setCellType('.');
		}
		this->matrix[oldPositionX][oldPositionY]->setCellType('.');
		this->matrix[newPositionX][oldPositionY]->setCellType('R');
		robot.setX(newPositionX);
	}
	if (this->matrix[newPositionX][oldPositionY]->getCellType() != '#' &&
		this->matrix[newPositionX][oldPositionY]->getCellType() != 'U' &&
		!robot.hasEffect("hummer")) {
		if (this->matrix[newPositionX][oldPositionY]->getCellType() == 'M' &&
			robot.hasEffect("shield") && !robot.hasEffect("sword")) {
			cout << "Potez koji ste odabrali nije moguce izvrsiti jer imate stit! Pokusajte ponovo." << endl;
			goodMove = false;
			return goodMove;
			
		}
		this->matrix[oldPositionX][oldPositionY]->setCellType('.');
		this->matrix[newPositionX][oldPositionY]->setCellType('R');
		robot.setX(newPositionX);
	}

	
	return goodMove;
}

// Funkcija moveElementPerY
// Pokusava da pomeri robota po Y osi (levo/desno), proverava validnost poteza i efekte predmeta.
// Ulazni argumenti:
//   - robot: referenca na robota
//   - newPositionY: nova Y pozicija
//   - oldPositionX: stara X pozicija
//   - oldPositionY: stara Y pozicija
//   - end: referenca na bool koji oznacava kraj igre
// Povratna vrednost: true ako je potez uspesan, false ako nije dozvoljen
bool Matrix::moveElementPerY(Robot& robot, int newPositionY, int oldPositionX, int oldPositionY, bool& end) {
	// Provera granica
	if (newPositionY < 0 || newPositionY >= cols) {
		std::cout << "Nevalidan potez: izlazite van matrice!" << std::endl;
		return false;
	}
	// Provera zida
	if (this->matrix[oldPositionX][newPositionY]->getCellType() == '#' && !robot.hasEffect("hummer")) {
		std::cout << "Ne mozete proci kroz zid bez cekica!" << std::endl;
		return false;
	}
	// Provera ulaza
	if (this->matrix[oldPositionX][newPositionY]->getCellType() == 'U') {
		std::cout << "Ne mozete stati na ulaz!" << std::endl;
		return false;
	}
	
	bool goodMove = true;

	if (this->matrix[oldPositionX][newPositionY]->getCellType() == 'M') {
		if (robot.hasEffect("shield") && !robot.hasEffect("sword")) {
			std::cout << "Ne mozete napasti Minotaura dok imate samo stit!" << std::endl;
			return false;
		}
		if (robot.hasEffect("sword")) {
			std::cout << "Efekat: Mac - unisten Minotaur!" << std::endl;
			this->matrix[oldPositionX][oldPositionY]->setCellType('.');
			this->matrix[oldPositionX][newPositionY]->setCellType('R');
			robot.setY(newPositionY);
			end = true;
			string outcome = "Pobeda!";
			FileHandler::saveGameResult(*this, outcome, "rezultat_igre.txt");
			return true;
		}
		else {
			this->matrix[oldPositionX][oldPositionY]->setCellType('.');
			robot.setY(newPositionY);
			end = true;
			cout << "Nazalost, izgubili ste! Minotaur vas je uhvatio!" << endl;
			string outcome = "Poraz!";
			FileHandler::saveGameResult(*this, outcome, "rezultat_igre.txt");
			return true;
		}
	}

	if (this->matrix[oldPositionX][newPositionY]->getCellType() == 'I') {
		this->matrix[oldPositionX][oldPositionY]->setCellType('.');
		this->matrix[oldPositionX][newPositionY]->setCellType('R');
		robot.setY(newPositionY);
		end = true;
		cout << "Uspeli ste da stignete do cilja. Cestitamo! " << endl;
		if (end) {
			string outcome = "Pobeda!"; 
			FileHandler::saveGameResult(*this, outcome, "rezultat_igre.txt");
			
		}
		
		return goodMove;
	}
	if (this->matrix[oldPositionX][newPositionY]->getCellType() == 'P') {
		robot.applyEffect(this->matrix[oldPositionX][newPositionY]);
	}
	if (robot.hasEffect("hummer") &&
		this->matrix[oldPositionX][newPositionY]->getCellType() != 'U' &&
		oldPositionX != 0 && oldPositionX != rows - 1 &&
		newPositionY != 0 && newPositionY != cols - 1) {
	    
	    cout << "Efekat: Cekic - prolazak kroz zid!" << endl;
	    if (this->matrix[oldPositionX][newPositionY]->getCellType() == '#') {
			this->matrix[oldPositionX][newPositionY]->setCellType('.');
	    }
		this->matrix[oldPositionX][oldPositionY]->setCellType('.');
		this->matrix[oldPositionX][newPositionY]->setCellType('R');
	    robot.setY(newPositionY);
	}
	if (this->matrix[oldPositionX][newPositionY]->getCellType() != '#' &&
	    !robot.hasEffect("hummer")) {
	    if (this->matrix[oldPositionX][newPositionY]->getCellType() == 'M' &&
	        robot.hasEffect("shield") && !robot.hasEffect("sword")) {
	        cout << "Potez koji ste odabrali nije moguce izvrsiti jer imate stit! Pokusajte ponovo." << endl;
	        
			goodMove = false;
			return goodMove;
	    }
		this->matrix[oldPositionX][oldPositionY]->setCellType('.');
		this->matrix[oldPositionX][newPositionY]->setCellType('R');
	    robot.setY(newPositionY);

	}
	
	return goodMove;
}

// Operator [] (konst verzija)
// Omogucava pristup redovima matrice lavirinta preko indeksa iz konst objekta.
// Ulazni argumenti:
//   - index: indeks reda (int)
// Povratna vrednost: pokazivac na niz pokazivaca na objekte klase Cell (Cell* const*)
// Bacanje izuzetka: ako je indeks van opsega
Cell* const* Matrix::operator[](int index) const {
	if (index < 0 || index >= rows) {
		throw ("Indeks koji ste uneli nije validan!");
	}
	return matrix[index];
}


//};


//#endif // MATRIX_CPP