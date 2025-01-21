#include "C_Pedido.h"
#include "C_Prato.h"
#include <iostream>
using namespace std;

// Construtor
Pedido::Pedido(int idPedido, int mesaAssociada) : idPedido(idPedido), mesaAssociada(mesaAssociada), totalAPagar(0.0) {}

// Método para calcular o total a pagar
void Pedido::calcularTotal() {
    totalAPagar = 0.0;
    for (const auto& prato : listaDePratos) {
        // Aqui assumimos que a classe Prato possui um método getPreco()
        totalAPagar += prato->getPreco();
    }
}

// Método para adicionar um prato ao pedido
void Pedido::adicionarPrato(Prato* prato) {
    listaDePratos.push_back(prato);
    calcularTotal();
    cout << "Prato " << prato->getNome() << " adicionado ao pedido " << idPedido << ".\n";
}

// Método para remover um prato pelo nome
void Pedido::removerPrato(const string& nomePrato) {
    for (auto it = listaDePratos.begin(); it != listaDePratos.end(); ++it) {
        if ((*it)->getNome() == nomePrato) {
            listaDePratos.erase(it);
            calcularTotal();
            cout << "Prato " << nomePrato << " removido do pedido " << idPedido << ".\n";
            return;
        }
    }
    cout << "Prato " << nomePrato << " não encontrado no pedido " << idPedido << ".\n";
}

// Métodos auxiliares
int Pedido::getIdPedido() const {
    return idPedido;
}

int Pedido::getMesaAssociada() const {
    return mesaAssociada;
}

double Pedido::getTotalAPagar() const {
    return totalAPagar;
}

// Método para exibir detalhes do pedido
void Pedido::exibirPedido() const {
    cout << "Pedido ID: " << idPedido << "\nMesa: " << mesaAssociada << "\nTotal a Pagar: R$ " << totalAPagar << "\n";
    cout << "Itens:\n";
    for (const auto& prato : listaDePratos) {
        prato->exibirInformacoes();
    }
}
