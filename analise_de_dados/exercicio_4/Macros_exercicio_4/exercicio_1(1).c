#include <iostream>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooFitResult.h>
#include <RooCrystalBall.h>
#include <RooPlot.h>
#include <RooRandom.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TBox.h>

void exercicio_1() {
    
    RooRealVar x("x", "x", -10, 10);
    
    
    RooRealVar mean("mean", "mean", 0, -5, 5);
    RooRealVar sigma("sigma", "sigma", 1, 0.1, 5);
    RooRealVar alpha("alpha", "alpha", 1, 0.1, 5);
    RooRealVar n("n", "n", 1, 0, 10);
    
    
    RooCrystalBall cb("cb", "Crystal Ball PDF", x, mean, sigma, alpha, n);
    
   
    RooDataSet* data = cb.generate(x, 1000);
    
   
    RooFitResult* fitResult = cb.fitTo(*data, RooFit::Save());
    
    
    RooPlot* xframe = x.frame();
    data->plotOn(xframe);
    cb.plotOn(xframe);
    
    // Configurando o gráfico
    xframe->SetTitle("Ajuste da PDF Crystal Ball");
    xframe->GetXaxis()->SetTitle("x");
    xframe->GetYaxis()->SetTitle("Frequencia");
    
    
    TCanvas* c = new TCanvas("c", "Ajuste Crystal Ball", 800, 600);
    xframe->Draw();
    
    
    TLegend* legend = new TLegend(0.6, 0.7, 0.89, 0.89);
    legend->SetTextSize(0.07); // Diminuindo a fonte da legenda
    legend->AddEntry(xframe->getObject(0), "Dados", "p");
    legend->AddEntry(xframe->getObject(1), "Ajuste", "l");
    legend->Draw();


    TLatex* latex = new TLatex();
    latex->SetNDC();
    latex->SetTextSize(0.05);
    

    double chi2 = xframe->chiSquare();
    int ndf = data->numEntries() - fitResult->floatParsFinal().getSize(); 


    
    latex->DrawLatex(0.14, 0.85, Form("Mean: %.3f #pm %.3f", mean.getVal(), mean.getError()));
    latex->DrawLatex(0.14, 0.8, Form("Sigma: %.3f #pm %.3f", sigma.getVal(), sigma.getError()));
    latex->DrawLatex(0.14, 0.75, Form("Alpha: %.3f #pm %.3f", alpha.getVal(), alpha.getError()));
    latex->DrawLatex(0.14, 0.7, Form("n: %.3f #pm %.3f", n.getVal(), n.getError()));
    latex->DrawLatex(0.14, 0.65, Form("#chi^{2}/ndf: %.2f/%d", chi2, ndf));
    
    c->SaveAs("fitCrystalBall.png"); // Salva o gráfico como PNG
}
