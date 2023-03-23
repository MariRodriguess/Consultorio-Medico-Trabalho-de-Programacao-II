#ifndef LISTAMEDICO_HPP
#define LISTAMEDICO_HPP
#include "Medico.hpp"
#include <iostream>
#include <string>

using namespace std;

class ListaMedico {
    private:
        Medico* pri; 
        Medico* ult; 
        int qtd;
        
    public:
        ListaMedico();
        
        ListaMedico(string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade, long long int crm, string especialidade);

        bool vazia();

        virtual ~ListaMedico();

        Medico* getPri();
        void setPri(Medico* pri);

        Medico* getUlt();
        void setUlt(Medico* ult);

        int getQtd();
        void setQtd(int qtd);

        void inserir(string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade, long long crm, string especialidade);
}; 

#endif 
