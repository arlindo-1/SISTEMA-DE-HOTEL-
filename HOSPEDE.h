#ifndef HOSPEDE_H
#define HOSPEDE_H

#include "Pessoa.h"
#include <string>
using namespace std;

// ============================================================
// Classe Derivada: Hospede (herda de Pessoa)
// Adiciona o telefone e um ID Ãºnico de hÃ³spede.
// Demonstra heranÃ§a e polimorfismo via exibirInfo().
// ============================================================
class Hospede : public Pessoa {
private:
    string telefone;
    int    idHospede;         // Identificador Ãºnico no sistema

    static int proximoId;     // Contador estÃ¡tico para gerar IDs Ãºnicos

public:
    // Construtor padrÃ£o
    Hospede();

    // Construtor parametrizado
    Hospede(const string& nome, const string& documento, const string& telefone);

    // Destrutor
    ~Hospede();

    // Getters
    string getTelefone()  const;
    int    getIdHospede() const;

    // Setter
    void setTelefone(const string& telefone);

    // Sobrescrita do mÃ©todo virtual puro de Pessoa (polimorfismo)
    void exibirInfo() const override;
};

#endif // HOSPEDE_H