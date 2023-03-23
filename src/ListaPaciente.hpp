#ifndef LISTAPACIENTE_HPP
#define LISTAPACIENTE_HPP
#include "Paciente.hpp"
#include <iostream>
#include <string>

using namespace std;

class ListaPaciente{
    private:
        
        Paciente* pri; 
        Paciente* ult; 
        int qtd;
        
    public:

        ListaPaciente();
        
        ListaPaciente(string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade, string relato, string dataUltimaConsulta, string medicacao);

        bool vazia();

        virtual ~ListaPaciente();

        Paciente* getPri();
        void setPri(Paciente* pri);

        Paciente* getUlt();
        void setUlt(Paciente* ult);

        int getQtd();
        void setQtd(int qtd);

        void inserir(string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade, string relato, string dataUltimaConsulta, string medicacao);
};    

#endif 