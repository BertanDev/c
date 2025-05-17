# 📦 Sistema de Vendas em C

Este é um sistema simples de controle de vendas, desenvolvido em linguagem C, com foco em cadastro e gerenciamento de produtos, clientes e vendas via terminal. Ideal como projeto de aprendizado sobre structs, arrays, modularização e lógica de programação procedural.

---

## ✅ Funcionalidades Implementadas

- **Cadastro de Produtos e Clientes**
- **Listagem de Produtos, Clientes e Vendas**
- **Realização de Vendas com múltiplos produtos**
- **Exclusão de Produtos e Clientes**
- **Validações de Limite e de Registros Vazios**

---

## 🚧 Funcionalidades em Desenvolvimento

- [ ] Modularização completa (separação por entidades)
- [ ] Atualização de dados de produtos e clientes
- [ ] Validação de exclusão para evitar remoção de clientes ou produtos com vendas registradas
- [ ] Inativação de clientes e produtos (tornar inutilizável sem perder registros de vendas)

---

## 📁 Estrutura do Projeto

📦 sistema-vendas-c
├── main.c # Função principal e menu
├── actions.c # Funções de negócio (cadastro, venda, listagem etc.)
├── utils.c # Funções auxiliares e utilitárias
└── structs.c # Definições das structs Product, Client, Sale
