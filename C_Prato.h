#ifndef PRATO_H
#define PRATO_H
using namespace std;

#include <string>

class Prato {
private:
    string nome;
    string descricao;
    float preco;
    string categoria;

public:
    // Construtor
    Prato(const string& nome, const string& descricao, float preco, const string& categoria);
    // Getters
    string getNome() const;
    float getPreco() const;

    // Métodos
    void exibirDados() const;
    void atualizarPreco(float novoPreco);
};

#endif
