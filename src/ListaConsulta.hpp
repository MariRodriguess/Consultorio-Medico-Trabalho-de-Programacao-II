#ifndef LISTACONSULTA_HPP
#define LISTACONSULTA_HPP
#include "Consulta.hpp"
#include <iostream>
#include <string>

using namespace std;

class ListaConsulta{
    private:
        
        Consulta* pri; 
        Consulta* ult; 
        int qtd;
        
    public:

        ListaConsulta();
        
        ListaConsulta (int dia, int mes, int ano, string hora, long long int cpfPaciente, long long int crmMedico);

        bool vazia();

        virtual ~ListaConsulta();

        Consulta* getPri();
        void setPri(Consulta* pri);

        Consulta* getUlt();
        void setUlt(Consulta* ult);

        int getQtd();
        void setQtd(int qtd);

        void inserir(int dia, int mes, int ano, string hora, long long int cpfPaciente, long long int crmMedico);
};    

#endif 