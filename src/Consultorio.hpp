#ifndef CONSULTORIO_HPP
#define CONSULTORIO_HPP
#include "ListaPaciente.hpp"
#include "ListaConsulta.hpp"
#include "ListaMedico.hpp"
#include <iostream>
#include <string>


using namespace std;

class Consultorio {
    private:
        ListaPaciente* pacientes;
        ListaConsulta* consultas;
        ListaMedico* medicos;
        string nome;
        string endereco;
        string telefone;

    public:
        
        Consultorio();
        Consultorio(string nome, string endereco, string telefone, ListaPaciente* paciente, ListaMedico* medico, ListaConsulta* consulta);

        void setNome(string nome);
        string getNome();

        void setEndereco(string endereco);
        string getEndereco();

        void setTelefone(string telefone);
        string getTelefone();

        void cadastrarPaciente();
        void removerPaciente();
        void imprimirListaDePacientes();
        void imprimirDadosPaciente();
        void removerConsultaPaciente(long long int cpf);

        void cadastrarMedico();
        void removerMedico();
        void imprimirListaDeMedicos();
        void imprimirDadosMedico();
        void imprimirConsultasDoMedico();
        void removerConsultaMedico(long long int crm);

        void cadastrarConsulta();
        void removerConsulta();
        void imprimirConsultas();
        void imprimirDadosConsulta();

};

#endif
 
    