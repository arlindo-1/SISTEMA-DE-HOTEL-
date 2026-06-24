#include "Hotel.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// ============================================================
// Construtor / Destrutor
// ============================================================

Hotel::Hotel(const string& nome) : nomeHotel(nome) {}

Hotel::~Hotel() {
    // Libera a memÃ³ria heap das reservas (alocadas com new)
    for (Reserva* r : reservas) {
        delete r;
    }
    reservas.clear();
}

// ============================================================
// Auxiliares internos
// ============================================================

Hospede* Hotel::buscarHospedePorId(int id) {
    for (Hospede& h : hospedes) {
        if (h.getIdHospede() == id) return &h;
    }
    return nullptr;
}

Quarto* Hotel::buscarQuartoPorNumero(int numero) {
    for (Quarto& q : quartos) {
        if (q.getNumero() == numero) return &q;
    }
    return nullptr;
}

bool Hotel::quartoExiste(int numero) const {
    for (const Quarto& q : quartos) {
        if (q.getNumero() == numero) return true;
    }
    return false;
}

void Hotel::exibirSeparador() const {
    cout << "  ==========================================" << endl;
}

// ============================================================
// LOOP PRINCIPAL
// ============================================================

void Hotel::executar() {
    int opcao = -1;

    while (opcao != 0) {
        cout << endl;
        cout << "  ==========================================" << endl;
        cout << "       SISTEMA DE HOTEL â€” " << nomeHotel       << endl;
        cout << "  ==========================================" << endl;
        cout << "  1. Registrar Hospede"                        << endl;
        cout << "  2. Cadastrar Quarto"                         << endl;
        cout << "  3. Fazer Reserva"                            << endl;
        cout << "  4. Realizar Check-in"                        << endl;
        cout << "  5. Realizar Check-out"                       << endl;
        cout << "  6. Listar Hospedes"                          << endl;
        cout << "  7. Listar Quartos"                           << endl;
        cout << "  8. Listar Reservas"                          << endl;
        cout << "  0. Sair"                                     << endl;
        cout << "  ==========================================" << endl;
        cout << "  Escolha uma opcao: ";
        cin  >> opcao;

        // Limpa buffer para evitar lixo em leituras de string
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << endl;

        switch (opcao) {
            case 1: registrarHospede();   break;
            case 2: cadastrarQuarto();    break;
            case 3: fazerReserva();       break;
            case 4: realizarCheckIn();    break;
            case 5: realizarCheckOut();   break;
            case 6: listarHospedes();     break;
            case 7: menuListarQuartos();  break;
            case 8: listarReservas();     break;
            case 0:
                cout << "  Encerrando o sistema. Ate logo!" << endl;
                break;
            default:
                cout << "  [AVISO] Opcao invalida. Tente novamente." << endl;
        }
    }
}

// ============================================================
// 1. REGISTRAR HÃ“SPEDE
// ============================================================

void Hotel::registrarHospede() {
    exibirSeparador();
    cout << "       REGISTRAR HOSPEDE" << endl;
    exibirSeparador();

    string nome, documento, telefone;

    cout << "  Nome completo : ";
    getline(cin, nome);

    cout << "  BI/Documento  : ";
    getline(cin, documento);

    cout << "  Telefone      : ";
    getline(cin, telefone);

    // ValidaÃ§Ã£o mÃ­nima
    if (nome.empty() || documento.empty()) {
        cout << "  [ERRO] Nome e documento sao obrigatorios." << endl;
        return;
    }

    // Cria o hÃ³spede e adiciona ao vetor
    Hospede novoHospede(nome, documento, telefone);
    hospedes.push_back(novoHospede);

    cout << "  Hospede registrado com sucesso! ID: "
         << hospedes.back().getIdHospede() << endl;
}

// ============================================================
// 2. CADASTRAR QUARTO
// ============================================================

void Hotel::cadastrarQuarto() {
    exibirSeparador();
    cout << "       CADASTRAR QUARTO" << endl;
    exibirSeparador();

    int    numero;
    int    tipoInt;
    double preco;

    cout << "  Numero do quarto     : ";
    cin  >> numero;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (quartoExiste(numero)) {
        cout << "  [ERRO] Ja existe um quarto com o numero " << numero << "." << endl;
        return;
    }

    cout << "  Tipo do quarto:" << endl;
    cout << "    1 - Simples" << endl;
    cout << "    2 - Duplo"   << endl;
    cout << "    3 - Luxo"    << endl;
    cout << "  Escolha (1-3)        : ";
    cin  >> tipoInt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (tipoInt < 1 || tipoInt > 3) {
        cout << "  [ERRO] Tipo invalido." << endl;
        return;
    }

    cout << "  Preco por noite (MZN): ";
    cin  >> preco;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (preco <= 0) {
        cout << "  [ERRO] Preco deve ser maior que zero." << endl;
        return;
    }

    TipoQuarto tipo = static_cast<TipoQuarto>(tipoInt - 1);
    Quarto novoQuarto(numero, tipo, preco);
    quartos.push_back(novoQuarto);

    cout << "  Quarto " << numero << " cadastrado com sucesso!" << endl;
}

// ============================================================
// 3. FAZER RESERVA
// ============================================================

void Hotel::fazerReserva() {
    exibirSeparador();
    cout << "       FAZER RESERVA" << endl;
    exibirSeparador();

    if (hospedes.empty()) {
        cout << "  Nenhum hospede cadastrado. Registre um hospede primeiro." << endl;
        return;
    }

    // Mostra hÃ³spedes para escolha
    cout << "  --- Hospedes Cadastrados ---" << endl;
    for (const Hospede& h : hospedes) {
        // Usa polimorfismo: chama exibirInfo() da classe Hospede
        h.exibirInfo();
    }

    int idHospede;
    cout << "  Informe o ID do hospede: ";
    cin  >> idHospede;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Hospede* hospede = buscarHospedePorId(idHospede);
    if (!hospede) {
        cout << "  [ERRO] Hospede com ID " << idHospede << " nao encontrado." << endl;
        return;
    }

    // Mostra quartos disponÃ­veis
    cout << endl << "  --- Quartos DisponÃ­veis ---" << endl;
    bool temDisponivel = false;
    for (const Quarto& q : quartos) {
        if (q.estaDisponivel()) {
            q.exibirInfo();
            temDisponivel = true;
        }
    }

    if (!temDisponivel) {
        cout << "  Nenhum quarto disponivel no momento." << endl;
        return;
    }

    int numeroQuarto;
    cout << "  Informe o numero do quarto: ";
    cin  >> numeroQuarto;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Quarto* quarto = buscarQuartoPorNumero(numeroQuarto);
    if (!quarto) {
        cout << "  [ERRO] Quarto " << numeroQuarto << " nao encontrado." << endl;
        return;
    }
    if (!quarto->estaDisponivel()) {
        cout << "  [ERRO] Quarto " << numeroQuarto << " nao esta disponivel." << endl;
        return;
    }

    int noites;
    cout << "  Numero de noites     : ";
    cin  >> noites;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (noites <= 0) {
        cout << "  [ERRO] Numero de noites deve ser maior que zero." << endl;
        return;
    }

    // Cria a reserva (alocaÃ§Ã£o dinÃ¢mica) e altera estado do quarto
    Reserva* novaReserva = new Reserva(hospede, quarto, noites);
    quarto->setEstado(EstadoQuarto::RESERVADO);
    reservas.push_back(novaReserva);

    cout << fixed << setprecision(2);
    cout << "  Reserva #" << novaReserva->getIdReserva() << " criada com sucesso!" << endl;
    cout << "  Valor total estimado : " << novaReserva->getValorTotal() << " MZN" << endl;
}

// ============================================================
// 4. REALIZAR CHECK-IN
// ============================================================

void Hotel::realizarCheckIn() {
    exibirSeparador();
    cout << "       REALIZAR CHECK-IN" << endl;
    exibirSeparador();

    // Mostra apenas reservas ativas (aguardando check-in)
    bool temAtiva = false;
    cout << "  --- Reservas Ativas ---" << endl;
    for (const Reserva* r : reservas) {
        if (r->getStatus() == StatusReserva::ATIVA) {
            r->exibirInfo();
            temAtiva = true;
        }
    }

    if (!temAtiva) {
        cout << "  Nenhuma reserva ativa para check-in." << endl;
        return;
    }

    int idReserva;
    cout << "  Informe o ID da reserva: ";
    cin  >> idReserva;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (Reserva* r : reservas) {
        if (r->getIdReserva() == idReserva) {
            r->realizarCheckIn();
            return;
        }
    }

    cout << "  [ERRO] Reserva #" << idReserva << " nao encontrada." << endl;
}

// ============================================================
// 5. REALIZAR CHECK-OUT
// ============================================================

void Hotel::realizarCheckOut() {
    exibirSeparador();
    cout << "       REALIZAR CHECK-OUT" << endl;
    exibirSeparador();

    // Mostra apenas reservas em estadia (check-in jÃ¡ feito)
    bool temEstadia = false;
    cout << "  --- Reservas Em Estadia ---" << endl;
    for (const Reserva* r : reservas) {
        if (r->getStatus() == StatusReserva::CHECKIN_FEITO) {
            r->exibirInfo();
            temEstadia = true;
        }
    }

    if (!temEstadia) {
        cout << "  Nenhum hospede em estadia para check-out." << endl;
        return;
    }

    int idReserva;
    cout << "  Informe o ID da reserva: ";
    cin  >> idReserva;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (Reserva* r : reservas) {
        if (r->getIdReserva() == idReserva) {
            // Exibe resumo antes de confirmar
            r->exibirResumo();

            char confirmacao;
            cout << "  Confirmar check-out? (s/n): ";
            cin  >> confirmacao;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (confirmacao == 's' || confirmacao == 'S') {
                r->realizarCheckOut();
            } else {
                cout << "  Check-out cancelado." << endl;
            }
            return;
        }
    }

    cout << "  [ERRO] Reserva #" << idReserva << " nao encontrada." << endl;
}

// ============================================================
// 6. LISTAR HÃ“SPEDES
// ============================================================

void Hotel::listarHospedes() const {
    exibirSeparador();
    cout << "       HOSPEDES CADASTRADOS (" << hospedes.size() << ")" << endl;
    exibirSeparador();

    if (hospedes.empty()) {
        cout << "  Nenhum hospede cadastrado." << endl;
        return;
    }

    // Polimorfismo: chama exibirInfo() da classe Hospede
    // (via referÃªncia a Pessoa* poderÃ­amos chamar de forma polimÃ³rfica)
    for (const Hospede& h : hospedes) {
        h.exibirInfo();
    }
}

// ============================================================
// 7. LISTAR QUARTOS (sub-menu)
// ============================================================

void Hotel::menuListarQuartos() {
    int opcao = -1;
    while (opcao != 0) {
        cout << "  --- Sub-menu Quartos ---"     << endl;
        cout << "  1. Listar todos os quartos"   << endl;
        cout << "  2. Listar quartos disponiveis"<< endl;
        cout << "  3. Listar quartos ocupados"   << endl;
        cout << "  0. Voltar"                    << endl;
        cout << "  Escolha: ";
        cin  >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        switch (opcao) {
            case 1: listarQuartos();            break;
            case 2: listarQuartosDisponiveis(); break;
            case 3: listarQuartosOcupados();    break;
            case 0: break;
            default: cout << "  Opcao invalida." << endl;
        }
    }
}

void Hotel::listarQuartos() const {
    exibirSeparador();
    cout << "       TODOS OS QUARTOS (" << quartos.size() << ")" << endl;
    exibirSeparador();

    if (quartos.empty()) {
        cout << "  Nenhum quarto cadastrado." << endl;
        return;
    }
    for (const Quarto& q : quartos) {
        q.exibirInfo();
    }
}

void Hotel::listarQuartosDisponiveis() const {
    exibirSeparador();
    cout << "       QUARTOS DISPONIVEIS" << endl;
    exibirSeparador();

    int count = 0;
    for (const Quarto& q : quartos) {
        if (q.estaDisponivel()) {
            q.exibirInfo();
            count++;
        }
    }
    if (count == 0) {
        cout << "  Nenhum quarto disponivel." << endl;
    }
}

void Hotel::listarQuartosOcupados() const {
    exibirSeparador();
    cout << "       QUARTOS OCUPADOS" << endl;
    exibirSeparador();

    int count = 0;
    for (const Quarto& q : quartos) {
        if (q.getEstado() == EstadoQuarto::OCUPADO) {
            q.exibirInfo();
            count++;
        }
    }
    if (count == 0) {
        cout << "  Nenhum quarto ocupado no momento." << endl;
    }
}

// ============================================================
// 8. LISTAR RESERVAS
// ============================================================

void Hotel::listarReservas() const {
    exibirSeparador();
    cout << "       RESERVAS (" << reservas.size() << ")" << endl;
    exibirSeparador();

    if (reservas.empty()) {
        cout << "  Nenhuma reserva registrada." << endl;
        return;
    }
    for (const Reserva* r : reservas) {
        r->exibirInfo();
    }
}