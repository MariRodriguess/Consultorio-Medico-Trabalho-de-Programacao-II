#include <iostream>
#include "Data.hpp"


Data :: Data (){
    this -> setDia(0);
    this -> setMes(0);
    this -> setAno(0);
    this -> setProx(NULL);
}

Data :: Data (int dia, int mes, int ano){
    this -> setDia(dia);
    this -> setMes(mes);
    this -> setAno(ano);
    this -> setProx(NULL);
}

void Data :: setDia(int dia){
    this -> dia = dia;
}
int Data :: getDia() {
    return this -> dia;
}

void Data :: setMes(int mes){
    this -> mes = mes;
}
int Data :: getMes() {
    return this -> mes;
}

void Data :: setAno(int ano){
    this -> ano = ano;
}
int Data :: getAno() {
    return this -> ano;
}

Data* Data :: getProx() 
{
	return this -> prox;
}
void Data :: setProx(Data* prox){
    this -> prox = prox;
}

