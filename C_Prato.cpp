#include "Prato.h"
#include <iostream>
using namespace std;

// Construtor
Prato::Prato(const string& nome, const string& descricao, float preco, const string& categoria)
    : nome(nome), descricao(descricao), preco(preco), categoria(categoria) {}

// Método para exibir os dados do prato
void Prato::exibirDados() const {
    cout << "Nome do Prato: " << nome << endl;
    cout << "Descrição: " << descricao << endl;
    cout << "Preço: " << preco << endl;
    cout << "Categoria: " << categoria << endl << endl;
}

// Método para atualizar o preço do prato
void Prato::atualizarPreco(float novoPreco) {
    if (novoPreco > 0) {
        preco = novoPreco;
        cout << "Preço de " << nome << " atualizado para: " << preco << endl << endl;
    } else {
        cout << "O preço não pode ser negativo, tente novamente!" << endl;
    }
}
