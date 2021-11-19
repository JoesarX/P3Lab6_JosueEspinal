#include <iostream>
#include "BuscaMinas.h"
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int menu();

int main(int argc, char** argv) {
	srand (time(NULL));
	int opcionmenu = 0;
	opcionmenu = menu();
	
	while (opcionmenu != 4) {
		if(opcionmenu>0 && opcionmenu<4){
			BuscaMinas* buscaminas = new BuscaMinas(opcionmenu);
			
			
			
			buscaminas->~BuscaMinas();
		}else{
			cout << "La opcion no es valida.";
		}
		opcionmenu = menu();
	}
	cout << "\nGracias por utilizar el programa. ";
	return 0;
}
int menu() {
	int opcion = 0;
	cout << "===========Menu===========" << endl
	     << "1) Facil (8x8)" << endl;
	cout << "2) Normal (10x10)" << endl;
	cout << "3) Dificil (12x12)" << endl;
	cout << "4) Salir" << endl;
	cout << "Ingrese su opcion: ";
	cin >> opcion;
	return opcion;
}