#include "CasillaBuscaMinas.h"

CasillaBuscaMinas::CasillaBuscaMinas(bool bomba){
	this->esBomba = bomba;
	this->descubierta= false;
	this->marcada = false;
	this->display='-';

}
char CasillaBuscaMinas::getDisplay(){
	return this->display;
}
bool CasillaBuscaMinas::getEsBomba(){
	return this->esBomba;
}
bool CasillaBuscaMinas::getMarcada(){
	return this->marcada;
}
void CasillaBuscaMinas::setDisplay(char dis){
	this->display = dis;
}
void CasillaBuscaMinas::setEsBomba(bool bomba){
	this->esBomba = bomba;
}
void CasillaBuscaMinas::setMarcada(bool marca){
	this->marcada = marca;
}

CasillaBuscaMinas::~CasillaBuscaMinas(){
}

