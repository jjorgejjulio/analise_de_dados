#include <iostream>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooExponential.h>
#include <RooFitResult.h>
#include <RooPlot.h>
#include <RooRandom.h>
#include <TCanvas.h>
#include <TLatex.h>

void exercicio_2() {
    RooRealVar x("x", "x", 0, 10);
    RooRealVar lambda("lambda", "decay constant", 1, 0.1, 2);
    RooExponential expDecay("expDecay", "Exponential Decay", x, lambda);
    RooDataSet* data = expDecay.generate(x, 1500);
    RooRealVar nEvents("nEvents", "Number of Events", 1500, 100, 5000);
    RooFitResult* fitResult = expDecay.fitTo(*data, RooFit::Save(), RooFit::Extended(kTRUE));
    RooPlot* xframe = x.frame();
    data->plotOn(xframe);
    expDecay.plotOn(xframe);
    xframe->GetXaxis()->SetTitle("x");
    xframe->GetYaxis()->SetTitle("Frequencia");
    TCanvas* c = new TCanvas("c", "Ajuste Exponencial", 800, 600);
    xframe->Draw();
    TLatex latex;
    latex.SetNDC();
    latex.SetTextSize(0.03);
    latex.DrawLatex(0.2, 0.8, Form("Ajuste de \\lambda: %.3f", lambda.getVal()));
    latex.DrawLatex(0.2, 0.75, Form("Total de Eventos Ajustados: %.0f", nEvents.getVal()));
    c->SaveAs("fitExponential.png");
    std::cout << "Valor ajustado para lambda: " << lambda.getVal() << std::endl;
    std::cout << "Número total de eventos ajustados: " << nEvents.getVal() << std::endl;
    double trueLambda = 1;
    double trueEvents = 1500;
    std::cout << "Valor gerado para lambda: " << trueLambda << std::endl;
    std::cout << "Número total de eventos gerados: " << trueEvents << std::endl;
    std::cout << "Os valores ajustados estão dentro das expectativas? "
              << (fabs(lambda.getVal() - trueLambda) < 0.1 ? "Sim" : "Não") << std::endl;
}
