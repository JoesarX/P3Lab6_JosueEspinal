#ifndef CASILLABUSCAMINAS_H
#define CASILLABUSCAMINAS_H

class CasillaBuscaMinas
{
	public:
		CasillaBuscaMinas(bool);
		~CasillaBuscaMinas();
		char getDisplay();
		bool getEsBomba();
		bool getMarcada();
		void setEsBomba(bool);
		void setDisplay(char);
		void setMarcada(bool);
		
	private:
		bool esBomba;
		bool descubierta;
		char display;
		bool marcada;
	protected:
};

#endif