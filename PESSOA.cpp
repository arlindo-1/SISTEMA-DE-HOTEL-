#include <iostream>
using namespace std;
#include "Pessoa.h"

// ---- Construtores ----

Pessoa::Pessoa() : nome(""), documento("") {}

Pessoa::Pessoa(const string& nome, const string& documento)
    : nome(nome), documento(documento) {}

// ---- Destrutor ----

Pessoa::~Pessoa() {}

// ---- Getters ----

string Pessoa::getNome()      const { return nome; }
string Pessoa::getDocumento() const { return documento; }

// ---- Setters ----

void Pessoa::setNome(const string& n)      { nome = n; }
void Pessoa::setDocumento(const string& d) { documento = d; }