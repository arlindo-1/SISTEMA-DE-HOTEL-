#include "Quarto.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ---- Construtores ----

Quarto::Quarto()
    : numero(0), tipo(TipoQuarto::SIMPLES),
      precoPorNoite(0.0), estado(EstadoQuarto::DISPONIVEL) {}

Quarto::Quarto(int numero, TipoQuarto tipo, double precoPorNoite)
    : numero(numero), tipo(tipo),
      precoPorNoite(precoPorNoite), estado(EstadoQuarto::DISPONIVEL) {}

// ---- Destrutor ----

Quarto::~Quarto() {}

// ---- Getters ----

int          Quarto::getNumero()        const { return numero; }
TipoQuarto   Quarto::getTipo()          const { return tipo; }
double       Quarto::getPrecoPorNoite() const { return precoPorNoite; }
EstadoQuarto Quarto::getEstado()        const { return estado; }

// ---- ConversÃ£o para texto ----

string Quarto::getTipoStr() const {
    switch (tipo) {
        case TipoQuarto::SIMPLES: return "Simples";
        case TipoQuarto::DUPLO:   return "Duplo";
        case TipoQuarto::LUXO:    return "Luxo";
        default:                  return "Desconhecido";
    }
}

string Quarto::getEstadoStr() const {
    switch (estado) {
        case EstadoQuarto::DISPONIVEL: return "Disponivel";
        case EstadoQuarto::RESERVADO:  return "Reservado";
        case EstadoQuarto::OCUPADO:    return "Ocupado";
        default:                       return "Desconhecido";
    }
}

// ---- Setter ----

void Quarto::setEstado(EstadoQuarto e) { estado = e; }

// ---- ExibiÃ§Ã£o ----

void Quarto::exibirInfo() const {
    cout << fixed << setprecision(2);
    cout << "  Quarto " << setw(3) << numero
         << " | Tipo: " << left << setw(8) << getTipoStr()
         << " | Preco/Noite: " << right << setw(10) << precoPorNoite << " MZN"
         << " | Estado: " << left << setw(10) << getEstadoStr() << endl;
}

// ---- VerificaÃ§Ã£o de disponibilidade ----

bool Quarto::estaDisponivel() const {
    return estado == EstadoQuarto::DISPONIVEL;
}