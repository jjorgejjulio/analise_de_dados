#include <iostream>
#include <cmath>
#include "TCanvas.h"
#include "TF1.h"
#include "TGraph.h"
#include "TAxis.h"


double f(double *x, double *par) {
    double p0 = par[0];
    double p1 = par[1];
    return (x[0] == 0) ? p0 * p1 : p0 * sin(p1 * x[0]) / x[0];
}


void exercicio_1() {
    
    double p0 = 1.0;
    double p1 = 2.0;

    
    TF1 *func = new TF1("", f, 0, 5, 2);
    func->SetParameters(p0, p1);
    
    
    TCanvas *c1 = new TCanvas("c1", "Parametric Function", 800, 600);
    func->SetLineColor(kBlue);
    func->Draw();

    
    double x_val = 1.0;
    double func_value_at_1 = func->Eval(x_val);
    std::cout << "Function value at x = 1: " << func_value_at_1 << std::endl;

    
    double dx = 1e-6; 
    double func_derivative_at_1 = (func->Eval(x_val + dx) - func->Eval(x_val - dx)) / (2 * dx);
    std::cout << "Function derivative at x = 1: " << func_derivative_at_1 << std::endl;

    
    double integral_value = func->Integral(0, 3);
    std::cout << "Integral from 0 to 3: " << integral_value << std::endl;

    
    c1->SaveAs("parametric_function.p");
}
