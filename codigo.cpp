// SISTEMA DE GERENCIAMENTO DE BIBLIOTECA 
// DEFININDO BIBLIOTECAS 
# include <iostream> 
# include <string> 

// DEFININDO STRUCT 
struct Livros {
    std::string titulo; 
    std::string autor; 
    int numero_de_paginas; 
    int ano_de_publicacao; 
    int id; 
    int quantidade; 
    std::string nome_pessoas; 
}; 

// FUNÇÃO PARA CADASTRAR LIVRO
void cadastro_livros(Livros vetor[], int &cont) { // devo passar cont por referencia porque sempre estou atualizando o valor dele
    // DEFININDO VARIÁVEIS
    int i;
    char resposta; 

    // DEFININDO CONDIÇÕES
    while (cont < 100) {
        // PEDINDO INFORMAÇÕES 
        std::cout << "Digite o titulo do livro: ";
        std::cin >> vetor[cont].titulo; 

        std::cout << "Digite o nome do autor: ";
        std::cin >> vetor[cont].autor;

        std::cout << "Digite o numero de paginas: ";
        std::cin >> vetor[cont].numero_de_paginas;

        std::cout << "Digite o ano de publicacao: ";
        std::cin >> vetor[cont].ano_de_publicacao;

        std::cout << "Digite o codigo de identificacao do livro: ";
        std::cin >> vetor[cont].id;

        std::cout << "Digite a quantidade disponivel: ";
        std::cin >> vetor[cont].quantidade;

        std::cout << "Digite o nome da pessoa que fez o emprestimo: ";
        std::cin >> vetor[cont].nome_pessoas;

        cont++;

        std::cout << "Livro cadastrado com sucesso!" << std::endl;

        std::cout << "Deseja cadastrar outro livro? (S || N): "; 
        std::cin >> resposta;

        if (resposta == 'n' || resposta == 'N') {
            break;
        }
    }

    if (cont == 100){
        std::cout << "O limite de livros foi atingido!";
    }
}

// FUNÇÃO PARA CONSULTAR OS LIVROS 
void consultar_livro (Livros vetor[], int cont) { // devo passar cont como parametro porque preciso que as funções trabalhem com o valor mais recente de cont
    // DEFININDO VARIÁVEIS 
    int opcao;
    int codigo_de_identificacao; 
    std::string titulo_identificacao;
    int i;

    // MENU INTERATIVO
    std::cout << "(1) Consultar todos os livros" << std::endl;
    std::cout << "(2) Consultar por codigo de identificacao" << std::endl;
    std::cout << "(3) Consultar pelo titulo" << std::endl;
    std::cout << "(4) Remover cadastro de um livro" << std::endl;
    std::cout << "Qual opcao deseja: " << std::endl;
    std::cin >> opcao;

    // DEFININDO CONDIÇÕES 
    if (opcao == 1) {
        for (i = 0; i < cont; i++) {
            std::cout << "Titulo: " << vetor[i].titulo  << ", autor: " << vetor[i].autor << ", numero de paginas: " << vetor[i].numero_de_paginas << ", ano de publicacao: " << vetor[i].ano_de_publicacao << ", ID: " << vetor[i].id << ", quantidade: " << vetor[i].quantidade << ", nome de pessoas que emprestou: " << vetor[i].nome_pessoas << std::endl;
        }
    }
    if (opcao == 2) {
        std::cout << "Digite o codigo de identificacao: "; 
        std::cin >> codigo_de_identificacao; 

        for (i = 0; i < cont; i++) {
            if (codigo_de_identificacao == vetor[i].id) {
                std::cout << "Titulo: " << vetor[i].titulo  << ", autor: " << vetor[i].autor << ", numero de paginas: " << vetor[i].numero_de_paginas << ", ano de publicacao: " << vetor[i].ano_de_publicacao << ", ID: " << vetor[i].id << ", quantidade: " << vetor[i].quantidade << ", nome de pessoas que emprestou: " << vetor[i].nome_pessoas << std::endl;
            }
        }
    }
    if (opcao == 3) {
        std::cout << "Digite o titulo: "; 
        std::cin >> titulo_identificacao; 

        for (i = 0; i < cont; i++) {
            if (titulo_identificacao == vetor[i].titulo) {
                std::cout << "Titulo: " << vetor[i].titulo  << ", autor: " << vetor[i].autor << ", numero de paginas: " << vetor[i].numero_de_paginas << ", ano de publicacao: " << vetor[i].ano_de_publicacao << ", ID: " << vetor[i].id << ", quantidade: " << vetor[i].quantidade << ", nome de pessoas que emprestou: " << vetor[i].nome_pessoas << std::endl;
            }
        }
    }
}

// FUNÇÃO PARA EMPRÉSTIMO 
void emprestimo_livro (Livros vetor[], int cont) {
    // DEFININDO VARIÁVEIS 
    int codigo_de_identificacao;
    int i;

    // PEDINDO INFORMAÇÕES 
    std::cout << "Digite o codigo de identificacao do livro para empretimo: ";
    std::cin >> codigo_de_identificacao;

    // DEFININDO CONDIÇÕES
    for (i = 0; i < cont; i++) {
        if (codigo_de_identificacao == vetor[i].id) {
            if (vetor[i].quantidade > 0) {
                std::cout << "Digite o nome da pessoa que está fazendo o emprestimo: ";
                std::cin >> vetor[i].nome_pessoas; 
                vetor[i].quantidade--; // tirando um livro de quantidade 

                std::cout << "Emprestimo realizado com sucesso!" << std::endl;
                std::cout << "Quantidade restante: " << vetor[i].quantidade << std::endl;
            }
        }
        else {
           std::cout << "O livro ja foi emprestado!" << std::endl; 
        }
    }
    std::cout << "Livro nao encontrado!" << std::endl;
}

// FUNÇÃO PARA REALIZAR DEVOLUÇÃO 
void devolucao_livro (Livros vetor[], int cont) {
    // DEFININDO VARIÁVEIS 
    int codigo_de_identificacao;
    int i;

    // PEDINDO INFORMAÇÕES 
    std::cout << "Digite o codigo de identificacao do livro para devolucao: "; 
    std::cin >> codigo_de_identificacao;

    // DEFININDO CONDIÇÕES 
    for (i = 0; i < cont; i++) {
        if (codigo_de_identificacao == vetor[i].id) {
            std::cout << "Devolucao realizada com sucesso!" << std::endl;
            std::cout << "Quantidade atual: " << vetor[i].quantidade << std::endl;
        }
    }
    std::cout << "Livro nao encontrado!";
}

// FUNÇÃO PARA REMOLVER LIVRO 
void remover_livro (Livros vetor[], int cont) {
    // DEFININDO VARIÁVEIS
    int codigo_de_identificacao;
    int livro = false;
    int i;

    // PEDINDO INFORMAÇÕES
    std::cout << "Digite o codigo de identificacao do livro que deseja remolver: ";
    std::cin >> codigo_de_identificacao;
}

int main() {
    // DEFININDO VARIÁVEIS 
    Livros vetor[100];
    int escolha;
    int cont = 0;

    do {
        // DEFININDO MENU INTERATIVO
        std::cout << "\n Menu de opcoes: \n" << std::endl;
        std::cout << "(1) Cadastro de livros \n" << std::endl;
        std::cout << "(2) Consulta de livros \n" << std::endl;
        std::cout << "(3) Emprestimo de livros \n" << std::endl; 
        std::cout << "(4) Devolucao de livros \n" << std::endl;
        std::cout << "(5) Remocao de livros \n" << std::endl; 
        std::cout << "(6) Sair \n" << std::endl;
        std::cout << "Qual opcao voce deseja: " << std::endl;
        std::cin >> escolha;

        // DEFININDO CONDIÇÕES 
        switch (escolha) {
            case 1: 
            cadastro_livros(vetor, cont);
            break;

            case 2: 
            consultar_livro(vetor, cont);
            break;

            case 6: 
            std::cout << "Saindo do programa...";

            default: 
            std::cout << "Essa opcao nao existe!";
        }
    } while (escolha != 6);

    return 0; 
}
