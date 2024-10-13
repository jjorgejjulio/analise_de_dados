#include <TGraph.h>
#include <TGraphErrors.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>

void exercicio_2() {
    // Gráfico 1: dispersão dos dados de graphdata.txt
    TCanvas *c1 = new TCanvas("c1", "", 800, 600);
    
    std::ifstream infile("graphdata.txt");
    int n = 0;
    double x[100], y[100];

    while (infile >> x[n] >> y[n]) {
        n++;
    }
    infile.close();

    TGraph *graphDisp = new TGraph(n, x, y);
    graphDisp->SetMarkerStyle(21);
    graphDisp->SetMarkerColor(kBlack);
    graphDisp->SetTitle(";X;Y");
    graphDisp->Draw("AP");

    c1->SaveAs("graph_dispersao.png");

    // Gráfico 2: pontos conectados por uma linha
    TCanvas *c2 = new TCanvas("c2", "", 800, 600);
    
    TGraph *graphLine = new TGraph(n, x, y);
    graphLine->SetLineColor(kBlue);
    graphLine->SetTitle(";X;Y");
    graphLine->Draw("AL");

    c2->SaveAs("graph_conexao.png");

    // Gráfico 3: dados com erro de graphdata_error.txt
    TCanvas *c3 = new TCanvas("c3", "", 800, 600);
    
    std::ifstream infile_error("graphdata_error.txt");
    double x_err[100], y_err[100], ex[100], ey[100];
    int n_error = 0;

    while (infile_error >> x_err[n_error] >> y_err[n_error] >> ex[n_error] >> ey[n_error]) {
        n_error++;
    }
    infile_error.close();

    TGraphErrors *graphErrors = new TGraphErrors(n_error, x_err, y_err, ex, ey);
    graphErrors->SetMarkerStyle(21);
    graphErrors->SetMarkerColor(kBlack);
    graphErrors->SetTitle(";X;Y");
    graphErrors->Draw("AP");

    c3->SaveAs("graph_dados_com_erro.png");
}
