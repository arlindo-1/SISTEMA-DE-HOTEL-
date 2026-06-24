#include "Hospede.h"
#include <iostream>
#include <iomanip>
using namespace std;

// InicializaÃ§Ã£o do contador estÃ¡tico (IDs comeÃ§am em 1)
int Hospede::proximoId = 1;

// ---- Construtores ----

Hospede::Hospede() : Pessoa(), telefone(""), idHospede(proximoId++) {}

Hospede::Hospede(const string& nome, const string& documento, const string& telefone)
    : Pessoa(nome, documento), telefone(telefone), idHospede(proximoId++) {}

// ---- Destrutor ----

Hospede::~Hospede() {}

// ---- Getters ----

string Hospede::getTelefone()  const { return telefone; }
int    Hospede::getIdHospede() const { return idHospede; }

// ---- Setter ----

void Hospede::setTelefone(const string& t) { telefone = t; }

// ---- exibirInfo() â€” polimorfismo ----

void Hospede::exibirInfo() const {
    cout << "  [ID " << setw(3) << setfill('0') << idHospede << setfill(' ') << "] "
         << "Nome: " << left << setw(25) << getNome()
         << " | Documento: " << setw(15) << getDocumento()
         << " | Tel: " << getTelefone() << endl;
}