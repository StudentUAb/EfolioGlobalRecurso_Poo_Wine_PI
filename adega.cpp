#include "adega.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>

Adega::Adega() : nome(""), localidade(""), pais(""), paginaweb("") {}

std::string Adega::getNome() const {
    return nome;
}

std::string Adega::getLocalidade() const {
    return localidade;
}

std::string Adega::getPais() const {
    return pais;
}

std::string Adega::getPaginaWeb() const {
    return paginaweb;
}

void Adega::setNome(const std::string& nome) {
    this->nome = nome;
}

void Adega::setLocalidade(const std::string& localidade) {
    this->localidade = localidade;
}

void Adega::setPais(const std::string& pais) {
    this->pais = pais;
}

void Adega::setPaginaWeb(const std::string& paginaweb) {
    this->paginaweb = paginaweb;
}

void Adega::adicionarVinho(const Vinho& vinho) {
    vinhos.push_back(vinho);
}

void Adega::removerVinho(const Vinho& vinho) {
    vinhos.erase(std::remove_if(vinhos.begin(), vinhos.end(),
                                [&vinho](const Vinho& v) { return v.getNome() == vinho.getNome(); }),
                 vinhos.end());
}

void Adega::imprimirAdega() {
    std::cout << "\n*** " << nome << " **** " << std::endl;
    std::cout << "Localidade: " << localidade << std::endl;
    std::cout << "Pais: " << pais << std::endl;
    std::cout << "Pagina Web: " << paginaweb << std::endl;
    std::cout << "Lista de Vinhos: " << std::endl;
    for (const auto& vinho : vinhos) {
        vinho.imprimirVinho();
    }
}

void Adega::mediaVolume() {
    float media = std::accumulate(vinhos.begin(), vinhos.end(), 0.0f,
                                  [](float sum, const Vinho& vinho) { return sum + vinho.getVolume(); });
    media = media / vinhos.size();
    std::cout << "Media de Volume: " << media << std::endl;

    std::vector<std::pair<std::string, float>> volumes;
    for (const auto& vinho : vinhos) {
        if (vinho.getVolume() < media) {
            volumes.emplace_back(vinho.getNome(), vinho.getVolume());
        }
    }

    std::string nomeficheiro = "suaves.txt";
    std::ofstream fw(nomeficheiro);
    if (fw.is_open()) {
        for (const auto& volume : volumes) {
            fw << volume.first << " " << volume.second << std::endl;
        }
        fw.close();
        std::cout << "Ficheiro criado com sucesso!!\n";
    } else {
        std::cout << "Erro no ficheiro!!\n";
    }
}

void Adega::mediaVolumeTipo(const std::string& tipo) {
    float media = 0;
    int numvinhos = 0;

    for (const auto& vinho : vinhos) {
        if (vinho.getTipo() == tipo) {
            media += vinho.getVolume();
            numvinhos++;
        }
    }

    if (numvinhos > 0) {
        media = media / numvinhos;
        std::cout << "Media de Volume de Vinhos do Tipo " << tipo << ": " << media << std::endl;

        std::vector<std::pair<std::string, float>> volumes;
        for (const auto& vinho : vinhos) {
            if (vinho.getTipo() == tipo && vinho.getVolume() < media) {
                volumes.emplace_back(vinho.getNome(), vinho.getVolume());
            }
        }

        std::string nomeficheiro = "suavescomtipo.txt";
        std::ofstream fw(nomeficheiro);
        if (fw.is_open()) {
            for (const auto& volume : volumes) {
                fw << volume.first << " " << volume.second << std::endl;
            }
            fw.close();
            std::cout << "Ficheiro criado com sucesso!!\n";
        } else {
            std::cout << "Erro no ficheiro!!\n";
        }
    } else {
        std::cout << "Nao existem vinhos do tipo " << tipo << " nesta adega!\n";
    }
}

void Adega::mediaVolumeTodasAdegas(const std::vector<Adega>& adegas) {
    float media = 0;
    int numvinhos = 0;

    for (const auto& adega : adegas) {
        for (const auto& vinho : adega.vinhos) {
            media += vinho.getVolume();
            numvinhos++;
        }
    }

    if (numvinhos > 0) {
        media = media / numvinhos;
        std::cout << "Media de Volume de Todos os Vinhos: " << media << std::endl;

        std::vector<std::pair<std::string, float>> volumes;
        for (const auto& adega : adegas) {
            for (const auto& vinho : adega.vinhos) {
                if (vinho.getVolume() < media) {
                    volumes.emplace_back(vinho.getNome(), vinho.getVolume());
                }
            }
        }

        std::string nomeficheiro = "suaves.txt";
        std::ofstream fw(nomeficheiro);
        if (fw.is_open()) {
            for (const auto& volume : volumes) {
                fw << volume.first << " " << volume.second << std::endl;
            }
            fw.close();
            std::cout << "Ficheiro criado com sucesso!!\n";
        } else {
            std::cout << "Erro no ficheiro!!\n";
        }
    } else {
        std::cout << "Nao existem vinhos em nenhuma adega!\n";
    }
}

void Adega::vinhosCom(const std::string& tipo_refeicao) {
    std::cout << "*** Vinhos para acompanhar com: " << tipo_refeicao << " ***" << std::endl;
    for (const auto& vinho : vinhos) {
        if (std::find(vinho.getTipoRefeicao().begin(), vinho.getTipoRefeicao().end(), tipo_refeicao) !=
            vinho.getTipoRefeicao().end()) {
            std::cout << getPaginaWeb() << std::endl;
            break;
        }
    }
}
