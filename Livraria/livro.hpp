#ifndef LIVRO_HPP
#define LIVRO_HPP
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

struct Livro {
    string titulo;
    string autor;
    int ano;
    int copias;
    int total;
    
};

struct Usuario {
    string nome;
    int numeroIdentificacao;
    int historicoLivros;
    string numeroEmprestimos ;
};

void cadastro_livro(Livro *livros,int tamanho);
void cadastrarUsuario(Usuario *usuarios, int tamanho);
void emprestarLivro(Usuario *usuarios, Livro *livros,int &livroIndex,int &usuarioIndex);
void devolucao_livro(Usuario *usuarios,Livro *livro,int &livroIndex,int &usuarioIndex,int &dia);
void imprimir(Livro *livro,int tamanhoo);
//void verificarLivrosEmprestados(Usuario *usuarios, Livro *livros, int &tamanhoo, int &usuarioIndex);
void listarLivrosDisponiveis(Livro *livros, int tamanhoo);
//void multa(Usuario *usuarios,int &dia,int &usuarioIndex,int &tamanhoo);
void estatisticas(Usuario *usuarios,Livro *livros,int &total_emprestimo,int &tamanhoo);

#endif