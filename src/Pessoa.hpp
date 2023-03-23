#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    protected:
        
        string nome;
        char sexo;
        string endereco;
        long long int CPF;
        string telefone;
        string identidade;
        
    public:
        
        Pessoa ();
        Pessoa (string nome, char sexo, string endereco, long long int CPF, string telefone, string identidade);
        ~Pessoa();

        void setNome(string nome);
        string getNome();

        void setSexo(char sexo);
        char getSexo();

        void setEndereco(string endereco);
        string getEndereco();

        void setCPF(long long int CPF);
        long long int getCPF();

        void setTelefone(string telefone);
        string getTelefone();

        void setIdentidade(string identidade);
        string getIdentidade();

        void Imprimir(); 

};

#endif
 
    