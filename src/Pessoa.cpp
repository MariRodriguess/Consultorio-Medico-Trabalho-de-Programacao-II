#include <iostream>
#include "Pessoa.hpp"

Pessoa :: Pessoa () {
    this -> setNome(" ");
    this -> setSexo(0);
    this -> setEndereco(" ");
    this -> setCPF(0);
    this -> setTelefone(" ");
    this -> setIdentidade(" ");
}

Pessoa :: Pessoa (string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade) {
    this -> setNome(nome);
    this -> setSexo(sexo);
    this -> setEndereco(endereco);
    this -> setCPF(CPF);
    this -> setTelefone(telefone);
    this -> setIdentidade(identidade);
}

Pessoa :: ~Pessoa () {

}   

void Pessoa :: setNome(string nome){
    this -> nome = nome;
}
string Pessoa :: getNome() {
    return this -> nome;
}

void Pessoa :: setSexo(char sexo){
    this -> sexo = sexo;
}
char Pessoa :: getSexo() {
    return this -> sexo;
}

void Pessoa :: setEndereco(string endereco){
    this -> endereco = endereco;
}
string Pessoa :: getEndereco() {
    return this -> endereco;
}

void Pessoa :: setCPF(long long int CPF){
    this -> CPF = CPF;
}
long long int Pessoa :: getCPF() {
    return this -> CPF;
}

void Pessoa :: setTelefone(string telefone){
    this -> telefone = telefone;
}
string Pessoa :: getTelefone() {
    return this -> telefone;
}

void Pessoa :: setIdentidade(string identidade){
    this -> identidade = identidade;
}
string Pessoa :: getIdentidade() {
    return this -> identidade;
}

void Pessoa :: Imprimir(){
    cout << "Nome: " << this->getNome() << endl;
    cout << "Sexo: " << this->getSexo() << endl;
    cout << "Endereco: " << this->getEndereco() << endl;
    cout << "CPF: " << this->getCPF() << endl;
    cout << "Telefone: " << this->getTelefone() << endl;
    cout << "Identidade: " << this->getIdentidade() << endl;
}