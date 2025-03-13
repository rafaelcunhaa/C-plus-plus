#include "livro.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int tamanhoo = 0;
  int tamanho = 6;
  int tamanho_livro = 6;
  int livroIndex;
  int usuarioIndex;
  int dia;
  int total_emprestimo;

  //----------------------------------------------------------
  Usuario *vetor_usuarios = new Usuario[tamanho];
  vetor_usuarios[0].nome = "CR7";
  vetor_usuarios[0].numeroIdentificacao = 1001;
  vetor_usuarios[0].historicoLivros = 0;
  vetor_usuarios[0].numeroEmprestimos = "";

  vetor_usuarios[1].nome = "Messi";
  vetor_usuarios[1].numeroIdentificacao = 1002;
  vetor_usuarios[1].historicoLivros = 0;
  vetor_usuarios[1].numeroEmprestimos = "";

  vetor_usuarios[2].nome = "Gabigol";
  vetor_usuarios[2].numeroIdentificacao = 1003;
  vetor_usuarios[2].historicoLivros = 0;
  vetor_usuarios[2].numeroEmprestimos = "";

  vetor_usuarios[3].nome = "Neymar";
  vetor_usuarios[3].numeroIdentificacao = 1004;
  vetor_usuarios[3].historicoLivros = 0;
  vetor_usuarios[3].numeroEmprestimos = "";

  vetor_usuarios[4].nome = "Pele";
  vetor_usuarios[4].numeroIdentificacao = 1005;
  vetor_usuarios[4].historicoLivros = 0;
  vetor_usuarios[4].numeroEmprestimos = "";

  vetor_usuarios[5].numeroIdentificacao = 1006;
  vetor_usuarios[5].historicoLivros = 0;
  vetor_usuarios[5].numeroEmprestimos = "";

  //-----------------------------------------------------------
  Livro *vetor_livros = new Livro[tamanho_livro];
  vetor_livros[0].titulo = "Cem Anos de Solidão";
  vetor_livros[0].autor = "Gabriel García Marquez";
  vetor_livros[0].ano = 1967;
  vetor_livros[0].copias = 3;
  vetor_livros[0].total = 0;

  vetor_livros[1].titulo = "O Senhor dos Anéis";
  vetor_livros[1].autor = "J.R.R. Tolkien";
  vetor_livros[1].ano = 1954;
  vetor_livros[1].copias = 5;
  vetor_livros[1].total = 0;

  vetor_livros[2].titulo = "O Pequeno Príncipe";
  vetor_livros[2].autor = "Antoine de Saint-Exupéry";
  vetor_livros[2].ano = 1943;
  vetor_livros[2].copias = 3;
  vetor_livros[2].total = 0;

  vetor_livros[3].titulo = "Harry Potter e a Pedra Filosofal";
  vetor_livros[3].autor = "J.K. Rowling";
  vetor_livros[3].ano = 1997;
  vetor_livros[3].copias = 12;
  vetor_livros[3].total = 0;

  vetor_livros[4].titulo = "O Alquimista";
  vetor_livros[4].autor = "Paulo Coelho";
  vetor_livros[4].ano = 1988;
  vetor_livros[4].copias = 6;
  vetor_livros[4].total = 0;

  //------------------------------------------------------------

  cadastro_livro(vetor_livros, tamanho);
  cadastrarUsuario(vetor_usuarios, tamanho);
  emprestarLivro(vetor_usuarios, vetor_livros, usuarioIndex, livroIndex);
  devolucao_livro(vetor_usuarios, vetor_livros, usuarioIndex, livroIndex, dia);
  imprimir(vetor_livros, tamanhoo);
  // verificarLivrosEmprestados(vetor_usuarios,
  // vetor_livros,tamanhoo,usuarioIndex);
  listarLivrosDisponiveis(vetor_livros, tamanhoo);
  // multa(vetor_usuarios,dia,usuarioIndex,tamanhoo);
  estatisticas(vetor_usuarios, vetor_livros, total_emprestimo, tamanhoo);
  return 0;
}