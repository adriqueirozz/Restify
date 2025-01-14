#include <iostream>
#include <vector>
#include "C_Prato.h"
#include "C_Mesa.h"
#include "C_Pedido.h"

using namespace std;

// Função para exibir o menu
void exibirMenu() {
    cout << "\n";
    cout << "===== Sistema de Gestão de Restaurante =====\n";
    cout << "1. Cadastrar Prato\n";
    cout << "2. Ocupar Mesa\n";
    cout << "3. Criar Pedido\n";
    cout << "4. Adicionar Prato ao Pedido\n";
    cout << "5. Exibir Pedido\n";
    cout << "6. Liberar Mesa\n";
    cout << "7. Sair\n";
    cout << "===========================================\n";
}

// Função principal
int main() {
    vector<Prato*> pratosDisponiveis;
    vector<Mesa*> mesas;
    vector<Pedido*> pedidos;

    // Criar mesas de exemplo
    for (int i = 1; i <= 5; i++) {
        mesas.push_back(new Mesa(i));
    }

    int escolha;
    do {
        exibirMenu();
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1: {
                // Cadastrar Prato
                string nome, descricao, categoria;
                float preco;
                cout << "Nome do prato: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Descrição do prato: ";
                getline(cin, descricao);
                cout << "Preço do prato: ";
                cin >> preco;
                cout << "Categoria do prato: ";
                cin.ignore();
                getline(cin, categoria);

                Prato* prato = new Prato(nome, descricao, preco, categoria);
                pratosDisponiveis.push_back(prato);
                cout << "Prato cadastrado com sucesso!\n";
                break;
            }
            case 2: {
                // Ocupar Mesa
                int numeroMesa, numClientes;
                cout << "Número da mesa para ocupar (1-5): ";
                cin >> numeroMesa;
                cout << "Número de clientes: ";
                cin >> numClientes;

                if (numeroMesa >= 1 && numeroMesa <= 5) {
                    mesas[numeroMesa - 1]->ocuparMesa(numClientes);
                } else {
                    cout << "Mesa inválida!\n";
                }
                break;
            }
            case 3: {
                // Criar Pedido
                int idPedido, numeroMesa;
                cout << "ID do pedido: ";
                cin >> idPedido;
                cout << "Número da mesa associada: ";
                cin >> numeroMesa;

                if (numeroMesa >= 1 && numeroMesa <= 5) {
                    Pedido* pedido = new Pedido(idPedido, numeroMesa);
                    pedidos.push_back(pedido);
                    cout << "Pedido criado com sucesso!\n";
                } else {
                    cout << "Mesa inválida!\n";
                }
                break;
            }
            case 4: {
                // Adicionar Prato ao Pedido
                int idPedido;
                string nomePrato;
                cout << "ID do pedido: ";
                cin >> idPedido;
                cout << "Nome do prato a adicionar: ";
                cin.ignore();
                getline(cin, nomePrato);

                // Encontrar o pedido
                Pedido* pedidoEncontrado = nullptr;
                for (auto pedido : pedidos) {
                    if (pedido->getIdPedido() == idPedido) {
                        pedidoEncontrado = pedido;
                        break;
                    }
                }

                if (pedidoEncontrado) {
                    // Encontrar o prato
                    Prato* pratoEncontrado = nullptr;
                    for (auto prato : pratosDisponiveis) {
                        if (prato->getNome() == nomePrato) {
                            pratoEncontrado = prato;
                            break;
                        }
                    }

                    if (pratoEncontrado) {
                        pedidoEncontrado->adicionarPrato(pratoEncontrado);
                        cout << "Prato adicionado ao pedido!\n";
                    } else {
                        cout << "Prato não encontrado!\n";
                    }
                } else {
                    cout << "Pedido não encontrado!\n";
                }
                break;
            }
            case 5: {
                // Exibir Pedido
                int idPedido;
                cout << "ID do pedido: ";
                cin >> idPedido;

                for (auto pedido : pedidos) {
                    if (pedido->getIdPedido() == idPedido) {
                        pedido->exibirPedido();
                        break;
                    }
                }
                break;
            }
            case 6: {
                // Liberar Mesa
                int numeroMesa;
                cout << "Número da mesa para liberar (1-5): ";
                cin >> numeroMesa;

                if (numeroMesa >= 1 && numeroMesa <= 5) {
                    mesas[numeroMesa - 1]->liberarMesa();
                } else {
                    cout << "Mesa inválida!\n";
                }
                break;
            }
            case 7:
                cout << "Saindo do sistema...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
        }

    } while (escolha != 7);

    // Liberar memória
    for (auto prato : pratosDisponiveis) {
        delete prato;
    }
    for (auto mesa : mesas) {
        delete mesa;
    }
    for (auto pedido : pedidos) {
        delete pedido;
    }

    return 0;
}
