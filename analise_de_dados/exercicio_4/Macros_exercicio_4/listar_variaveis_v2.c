#include <iostream>
#include "TFile.h"
#include "TTree.h"

void listar_variaveis_v2() {
    TFile *file = TFile::Open("DataSet_lowstat.root");
    if (!file || file->IsZombie()) {
        std::cerr << "Erro ao abrir o arquivo DataSet_lowstat.root" << std::endl;
        return;
    }

    // Tentando acessar a TTree diretamente
    TTree *tree = (TTree*)file->Get("data");
    if (!tree) {
        std::cerr << "Erro ao acessar a árvore 'data'" << std::endl;
        return;
    }

    // Imprime as variáveis do TTree
    tree->Print();  // Imprime as variáveis e suas informações

    file->Close();
}
