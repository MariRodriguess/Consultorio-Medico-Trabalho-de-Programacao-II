#include <iostream>
#include "ListaConsulta.hpp"
#include <string>

using namespace std;

ListaConsulta :: ListaConsulta()
{
    this -> setPri(NULL);
    this -> setUlt(NULL);
    this -> setQtd(0);
}

bool ListaConsulta :: vazia() 
{
	return (pri == NULL);
}

ListaConsulta :: ~ListaConsulta(){
    delete pri;
}

Consulta* ListaConsulta :: getPri()
{
	return this -> pri;
}

void ListaConsulta :: setPri(Consulta* primeiro){
    this -> pri = primeiro;
}

Consulta* ListaConsulta :: getUlt() 
{
	return this -> ult;
}

void ListaConsulta :: setUlt(Consulta* ultimo){
    this -> ult = ultimo;
}

int ListaConsulta :: getQtd() 
{
	return this -> qtd;
}

void ListaConsulta :: setQtd(int qtd){
    this -> qtd = qtd;
}

void ListaConsulta :: inserir (int dia, int mes, int ano, string hora, long long int cpfPaciente, long long int crmMedico){
    
    Consulta* nova_Consulta = new Consulta (dia, mes, ano, hora, cpfPaciente, crmMedico);

    if (vazia()) {
        pri = nova_Consulta;
        ult = nova_Consulta;
        this->setQtd(getQtd()+1);
        cout << "\nConsulta cadastrado com sucesso.";
    }
    else{
        ult -> setProx(nova_Consulta);
        ult = nova_Consulta;
        this->setQtd(getQtd()+1);
        cout << "\nConsulta cadastrado com sucesso.";
    }

}