#ifndef MESA_H
#define MESA_H

#include <string>
#include <vector>
using namespace std;

// Forward declaration da classe Pedido (para evitar dependência circular)
class Pedido;

class Mesa {
private:
    int numero;
    string status;   // "livre" ou "ocupada"
    int clientes;         // Número de clientes na mesa
    vector<Pedido*> pedidos;  // Lista de pedidos associados à mesa

public:
    // Construtor
    Mesa(int numero);

    // Métodos
    void ocuparMesa(int numClientes);
    void liberarMesa();
    void adicionarPedido(Pedido* pedido);

    // Métodos auxiliares
    int getNumero() const;
    string getStatus() const;
    int getClientes() const;
};

#endif
