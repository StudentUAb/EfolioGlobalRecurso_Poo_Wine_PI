#ifndef VINHO_H
#define VINHO_H

#include <string>
#include <vector>

class Vinho {
private:
    std::string nome;
    std::string tipo;
    std::vector<std::string> castas;
    std::vector<std::string> tipo_refeicao;
    float volume;

public:
    Vinho(const std::string& nome, const std::string& tipo, const std::vector<std::string>& castas,
          const std::vector<std::string>& tipo_refeicao, float volume);

    std::string getNome() const;
    std::string getTipo() const;
    std::vector<std::string> getCastas() const;
    std::vector<std::string> getTipoRefeicao() const;
    float getVolume() const;

    void imprimirVinho() const;
};

#endif
