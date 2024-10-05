// SISTEMA DE GERENCIAMENTO DE BIBLIOTECA
// DEFININDO BIBLIOTECAS
#include <iostream>
#include <string>
using namespace std;

// DEFININDO STRUCT
struct Livros {
  // ATRIBUTOS DO STRUCT LIVROS
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
    // DEFININDO VARIÁVEIS
    int num;

    // PEDINDO INFORMAÇÕES DO LIVRO
    cout << "Digite o titulo do livro (use '_' para espacos): ";
    cin >> vetor[cont].titulo; // LÊ O TÍTULO DO LIVRO

    cout << "Digite o nome do autor (use '_' para espacos): ";
    cin >> vetor[cont].autor; // LÊ O NOME DO AUTOR

    // Validando o número de páginas
    do {
        cout << "Digite o numero de paginas: ";
        cin >> vetor[cont].numero_de_paginas; // LÊ O NÚMERO DE PÁGINAS
        if (vetor[cont].numero_de_paginas <= 0) {
            cout << "Numero de paginas invalido. Deve ser maior que zero." << endl; // MENSAEM DE ERRO
        }
    } while (vetor[cont].numero_de_paginas <= 0); // Repetir enquanto for inválido

    // Validando o ano de publicação
    do {
        cout << "Digite o ano de publicacao: ";
        cin >> vetor[cont].ano_de_publicacao; // LÊ O ANO DE PUBLICAÇÃO
        if (vetor[cont].ano_de_publicacao <= 0) {
            cout << "Ano de publicação inválido. Deve ser um número positivo." << endl; // MENSAEM DE ERRO
        }
    } while (vetor[cont].ano_de_publicacao <= 0); // Repetir enquanto for inválido

    // VERIFICANDO SE O CÓDIGO JÁ EXISTE
    bool codigo_existe = false;
    do {
        cout << "Digite o codigo de identificacao do livro: ";
        cin >> vetor[cont].id; // LÊ O CÓDIGO DE IDENTIFICAÇÃO DO LIVRO

        // VERIFICANDO SE O CÓDIGO JÁ EXISTE
        for (int i = 0; i < cont; i++) {
            if (vetor[i].id == vetor[cont].id) {
                cout << "O código de identificação ja existe! Digite um novo codigo." << endl; // MENSAEM DE ERRO
                codigo_existe = true; // CÓDIGO JÁ EXISTE
                break;
            } else {
                codigo_existe = false; // CÓDIGO NÃO EXISTE
            }
        }
    } while (codigo_existe); // repete até que um código único seja inserido

    // DEFININDO QUANTIDADE DE LIVROS DISPONÍVEIS E VALIDANDO O VALOR ENTRE 1 E 10
    do {
        cout << "Digite a quantidade disponivel (ate 10 unidades): ";
        cin >> vetor[cont].quantidade; // LÊ A QUANTIDADE DISPONÍVEL
        if (vetor[cont].quantidade > 10 || vetor[cont].quantidade < 1) {
            cout << "Quantidade invalida, digite novamente: "; // MENSAEM DE ERRO
        }
    } while (vetor[cont].quantidade > 10 || vetor[cont].quantidade < 1); // VALIDANDO QUANTIDADE

    // Inicializa o contador de pessoas
    vetor[cont].cont_pessoas = 0; // ZERA O CONTADOR DE PESSOAS QUE PEGARAM O LIVRO

    // AUMENTANDO O CONTADOR APÓS O CADASTRO
    cont++; // INCREMENTA O CONTADOR DE LIVROS CADASTRADOS
    
    cout << "Livro cadastrado com sucesso!" << endl; // MENSAGEM DE SUCESSO
}

// FUNÇÃO PARA CONSULTAR OS LIVROS
void consultar_livro(Livros vetor[], int cont) {
  // VERIFICA SE NENHUM LIVRO FOI CADASTRADO AINDA
  if (cont == 0) {
    cout << "Nenhum livro foi cadastrado ainda!" << endl; // MENSAEM SE NENHUM LIVRO ESTIVER CADASTRADO
    return; // Encerra a função caso não haja livros cadastrados
  }

  // DEFININDO VARIÁVEIS
  int opcao; // OPÇÃO DO MENU
  int codigo_de_identificacao; // CÓDIGO DE IDENTIFICAÇÃO DO LIVRO
  string titulo_identificacao; // TÍTULO DO LIVRO PARA CONSULTA

  // MENU PARA CONSULTA
  cout << "\n=========================================" << endl;
  cout << "          CONSULTA DE LIVROS             " << endl;
  cout << "=========================================" << endl;
  cout << "1. Listar todos os livros" << endl; // OPÇÃO 1: LISTAR TODOS OS LIVROS
  cout << "2. Consultar por código de identificação" << endl; // OPÇÃO 2: CONSULTAR POR CÓDIGO
  cout << "3. Consultar por título" << endl; // OPÇÃO 3: CONSULTAR POR TÍTULO
  cout << "-----------------------------------------" << endl;
  cout << "Digite a sua opção: ";
  cin >> opcao; // LÊ A OPÇÃO DO USUÁRIO

  // MOSTRA TODOS OS LIVROS CADASTRADOS
  if (opcao == 1) {
    cout << "\nLista de livros cadastrados:" << endl;
    for (int i = 0; i < cont; i++) {
      // EXIBE AS INFORMAÇÕES DE CADA LIVRO
      cout << "Título: " << vetor[i].titulo << ", Autor: " << vetor[i].autor
           << ", Número de páginas: " << vetor[i].numero_de_paginas
           << ", Ano de publicação: " << vetor[i].ano_de_publicacao
           << ", ID: " << vetor[i].id
           << ", Quantidade: " << vetor[i].quantidade;

      // VERIFICA SE O LIVRO JÁ FOI EMPRESTADO
      cout << ", Emprestimos: ";
      if (vetor[i].cont_pessoas == 0) {
        cout << "Nenhum" << endl; // SE NINGUÉM EMPRESTOU
      } else {
        for (int j = 0; j < vetor[i].cont_pessoas; j++) {
            cout << vetor[i].nomes_pessoas[j]; // EXIBE O NOME DAS PESSOAS QUE EMPRESTARAM
            if (j < vetor[i].cont_pessoas - 1) {
                cout << ", "; // SE NÃO FOR O ÚLTIMO NOME, ADICIONA A VÍRGULA
            }
        }
        cout << endl; // NOVA LINHA APÓS LISTAR NOME
      }
    }
  }
  // CONSULTA POR CÓDIGO DE IDENTIFICAÇÃO
  else if (opcao == 2) {
    bool livro_encontrado = false; // FLAG PARA LIVRO ENCONTRADO
    cout << "Digite o código de identificação: ";
    cin >> codigo_de_identificacao; // LÊ O CÓDIGO DE IDENTIFICAÇÃO
    for (int i = 0; i < cont; i++) {
      if (codigo_de_identificacao == vetor[i].id) { // VERIFICA SE O CÓDIGO ENCONTRADO
        livro_encontrado = true; // LIVRO ENCONTRADO
        // EXIBE AS INFORMAÇÕES DO LIVRO
        cout << "Título: " << vetor[i].titulo << ", Autor: " << vetor[i].autor
             << ", Número de páginas: " << vetor[i].numero_de_paginas
             << ", Ano de publicação: " << vetor[i].ano_de_publicacao
             << ", ID: " << vetor[i].id
             << ", Quantidade: " << vetor[i].quantidade;

        // VERIFICA SE O LIVRO JÁ FOI EMPRESTADO
        cout << ", Emprestimos: ";
        if (vetor[i].cont_pessoas == 0) {
          cout << "Nenhum" << endl; // SE NINGUÉM EMPRESTOU
        } else {
          for (int j = 0; j < vetor[i].cont_pessoas; j++) {
            cout << vetor[i].nomes_pessoas[j]; // EXIBE O NOME DAS PESSOAS QUE EMPRESTARAM
            if (j < vetor[i].cont_pessoas - 1) {
              cout << ", "; // SE NÃO FOR O ÚLTIMO NOME, ADICIONA A VÍRGULA
            }
          }
          cout << endl; // NOVA LINHA APÓS LISTAR NOME
        }
      }
    }
    // MENSAEM SE O LIVRO NÃO FOR ENCONTRADO
    if (!livro_encontrado) {
      cout << "Livro nao encontrado!" << endl; // MENSAGEM DE ERRO
    }
  }
  // CONSULTA POR TÍTULO
  else if (opcao == 3) {
    bool livro_encontrado = false; // FLAG PARA LIVRO ENCONTRADO
    cout << "Digite o título do livro (use '_' para espacos): ";
    cin >> titulo_identificacao; // LÊ O TÍTULO DO LIVRO
    for (int i = 0; i < cont; i++) {
      if (titulo_identificacao == vetor[i].titulo) { // VERIFICA SE O TÍTULO ENCONTRADO
        livro_encontrado = true; // LIVRO ENCONTRADO
        // EXIBE AS INFORMAÇÕES DO LIVRO
        cout << "Título: " << vetor[i].titulo << ", Autor: " << vetor[i].autor
             << ", Número de páginas: " << vetor[i].numero_de_paginas
             << ", Ano de publicação: " << vetor[i].ano_de_publicacao
             << ", ID: " << vetor[i].id
             << ", Quantidade: " << vetor[i].quantidade;

        // VERIFICA SE O LIVRO JÁ FOI EMPRESTADO
        cout << ", Emprestimos: ";
        if (vetor[i].cont_pessoas == 0) {
          cout << "Nenhum" << endl; // SE NINGUÉM EMPRESTOU
        } else {
          for (int j = 0; j < vetor[i].cont_pessoas; j++) {
            cout << vetor[i].nomes_pessoas[j]; // EXIBE O NOME DAS PESSOAS QUE EMPRESTARAM
            if (j < vetor[i].cont_pessoas - 1) {
              cout << ", "; // SE NÃO FOR O ÚLTIMO NOME, ADICIONA A VÍRGULA
            }
          }
          cout << endl; // NOVA LINHA APÓS LISTAR NOME
        }
      }
    }
    // MENSAEM SE O LIVRO NÃO FOR ENCONTRADO
    if (!livro_encontrado) {
      cout << "Livro nao encontrado!" << endl; // MENSAGEM DE ERRO
    }
  } 
  // MENSAGEM SE A OPÇÃO FOR INVÁLIDA
  else {
    cout << "Opcao invalida!" << endl; // MENSAGEM DE ERRO
  }
}

// FUNÇÃO PRINCIPAL
int main() {
  Livros vetor[100]; // CRIA UM VETOR DE 100 LIVROS
  int cont = 0; // CONTADOR DE LIVROS CADASTRADOS
  int opcao; // OPÇÃO DO MENU

  // MENU DE OPÇÕES
  do {
    cout << "\n=========================================" << endl;
    cout << "          MENU DE OPÇÕES                  " << endl;
    cout << "=========================================" << endl;
    cout << "1. Cadastro de livros" << endl; // OPÇÃO 1: CADASTRO DE LIVROS
    cout << "2. Consultar livros" << endl; // OPÇÃO 2: CONSULTAR LIVROS
    cout << "3. Sair" << endl; // OPÇÃO 3: SAIR
    cout << "-----------------------------------------" << endl;
    cout << "Digite a sua opcao: ";
    cin >> opcao; // LÊ A OPÇÃO DO USUÁRIO

    // CHAMA A FUNÇÃO DE CADASTRO
    if (opcao == 1) {
      cadastro_livros(vetor, cont); // CHAMA A FUNÇÃO DE CADASTRO
    } 
    // CHAMA A FUNÇÃO DE CONSULTA
    else if (opcao == 2) {
      consultar_livro(vetor, cont); // CHAMA A FUNÇÃO DE CONSULTA
    }
    // FINALIZA O PROGRAMA
    else if (opcao == 3) {
      cout << "Saindo do sistema..." << endl; // MENSAGEM DE SAÍDA
    }
    // MENSAGEM SE A OPÇÃO FOR INVÁLIDA
    else {
      cout << "Opcao invalida!" << endl; // MENSAGEM DE ERRO
    }
  } while (opcao != 3); // CONTINUA O MENU ATÉ QUE O USUÁRIO ESCOLHA SAIR

  return 0; // RETORNA 0 PARA O SISTEMA OPERACIONAL
}
