#include <iostream>
#include <fstream>
#include "receita.hpp"
using namespace std;

bool verificar_credenciais_usuario() {
    string login, senha;
    cout << "Digite o login" << endl;
    cin >> login;
    cout << "Digite a senha" << endl;
    cin >> senha;

    try {
        Usuario usuario = getUsuario(login, senha);
    } catch(const runtime_error& e) {
        throw runtime_error(e.what());
    }
    
    return true;
}

void abrir_menu(){
    string titulo = "Miojo";
    string ingredientes = "1 pacote de miojo (sabor de sua preferência), Água (conforme instruções da embalagem)";
    string instrucoes = "Ferva a quantidade de água indicada na embalagem do miojo, Adicione o miojo na água fervente, Cozinhe por cerca de 3 a 4 minutos, mexendo de vez em quando, Desligue o fogo e espere um pouco para o miojo terminar de absorver a água, Escorra o excesso de água, Sirva quente e aproveite o seu miojo!";
    int tempo_preparo = 4;
    int id = 1;
    Receita receita(titulo, ingredientes, instrucoes, tempo_preparo, id);
    string novoNomee;
    string novoIngredientee;
    string novaInstrucaoo;
    int novoTempoo;
    string addIngredientess;
    string addInstrucoess;
    string Loca_Tituloo;
    string Loca_Ingredientee;
    int op = 1;
    while(op!=0){
        cout << "1- Imprimir Receita" << endl;
        cout << "2- Adicionar Receita" << endl;
        cout << "3- Mudar Nome da Receita" << endl;
        cout << "4- Mudar Ingrediente da Receita" << endl;
        cout << "5- Mudar Instruções da Receita" << endl;
        cout << "6- Mudar Tempo da Receita" << endl;
        cout << "7- Adicionar Ingrediente na Receita" << endl;
        cout << "8- Adicionar Instruções na Receita" << endl;
        cout << "9- Localizar pelo o nome a Receita" << endl;
        cout << "10- Localizar pelo Ingrediente a Receita" << endl;
        cout << "0- Sair" << endl;
        cin >> op;

        switch(op){
            case 1:
                cout << "Executando a ação de imprimir informações da Receita" << endl;
                imprimirReceita(receita);
                break;
            case 2:
                cout << "Executando a ação de adicionar Receita" << endl;
                adicionarAoHistorico(receita);
                getReceita(receita);
                adicionarReceita(receita);
                break;
            case 3:
            
                cout << "Executando a ação de mudar Nome da Receita" << "\n" <<endl;
                cout << "Diga o novo nome da receita:" << endl;
                cin >> novoNomee;
                Mudar_Nome(receita, novoNomee);
                break;
            case 4:
                cout << "Executando a ação de mudar Ingrediente da Receita" << "\n" <<endl;
                cout << "Diga o novo Ingrediente da receita:" << endl;
                cin >> novoIngredientee;
                Mudar_Ingrediente(receita, novoIngredientee);
                break;
            case 5:
                cout << "Executando a ação de mudar Instruções da Receita" << "\n" <<endl;
                cout << "Diga o nova Instruções da receita:" << endl;
                cin >> novaInstrucaoo;
                Mudar_Instrucao(receita, novaInstrucaoo);
                break;
            case 6:
                cout << "Executando a ação de mudar Tempo da Receita" << "\n" <<endl;
                cout << "Diga o novo Tempo da receita:" << endl;
                cin >> novoTempoo;
                Mudar_Tempo_Preparo(receita, novoTempoo);
                break;
            case 7:
                cout << "Executando a ação de adicionar Ingrediente na Receita" << "\n" <<endl;
                cout << "Qual Ingrediente sera inserido na receita:" << endl;
                cin >>  addIngredientess;
                Add_Ingredientes(receita, addIngredientess);
                break;
            case 8:
                cout << "Executando a ação de adicionar Instruções na Receita" << "\n" <<endl;
                cout << "Qual Instruções sera inserido na receita:" << endl;
                cin >> addInstrucoess;
                Add_Instrucoes(receita, addInstrucoess);
                break;
            case 9:
                cout << "Executando a ação de localizar pelo nome a Receita" << "\n" <<endl;
                cout << "Qual o nome da Receita para fazer a procura:" << endl;
                cin >> Loca_Tituloo;
                Loc_Titulo(receita, Loca_Tituloo);
                break;
            case 10:
                cout << "Executando a ação de localizar pelo Ingrediente a Receita" << "\n" <<endl;
                cout << "Qual o Ingrediente da Receita para fazer a procura:" << endl;
                cin >> Loca_Ingredientee;
                Loc_Ingrediente(receita, Loca_Ingredientee);
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida, tente novamente" << endl;
        }
    }
}



int main() {
    try {
        bool usuario_autorizado = verificar_credenciais_usuario();
        if (usuario_autorizado) {
            abrir_menu();
        }
    } catch(const runtime_error& e) {
        cout << e.what() << endl;
        cout << "Por favor, tente novamente!" << endl;
    }
    return 0;
}


