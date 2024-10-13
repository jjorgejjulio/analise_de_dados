void exercicio_4()
{


    TCanvas *c1 = new TCanvas("c1", "Histograma de Momento", 800, 600);
    TFile *file = new TFile("tree.root");
    TTree *tree = (TTree*)file->Get("tree1");
    TH1F *hist = new TH1F("hist", "", 100, 100, 200);
    TH1F *histEbeam = new TH1F("histEbeam", "", 100, 0, 1000);
    float px, py, pz, ebeam;

    tree->SetBranchAddress("ebeam", &ebeam);
    tree->SetBranchAddress("px", &px); 
    tree->SetBranchAddress("py", &py);
    tree->SetBranchAddress("pz", &pz);

    Int_t nEntries = tree->GetEntries();

    for (Int_t i = 0; i < nEntries; i++) {
        tree->GetEntry(i);
        histEbeam->Fill(ebeam);
    }

    float meanEbeam = histEbeam->GetMean();
    for (Int_t i = 0; i < nEntries; i++) {
        tree->GetEntry(i);
        if (ebeam > meanEbeam * 0.2) {
            float pMagnitude = sqrt(px * px + py * py + pz * pz);
            hist->Fill(pMagnitude);
        }
    }

    hist->Draw();
    c1->SaveAs("histograma_momento.png");
}