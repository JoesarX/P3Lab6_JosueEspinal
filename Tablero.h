#ifndef TABLERO_H
#define TABLERO_H
#include "CasillaBuscaMinas.h"
#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <time.h>


class Tablero
{
	public:
		Tablero(int);
		~Tablero();
		bool destaparCasilla(int x, int y);
		int calcularBombas(int x,int y);
		void marcarCasilla(int x,int y);
		void imprimirBombas();
		void imprimir();
		void rellenarTablero();
		void setSize(int);
		int getSize();
		int getObjetivo();
		int getVacio();
		void llenarBombas(int);
	private:
		CasillaBuscaMinas*** tablero;
		int size;
		int objetivo;
		int vacio;
		
	protected:
		
};

#endif