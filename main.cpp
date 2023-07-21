#include "adega.h"
#include "vinho.h"
#include <iostream>
#include <memory>

int main() {
    std::vector<std::unique_ptr<Adega>> adegas;
    std::vector<Vinho> vinhos;

    // Criar vinhos
    Vinho vinho1("Vinho 1", "Tinto", {"Casta 1", "Casta 2"}, {"Peixe", "Queijo"}, 14);
    Vinho vinho2("Vinho 2", "Verde", {"Casta 3", "Casta 4"}, {"Carne", "Peixe"}, 11);
    Vinho vinho3("Vinho 3", "Branco", {"Casta 5", "Casta 6"}, {"Carne", "Fruta"}, 13);
    Vinho vinho4("Vinho 4", "Rose", {"Casta 7", "Casta 8"}, {"Peixe", "Queijo"}, 12);

    // Criar adegas
    std::unique_ptr<Adega> adega1 = std::make_unique<Adega>();
    adega1->setNome("Adega 1");
    adega1->setLocalidade("Porto");
    adega1->setPais("Portugal");
    adega1->setPaginaWeb("www.adega1.pt");
    adega1->adicionarVinho(vinho1);
    adega1->adicionarVinho(vinho2);
    adegas.push_back(std::move(adega1));

    std::unique_ptr<Adega> adega2 = std::make_unique<Adega>();
    adega2->setNome("Adega 2");
    adega2->setLocalidade("Lisboa");
    adega2->setPais("Portugal");
    adega2->setPaginaWeb("www.adegadeLisboa.pt");
    adega2->adicionarVinho(vinho3);
    adega2->adicionarVinho(vinho4);
    adegas.push_back(std::move(adega2));
    
    // Imprimir adegas e vinhos
    adegas[0]->imprimirAdega();
    adegas[0]->mediaVolumeTipo("Novo Tinto");
    adegas[0]->mediaVolume();

    std::cout << std::endl;

    adegas[1]->imprimirAdega();
    adegas[1]->mediaVolumeTipo("Maduro Tinto");
    adegas[1]->mediaVolume();

    std::cout << "\n*** Media Total de todos os vinhos ***" << std::endl;
    Adega adegasTotais;
    adegasTotais.mediaVolumeTodasAdegas({*adegas[0], *adegas[1]});

    std::cout << std::endl;
    adegas[0]->vinhosCom("Peixe");
    adegas[0]->vinhosCom("Carne");
    adegas[0]->vinhosCom("Queijo");
    adegas[0]->vinhosCom("Fruta");

    return 0;
}
