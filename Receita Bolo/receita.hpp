#ifndef RECEITA_HPP
#define RECEITA_HPP
#include <iostream>
#include <vector>
using namespace std;
struct Receita {
    string titulo;
    string ingredientes;
    string instrucoes;
    int tempo_preparo;
    int id;

    Receita(string _titulo, string _ingredientes, string _instrucoes, int _tempo_preparo, int _id) {
        titulo = _titulo;
        ingredientes = _ingredientes;
        instrucoes = _instrucoes;
        tempo_preparo = _tempo_preparo;
        id = _id;
    }
};

struct Usuario {
  
  string nome;
  int idade;
  int id;
  
  Usuario(string _nome, int _idade, int _id){
      nome = _nome;
      idade = _idade;
      id = _id;
  }
  
};


Usuario getUsuario(string login, string senha);

ofstream abrirReceitaEscrita(Receita receita);

ifstream abrirReceitaLeitura(Receita receita);

void imprimirReceita(Receita receita);

void adicionarReceita(Receita receita);

void adicionarAoHistorico(Receita receita);

void getReceita(Receita receita);

void Mudar_Nome(Receita receita, string novoNome);

void Mudar_Ingrediente(Receita receita, string novoIngrediente);

void Mudar_Instrucao(Receita receita, string novaInstrucao);

void Mudar_Tempo_Preparo(Receita receita, int novoTempo);

void Add_Ingredientes(Receita receita, string addIngrediente);

void Add_Instrucoes(Receita receita, string addInstrucoes);

void Loc_Titulo(Receita receita,string Loca_Titulo);

void Loc_Ingrediente(Receita receita,string Loca_Ingrediente);

#endif

