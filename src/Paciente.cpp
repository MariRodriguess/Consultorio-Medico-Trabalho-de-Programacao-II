#include <iostream>
#include "Pessoa.hpp"
#include "Paciente.hpp"


Paciente :: Paciente (){
    this -> setRelato(" ");
    this -> setDataUltimaConsulta(" ");
    this -> setMedicacao(" ");
    this -> setProx(NULL);
}

Paciente :: Paciente (string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade, string relato, string dataUltimaConsulta, string medicacao) : Pessoa (nome, sexo, endereco, CPF, telefone, identidade){
    this -> setRelato(relato);
    this -> setDataUltimaConsulta(dataUltimaConsulta);
    this -> setMedicacao(medicacao);
    this -> setProx(NULL);
}

void Paciente :: setRelato(string relato){
    this -> relato = relato;
}
string Paciente :: getRelato() {
    return this -> relato;
}

void Paciente :: setDataUltimaConsulta(string dataUltimaConsulta){
    this -> dataUltimaConsulta = dataUltimaConsulta;
}
string Paciente :: getDataUltimaConsulta() {
    return this -> dataUltimaConsulta;
}

void Paciente :: setMedicacao(string medicacao){
    this -> medicacao = medicacao;
}
string Paciente :: getMedicacao() {
    return this -> medicacao;
}

Paciente* Paciente :: getProx() 
{
	return this -> prox;
}
void Paciente :: setProx(Paciente* prox){
    this -> prox = prox;
}

void Paciente :: Imprimir (){

    cout << "\nNome: " << this->getNome() << endl;
    cout << "Sexo: " << this->getSexo() << endl;
    cout << "Endereco: " << this->getEndereco() << endl;
    cout << "CPF: " << this->getCPF() << endl;
    cout << "Telefone: " << this->getTelefone() << endl;
    cout << "Identidade: " << this->getIdentidade() << endl;
    cout << "Relato: " << this->getRelato() << endl;
    cout << "Data da ultima consulta: " << this->getDataUltimaConsulta() << endl;
    cout << "Medicacao: " << this->getMedicacao() << endl;
}

void Paciente :: imprimirLista (){
    cout << this->getNome() << endl;
}
