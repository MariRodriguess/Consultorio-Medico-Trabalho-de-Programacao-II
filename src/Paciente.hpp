#ifndef PACIENTE_HPP
#define PACIENTE_HPP
#include <iostream>
#include <string>
#include "Pessoa.hpp"

class Paciente : public Pessoa {
    private:
        string relato;
        string dataUltimaConsulta;
        string medicacao;
        Paciente* prox;
    public:
        Paciente ();
        Paciente (string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade, string relato, string dataUltimaConsulta, string medicacao); 
        void setRelato(string relato);   
        string getRelato();
        void setDataUltimaConsulta(string dataUltimaConsulta);
        string getDataUltimaConsulta();
        void setMedicacao(string medicacao);   
        string getMedicacao();
        Paciente* getProx();
        void setProx(Paciente* prox);
        void Imprimir();
        void imprimirLista();   
};

#endif