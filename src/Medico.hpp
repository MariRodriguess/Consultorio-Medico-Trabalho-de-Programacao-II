#ifndef MEDICO_HPP
#define MEDICO_HPP
#include <iostream>
#include <string>
#include "Pessoa.hpp"

class Medico : public Pessoa{
    private:
        long long int crm;
        string especialidade;
        Medico* prox;
    public:
        Medico ();
        Medico (string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade, long long int crm, string especialidade);
        void setCrm (long long int crm);
        long long int getCrm();
        void setEspecialidade(string especialidade);
        string getEspecialidade();
        void setProx(Medico* prox);
        Medico* getProx();    
        void Imprimir();   
        void imprimirLista();      
};

#endif