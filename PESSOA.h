#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

// ============================================================
// Classe Base: Pessoa
// Representa qualquer pessoa no sistema (base para Hospede).
// Aplica encapsulamento: atributos privados, mÃ©todos pÃºblicos.
// ============================================================
class Pessoa {
private:
    string nome;
    string documento; // BI / Passaporte / NIF

public:
    // Construtor padrÃ£o
    Pessoa();

    // Construtor parametrizado
    Pessoa(const string& nome, const string& documento);

    // Destrutor virtual (necessÃ¡rio para heranÃ§a polimÃ³rfica)
    virtual ~Pessoa();

    // Getters
    string getNome()      const;
    string getDocumento() const;

    // Setters
    void setNome(const string& nome);
    void setDocumento(const string& documento);

    // MÃ©todo virtual puro => torna Pessoa uma classe abstrata.
    // Cada subclasse deve fornecer sua prÃ³pria implementaÃ§Ã£o.
    virtual void exibirInfo() const = 0;
};

#endif // PESSOA_H