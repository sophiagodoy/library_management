// SISTEMA DE GERENCIAMENTO DE BIBLIOTECA
// DEFININDO BIBLIOTECAS
#include <iostream>
#include <string>
using namespace std;

// DEFININDO STRUCT
struct Livros {
    string titulo;                // TITULO DO LIVRO
    string autor;                 // AUTOR DO LIVRO
    int numero_de_paginas;        // NÚMERO DE PÁGINAS DO LIVRO
    int ano_de_publicacao;        // ANO DE PUBLICAÇÃO DO LIVRO
    int id;                       // CÓDIGO DE IDENTIFICAÇÃO DO LIVRO
    int quantidade;               // QUANTIDADE DE EXEMPLARES DISPONÍVEIS
    string nomes_pessoas[10];     // ARRAY PARA ATÉ 10 PESSOAS QUE PODEM PEGAR O LIVRO EMPRESTADO
    int cont_pessoas;             // CONTADOR PARA RASTREAR O NÚMERO DE PESSOAS QUE PEGARAM O LIVRO EMPRESTADO
};

// FUNÇÃO PARA CADASTRO DE LIVROS
void cadastro_livros(Livros vetor[], int &cont) {
    // PEDINDO INFORMAÇÕES DO LIVRO
    cout << "Digite o titulo do livro (use '_' para espacos): ";
    cin >> vetor[cont].titulo; // LÊ O TÍTULO DO LIVRO

    cout << "Digite o nome do autor (use '_' para espacos): ";
    cin >> vetor[cont].autor; // LÊ O NOME DO AUTOR

    // VALIDANDO O NÚMERO DE PÁGINAS
    do {
        cout << "Digite o numero de paginas: ";
        cin >> vetor[cont].numero_de_paginas; // LÊ O NÚMERO DE PÁGINAS
        if (vetor[cont].numero_de_paginas <= 0) {
            cout << "Numero de paginas invalido. Deve ser maior que zero." << endl; // VALIDA O NÚMERO DE PÁGINAS
        }
    } while (vetor[cont].numero_de_paginas <= 0);

    // VALIDANDO O ANO DE PUBLICAÇÃO
    do {
        cout << "Digite o ano de publicacao: ";
        cin >> vetor[cont].ano_de_publicacao; // LÊ O ANO DE PUBLICAÇÃO
        if (vetor[cont].ano_de_publicacao <= 0) {
            cout << "Ano de publicação inválido. Deve ser um número positivo." << endl; // VALIDA O ANO
        }
    } while (vetor[cont].ano_de_publicacao <= 0);

    // VERIFICANDO SE O CÓDIGO DE IDENTIFICAÇÃO JÁ EXISTE
    bool codigo_existe = false;
    do {
        cout << "Digite o codigo de identificacao do livro: ";
        cin >> vetor[cont].id; // LÊ O CÓDIGO DE IDENTIFICAÇÃO

        // VERIFICANDO SE O CÓDIGO JÁ EXISTE
        for (int i = 0; i < cont; i++) {
            if (vetor[i].id == vetor[cont].id) {
                cout << "O código de identificação ja existe! Digite um novo codigo." << endl; // AVISA SE O CÓDIGO JÁ EXISTE
                codigo_existe = true; // MARCA QUE O CÓDIGO EXISTE
                break;
            } else {
                codigo_existe = false; // MARCA QUE O CÓDIGO NÃO EXISTE
            }
        }
    } while (codigo_existe); // REPETE ATÉ QUE UM CÓDIGO ÚNICO SEJA INSERIDO

    // DEFININDO QUANTIDADE DE LIVROS DISPONÍVEIS
    do {
        cout << "Digite a quantidade disponivel (ate 10 unidades): ";
        cin >> vetor[cont].quantidade; // LÊ A QUANTIDADE DISPONÍVEL
        if (vetor[cont].quantidade > 10 || vetor[cont].quantidade < 1) {
            cout << "Quantidade invalida, digite novamente." << endl; // VALIDA A QUANTIDADE
        }
    } while (vetor[cont].quantidade > 10 || vetor[cont].quantidade < 1);

    vetor[cont].cont_pessoas = 0; // ZERA O CONTADOR DE PESSOAS
    cont++; // INCREMENTA O CONTADOR DE LIVROS CADASTRADOS
    
    cout << "Livro cadastrado com sucesso!" << endl; // MENSAGEM DE SUCESSO
}

// FUNÇÃO PARA CONSULTAR OS LIVROS
void consultar_livro(Livros vetor[], int cont) {
    if (cont == 0) {
        cout << "Nenhum livro foi cadastrado ainda!" << endl; // AVISA SE NÃO HÁ LIVROS CADASTRADOS
        return;
    }

    int opcao;
    int codigo_de_identificacao;
    string titulo_identificacao;

    cout << "\n=========================================" << endl;
    cout << "          CONSULTA DE LIVROS             " << endl;
    cout << "=========================================" << endl;
    cout << "1. Listar todos os livros" << endl; // OPÇÃO PARA LISTAR TODOS OS LIVROS
    cout << "2. Consultar por codigo de identificacao" << endl; // OPÇÃO PARA CONSULTAR POR CÓDIGO
    cout << "3. Consultar por titulo" << endl; // OPÇÃO PARA CONSULTAR POR TÍTULO
    cout << "-----------------------------------------" << endl;
    cout << "Digite uma opcao: ";
    cin >> opcao; // LÊ A OPÇÃO DO USUÁRIO

    if (opcao == 1) {
        cout << "\nLista de livros cadastrados:" << endl;
        for (int i = 0; i < cont; i++) { // LISTA TODOS OS LIVROS CADASTRADOS
            cout << "Titulo: " << vetor[i].titulo << ", Autor: " << vetor[i].autor
                 << ", Número de paginas: " << vetor[i].numero_de_paginas
                 << ", Ano de publicacao: " << vetor[i].ano_de_publicacao
                 << ", ID: " << vetor[i].id
                 << ", Quantidade: " << vetor[i].quantidade;

            cout << ", Emprestimos: ";
            if (vetor[i].cont_pessoas == 0) {
                cout << "Nenhum" << endl; // AVISA SE NINGUÉM EMPRESTOU O LIVRO
            } else {
                for (int j = 0; j < vetor[i].cont_pessoas; j++) {
                    cout << vetor[i].nomes_pessoas[j]; // LISTA NOME DAS PESSOAS QUE EMPRESTARAM
                    if (j < vetor[i].cont_pessoas - 1) {
                        cout << ", "; // FORMATA A LISTA
                    }
                }
                cout << endl;
            }
        }
    } else if (opcao == 2) {
        bool livro_encontrado = false; // INICIA COMO FALSO
        cout << "Digite o codigo de identificacao: ";
        cin >> codigo_de_identificacao; // LÊ O CÓDIGO DE IDENTIFICAÇÃO
        for (int i = 0; i < cont; i++) {
            if (codigo_de_identificacao == vetor[i].id) {
                livro_encontrado = true; // MARCA QUE O LIVRO FOI ENCONTRADO
                cout << "Titulo: " << vetor[i].titulo << ", Autor: " << vetor[i].autor
                     << ", Numero de paginas: " << vetor[i].numero_de_paginas
                     << ", Ano de publicação: " << vetor[i].ano_de_publicacao
                     << ", ID: " << vetor[i].id
                     << ", Quantidade: " << vetor[i].quantidade;
                cout << ", Emprestimos: ";
                if (vetor[i].cont_pessoas == 0) {
                    cout << "Nenhum" << endl; // AVISA SE NINGUÉM EMPRESTOU O LIVRO
                } else {
                    for (int j = 0; j < vetor[i].cont_pessoas; j++) {
                        cout << vetor[i].nomes_pessoas[j]; // LISTA NOME DAS PESSOAS QUE EMPRESTARAM
                        if (j < vetor[i].cont_pessoas - 1) {
                            cout << ", "; // FORMATA A LISTA
                        }
                    }
                    cout << endl;
                }
            }
        }
        if (!livro_encontrado) {
            cout << "Livro nao encontrado!" << endl; // AVISA SE O LIVRO NÃO FOI ENCONTRADO
        }
    } else if (opcao == 3) {
        bool livro_encontrado = false; // INICIA COMO FALSO
        cout << "Digite o titulo do livro (use '_' para espacos): ";
        cin >> titulo_identificacao; // LÊ O TÍTULO DO LIVRO
        for (int i = 0; i < cont; i++) {
            if (titulo_identificacao == vetor[i].titulo) {
                livro_encontrado = true; // MARCA QUE O LIVRO FOI ENCONTRADO
                cout << "Titulo: " << vetor[i].titulo << ", Autor: " << vetor[i].autor
                     << ", Numero de paginas: " << vetor[i].numero_de_paginas
                     << ", Ano de publicacao: " << vetor[i].ano_de_publicacao
                     << ", ID: " << vetor[i].id
                     << ", Quantidade: " << vetor[i].quantidade;

                cout << ", Emprestimos: ";
                if (vetor[i].cont_pessoas == 0) {
                    cout << "Nenhum" << endl; // AVISA SE NINGUÉM EMPRESTOU O LIVRO
                } else {
                    for (int j = 0; j < vetor[i].cont_pessoas; j++) {
                        cout << vetor[i].nomes_pessoas[j]; // LISTA NOME DAS PESSOAS QUE EMPRESTARAM
                        if (j < vetor[i].cont_pessoas - 1) {
                            cout << ", "; // FORMATA A LISTA
                        }
                    }
                    cout << endl;
                }
            }
        }
        if (!livro_encontrado) {
            cout << "Livro nao encontrado!" << endl; // AVISA SE O LIVRO NÃO FOI ENCONTRADO
        }
    } else {
        cout << "Opcao invalida!" << endl; // AVISA SE A OPÇÃO É INVÁLIDA
    }
}

// FUNÇÃO PARA EMPRÉSTIMO DE LIVROS
void emprestar_livro(Livros vetor[], int cont) {
    if (cont == 0) {
        cout << "Nenhum livro cadastrado!" << endl; // AVISA SE NÃO HÁ LIVROS CADASTRADOS
        return;
    }

    int codigo_de_identificacao; // CÓDIGO DO LIVRO A SER EMPRESTADO
    string nome; // NOME DA PESSOA QUE EMPRESTOU
    bool livro_encontrado = false; // INICIA COMO FALSO

    cout << "Digite o codigo de identificacao do livro que deseja emprestar: ";
    cin >> codigo_de_identificacao; // LÊ O CÓDIGO DO LIVRO A SER EMPRESTADO

    // BUSCA O LIVRO NO VETOR
    for (int i = 0; i < cont; i++) {
        if (codigo_de_identificacao == vetor[i].id) {
            livro_encontrado = true; // MARCA QUE O LIVRO FOI ENCONTRADO
            if (vetor[i].quantidade > 0) { // VERIFICA SE HÁ EXEMPLARES DISPONÍVEIS
                cout << "Digite o nome da pessoa que vai pegar emprestado (use '_' para espacos): ";
                cin >> nome; // LÊ O NOME DA PESSOA

                // ADICIONA O NOME À LISTA DE PESSOAS QUE EMPRESTARAM O LIVRO
                vetor[i].nomes_pessoas[vetor[i].cont_pessoas] = nome;
                vetor[i].cont_pessoas++;
                vetor[i].quantidade--; // DECREMENTA A QUANTIDADE DISPONÍVEL

                cout << "Livro emprestado com sucesso!" << endl; // MENSAGEM DE SUCESSO
            } else {
                cout << "Livro indisponivel para emprestimo!" << endl; // AVISA QUE O LIVRO NÃO ESTÁ DISPONÍVEL
            }
            break; // SAÍDA DO LOOP APÓS ENCONTRAR O LIVRO
        }
    }

    if (!livro_encontrado) {
        cout << "Livro nao encontrado!" << endl; // AVISA SE O LIVRO NÃO FOI ENCONTRADO
    }
}

// FUNÇÃO PARA DEVOLUÇÃO DE LIVROS
void devolver_livro(Livros vetor[], int cont) {
    if (cont == 0) {
        cout << "Nenhum livro cadastrado!" << endl; // AVISA SE NÃO HÁ LIVROS CADASTRADOS
        return;
    }

    int codigo_de_identificacao; // CÓDIGO DO LIVRO A SER DEVOLVIDO
    string nome; // NOME DA PESSOA QUE DEVOLVE
    bool livro_encontrado = false; // INICIA COMO FALSO

    cout << "Digite o codigo de identificação do livro que deseja devolver: ";
    cin >> codigo_de_identificacao; // LÊ O CÓDIGO DO LIVRO A SER DEVOLVIDO

    // BUSCA O LIVRO NO VETOR
    for (int i = 0; i < cont; i++) {
        if (codigo_de_identificacao == vetor[i].id) {
            livro_encontrado = true; // MARCA QUE O LIVRO FOI ENCONTRADO
            cout << "Digite o nome da pessoa que está realizando a devolucao (use '_' para espacos): ";
            cin >> nome; // LÊ O NOME DA PESSOA

            // BUSCA O NOME NA LISTA DE PESSOAS QUE EMPRESTARAM
            for (int j = 0; j < vetor[i].cont_pessoas; j++) {
                if (vetor[i].nomes_pessoas[j] == nome) {
                    // REMOVE O NOME DA LISTA
                    for (int k = j; k < vetor[i].cont_pessoas - 1; k++) {
                        vetor[i].nomes_pessoas[k] = vetor[i].nomes_pessoas[k + 1]; // DESLOCA NOME PARA A ESQUERDA
                    }
                    vetor[i].cont_pessoas--; // DECREMENTA O CONTADOR DE PESSOAS
                    vetor[i].quantidade++; // INCREMENTA A QUANTIDADE DISPONÍVEL

                    cout << "Livro devolvido com sucesso!" << endl; // MENSAGEM DE SUCESSO
                    return;
                }
            }
            cout << "Nome nao encontrado na lista de emprestimos!" << endl; // AVISA SE O NOME NÃO ESTÁ NA LISTA
            return;
        }
    }

    if (!livro_encontrado) {
        cout << "Livro nao encontrado!" << endl; // AVISA SE O LIVRO NÃO FOI ENCONTRADO
    }
}

// FUNÇÃO PARA REMOÇÃO DE LIVROS
void remover_livro(Livros vetor[], int &cont) {
    if (cont == 0) {
        cout << "Nenhum livro cadastrado!" << endl; // AVISA SE NÃO HÁ LIVROS CADASTRADOS
        return;
    }

    int codigo_de_identificacao; // CÓDIGO DO LIVRO A SER REMOVIDO
    bool livro_encontrado = false; // INICIA COMO FALSO

    cout << "Digite o codigo de identificacao do livro que deseja remover: ";
    cin >> codigo_de_identificacao; // LÊ O CÓDIGO DO LIVRO A SER REMOVIDO

    // BUSCA O LIVRO NO VETOR
    for (int i = 0; i < cont; i++) {
        if (codigo_de_identificacao == vetor[i].id) {
            livro_encontrado = true; // MARCA QUE O LIVRO FOI ENCONTRADO
            // DESLOCA OS LIVROS PARA A ESQUERDA
            for (int j = i; j < cont - 1; j++) {
                vetor[j] = vetor[j + 1];
            }
            cont--; // DECREMENTA O CONTADOR DE LIVROS
            cout << "Livro removido com sucesso!" << endl; // MENSAGEM DE SUCESSO
            return;
        }
    }

    if (!livro_encontrado) {
        cout << "Livro nao encontrado!" << endl; // AVISA SE O LIVRO NÃO FOI ENCONTRADO
    }
}

// FUNÇÃO PRINCIPAL
int main() {
    Livros vetor[100]; // ARRAY DE LIVROS
    int cont = 0;      // CONTADOR DE LIVROS
    int opcao;        // VARIÁVEL PARA ARMAZENAR A OPÇÃO DO MENU

    // LOOP PARA O MENU
    do {
        cout << "\n=========================================" << endl;
        cout << "         MENU DE GERENCIAMENTO          " << endl;
        cout << "=========================================" << endl;
        cout << "1. Cadastrar Livro" << endl; // OPÇÃO PARA CADASTRAR LIVRO
        cout << "2. Consultar Livro" << endl; // OPÇÃO PARA CONSULTAR LIVRO
        cout << "3. Emprestar Livro" << endl; // OPÇÃO PARA EMPRESTAR LIVRO
        cout << "4. Devolver Livro" << endl; // OPÇÃO PARA DEVOLVER LIVRO
        cout << "5. Remover Livro" << endl; // OPÇÃO PARA REMOVER LIVRO
        cout << "6. Sair" << endl; // OPÇÃO PARA SAIR
        cout << "-----------------------------------------" << endl;
        cout << "Digite uma opcao: ";
        cin >> opcao; // LÊ A OPÇÃO DO USUÁRIO

        // EXECUTA A OPÇÃO ESCOLHIDA
        switch (opcao) {
            case 1:
                cadastro_livros(vetor, cont); // CHAMA A FUNÇÃO DE CADASTRO
                break;
            case 2:
                consultar_livro(vetor, cont); // CHAMA A FUNÇÃO DE CONSULTA
                break;
            case 3:
                emprestar_livro(vetor, cont); // CHAMA A FUNÇÃO DE EMPRÉSTIMO
                break;
            case 4:
                devolver_livro(vetor, cont); // CHAMA A FUNÇÃO DE DEVOLUÇÃO
                break;
            case 5:
                remover_livro(vetor, cont); // CHAMA A FUNÇÃO DE REMOÇÃO
                break;
            case 6:
                cout << "Saindo do sistema..." << endl; // MENSAGEM DE SAÍDA
                break;
            default:
                cout << "Opcao invalida!" << endl; // AVISA SE A OPÇÃO É INVÁLIDA
                break;
        }
    } while (opcao != 6); // CONTINUA O LOOP ATÉ QUE O USUÁRIO ESCOLHA SAIR

    return 0; // FINALIZA O PROGRAMA
}
