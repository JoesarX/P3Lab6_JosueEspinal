#include "BuscaMinas.h"

BuscaMinas::BuscaMinas(int level) {
	this->tableroBombas=new Tablero(level);
	tableroBombas->imprimir();
	tableroBombas->imprimirBombas();
	jugar();
}
void BuscaMinas::jugar() {
	bool flag = true;
	bool gano = false;
	bool flag2 = true;
	while(flag) {

		int opcion = menu2();
		if(opcion >=1 && opcion <= 3) {
			flag2 = false;
		}
		while(flag2) {
			cout <<  "LA OPCION INGRESADA NO ES VALIDA" << endl;
			opcion = menu2();
			if(opcion >=1 && opcion <= 2) {
				flag = false;
			}
		}
		
		int x = xValue();
		int y = yValue();
		
		if(opcion == 1) {
			flag = tableroBombas->destaparCasilla(y,x);
			tableroBombas->imprimir();
			tableroBombas->imprimirBombas();
			
			if(tableroBombas->getObjetivo() == tableroBombas->getVacio()){
				gano = true;
				flag = false;
			}
		} else if(opcion == 2) {
			tableroBombas->marcarCasilla(y,x);
			tableroBombas->imprimir();
			tableroBombas->imprimirBombas();
			
		} 
	} 
	if(gano){
		cout<<"BUENISIMA.\nUSTED A GANADO, MENUDO ASTRO\n\n";
	}else{
		cout<<"BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM!!!!!! Y VOLO.\nMURIO POR UNA BOMBA ENTRE TERRIBLES SUFRIMIENTOS\n\n";
	}
	
}
int BuscaMinas::xValue() {
	int opcion = 0;
	cout << "\nDECIDA EN QUE CASILLA ACTUARA:" << endl <<"Cordenada x: " ;
	cin >> opcion;
	bool flag = false;
	if(opcion >= 0 && opcion<(tableroBombas->getSize())) {
		flag = true;
	}
	while (flag == false) {
		cout << "EL VALOR INGRESADO NO ES VALIDO, INGRESE NUEVAMENTE:" << endl <<"Cordenada x: ";
		cin >> opcion;
		if(opcion >= 0 && opcion < tableroBombas->getSize()) {
			flag = true;
		}
	}
	return opcion;
}
int BuscaMinas::yValue() {
	int opcion = 0;
	cout <<"Cordenada y: " ;
	cin >> opcion;
	bool flag = false;
	if(opcion >= 0 && opcion < tableroBombas->getSize()) {
		flag = true;
	}
	while (flag == false) {
		cout << "EL VALOR INGRESADO NO ES VALIDO, INGRESE NUEVAMENTE:" << endl <<"Cordenada y: " ;
		cin >> opcion;
		if(opcion >= 0 && opcion < tableroBombas->getSize()) {
			flag = true;
		}
	}
	return opcion;
}

int BuscaMinas::menu2() {
	int opcion = 0;
	cout << "\nQUE QUIERE HACER:" << endl
	     << "1) Destapar Casilla" << endl;
	cout << "2) Asignar flag" << endl;
	cout << "Ingrese su opcion: ";
	cin >> opcion;
	return opcion;
}

BuscaMinas::~BuscaMinas() {
	delete tableroBombas;

}