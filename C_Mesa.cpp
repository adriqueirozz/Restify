#include "C_Mesa.h"
#include "C_Pedido.h"
#include <iostream>
using namespace std;

// Construtor
Mesa::Mesa(int numero) : numero(numero), status("livre"), clientes(0) {}

// Método para ocupar a mesa com um número de clientes
void Mesa::ocuparMesa(int numClientes) {
    if (status == "livre") {
        status = "ocupada";
        clientes = numClientes;
        cout << "Mesa " << numero << " ocupada por " << clientes << " clientes.\n";
    } else {
        cout << "Mesa " << numero << " já está ocupada!\n";
    }
}

// Método para liberar a mesa
void Mesa::liberarMesa() {
    if (status == "ocupada") {
        status = "livre";
        clientes = 0;
        pedidos.clear();  // Limpa os pedidos da mesa
        cout << "Mesa " << numero << " foi liberada.\n";
    } else {
        cout << "Mesa " << numero << " já está livre!\n";
    }
}

// Método para adicionar um pedido à mesa
void Mesa::adicionarPedido(Pedido* pedido) {
    if (status == "ocupada") {
        pedidos.push_back(pedido);
        cout << "Pedido adicionado à mesa " << numero << ".\n";
    } else {
        cout << "Não é possível adicionar pedido a uma mesa livre!\n";
    }
}

// Métodos auxiliares
int Mesa::getNumero() const {
    return numero;
}

string Mesa::getStatus() const {
    return status;
}

int Mesa::getClientes() const {
    return clientes;
}
