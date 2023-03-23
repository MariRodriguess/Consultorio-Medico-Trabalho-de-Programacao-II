#ifndef CONSULTA_HPP
#define CONSULTA_HPP
#include "Data.hpp"
#include <iostream>
#include <string>

using namespace std;

class Consulta{
    private:
        Consulta* prox;
        Data* data;
        int dia, mes, ano;
        string hora;
        long long int cpfPaciente;
        long long int crmMedico;
    public:
        Consulta ();
        Consulta (int dia, int mes, int ano, string hora, long long int cpfPaciente, long long int crmMedico); 
        
        void setData (int dia, int mes, int ano);
        Data* getData();

        void setHora(string hora);
        string getHora();

        void setCpfPaciente(long long int cpfPaciente);
        long long int getCpfPaciente();

        void setCrmMedico(long long int crmMedico);
        long long int getCrmMedico();

        Consulta* getProx();
        void setProx(Consulta* prox);

        void Imprimir();
};

#endif