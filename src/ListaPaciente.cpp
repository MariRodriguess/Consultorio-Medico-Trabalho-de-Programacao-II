#include <iostream>
#include "ListaPaciente.hpp"
#include <string>

using namespace std;


ListaPaciente :: ListaPaciente()
{
    this -> setPri(NULL);
    this -> setUlt(NULL);
    this -> setQtd(0);
}

ListaPaciente :: ListaPaciente(string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade, string relato, string dataUltimaConsulta, string medicacao){

    Paciente* novo_Paciente = new Paciente (nome, sexo, endereco, CPF, telefone, identidade, relato, dataUltimaConsulta, medicacao);
    this -> setPri(novo_Paciente);
    this -> setUlt(novo_Paciente);
    this -> setQtd(1);
}

bool ListaPaciente :: vazia() 
{
	return (pri == NULL);
}

ListaPaciente :: ~ListaPaciente(){
    delete pri;
}

Paciente* ListaPaciente :: getPri()
{
	return this -> pri;
}

void ListaPaciente :: setPri(Paciente* primeiro){
    this -> pri = primeiro;
}

Paciente* ListaPaciente :: getUlt() 
{
	return this -> ult;
}

void ListaPaciente :: setUlt(Paciente* ultimo){
    this -> ult = ultimo;
}

int ListaPaciente :: getQtd() 
{
	return this -> qtd;
}

void ListaPaciente :: setQtd(int qtd){
    this -> qtd = qtd;
}

void ListaPaciente :: inserir (string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade, string relato, string dataUltimaConsulta, string medicacao){
    
    Paciente* novo_Paciente = new Paciente (nome, sexo, endereco, CPF, telefone, identidade, relato, dataUltimaConsulta, medicacao);

    if (vazia()) {
        pri = novo_Paciente;
        ult = novo_Paciente;
        this -> setQtd(getQtd()+1);
        cout << "\nPaciente cadastrado com sucesso.";
    }
    else{
        ult -> setProx(novo_Paciente);
        ult = novo_Paciente;
        this -> setQtd(getQtd()+1);
        cout << "\nPaciente cadastrado com sucesso.";
    }

}