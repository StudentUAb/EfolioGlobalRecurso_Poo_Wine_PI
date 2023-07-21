#ifndef ADEGA_H
#define ADEGA_H

#include <string>
#include <vector>
#include "vinho.h"

class Adega {
private:
    std::string nome;
    std::string localidade;
    std::string pais;
    std::string paginaweb;
    std::vector<Vinho> vinhos;

public:
    Adega();
    std::string getNome() const;
    std::string getLocalidade() const;
    std::string getPais() const;
    std::string getPaginaWeb() const;

    void setNome(const std::string& nome);
    void setLocalidade(const std::string& localidade);
    void setPais(const std::string& pais);
    void setPaginaWeb(const std::string& paginaweb);

    void adicionarVinho(const Vinho& vinho);
    void removerVinho(const Vinho& vinho);

    void imprimirAdega();
    void mediaVolume();
    void mediaVolumeTipo(const std::string& tipo);
    void mediaVolumeTodasAdegas(const std::vector<Adega>& adegas);

    void vinhosCom(const std::string& tipo_refeicao);
};

#endif
