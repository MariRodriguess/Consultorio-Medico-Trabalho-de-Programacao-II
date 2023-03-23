#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>
#include <string>

using namespace std;

class Data{
    private:
        Data* prox;
        int dia;
        int mes;
        int ano;
    public:
        Data ();
        Data (int dia, int mes, int ano); 

        void setDia(int dia);
        int getDia();

        void setMes(int mes);
        int getMes();

        void setAno(int ano);
        int getAno();

        Data* getProx();
        void setProx(Data* prox);
};

#endif