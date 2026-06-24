#include "Reserva.h"
#include <iostream>
#include <iomanip>
using namespace std;

// InicializaÃ§Ã£o do contador estÃ¡tico
int Reserva::proximoId = 1;

// ---- Construtor ----

Reserva::Reserva(Hospede* hospede, Quarto* quarto, int numNoites)
    : hospede(hospede), quarto(quarto),
      numNoites(numNoites), status(StatusReserva::ATIVA)
{
    idReserva  = proximoId++;
    // CÃ¡lculo automÃ¡tico do valor total no momento da reserva
    valorTotal = quarto->getPrecoPorNoite() * numNoites;
}

// ---- Destrutor ----

Reserva::~Reserva() {}

// ---- Getters ----

int           Reserva::getIdReserva()  const { return idReserva; }
Hospede*      Reserva::getHospede()    const { return hospede; }
Quarto*       Reserva::getQuarto()     const { return quarto; }
int           Reserva::getNumNoites()  const { return numNoites; }
double        Reserva::getValorTotal() const { return valorTotal; }
StatusReserva Reserva::getStatus()     const { return status; }

string Reserva::getStatusStr() const {
    switch (status) {
        case StatusReserva::ATIVA:         return "Ativa";
        case StatusReserva::CHECKIN_FEITO: return "Em Estadia";
        case StatusReserva::ENCERRADA:     return "Encerrada";
        default:                           return "Desconhecido";
    }
}

// ---- Check-in ----

void Reserva::realizarCheckIn() {
    if (status != StatusReserva::ATIVA) {
        cout << "  [ERRO] Esta reserva nao esta no estado 'Ativa'." << endl;
        return;
    }
    status = StatusReserva::CHECKIN_FEITO;
    // Atualiza o estado do quarto para Ocupado
    quarto->setEstado(EstadoQuarto::OCUPADO);
    cout << "  Check-in realizado com sucesso!" << endl;
}

// ---- Check-out ----

void Reserva::realizarCheckOut() {
    if (status != StatusReserva::CHECKIN_FEITO) {
        cout << "  [ERRO] Esta reserva nao esta no estado 'Em Estadia'." << endl;
        return;
    }
    status = StatusReserva::ENCERRADA;
    // Libera o quarto novamente
    quarto->setEstado(EstadoQuarto::DISPONIVEL);
    cout << "  Check-out realizado com sucesso!" << endl;
}

// ---- ExibiÃ§Ã£o resumida ----

void Reserva::exibirInfo() const {
    cout << fixed << setprecision(2);
    cout << "  [Reserva #" << setw(3) << setfill('0') << idReserva << setfill(' ') << "] "
         << "Hospede: " << left << setw(20) << hospede->getNome()
         << " | Quarto: " << setw(4) << quarto->getNumero()
         << " (" << setw(7) << quarto->getTipoStr() << ")"
         << " | Noites: " << setw(2) << numNoites
         << " | Total: " << right << setw(10) << valorTotal << " MZN"
         << " | Status: " << left << getStatusStr() << endl;
}

// ---- ExibiÃ§Ã£o detalhada (resumo de check-out) ----

void Reserva::exibirResumo() const {
    cout << fixed << setprecision(2);
    cout << "  +-----------------------------------------+" << endl;
    cout << "  |         RESUMO DA ESTADIA               |" << endl;
    cout << "  +-----------------------------------------+" << endl;
    cout << "  | Reserva Nro : #" << left << setw(26) << idReserva          << "|" << endl;
    cout << "  | Hospede     : " << left << setw(27) << hospede->getNome()   << "|" << endl;
    cout << "  | Documento   : " << left << setw(27) << hospede->getDocumento() << "|" << endl;
    cout << "  | Quarto      : " << left << setw(27) << quarto->getNumero()  << "|" << endl;
    cout << "  | Tipo Quarto : " << left << setw(27) << quarto->getTipoStr() << "|" << endl;
    cout << "  | Noites      : " << left << setw(27) << numNoites            << "|" << endl;
    cout << "  | Preco/Noite : " << left << setw(21) << quarto->getPrecoPorNoite()
         << " MZN    |" << endl;
    cout << "  +-----------------------------------------+" << endl;
    cout << "  | VALOR TOTAL : " << left << setw(21) << valorTotal
         << " MZN    |" << endl;
    cout << "  +-----------------------------------------+" << endl;
}