#include <iostream>
#include "ListaMedico.hpp"
#include <string>

using namespace std;


ListaMedico :: ListaMedico()
{
    this -> setPri(NULL);
    this -> setUlt(NULL);
    this -> setQtd(0);
}

ListaMedico :: ListaMedico(string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade, long long int crm, string especialidade)
{
    Medico* novo_Med = new Medico (nome, sexo, endereco, CPF, telefone, identidade, crm, especialidade);
    this -> setPri(novo_Med);
    this -> setUlt(novo_Med);
    this -> setQtd(1);
}


bool ListaMedico :: vazia() 
{
	return (pri == NULL);
}

ListaMedico :: ~ListaMedico(){
    delete pri;
}

Medico* ListaMedico :: getPri()
{
	return this -> pri;
}

void ListaMedico :: setPri(Medico* primeiro){
    this -> pri = primeiro;
}

Medico* ListaMedico :: getUlt() 
{
	return this -> ult;
}

void ListaMedico :: setUlt(Medico* ultimo){
    this -> ult = ultimo;
}

int ListaMedico :: getQtd() 
{
	return this -> qtd;
}

void ListaMedico :: setQtd(int qtd){
    this -> qtd = qtd;
}

void ListaMedico :: inserir (string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade, long long int crm, string especialidade){
    
    Medico* novo_Medico = new Medico (nome, sexo, endereco, CPF, telefone, identidade, crm, especialidade);

    if (vazia()) {
        pri = novo_Medico;
        ult = novo_Medico;
        this->setQtd(getQtd()+1);
        cout << "\nMedico cadastrado com sucesso.";
    }
    else{
        ult -> setProx(novo_Medico);
        ult = novo_Medico;
        this->setQtd(getQtd()+1);
        cout << "\nMedico cadastrado com sucesso.";
    }

}