# SISTEMA DE GERENCIAMENTO DE BIBLIOTECA 

Este projeto é um sistema de gerenciamento de biblioteca implementado em C++, que permite cadastrar, consultar, emprestar, devolver e remover livros. O programa funciona através de um menu interativo, onde o usuário pode selecionar diferentes opções para gerenciar o acervo de livros.

## Funcionalidades

O sistema possui as seguintes funcionalidades:

1. **Cadastrar Livro**: Permite o cadastro de um novo livro, fornecendo informações como:
   - Título
   - Autor
   - Número de páginas
   - Ano de publicação
   - Código de identificação (único)
   - Quantidade de exemplares disponíveis (até 10)

2. **Consultar Livro**: Permite consultar os livros cadastrados de três maneiras:
   - Listar todos os livros.
   - Consultar por código de identificação.
   - Consultar por título.

3. **Emprestar Livro**: Registra o empréstimo de um livro, associando o nome da pessoa que o pegou emprestado. Só é possível emprestar um livro se houver exemplares disponíveis.

4. **Devolver Livro**: Permite devolver um livro, removendo o nome da pessoa que realizou o empréstimo e aumentando o número de exemplares disponíveis.

5. **Remover Livro**: Remove um livro do sistema com base no seu código de identificação.
