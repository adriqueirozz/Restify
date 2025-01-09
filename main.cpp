#include <iostream>
#include <string>
#include <
using namespace std;

int main() {
    Prato prato1("Estrogonofe", "frango ao molho, acompanhado de arroz e fritas", 23.55, "Principal");

    prato1.exibirDados();
    prato1.atualizarPreco(40.00);
    prato1.exibirDados();

    return 0;
}
