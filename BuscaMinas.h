#ifndef BUSCAMINAS_H
#define BUSCAMINAS_H
#include "Tablero.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class BuscaMinas
{
	public:
		BuscaMinas(int);
		~BuscaMinas();
		void jugar();
		int menu2();
		int xValue();
		int yValue();
	private: 
		Tablero* tableroBombas;
	protected:
};

#endif