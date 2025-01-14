#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>
#include <string>
using namespace std;

// Forward declaration da classe Prato (para evitar dependência circular)
class Prato;

class Pedido {
private:
    int idPedido;
    int mesaAssociada;
    vector<Prato*> listaDePratos;
    double totalAPagar;

public:
    // Construtor
    Pedido(int idPedido, int mesaAssociada);

    // Métodos
    void calcularTotal();
    void adicionarPrato(Prato* prato);
    void removerPrato(const std::string& nomePrato);

    // Métodos auxiliares
    int getIdPedido() const;
    int getMesaAssociada() const;
    double getTotalAPagar() const;
    void exibirPedido() const;
};

#endif
