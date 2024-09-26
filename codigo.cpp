// SISTEMA DE GERENCIAMENTO DE BIBLIOTECA 
// DEFININDO BIBLIOTECAS 
# include <iostream> 
# include <string> 
using namespace std;

// FUNÇÃO PARA CADASTRAR LIVRO
void cadastro_livros(Livros vetor[], int &cont) {
    // DEFININDO VARIÁVEIS
    int i;
    char resposta; 

    // DEFININDO CONDIÇÕES
    while (cont < 100) {
        // PEDINDO INFORMAÇÕES 
        cout << "Digite o titulo do livro: ";
        cin >> vetor[cont].titulo; 

        cout << "Digite o nome do autor: ";
        cin >> vetor[cont].autor;

        cout << "Digite o numero de paginas: ";
        cin >> vetor[cont].numero_de_paginas;

        cout << "Digite o ano de publicacao: ";
        cin >> vetor[cont].ano_de_publicacao;

        cout << "Digite o codigo de identificacao do livro: ";
        cin >> vetor[cont].id;

        cout << "Digite a quantidade disponivel: ";
        cin >> vetor[cont].quantidade;

        cout << "Digite o nome da pessoa que fez o emprestimo: ";
        cin >> vetor[cont].nome_pessoas;

        cont++;

        cout << "Livro cadastrado com sucesso!" << endl;

        cout << "Deseja cadastrar outro livro? (S || N): "; 
        cin >> resposta;

        if (resposta == 'n' || resposta == 'N') {
            break;
        }
    }

    if (cont == 100){
        cout << "O limite de livros foi atingido!";
    }
}

// FUNÇÃO PARA CONSULTAR OS LIVROS 
void consultar_livro (Livros vetor[], int cont) {
    // DEFININDO VARIÁVEIS 
    int opcao;
    int codigo_de_identificacao; 
    string titulo;
    string titulo_identificacao;
    int i;
    int id;

    // MENU INTERATIVO
    cout << "(1) Consultar todos os livros" << endl;
    cout << "(2) Consultar por codigo de identificacao" << endl;
    cout << "(3) Consultar pelo titulo" << endl;
    cout << "Qual opcao deseja: " << endl;
    cin >> opcao;

    // DEFININDO CONDIÇÕES 
    if (opcao == 1) {
        for (i = 0; i < cont; i++) {
            cout << "Titulo: " << vetor[i].titulo  << ", autor: " << vetor[i].autor << ", numero de paginas: " << vetor[i].numero_de_paginas << ", ano de publicacao: " << vetor[i].ano_de_publicacao << ", ID: " << vetor[i].id << ", quantidade: " << vetor[i].quantidade << ", nome de pessoas que emprestou: " << vetor[i].nome_pessoas << endl;
        }
    }
    if (opcao == 2) {
        cout << "Digite o codigo de identificacao: "; 
        cin << codigo_de_identificacao; 

        for (i = 0; i < cont; i++) {
            if (codigo_de_identificacao == id) {
                cout << "Titulo: " << vetor[i].titulo  << ", autor: " << vetor[i].autor << ", numero de paginas: " << vetor[i].numero_de_paginas << ", ano de publicacao: " << vetor[i].ano_de_publicacao << ", ID: " << vetor[i].id << ", quantidade: " << vetor[i].quantidade << ", nome de pessoas que emprestou: " << vetor[i].nome_pessoas << endl;
            }
        }
    }
    if (opcao == 3) {
        cout << "Digite o titulo: "; 
        cin << titulo_identificacao; 

        for (i = 0; i < cont; i++) {
            if (titulo_identificacao == titulo) {
                cout << "Titulo: " << vetor[i].titulo  << ", autor: " << vetor[i].autor << ", numero de paginas: " << vetor[i].numero_de_paginas << ", ano de publicacao: " << vetor[i].ano_de_publicacao << ", ID: " << vetor[i].id << ", quantidade: " << vetor[i].quantidade << ", nome de pessoas que emprestou: " << vetor[i].nome_pessoas << endl;
            }
        }
    }
}

// DEFININDO STRUCT 
struct Livros {
    string titulo; 
    string autor; 
    int numero_de_paginas; 
    int ano_de_publicacao; 
    int id; 
    int quantidade[10]; 
    string nome_pessoas[]; 
}; 

int main() {
    // DEFININDO VARIÁVEIS 
    Livros vetor[100];
    int escolha;
    int cont = 0;

    // DEFININDO MENU INTERATIVO
    cout << "\n Menu de opcoes: \n" << endl;
    cout << "(1) Cadastro de livros" << endl;
    cout << "(2) Consulta de livros" << endl;
    cout << "(3) Emprestimo de livros" << endl; 
    cout << "(4) Devolucao de livros" << endl;
    cout << "(5) Remocao de livros" << endl; 
    cout << "Qual opcao voce deseja: " << endl;
    cin >> escolha;

    return 0; 
}
