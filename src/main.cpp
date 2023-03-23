#include <iostream>
#include <string>
#include "Consultorio.hpp"

using namespace std;

int main ()
{

    Consultorio* c = new Consultorio();
    int op=0;
    string nome, endereco, telefone;
    cout << "\n----[CONSULTORIO]----\n";
    cout << "\nDigite o nome do consultorio: ";
    getline(cin, nome);
    cout << "\nDigite o endereco do consultorio: ";
    getline(cin, endereco);
    cout << "\nDigite o telefone do consultorio: ";
    getline(cin, telefone);
    c->setNome(nome);
    c->setEndereco(endereco);
    c->setTelefone(telefone);
    
    do{
        cout << "\n\n-------> MENU <------\n" << endl;

        cout << "\nSelecione a opcao desejada: " << endl;
        cout << "\n[1]-  Cadastrar medico.\n[2]-  Cadastrar paciente.\n[3]-  Cadastrar consulta.";
        cout << "\n[4]-  Imprimir lista de medicos.\n[5]-  Imprimir lista de pacientes.\n[6]-  Imprimir lista de consultas.";
        cout << "\n[7]-  Imprimir dados de um medico.\n[8]-  Imprimir dados de um paciente.\n[9]-  Imprimir dados de uma consulta especifica.";
        cout << "\n[10]- Imprimir consultas de um medico em especifico.\n[11]- Remover medico.\n[12]- Remover paciente.";
        cout << "\n[13]- Remover consulta.\n[14]- Sair do programa.\n-> ";
        cin >> op;
      

        switch (op){
            case 1:
                c->cadastrarMedico();
            break;
                
            case 2:
                c->cadastrarPaciente();
            break;
                
            case 3:
                c->cadastrarConsulta();
            break;

            case 4:
                c->imprimirListaDeMedicos();
            break;

            case 5:
                c->imprimirListaDePacientes();
            break;

            case 6:
                c->imprimirConsultas();
            break;

            case 7:
                c->imprimirDadosMedico();
            break;

            case 8:
                c->imprimirDadosPaciente();
            break;

            case 9:
                c->imprimirDadosConsulta();
            break;

            case 10:  
                c->imprimirConsultasDoMedico();  
            break;

            case 11:
                c->removerMedico();
            break;    

            case 12:
                c->removerPaciente();
            break;

            case 13:
                c->removerConsulta();
            break;    
        }
        
    }while(op != 14);


    return 0;
}