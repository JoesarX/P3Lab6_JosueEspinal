#include "Tablero.h"

Tablero::Tablero(int level) {

	switch(level) {
		case 1: {
			this->tablero = new CasillaBuscaMinas**[8];
			for(int i =0; i < 8; i++) {
				tablero[i] = new CasillaBuscaMinas*[8];
			}
			this->setSize(8);
			break;
		}
		case 2: {
			this->tablero = new CasillaBuscaMinas**[10];
			for(int i =0; i < 10; i++) {
				tablero[i] = new CasillaBuscaMinas*[10];
			}
			this->setSize(10);
			break;
		}
		case 3: {
			this->tablero = new CasillaBuscaMinas**[12];
			for(int i =0; i < 12; i++) {
				tablero[i] = new CasillaBuscaMinas*[12];
			}
			this->setSize(12);
			break;
		}
	}
	rellenarTablero();
	llenarBombas(level);

}
void Tablero::rellenarTablero() {
	for(int i = 0; i<size; i++) {
		for(int j =0; j<size; j++) {
			this->tablero[i][j] = new CasillaBuscaMinas(false);
		}
	}
}
void Tablero::llenarBombas(int level) {
	int bombas = 0;
	if(level == 1) {
		bombas = 12;
	} else if(level == 2) {
		bombas = 25;
	} else {
		bombas = 43;
	}
	int contador = 0;
	while(contador < bombas) {
		int x = (rand()%(this->size));
		int y = (rand()%(this->size));
		if(tablero[x][y]->getEsBomba() != true) {
			tablero[x][y]->setEsBomba(true);
			//tablero[x][y]->setDisplay('B');
			contador++;
		}
	}
}
void Tablero::setSize(int level) {
	this->size = level;
}
int Tablero::getSize() {
	return this->size;
}
int Tablero::calcularBombas(int x,int y) {
	int contador = 0;

	if(x>0) {
		if(tablero[x-1][y]->getEsBomba() == true) {
			contador++;
		}
		if(y>0) {
			if(tablero[x-1][y-1]->getEsBomba() == true) {
				contador++;
			}
		}
		if(y<size-1) {
			if(tablero[x-1][y+1]->getEsBomba() == true) {
				contador++;
			}
		}
	}
	if(x<size-1) {
		if(tablero[x+1][y]->getEsBomba() == true) {
			contador++;
		}
		if(y>0) {
			if(tablero[x+1][y-1]->getEsBomba() == true) {
				contador++;
			}
		}
		if(y<size-1) {
			if(tablero[x+1][y+1]->getEsBomba() == true) {
				contador++;
			}
		}
	}
	if(y>0) {
		if(tablero[x][y-1]->getEsBomba() == true) {
			contador++;
		}
	}
	if(y<size-1) {
		if(tablero[x][y+1]->getEsBomba() == true) {
			contador++;
		}
	}
	return contador;

}

bool Tablero::destaparCasilla(int x,int y) {
	bool bomba = true;
	if(tablero[x][y]->getEsBomba() == true) {
		bomba = false;
	} else {
		tablero[x][y]->setDisplay(48+calcularBombas(x,y));
		tablero[x][y]->setDescubierta(true);
		if(x>0) {
			if(tablero[x-1][y]->getEsBomba()==false && tablero[x-1][y]->getDescubierta() == false) {
				destaparCasilla(x-1,y);
			}
			/*if(y>0) {
				if(tablero[x-1][y-1]->getEsBomba()==false && tablero[x-1][y-1]->getDescubierta() == false) {
					destaparCasilla(x-1,y-1);
				}
			}
			if(y<size-1) {
				if(tablero[x-1][y+1]->getEsBomba() == false && tablero[x-1][y+1]->getDescubierta() == false) {
					destaparCasilla(x-1,y+1);
				}
			}*/
		}
		if(x<size-1) {
			if(tablero[x+1][y]->getEsBomba() == false && tablero[x+1][y]->getDescubierta() == false) {
				destaparCasilla(x+1,y);
			}
			/*if(y>0) {
				if(tablero[x+1][y-1]->getEsBomba() == false && tablero[x+1][y-1]->getDescubierta() == false) {
					destaparCasilla(x+1,y-1);
				}
			}
			if(y<size-1) {
				if(tablero[x+1][y+1]->getEsBomba() == false && tablero[x+1][y+1]->getDescubierta() == false) {
					destaparCasilla(x+1,y+1);
				}
			}*/
		}
		if(y>0) {
			if(tablero[x][y-1]->getEsBomba() == false && tablero[x][y-1]->getDescubierta() == false) {
				destaparCasilla(x,y-1);
			}
		}
		if(y<size-1) {
			if(tablero[x][y+1]->getEsBomba() == false && tablero[x][y+1]->getDescubierta() == false) {
				destaparCasilla(x,y+1);
			}
		}
	}
	return bomba;
}

void Tablero::marcarCasilla(int x,int y) {
	tablero[x][y]->setDisplay('X');
	tablero[x][y]->setMarcada(true);
}

void Tablero::imprimirBombas() {
	if (this->tablero != NULL) {
		for(int i = 0; i < this->size; i++) {
			for(int j = 0; j < this->size; j++) {
				if(tablero[i][j]->getEsBomba()) {
					std::cout << "# ";
				} else {
					std::cout << "- ";
				}
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}
void Tablero::imprimir() {
	if (this->tablero != NULL) {
		for(int i = 0; i < this->size; i++) {
			for(int j = 0; j < this->size; j++) {
				//std::cout << "prueba" << i << j;
				std::cout << tablero[i][j]->getDisplay() << " ";
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

Tablero::~Tablero() {
	if (this->tablero != NULL) {
		for(int i = 0; i < this->size; i++) {
			delete[] tablero[i];
		}
		delete[] tablero;
		tablero = NULL;
	}
}