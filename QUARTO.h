#ifndef QUARTO_H
#define QUARTO_H

#include <string>
using namespace std;

// ============================================================
// EnumeraÃ§Ã£o: TipoQuarto
// Facilita comparaÃ§Ã£o e exibiÃ§Ã£o do tipo sem usar strings
// brutas espalhadas pelo cÃ³digo.
// ============================================================
enum class TipoQuarto {
    SIMPLES,
    DUPLO,
    LUXO
};

// ============================================================
// EnumeraÃ§Ã£o: EstadoQuarto
// Representa os trÃªs estados possÃ­veis de um quarto.
// ============================================================
enum class EstadoQuarto {
    DISPONIVEL,
    RESERVADO,
    OCUPADO
};

// ============================================================
// Classe: Quarto
// Representa um quarto fÃ­sico do hotel.
// ============================================================
class Quarto {
private:
    int         numero;
    TipoQuarto  tipo;
    double      precoPorNoite;
    EstadoQuarto estado;

public:
    // Construtor padrÃ£o
    Quarto();

    // Construtor parametrizado
    Quarto(int numero, TipoQuarto tipo, double precoPorNoite);

    // Destrutor
    ~Quarto();

    // Getters
    int          getNumero()        const;
    TipoQuarto   getTipo()          const;
    double       getPrecoPorNoite() const;
    EstadoQuarto getEstado()        const;

    // ConversÃ£o de tipo/estado para texto (Ãºtil para exibiÃ§Ã£o)
    string getTipoStr()   const;
    string getEstadoStr() const;

    // Altera o estado do quarto
    void setEstado(EstadoQuarto estado);

    // Exibe informaÃ§Ãµes resumidas do quarto
    void exibirInfo() const;

    // Verifica se estÃ¡ disponÃ­vel
    bool estaDisponivel() const;
};

#endif // QUARTO_H