#include <iostream>
#include <fstream>
#include <vector>
#include "receita.hpp"

using namespace std;

Usuario getUsuario(string login, string senha) {
    string nome_arquivo = login + "_" + senha + ".txt";
    ifstream arquivo_usuario(nome_arquivo);

    if (!arquivo_usuario.is_open()) {
        throw runtime_error("Os dados do usuário não existem");
    }

    string linha, nome;
    int idade, id;
    getline(arquivo_usuario,linha);
    nome = linha;
    getline(arquivo_usuario,linha);
    idade = stoi(linha);
    getline(arquivo_usuario,linha);
    id = stoi(linha);
    
    Usuario usuario(nome,idade,id);

    arquivo_usuario.close();

    return usuario;
}

ofstream abrirReceitaEscrita(Receita receita){
    ofstream arquivo_saida("Receita.txt", ios::app); 
    if (!arquivo_saida.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo");
    }
    return arquivo_saida;
}

ifstream abrirReceitaLeitura(Receita receita){
    ifstream arquivo_entrada("Receita.txt");
    if (!arquivo_entrada.is_open()) {
        throw runtime_error("Erro ao abrir o arquivo");
    }   
    return arquivo_entrada;
}

void imprimirReceita(Receita receita){
    cout << "|Título: " << receita.titulo << endl;
    cout << "|Ingredientes: " << receita.ingredientes << endl;
    cout << "|Instruções: " << receita.instrucoes << endl;
    cout << "|Tempo de Preparo: " << receita.tempo_preparo << endl;
    cout << "|Id: " << receita.id << endl;
    cout << "\n";
}

void adicionarReceita(Receita receita) {
    try {
        ofstream arquivoReceita = abrirReceitaEscrita(receita);

        arquivoReceita << "|Título:" << receita.titulo << " ||" << endl;
        arquivoReceita << "|Ingredientes:" << receita.ingredientes << " |||" << endl;
        arquivoReceita << "|Instruções:" << receita.instrucoes << " ||||" << endl;
        arquivoReceita << "|Tempo de Preparo:" << receita.tempo_preparo << " minutos." << " |||||" << endl;
        arquivoReceita << "|Id: " << receita.id << " ||" << endl;
        arquivoReceita << "-----------------------------" << endl;

        arquivoReceita.close();

    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void getReceita(Receita receita) {
    try {
        ifstream arquivoReceita("Receita.txt");
        if (!arquivoReceita.is_open()) {
            throw runtime_error("Erro ao abrir o arquivo");
        }
        string linha;
        bool lendoHistorico = false;
        string historico;

        while (getline(arquivoReceita, linha)) {
            if (linha == "|HISTORICO RECEITAS|") {
                lendoHistorico = true;
            } else if (lendoHistorico && linha[0] == '-') {
                historico += linha + '\n';
            }
        }

        arquivoReceita.close();

        cout << "Histórico de Receitas para " << receita.titulo << ":\n";
        cout << historico << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

void adicionarAoHistorico(Receita receita) {
    try {
        ofstream arquivoHistorico = abrirReceitaEscrita(receita);

        arquivoHistorico << "|HISTORICO RECEITAS|" << endl;
        arquivoHistorico << "-Título: " << receita.titulo << endl;
        arquivoHistorico << "-Ingredientes: " << receita.ingredientes << endl;
        arquivoHistorico << "-Instruções: " << receita.instrucoes << endl;
        arquivoHistorico << "-Tempo de Preparo: " << receita.tempo_preparo << " minutos." << endl;
        arquivoHistorico << "-Id: " << receita.id << endl;
        arquivoHistorico << "-----------------------------" << endl;

        arquivoHistorico.close();
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}
void Mudar_Nome(Receita receita, string novoNome) {
    string nome_arquivo = "Receita.txt";
    ifstream arquivoReceita(nome_arquivo);
    if (!arquivoReceita.is_open()) {
        cout << "Erro ao abrir o arquivo " << nome_arquivo << endl;
        return;
    }

    string linha;
    string arquivo_temporario = "temp.txt";
    ofstream arquivo_temp(arquivo_temporario);
    if (!arquivo_temp.is_open()) {
        cout << "Erro ao abrir o arquivo " << arquivo_temporario << endl;
        return;
    }

    while (getline(arquivoReceita, linha)) {
        if (linha == "|Título:") {
            arquivo_temp << "|Título: " << novoNome << "||"<< endl;
        } else {
            arquivo_temp << linha << endl;
        }
    }

    arquivo_temp.close();
    arquivoReceita.close();

    remove(nome_arquivo.c_str());
    rename(arquivo_temporario.c_str(), nome_arquivo.c_str());

    cout << "Informação adicionada a Receita com sucesso!" << "\n" <<endl;
}

void Mudar_Ingrediente(Receita receita, string novoIngrediente) {
    string nome_arquivo = "Receita.txt";
    ifstream arquivoReceita(nome_arquivo);
    if (!arquivoReceita.is_open()) {
        cout << "Erro ao abrir o arquivo " << nome_arquivo << endl;
        return;
    }

    string linha;
    string arquivo_temporario = "temp.txt";
    ofstream arquivo_temp(arquivo_temporario);
    if (!arquivo_temp.is_open()) {
        cout << "Erro ao abrir o arquivo " << arquivo_temporario << endl;
        return;
    }

    while (getline(arquivoReceita, linha)) {
        if (linha == "|Ingredientes:") {
            arquivo_temp << "|Ingredientes: " << novoIngrediente << "||" <<endl;
        } else {
            arquivo_temp << linha << endl;
        }
    }

    arquivo_temp.close();
    arquivoReceita.close();

    remove(nome_arquivo.c_str());
    rename(arquivo_temporario.c_str(), nome_arquivo.c_str());

    cout << "Informação adicionada a Receita com sucesso!" << "\n" <<endl;
}

void Mudar_Instrucao(Receita receita, string novaInstrucao) {
    string nome_arquivo = "Receita.txt";
    ifstream arquivoReceita(nome_arquivo);
    if (!arquivoReceita.is_open()) {
        cout << "Erro ao abrir o arquivo " << nome_arquivo << endl;
        return;
    }

    string linha;
    string arquivo_temporario = "temp.txt";
    ofstream arquivo_temp(arquivo_temporario);
    if (!arquivo_temp.is_open()) {
        cout << "Erro ao abrir o arquivo " << arquivo_temporario << endl;
        return;
    }

    while (getline(arquivoReceita, linha)) {
        if (linha == "|Instruções:") {
            arquivo_temp << "|Instruções: " << novaInstrucao << "||" <<endl;
        } else {
            arquivo_temp << linha << endl;
        }
    }

    arquivo_temp.close();
    arquivoReceita.close();

    remove(nome_arquivo.c_str());
    rename(arquivo_temporario.c_str(), nome_arquivo.c_str());

    cout << "Informação adicionada a Receita com sucesso!" << "\n" << endl;
}

void Mudar_Tempo_Preparo(Receita receita, int novoTempo) {
    string nome_arquivo = "Receita.txt";
    ifstream arquivoReceita(nome_arquivo);
    if (!arquivoReceita.is_open()) {
        cout << "Erro ao abrir o arquivo " << nome_arquivo << endl;
        return;
    }

    string linha;
    string arquivo_temporario = "temp.txt";
    ofstream arquivo_temp(arquivo_temporario);
    if (!arquivo_temp.is_open()) {
        cout << "Erro ao abrir o arquivo " << arquivo_temporario << endl;
        return;
    }

    while (getline(arquivoReceita, linha)) {
        if (linha == "|Tempo de Preparo:") {
            arquivo_temp << "|Tempo de Preparo: " << novoTempo <<  " minutos." << "||" <<endl;
        } else {
            arquivo_temp << linha << endl;
        }
    }

    arquivo_temp.close();
    arquivoReceita.close();

    remove(nome_arquivo.c_str());
    rename(arquivo_temporario.c_str(), nome_arquivo.c_str());

    cout << "Informação adicionada a Receita com sucesso!" << "\n" << endl;
}

void Add_Ingredientes(Receita receita, string addIngrediente) {
    string nome_arquivo = "Receita.txt";
    ifstream arquivoReceita(nome_arquivo);
    if (!arquivoReceita.is_open()) {
        cout << "Erro ao abrir o arquivo " << nome_arquivo << endl;
        return;
    }

    string linha;
    string arquivo_temporario = "temp.txt";
    ofstream arquivo_temp(arquivo_temporario);
    if (!arquivo_temp.is_open()) {
        cout << "Erro ao abrir o arquivo " << arquivo_temporario << endl;
        return;
    }

    while (getline(arquivoReceita, linha)) {
        if (linha == "|||") {
            arquivo_temp << "|||" <<addIngrediente  << "|||" <<endl;
        } else {
            arquivo_temp << linha << endl;
        }
    }

    arquivo_temp.close();
    arquivoReceita.close();

    remove(nome_arquivo.c_str());
    rename(arquivo_temporario.c_str(), nome_arquivo.c_str());

    cout << "Informação adicionada a Receita com sucesso!" << "\n" << endl;
}

void Add_Instrucoes(Receita receita, string addInstrucoes) {
    string nome_arquivo = "Receita.txt";
    ifstream arquivoReceita(nome_arquivo);
    if (!arquivoReceita.is_open()) {
        cout << "Erro ao abrir o arquivo " << nome_arquivo << endl;
        return;
    }

    string linha;
    string arquivo_temporario = "temp.txt";
    ofstream arquivo_temp(arquivo_temporario);
    if (!arquivo_temp.is_open()) {
        cout << "Erro ao abrir o arquivo " << arquivo_temporario << endl;
        return;
    }

    while (getline(arquivoReceita, linha)) {
        if (linha == "||||") {
            arquivo_temp << "||||" << addInstrucoes  << "||||" <<endl;
        } else {
            arquivo_temp << linha << endl;
        }
    }

    arquivo_temp.close();
    arquivoReceita.close();

    remove(nome_arquivo.c_str());
    rename(arquivo_temporario.c_str(), nome_arquivo.c_str());

    cout << "Informação adicionada a Receita com sucesso!" << "\n" << endl;
}

void Loc_Titulo(Receita receita,string Loca_Titulo){
    try{
        ifstream loc_Titulo = abrirReceitaLeitura(receita);
        string linha;
        while(getline(loc_Titulo,linha)){
            if(linha == "|Título:" ){
        if(linha == Loca_Titulo){
            cout << "Essa Receita foi encontrada." << "\n" << endl;
        }else{
            cout << "Não foi encontrado essa receita." << "\n" << endl;
                }
            }else if(linha == "|Ingredientes:" ){
                break;
            }
        }
    }catch(const runtime_error e){
        cout << e.what() << endl;
    }
}

void Loc_Ingrediente(Receita receita,string Loca_Ingrediente){
    try{
        ifstream loc_Ingrediente = abrirReceitaLeitura(receita);
        string linha;
        while(getline(loc_Ingrediente,linha)){
            if(linha == "|Ingredientes:" ){
        if(linha == Loca_Ingrediente){
            cout << "Essa Receita com esse Ingrediente foi encontrada." << "\n" << endl;
        }else{
            cout << "Não foi encontrado esse Ingrediente." << "\n" << endl;
                }
            }else if(linha == "|Instruções:" ){
                break;
            }
        }
    }catch(const runtime_error e){
        cout << e.what() << endl;
    }
}


