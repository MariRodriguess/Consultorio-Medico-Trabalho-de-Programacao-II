#include <iostream>
#include "Pessoa.hpp"
#include "Medico.hpp"


Medico :: Medico (){
    this -> setCrm(0);
    this -> setEspecialidade(" ");
    this -> setProx(NULL);
}

Medico :: Medico (string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade, long long int crm, string especialidade) : Pessoa (nome, sexo, endereco, CPF, telefone, identidade){
    this -> setCrm(crm);
    this -> setEspecialidade(especialidade);
    this -> setProx(NULL);
}

void Medico :: setCrm(long long int crm){
    this -> crm = crm;
}
long long int Medico :: getCrm() {
    return this ->  crm;
}

void Medico :: setEspecialidade(string especialidade){
    this -> especialidade = especialidade;
}
string Medico :: getEspecialidade() {
    return this -> especialidade;
}

Medico* Medico :: getProx() 
{
	return this -> prox;
}
void Medico :: setProx(Medico* prox){
    this -> prox = prox;
}

void Medico :: Imprimir (){
    
    cout << "\nNome: " << this->getNome() << endl;
    cout << "Sexo: " << this->getSexo() << endl;
    cout << "Endereco: " << this->getEndereco() << endl;
    cout << "CPF: " << this->getCPF() << endl;
    cout << "Telefone: " << this->getTelefone() << endl;
    cout << "Identidade: " << this->getIdentidade() << endl;
    cout << "Crm: " << this->getCrm() << endl;
    cout << "Especialidade: " << this->getEspecialidade() << endl;
}

void Medico :: imprimirLista (){
    cout << this->getNome() << endl;
}
