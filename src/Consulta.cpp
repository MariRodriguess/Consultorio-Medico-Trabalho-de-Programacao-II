#include <iostream>
#include "Pessoa.hpp"
#include "Consulta.hpp"


Consulta :: Consulta (){
    this -> setData(0,0,0);
    this -> setHora(" ");
    this -> setCpfPaciente(0);
    this -> setCrmMedico(0);
    this -> setProx(NULL);
}

Consulta :: Consulta  (int dia, int mes, int ano, string hora, long long int cpfPaciente, long long int crmMedico){
    this -> setData(dia, mes, ano);
    this -> setHora(hora);
    this -> setCpfPaciente(cpfPaciente);
    this -> setCrmMedico(crmMedico);
    this -> setProx(NULL);
}

void Consulta :: setData(int dia, int mes, int ano){
    Data* dataa = new Data(dia, mes, ano);
    this -> data = dataa;
}
Data* Consulta :: getData() {
    return this -> data;
}

void Consulta :: setHora(string hora){
    this -> hora = hora;
}
string Consulta :: getHora() {
    return this -> hora;
}

void Consulta :: setCpfPaciente(long long int cpfPaciente){
    this -> cpfPaciente = cpfPaciente;
}
long long int Consulta :: getCpfPaciente() {
    return this -> cpfPaciente;
}

void Consulta :: setCrmMedico(long long int crmMedico){
    this -> crmMedico = crmMedico;
}
long long int Consulta :: getCrmMedico() {
    return this -> crmMedico;
}

Consulta* Consulta :: getProx() 
{
	return this -> prox;
}
void Consulta :: setProx(Consulta* prox){
    this -> prox = prox;
}

void Consulta :: Imprimir (){
    cout << "Data: " << this->getData()->getDia() << "/" << this->getData()->getMes() << "/" << this->getData()->getAno() << endl;
    cout << "Hora: " << this->getHora() << endl;
    cout << "CPF do paciente: " << this->getCpfPaciente() << endl;
    cout << "CRM do Medico: " << this->getCrmMedico() << endl;
}
