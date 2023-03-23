#include <iostream>
#include <string>
#include <sstream>
#include "Consultorio.hpp"

int ContPaciente=0;

Consultorio :: Consultorio(){
    this -> setNome("");
    this -> setEndereco(" ");
    this -> setTelefone("");
    this -> pacientes = new ListaPaciente();
    this -> medicos = new ListaMedico();
    this -> consultas = new ListaConsulta();
}

Consultorio :: Consultorio(string nome, string endereco, string telefone, ListaPaciente* paciente, ListaMedico* medico, ListaConsulta* consulta){
    this -> setNome(nome);
    this -> setEndereco(endereco);
    this -> setTelefone(telefone);
    this -> pacientes = paciente;
    this -> medicos = medico;
    this -> consultas = consulta;
}

void Consultorio :: setNome(string nome){
    this -> nome = nome;
}
string Consultorio :: getNome() {
    return this -> nome;
}

void Consultorio :: setEndereco(string endereco){
    this -> endereco = endereco;
}
string Consultorio :: getEndereco() {
    return this -> endereco;
}

void Consultorio :: setTelefone(string telefone){
    this -> telefone = telefone;
}
string Consultorio :: getTelefone() {
    return this -> telefone;
}

void Consultorio :: cadastrarPaciente(){
    Medico* m = medicos -> getPri();
    Paciente* p = pacientes -> getPri();
    string nome, endereco, telefone, identidade, relato, data, medicacao;
    long long int CPF;
    char sexo;
    unsigned short int cadastrado=0, cpf_diferente=0, nome_diferente=0, medico=0, rg_diferente=0, aux1=0, aux2=0;
    cout << "\n----[CADASTRO PACIENTE]----\n";
    cout << "\nDigite o numero do CPF do Paciente sem pontos, espacos ou tracos: ";
    cin >> CPF;
    cout << "\nDigite a identidade do paciente: ";
    cin.ignore();
    getline(cin, identidade);
    cout << "\nDigite o nome do paciente: ";
    getline(cin, nome);

    while(p){
        if((CPF == p->getCPF()) || (identidade == p->getIdentidade())){
            cout << "\nErro. Paciente ja cadastrado no sistema.";
            cadastrado=1;
        }
        p = p->getProx();
    }

    while(m){
        if(identidade == m->getIdentidade() && CPF != m->getCPF()){
            cpf_diferente=1;
        }  
        if(CPF == m->getCPF()){  
            if(identidade == m->getIdentidade()){
                if(nome == m->getNome()){
                    cout << "\nCadastrando medico de crm '" << m->getCrm() << "' como paciente.";
                    cout << "\nPreencha o restantes dos dados: \n";
                    medico=1;
                }
                nome_diferente=1;
            } 
            rg_diferente=1;   
        }
        m = m->getProx();
    } 

    if (cpf_diferente == 0){
        if ((cadastrado==0 && rg_diferente==0) || (cadastrado==0 && medico==1)){
            do{
                if (aux2 != 0){
                    cout << "\nCaractere invalido. Digite novamente.";
                }
                cout << "\nDigite o sexo do paciente (F para feminino e M para masculino): ";
                cin >> sexo;
                if ((sexo == 'F') || (sexo == 'f') || (sexo == 'M') || (sexo == 'm')){
                    aux1=1;
                }
                aux2=1;
            }while(aux1 == 0);
            cout << "\nDigite o endereco do paciente: ";
            cin.ignore();
            getline(cin, endereco);
            cout << "\nDigite o telefone do paciente: ";
            getline(cin, telefone);
            cout << "\nDigite o relato paciente: ";
            getline(cin, relato);
            cout << "\nDigite a data da ultima consulta do paciente: ";
            getline(cin, data);
            cout << "\nDigite a medicacao do paciente: ";
            getline(cin, medicacao);

            pacientes->inserir(nome, sexo, endereco, CPF, telefone, identidade, relato, data, medicacao);
        }
        else{
            if ((rg_diferente==1) && (nome_diferente==0)){
                cout << "\nCPF invalido.\nO CPF informado ja esta cadastrado para um medico do consultorio e com outra identidade.";
            }
            if ((rg_diferente==1) && (nome_diferente==1) && (medico==0)){
                cout << "\nCPF invalido.\nO CPF informado ja esta cadastrado para um medico do consultorio e com outro nome.";
            }
        }
    }
    else{
        cout << "\nErro. Essa identidade ja esta cadastrada para um medico do consultorio e com um CPF diferente.";
    }    
}

void Consultorio :: removerPaciente(){
    Paciente* p = pacientes->getPri();
    Paciente* ant = NULL;
    Consulta* c = consultas->getPri();
    long long int cpf;
    cout << "\n----[REMOVER PACIENTE]----\n";

    if (pacientes -> vazia()){
        cout << "\nNenhum paciente cadastrado.";
    }
    else{
        cout << "\nDigite o CPF do paciente que deseja remover (sem pontos, espacos ou tracos): ";
        cin >> cpf;
        if (cpf == p->getCPF()){
            while(c){
                removerConsultaPaciente(cpf);
                c = c ->getProx();
            }
            pacientes -> setQtd(pacientes->getQtd()-1);
            pacientes->setPri(p->getProx());
            delete p;
            cout <<"\nPaciente removido do sistema.";
        }
        else{
            while ((p != NULL) && (p->getCPF() != cpf)){
                ant = p;
                p = p->getProx();
            }
            if (p == NULL){
                cout << "\nPaciente informado nao existe no sistema.";
            }    
            else{
                if((pacientes->getPri()->getProx()->getProx()==NULL) && (pacientes->getUlt()->getCPF() == cpf)){
                    while(c){
                        removerConsultaPaciente(cpf);
                        c = c ->getProx();
                    }
                    pacientes -> setQtd(pacientes->getQtd()-1);
                    pacientes->getPri()->setProx(NULL);
                    pacientes->setUlt(pacientes->getPri());
                    cout <<"\nPaciente removido do sistema.";
                }
                else if ((p == pacientes->getUlt()) && (p->getCPF() == cpf)){
                    while(c){
                        removerConsultaPaciente(cpf);
                        c = c ->getProx();
                    }
                    pacientes -> setQtd(pacientes->getQtd()-1);
                    ant -> setProx(NULL);
                    pacientes->setUlt(ant);
                    delete p;
                    cout <<"\nPaciente removido do sistema.";
                }
                else{
                    while(c){
                        removerConsultaPaciente(cpf);
                        c = c ->getProx();
                    }
                    pacientes -> setQtd(pacientes->getQtd()-1);
                    ant -> setProx(p->getProx());
                    delete p;
                    cout <<"\nPaciente removido do sistema.";
                }    
            }
        }    
    } 
}

void Consultorio :: imprimirListaDePacientes(){
    Paciente* p = pacientes->getPri();

    if (pacientes->vazia()){
        cout << "\nLista vazia. Nenhum paciente cadastrado";
    }
    else{
        cout << "\n---[LISTA DE PACIENTES]---\n\n";
        while (p){
            p->imprimirLista();
            p = p->getProx();
        }
        cout << "\nPacientes cadastrados: " << pacientes->getQtd();
    }  
}  

void Consultorio :: imprimirDadosPaciente(){

    Paciente* p = pacientes -> getPri();
    long long int CPF;
    unsigned short int aux=0;
    cout << "\n----[IMPRIMIR DADOS DE UM PACIENTE]----\n";

    if (pacientes -> vazia()){
        cout << "\nNenhum paciente cadastrado.\n" << endl;
    }
    else{
        cout << "\nDigite o CPF do paciente que deseja visualizar os dados (sem pontos, espacos ou tracos): ";
        cin >> CPF;
        
        while (p){
            if (p->getCPF() == CPF){
                cout << "\n---[DADOS PACIENTE]---\n\n ";
                p->Imprimir();
                cout << "\n---";
                aux=1;
                break;
            }    
            p = p->getProx();
        }
        if (aux == 0){
            cout << "\nPaciente nao encontrado.";
        }
    }
}

void Consultorio :: cadastrarMedico(){
    Paciente* p = pacientes -> getPri();
    Medico* m = medicos -> getPri();
    string nome, endereco, telefone, identidade, relato, data, medicacao, especialidade;
    char sexo;
    long long int crm, CPF;
    unsigned short int cadastrado=0, cpf_diferente=0, nome_diferente=0, paciente=0, rg_diferente=0, aux1=0, aux2=0;

    cout << "\n----[CADASTRO MEDICO]----\n";
    cout << "\nDigite o CRM do medico (sem pontos, espacos ou tracos): ";
    cin >> crm;
    cout << "\nDigite o CPF do medico (sem pontos, espacos ou tracos): ";
    cin >> CPF;
    cout << "\nDigite a identidade do medico: ";
    cin.ignore();
    getline(cin, identidade);
    cout << "\nDigite o nome do medico: ";
    getline(cin, nome);

    while(m){
        if((crm == m->getCrm()) || (CPF == m->getCPF()) || (identidade == m->getIdentidade())){
            cout << "\nErro. Medico ja cadastrado no sistema.";
            cadastrado=1;
        }
        m = m->getProx();
    }

    while(p){
        if (cadastrado==0){
            if(identidade == p->getIdentidade() && CPF != p->getCPF()){
                cpf_diferente=1;
            } 
            if(CPF == p->getCPF()){  
                if(identidade == p->getIdentidade()){
                    if(nome == p->getNome()){
                        cout << "\nCadastrando paciente como medico.";
                        cout << "\nPreencha o restantes dos dados: \n";
                        paciente=1;
                    }
                    nome_diferente=1;
                } 
                rg_diferente=1;   
            }
        }
        p = p->getProx();
    }    
    if (cpf_diferente==0){
        if ((cadastrado==0 && rg_diferente==0) || (cadastrado==0 && paciente==1)){
            do{
                if (aux2 != 0){
                    cout << "\nCaractere invalido. Digite novamente.";
                }
                cout << "\nDigite o sexo do medico (F para feminino e M para masculino): ";
                cin >> sexo;
                if ((sexo == 'F') || (sexo == 'f') || (sexo == 'M') || (sexo == 'm')){
                    aux1=1;
                }
                aux2++;
            }while(aux1 == 0);
            cout << "\nDigite o endereco do medico: ";
            cin.ignore();
            getline(cin, endereco);
            cout << "\nDigite o telefone do medico: ";
            getline(cin, telefone);
            cout << "\nDigite a especialidade do medico: ";
            getline(cin, especialidade);

            medicos->inserir(nome, sexo, endereco, CPF, telefone, identidade, crm, especialidade);
        }else{
            if ((rg_diferente==1) && (nome_diferente==0)){
                cout << "\nCPF invalido.\nO CPF informado ja esta cadastrado para um paciente do consultorio e com outra identidade.";
            }
            if ((rg_diferente==1) && (nome_diferente==1) && (paciente==0)){
                cout << "\nCPF invalido.\nO CPF informado ja esta cadastrado para um paciente do consultorio e com outro nome.";
            }
        }
    }
    else{
        cout << "\nErro. Essa identidade ja esta cadastrada para um paciente do consultorio e com um CPF diferente.";
    }
}

void Consultorio :: removerMedico(){
    Medico* m = medicos->getPri();
    Medico* ant = NULL;
    Consulta* c = consultas->getPri();
    long long int crm;
    cout << "\n----[REMOVER MEDICO]----\n";

    if (medicos -> vazia()){
        cout << "\nNenhum medico cadastrado.";
    }
    else{
        cout << "\nDigite o CRM do medico que deseja remover (sem pontos, espacos ou tracos): ";
        cin >> crm;
        if (crm == m->getCrm()){
            while(c){
                removerConsultaMedico(crm);
                c = c ->getProx();
            }
            medicos -> setQtd(medicos->getQtd()-1);
            medicos->setPri(m->getProx());
            delete m;
            cout <<"\nMedico removido do sistema.";
        }
        else{
            while ((m != NULL) && (m->getCrm() != crm)){
                ant = m;
                m = m->getProx();
            }
            if (m == NULL){
                cout << "\nMedico informado nao existe no sistema.";
            }    
            else{
                if((medicos->getPri()->getProx()->getProx()==NULL) && (medicos->getUlt()->getCrm() == crm)){
                    while(c){
                       removerConsultaMedico(crm);
                        c = c ->getProx();
                    }     
                    medicos -> setQtd(medicos->getQtd()-1);
                    medicos->getPri()->setProx(NULL);
                    medicos->setUlt(medicos->getPri());
                    cout <<"\nMedico removido do sistema.";
                }
                else if ((m == medicos->getUlt()) && (m->getCrm() == crm)){
                    while(c){
                        removerConsultaMedico(crm);
                        c = c ->getProx();
                    }
                    medicos -> setQtd(medicos->getQtd()-1);
                    ant -> setProx(NULL);
                    medicos->setUlt(ant);
                    delete m;
                    cout <<"\nMedico removido do sistema.";
                }
                else{
                    while(c){
                        removerConsultaMedico(crm);
                        c = c ->getProx();
                    }
                    medicos -> setQtd(medicos->getQtd()-1);
                    ant -> setProx(m->getProx());
                    delete m;
                    cout <<"\nMedico removido do sistema.";
                }    
            }
        }    
    } 
}

void Consultorio :: imprimirListaDeMedicos(){
    Medico* m = medicos -> getPri();

    if (medicos -> vazia()){
        cout << "\nLista vazia. Nenhum medico cadastrado.";
    }
    else{
        cout << "\n---[LISTA DE MEDICOS]---\n\n";
        while (m){
            m->imprimirLista();
            m = m->getProx();
        }
        cout << "\nMedicos cadastrados: " << medicos->getQtd();
    }  
}  

void Consultorio :: imprimirDadosMedico(){

    Medico* m = medicos -> getPri();
    long long int crm;
    unsigned short int aux=0;
    cout << "\n----[IMPRIMIR DADOS DE UM MEDICO]----\n";


    if (medicos -> vazia()){
        cout << "\nNenhum medico cadastrado.\n" << endl;
    }
    else{
        cout << "\nDigite o CRM do medico que deseja visualizar os dados (sem pontos, espacos ou tracos): ";
        cin>>crm;
        
        while (m){
            if (m->getCrm() == crm){
                cout << "\n---[DADOS MEDICO]---\n\n ";
                m->Imprimir();
                cout << "\n---";
                aux=1;
                break;
            }    
            m = m->getProx();
        }
        if (aux == 0){
            cout << "\nMedico nao encontrado.";
        }
    }
}

void Consultorio :: imprimirConsultasDoMedico(){
    Medico* m = medicos -> getPri();    
    Consulta* c = consultas -> getPri();
    long long int crm=0;
    unsigned short int cadastrado=0, consulta=0;
    cout << "\n----[IMPRIMIR CONSULTAS DE UM MEDICO EM ESPECIFICO]----\n";

    if (consultas -> vazia()){
        cout << "\nNenhuma consulta cadastrada.\n" << endl;
    }
    else{
        cout << "\nDigite o CRM do medico que deseja visualizar a consulta (sem pontos, espacos ou tracos): ";
        cin >> crm;

        while(m){
            if (m->getCrm() == crm){
                cadastrado=1;
                break;
            }    
            m = m->getProx();
        }
        if(cadastrado==0){
            cout << "\nCRM do medico nao esta cadastrado.";
        }
        else{
            while(c){
                if(c->getCrmMedico() == crm){
                    cout << "\n---[DADOS CONSULTA]---\n";
                    c->Imprimir();
                    cout << "\n-------------";
                    consulta=1;
                }
                c = c->getProx();
            }
            if (consulta==0){
            cout << "\nO medico nao tem nenhuma consulta cadastrada nesse consultorio.";
            }
        } 
        
    }  
}    

void Consultorio :: cadastrarConsulta(){
    Consulta* c = consultas -> getPri();
    Paciente* p = pacientes -> getPri();
    Medico* m = medicos -> getPri();

    string hora;
    long long int crm, cpf;
    unsigned short int dia, mes, ano;
    string data_atualizada = "", strdia, strmes, strano;
    stringstream diaaux, mesaux, anoaux;
    unsigned short int cpf_cadastrado=0, crm_cadastrado=0, mesmo_medico=0, aux=0, consulta_medico=0, consulta_paciente=0;
 
    cout << "\n----[CADASTRO CONSULTA]----\n";
    cout << "\nDigite o CPF do paciente (sem pontos, espacos ou tracos): ";
    cin>>cpf;

    while(p){
        if (p->getCPF() == cpf){
            cpf_cadastrado=1;
            break;
        }
        p = p->getProx();
    }

    if(cpf_cadastrado == 1){
        cout << "\nDigite o CRM do medico (sem pontos, espacos ou tracos): ";
        cin >> crm;
        while (m){
            if (m->getCrm() == crm){
                crm_cadastrado=1;
                break;
            }
            m = m->getProx();
        }
        while (m){
            if ((m->getCPF() == cpf) && (m->getCrm() == crm)){
                mesmo_medico=1;
                break;
            }
            m = m->getProx();
        }
    }
    else{
        cout << "\nErro. Paciente nao cadastrado.";
    }

    if (crm_cadastrado==1 && cpf_cadastrado==1 && mesmo_medico==0){
        do{
            if (aux != 0){
                cout << "\nData invalida. Digite novamente.";
            }
            cout << "\nDigite o dia da consulta (d): ";
            cin >> dia;
            cout << "\nDigite o mes da consulta (mm): ";
            cin >> mes;
            cout << "\nDigite o ano da consulta (aaaa): ";
            cin >> ano;
            aux++;
        }while(dia<=0 || dia>=31 || mes<=0 || mes>=13 || ano<=2021);   
        cout << "\nDigite a hora da consulta: ";
        cin.ignore();
        getline(cin, hora);
        while(c){
            if ((c->getCrmMedico() == crm) && (c->getData()->getDia() == dia) && (c->getData()->getMes() == mes) && (c->getData()->getAno() == ano) && (c->getHora() == hora)){
                consulta_medico=1;
            }
            if ((c->getCpfPaciente() == cpf) && (c->getData()->getDia() == dia) && (c->getData()->getMes() == mes) && (c->getData()->getAno() == ano) && (c->getHora() == hora)){
                consulta_paciente=1;
            }
            c = c->getProx();
        }
    }
    
    if(crm_cadastrado == 0 && cpf_cadastrado==1){
        cout << "\nErro. Medico nao cadastrado.";
    }    
    if (consulta_medico == 1){
        cout << "\nO medico informado ja tem uma consulta marcada neste dia e horario.";
    }
    if (consulta_paciente == 1){
        cout <<"\nO paciente informado ja tem uma outra consulta marcada neste mesmo dia e horario.";
    }
    if (mesmo_medico == 1){
        cout <<"\nErro. Um medico nao pode marcar uma consulta com ele mesmo.";
    }

    if ((cpf_cadastrado == 1) && (crm_cadastrado == 1) && (consulta_medico == 0) && (consulta_paciente == 0) && (mesmo_medico==0)){
        
        diaaux << dia;
        strdia = diaaux.str();
        mesaux << mes;
        strmes = mesaux.str();
        anoaux << ano;
        strano = anoaux.str();

        data_atualizada += strdia;
        data_atualizada += "/";
        data_atualizada += strmes;
        data_atualizada += "/";
        data_atualizada += strano;

        while(p){
            if (p->getCPF() == cpf){
                p->setDataUltimaConsulta(data_atualizada);
                break;
            }
            p = p->getProx();
        }

        consultas->inserir(dia, mes, ano, hora, cpf, crm);
    }
}

void Consultorio :: removerConsulta()
{
    Consulta* c = consultas->getPri();
    string hora;
    long long int crm;
    unsigned short int dia=0, mes=0, ano=0, aux=0;
    cout << "\n----[REMOVER CONSULTA]----\n";

    if (consultas -> vazia()){
        cout << "\nNenhuma consulta cadastrada.";
    }
    else{
        cout << "\nDigite o CRM do medico (sem pontos, espacos ou tracos): ";
        cin >> crm;
        cout << "\nDigite o dia da consulta (d): ";
        cin >> dia;
        cout << "\nDigite o mes da consulta (mm): ";
        cin >> mes;
        cout << "\nDigite o ano da consulta (aaaa): ";
        cin >> ano;
        cout << "\nDigite o horario da consulta: ";
        cin.ignore();
        getline(cin, hora);
        
        while(c){
            if((c->getCrmMedico() == crm) && (c->getData()->getDia() == dia) && (c->getData()->getMes() == mes) && (c->getData()->getAno() == ano) && (c->getHora() == hora)){
                aux = 1;
            }
            c = c -> getProx();
        }
        if(aux == 0){
            cout << "\nConsulta informada nao encontrada no sistema.\n";
        }
        else{
            if(consultas->vazia()){
                cout << "\nA lista de consultas cadastradas esta vazia.\n";
            }
            else{
        
                if(consultas->getPri()->getProx()==NULL && (consultas->getPri()->getCrmMedico() == crm) && (consultas->getPri()->getData()->getDia() == dia) && (consultas->getPri()->getData()->getMes() == mes) && (consultas->getPri()->getData()->getAno() == ano) && (consultas->getPri()->getHora() == hora)){
                    consultas -> setQtd(consultas->getQtd()-1);
                    consultas->setPri(NULL);
                    cout <<"\nConsulta removida do sistema.";
                }
                else if((consultas->getPri()->getProx()->getProx()==NULL) && (consultas->getPri()->getCrmMedico() == crm) && (consultas->getPri()->getData()->getDia() == dia) && (consultas->getPri()->getData()->getMes() == mes) && (consultas->getPri()->getData()->getAno() == ano) && (consultas->getPri()->getHora() == hora)){
                    consultas -> setQtd(consultas->getQtd()-1);
                    consultas->setPri(consultas->getPri()->getProx());
                    cout <<"\nConsulta removida do sistema.";
                }
                else if((consultas->getPri()->getProx()->getProx()==NULL) && (consultas->getPri()->getProx()->getCrmMedico() == crm) && (consultas->getPri()->getProx()->getData()->getDia() == dia) && (consultas->getPri()->getProx()->getData()->getMes() == mes) && (consultas->getPri()->getProx()->getData()->getAno() == ano) && (consultas->getPri()->getProx()->getHora() == hora)){
                    consultas -> setQtd(consultas->getQtd()-1);
                    consultas->getPri()->setProx(NULL);
                    consultas->setUlt(consultas->getPri());
                    cout <<"\nConsulta removida do sistema.";
                }
                else{
        
                    Consulta* c = consultas->getPri();
                    Consulta* depoisi = consultas->getPri()->getProx();
                    Consulta* depoisdepoisi = consultas->getPri()->getProx()->getProx();
        
                    while(depoisdepoisi)
                    {
                        if((consultas->getPri()->getCrmMedico() == crm) && (consultas->getPri()->getData()->getDia() == dia) && (consultas->getPri()->getData()->getMes() == mes) && (consultas->getPri()->getData()->getAno() == ano) && (consultas->getPri()->getHora() == hora)){
                            consultas -> setQtd(consultas->getQtd()-1);
                            consultas->setPri(consultas->getPri()->getProx());
                            cout <<"\nConsulta removida do sistema.";
                            break;
                        }
                        else if((depoisi->getCrmMedico() == crm) && (depoisi->getData()->getDia() == dia) && (depoisi->getData()->getMes() == mes) && (depoisi->getData()->getAno() == ano) && (depoisi->getHora() == hora)){
                            consultas -> setQtd(consultas->getQtd()-1);
                            c->setProx(depoisdepoisi);
                            free(depoisi);
                            cout <<"\nConsulta removida do sistema.";
                            break;
                        }
                        
                        c = depoisi;
                        depoisi = depoisdepoisi;
                        depoisdepoisi =  depoisdepoisi->getProx();
                    }
                    if((depoisi == consultas->getUlt()) && (depoisi->getCrmMedico() == crm) && (depoisi->getData()->getDia() == dia) && (depoisi->getData()->getMes() == mes) && (depoisi->getData()->getAno() == ano) && (depoisi->getHora() == hora)){
                        consultas -> setQtd(consultas->getQtd()-1);
                        c->setProx(NULL);
                        consultas->setUlt(c);
                        delete depoisi;
                        cout <<"\nConsulta removida do sistema.";
                    }
                }
            }
        }  
    }
}    

void Consultorio :: imprimirConsultas(){
    Consulta* c = consultas->getPri();

    if (consultas->vazia()){
        cout << "\nLista vazia. Nenhuma consulta cadastrada.";
    }
    else{
        cout << "\n---[LISTA DE CONSULTAS]---\n\n";
        while (c){
            c->Imprimir();
            cout << "\n-----";
            c = c->getProx();
        }
        cout << "\nConsultas cadastradas: " << consultas->getQtd();
    }  
}  

void Consultorio :: imprimirDadosConsulta(){

    Paciente* p = pacientes -> getPri();
    Medico* m = medicos -> getPri();    
    Consulta* c = consultas -> getPri();
    long long int crm, cpf;
    unsigned short int crm_cadastrado=0, cpf_cadastrado=0;
    
    cout << "\n----[IMPRIMIR DADOS DE UMA CONSULTA EM ESPECIFICO]----\n";

    if (consultas -> vazia()){
        cout << "\nNenhuma consulta cadastrada.\n" << endl;
    }
    else{
        cout << "\nDigite o CRM do medico que deseja visualizar a consulta (sem pontos, espacos ou tracos): ";
        cin >> crm;

        while(m){
            if (m->getCrm() == crm){
                crm_cadastrado=1;
                break;
            }    
            m = m->getProx();
        }
        if(crm_cadastrado==0){
            cout << "\nCRM do medico nao esta cadastrado.";
        }else{
            cout << "\nDigite o CPF do paciente que deseja visualizar a consulta (sem pontos, espacos ou tracos): ";
            cin >> cpf;
            while(p){
                if (p->getCPF() == cpf){
                    cpf_cadastrado=1;
                    break;
                }    
                p = p->getProx();
            }
        }    
        
        if(crm_cadastrado==1 && cpf_cadastrado==0){
            cout << "\nCPF do paciente nao esta cadastrado.";
        }

        if((crm_cadastrado==1) && (cpf_cadastrado==1)){
            while(c){
                if(c->getCrmMedico() == crm && c->getCpfPaciente() == cpf){
                    cout << "\n---[DADOS CONSULTA]---\n\n";
                    c->Imprimir();
                    cout << "\n-------------";
                }
                c = c->getProx();
            }
        } 
    }            
}

void Consultorio :: removerConsultaMedico(long long int crm){
    Consulta* c = consultas->getPri();
    unsigned short int crm_cadastrado=0;
    
    while(c){
        if(c->getCrmMedico() == crm){
            crm_cadastrado = 1;
        }
        c = c -> getProx();
    }
    if(crm_cadastrado == 0){
        cout << "\nErro. Medico nao cadastrado.";
    }
    else{
        if(consultas->vazia()){
            
        }
        else{   
            if(consultas->getPri()->getProx()==NULL && (consultas->getPri()->getCrmMedico() == crm)){
                consultas -> setQtd(consultas->getQtd()-1);
                consultas->setPri(NULL);
            }
            else if((consultas->getPri()->getProx()->getProx()==NULL) && (consultas->getPri()->getCrmMedico() == crm)){
                consultas -> setQtd(consultas->getQtd()-1);
                consultas->setPri(consultas->getPri()->getProx());
            }
            else if((consultas->getPri()->getProx()->getProx()==NULL) && (consultas->getPri()->getProx()->getCrmMedico() == crm)){
                consultas -> setQtd(consultas->getQtd()-1);
                consultas->getPri()->setProx(NULL);
                consultas->setUlt(consultas->getPri());
            }
            else{
                Consulta* c = consultas->getPri();
                Consulta* depoisi = consultas->getPri()->getProx();
                Consulta* depoisdepoisi = consultas->getPri()->getProx()->getProx();
                while(depoisdepoisi)
                {
                    if((consultas->getPri()->getCrmMedico() == crm)){
                        consultas -> setQtd(consultas->getQtd()-1);
                        consultas->setPri(consultas->getPri()->getProx());
                        break;
                    }
                    else if(depoisi->getCrmMedico() == crm){
                        consultas -> setQtd(consultas->getQtd()-1);
                        c->setProx(depoisdepoisi);
                        free(depoisi);
                        break;
                    }
                    c = depoisi;
                    depoisi = depoisdepoisi;
                    depoisdepoisi =  depoisdepoisi->getProx();
                }
                if((depoisi == consultas->getUlt()) && (depoisi->getCrmMedico() == crm)){
                    consultas -> setQtd(consultas->getQtd()-1);
                    c->setProx(NULL);
                    consultas->setUlt(c);
                    delete depoisi;
                }
            }
        }
    }   
}    

void Consultorio :: removerConsultaPaciente(long long int cpf){
    Consulta* c = consultas->getPri();
    unsigned short int cpf_cadastrado=0;
    
    while(c){
        if(c->getCpfPaciente() == cpf){
            cpf_cadastrado = 1;
        }
        c = c -> getProx();
    }
    if(cpf_cadastrado == 0){
        cout << "\nErro. Paciente nao cadastrado.";
    }
    else{
        if(consultas->vazia()){
 
        }
        else{   
            if(consultas->getPri()->getProx()==NULL && (consultas->getPri()->getCpfPaciente() == cpf)){
                consultas -> setQtd(consultas->getQtd()-1);
                consultas->setPri(NULL);
            }
            else if((consultas->getPri()->getProx()->getProx()==NULL) && (consultas->getPri()->getCpfPaciente() == cpf)){
                consultas -> setQtd(consultas->getQtd()-1);
                consultas->setPri(consultas->getPri()->getProx());
            }
            else if((consultas->getPri()->getProx()->getProx()==NULL) && (consultas->getPri()->getProx()->getCpfPaciente() == cpf)){
                consultas -> setQtd(consultas->getQtd()-1);
                consultas->getPri()->setProx(NULL);
                consultas->setUlt(consultas->getPri());
            }
            else{
                Consulta* c = consultas->getPri();
                Consulta* depoisi = consultas->getPri()->getProx();
                Consulta* depoisdepoisi = consultas->getPri()->getProx()->getProx();
                while(depoisdepoisi)
                {
                    if((consultas->getPri()->getCpfPaciente() == cpf)){
                        consultas -> setQtd(consultas->getQtd()-1);
                        consultas->setPri(consultas->getPri()->getProx());
                        break;
                    }
                    else if(depoisi->getCpfPaciente() == cpf){
                        consultas -> setQtd(consultas->getQtd()-1);
                        c->setProx(depoisdepoisi);
                        free(depoisi);
                        break;
                    }
                    c = depoisi;
                    depoisi = depoisdepoisi;
                    depoisdepoisi =  depoisdepoisi->getProx();
                }
                if((depoisi == consultas->getUlt()) && (depoisi->getCpfPaciente() == cpf)){
                    consultas -> setQtd(consultas->getQtd()-1);
                    c->setProx(NULL);
                    consultas->setUlt(c);
                    delete depoisi;
                }
            }
        }
    }  
} 
