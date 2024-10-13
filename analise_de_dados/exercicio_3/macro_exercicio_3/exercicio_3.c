#include <TH1F.h>
#include <TRandom3.h>
#include <TCanvas.h>
#include <TStyle.h>

void exercicio_3() {
    // Cria um histograma com 50 bins entre 0 e 10
    TH1F *hist = new TH1F("hist", "Histograma;Valores;Frequencia", 50, 0, 10);

    // Cria um gerador de números aleatórios
    TRandom3 rand;

    // Preenche o histograma com 10.000 números aleatórios gaussianos
    for (int i = 0; i < 10000; i++) {
        double valor = rand.Gaus(5, 2);
        hist->Fill(valor);
    }

    // Cria um canvas para desenhar o histograma
    TCanvas *canvas = new TCanvas("canvas", "Histograma", 800, 600);
    hist->Draw();

    // Ativa a exibição da caixa de estatísticas
    hist->SetStats(1); // 1 para ativar, 0 para desativar

    // Define as opções de estatísticas globalmente
    gStyle->SetOptStat("neMRio"); // n: número de entradas, e: média, M: RMS, R: integral, o: underflows, i: overflows

    canvas->SaveAs("histograma_gaussiano_1.png");

}
