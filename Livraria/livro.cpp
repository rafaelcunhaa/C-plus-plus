#include "livro.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

void cadastro_livro(Livro *livros, int tamanho) {
  for (int i = 5; i < tamanho; i++) {
    string nome_livro;
    string nome_autor;
    int ano_livro;
    int copias_livro;
    cout << "Digite o nome do livro " << endl;
    cin >> nome_livro;
    cout << "Digite o nome do autor " << endl;
    cin >> nome_autor;
    cout << "Digite o ano do livro " << endl;
    cin >> ano_livro;
    cout << "Digite as copias " << endl;
    cin >> copias_livro;
    livros[i].titulo = nome_livro;
    livros[i].autor = nome_autor;
    livros[i].ano = ano_livro;
    livros[i].copias = copias_livro;
    livros[i].total = 0;
    cout << "Cadastro do livro feito" << endl;
  }
}

void cadastrarUsuario(Usuario *usuarios, int tamanho) {

  for (int i = 5; i < tamanho; i++) {
    string nome;
    cout << "Digite o nome do usuário " << i + 1 << ": " << endl;
    cin >> nome;

    usuarios[i].nome = nome;
    usuarios[i].historicoLivros = 0;
    usuarios[i].numeroEmprestimos = "";
    cout << "Cadastro feito, seu numero de indentificacao é 1006" << endl;
  }
}

void emprestarLivro(Usuario *usuarios, Livro *livros, int &livroIndex,
                    int &usuarioIndex) {

  cout << "Digite o ID do usuário (1001 a 1006): ";
  cin >> usuarioIndex;

  if (usuarioIndex >= 1001 && usuarioIndex <= 1006) {
    cout << "Qual livro você deseja pegar (0 até 4) " << endl;
    cin >> livroIndex;

    if (livroIndex >= 0 && livroIndex <= 4) {
      if (livros[livroIndex].copias > 0) {
        cout << "Livro emprestado com sucesso para o usuário "
             << usuarios[usuarioIndex - 1001].nome << "." << endl;
        usuarios[usuarioIndex - 1001].historicoLivros++;
        usuarios[usuarioIndex - 1001].numeroEmprestimos =
            livros[livroIndex].titulo;
        livros[livroIndex].total++;
        livros[livroIndex].copias--;
      } else {
        cout << "Não há cópias disponíveis deste livro." << endl;
      }
    } else {
      cout << "Índice de livro inválido." << endl;
    }
  } else {
    cout << "Número de identificação de usuário inválido." << endl;
  }
}

void devolucao_livro(Usuario *usuarios, Livro *livro, int &livroIndex,
                     int &usuarioIndex, int &dia) {
  cout << "Digite o ID do usuário (1001 a 1006): ";
  cin >> usuarioIndex;
  if (usuarioIndex >= 1001 && usuarioIndex <= 1006) {
    cout << "Qual livro você deseja devolver (0 até 4) " << endl;
    cin >> livroIndex;

    if (livroIndex >= 0 && livroIndex <= 4) {
      if (livro[livroIndex].copias > 0) {
        cout << "Livro devolvido com sucesso "
             << usuarios[usuarioIndex - 1001].nome << "." << endl;
        usuarios[usuarioIndex - 1001].numeroEmprestimos = "";
        livro[livroIndex].copias++;
        cout << "quantos dias ficou sem devolver";
        cin >> dia;
        dia = dia * 2;
        cout << "voce deve" << dia << endl;
      } else {
        cout << "Não há cópias disponíveis deste livro." << endl;
      }
    } else {
      cout << "Índice de livro inválido." << endl;
    }
  } else {
    cout << "Número de identificação de usuário inválido." << endl;
  }
}
void imprimir(Livro *livros, int tamanhoo) {
  string titulo;
  string autor;
  int ano;

  cout << "Digite o nome do livro: ";
  cin >> titulo;
  cout << "Digite o autor do livro: ";
  cin >> autor;
  cout << "Digite o ano de lançamento do livro: ";
  cin >> ano;

  bool encontrado = false;

  for (int i = 0; i < tamanhoo; i++) {
    if (titulo == livros[i].titulo && autor == livros[i].autor &&
        ano == livros[i].ano) {
      encontrado = true;
      cout << "Livro encontrado:" << endl;
      cout << "Título: " << livros[i].titulo
           << endl; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      cout << "Autor: " << livros[i].autor << endl;
      cout << "Ano de lançamento: " << livros[i].ano << endl;
      break;
    }
  }

  if (!encontrado) {
    cout << "Livro não encontrado." << endl;
  }
}

/*void verificarLivrosEmprestados(Usuario *usuarios, Livro *livros, int
tamanhoo, int usuarioIndex) { cout << "Digite o ID do usuário (1001 a 1006): ";
    cin >> usuarioIndex;
        cout << "Livros emprestados para " << usuarios[usuarioIndex - 1001].nome
<< ":" << endl;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! for (int i = 0; i < tamanhoo;
i++) { if(usuarios[usuarioIndex - 1001].numeroEmprestimos != ""){ cout <<
"Título: " << livros[i].titulo << endl; cout << "Autor: " << livros[i].autor <<
endl; cout << "Ano de lançamento: " << livros[i].ano << endl; cout <<
"-------------------------" << endl;
            }
        }
}*/
void listarLivrosDisponiveis(Livro *livros, int tamanhoo) {
  cout << "Livros disponíveis na biblioteca:" << endl;

  for (int i = 0; i < tamanhoo; i++) {
    if (livros[i].copias > 0) {
      cout << "Título: " << livros[i].titulo << endl;
      cout << "Autor: " << livros[i].autor << endl;
      cout << "Ano de lançamento: " << livros[i].ano << endl;
      cout << "Cópias disponíveis: " << livros[i].copias << endl;
      cout << "-------------------------" << endl;
    }
  }
}
/*void multa(Usuario *usuarios,int &dia,int &usuarioIndex,int &tamanhoo){
  cout << "MULTA"<<endl;
    cout << "Digite o ID do usuário (1001 a 1006): ";
    cin >> usuarioIndex;
    if (usuarioIndex >= 1001 && usuarioIndex <= 1006) {
      cout << "quantos dias ficou sem devolver";
      cin >> dia;
dia=dia *2;
            cout << "voce deve"<< dia<< endl;


    }

}*/
void estatisticas(Usuario *usuarios, Livro *livros, int &total_emprestimo,
                  int &tamanhoo) {
  total_emprestimo = 0;
  int livroMaisPopularIndex = 0;
  int usuarioMaisAtivo = 0;

  for (int i = 0; i < tamanhoo; i++) {
    total_emprestimo += usuarios[i].historicoLivros;
  }
  cout << "Total de empréstimos: " << total_emprestimo << endl;
  for (int h = 0; h < tamanhoo; h++) {
    if (livros[h].total > livros[livroMaisPopularIndex].total) {
      livroMaisPopularIndex = h;
    }
  }
  cout << "Livro mais popular:" << endl;
  cout << "Título: " << livros[livroMaisPopularIndex].titulo << endl;
  cout << "Autor: " << livros[livroMaisPopularIndex].autor << endl;
  cout << "Ano de lançamento: " << livros[livroMaisPopularIndex].ano << endl;
  cout << "Total de empréstimos: " << livros[livroMaisPopularIndex].total
       << endl;
  for (int e = 0; e < tamanhoo; e++) {
    if (usuarios[e].historicoLivros >
        usuarios[usuarioMaisAtivo].historicoLivros) {
      usuarioMaisAtivo = e;
    }
  }
  cout << "Usuário mais ativo:" << endl;
  cout << "Nome: " << usuarios[usuarioMaisAtivo].nome << endl;
  cout << "Número de Identificação: "
       << usuarios[usuarioMaisAtivo].numeroIdentificacao << endl;
  cout << "Total de empréstimos: " << usuarios[usuarioMaisAtivo].historicoLivros
       << endl;
}
