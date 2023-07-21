#include "vinho.h"
#include <iostream>

Vinho::Vinho(const std::string& nome, const std::string& tipo, const std::vector<std::string>& castas,
             const std::vector<std::string>& tipo_refeicao, float volume)
    : nome(nome), tipo(tipo), castas(castas), tipo_refeicao(tipo_refeicao), volume(volume) {}

std::string Vinho::getNome() const {
    return nome;
}

std::string Vinho::getTipo() const {
    return tipo;
}

std::vector<std::string> Vinho::getCastas() const {
    return castas;
}

std::vector<std::string> Vinho::getTipoRefeicao() const {
    return tipo_refeicao;
}

float Vinho::getVolume() const {
    return volume;
}

void Vinho::imprimirVinho() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Volume: " << volume << std::endl;
    std::cout << "Castas: ";
    for (const auto& casta : castas) {
        std::cout << casta << " ";
    }
    std::cout << std::endl;
    std::cout << "Tipo de Refeição: ";
    for (const auto& tipo : tipo_refeicao) {
        std::cout << tipo << " ";
    }
    std::cout << std::endl;
}
