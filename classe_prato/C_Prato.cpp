#include "C_Prato.h"
using namespace std;

// Construtor
Prato::Prato(const string& nome, const string& descricao, float preco, const string& categoria)
    : nome(nome), descricao(descricao), preco(preco), categoria(categoria) {}

// Getters
string Prato::getNome() const {
    return nome;
}

float Prato::getPreco() const {
    return preco;
}

// Método para exibir informações do prato
void Prato::exibirInformacoes() const {
        cout << "Nome do Prato: " << nome << "\n"
             << "Descrição: " << descricao << "\n"
             << "Preço: R$ " << preco << "\n"
             << "Categoria: " << categoria << "\n";
}
