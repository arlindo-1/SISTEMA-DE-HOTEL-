// ============================================================
// main.cpp â€” Ponto de entrada do Sistema de Reserva de Hotel
//
// Compilacao (Dev-C++ / g++ com C++11 ou superior):
//   g++ -std=c++11 -o hotel main.cpp Pessoa.cpp Hospede.cpp
//                                    Quarto.cpp Reserva.cpp Hotel.cpp
//
// Ou via Dev-C++ Project:
//   1. Crie um novo projeto e adicione todos os arquivos .cpp
//   2. VÃ¡ em Project > Project Options > Parameters
//      e acrescente: -std=c++11
// ============================================================

#include "Hotel.h"
#include <iostream>
using namespace std;

int main() {
    // Define o nome do hotel exibido no menu principal
    Hotel hotel("Grand Beira Palace");

    // Inicia o loop principal do sistema
    hotel.executar();

    return 0;
}