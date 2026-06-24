#ifndef HOTEL_H
#define HOTEL_H

#include "Hospede.h"
#include "Quarto.h"
#include "Reserva.h"
#include <vector>
#include <string>
using namespace std;

// ============================================================
// Classe: Hotel
// Controlador central do sistema. Armazena e gerencia todas
// as coleÃ§Ãµes (hÃ³spedes, quartos, reservas) e implementa
// todas as operaÃ§Ãµes de negÃ³cio.
// ============================================================
class Hotel {
private:
    string          nomeHotel;
    vector<Hospede> hospedes;   // Colecao de hospedes cadastrados
    vector<Quarto>  quartos;    // Colecao de quartos do hotel
    vector<Reserva*> reservas;  // Colecao de reservas (ponteiros)

    // ---- MÃ©todos auxiliares internos ----

    // Localiza um hÃ³spede pelo ID; retorna nullptr se nÃ£o encontrado
    Hospede* buscarHospedePorId(int id);

    // Localiza um quarto pelo nÃºmero; retorna nullptr se nÃ£o encontrado
    Quarto* buscarQuartoPorNumero(int numero);

    // Verifica se jÃ¡ existe quarto com esse nÃºmero cadastrado
    bool quartoExiste(int numero) const;

    // Exibe uma linha separadora decorativa no menu
    void exibirSeparador() const;

public:
    // Construtor
    Hotel(const string& nomeHotel);

    // Destrutor â€” libera memÃ³ria alocada para as reservas
    ~Hotel();

    // ============================================================
    // MENU PRINCIPAL
    // ============================================================
    void executar(); // Loop principal do sistema

    // ============================================================
    // OPERAÃ‡Ã•ES PRINCIPAIS
    // ============================================================
    void registrarHospede();
    void cadastrarQuarto();
    void fazerReserva();
    void realizarCheckIn();
    void realizarCheckOut();

    // ============================================================
    // CONSULTAS / LISTAGENS
    // ============================================================
    void listarHospedes()   const;
    void listarQuartos()    const;   // Lista TODOS os quartos
    void listarReservas()   const;

    // ============================================================
    // MENU DE QUARTOS (sub-menu)
    // ============================================================
    void menuListarQuartos();

private:
    void listarQuartosDisponiveis() const;
    void listarQuartosOcupados()    const;
};

#endif // HOTEL_H