
{
    gROOT->Reset();
    ifstream in;
    in.open("pi.dat");
    Float_t x; Int_t nlines = 0;
    TFile *f = new TFile("pi1.root","RECREATE");
    TH1F *h1 = new TH1F("h1","pi_grafik",100,2.5,4.0);
    TNtuple *ntuple = new TNtuple("ntuple","pi","x");
    for (nlines=0; nlines<10000; nlines++) {
        in >> x;
        if (!in.good()) {break;}
        if (nlines < 5) {printf("x=%5f\n",x);}
        h1->Fill(x);
        ntuple->Fill(x);
        nlines++;
    }
    in.close();
    f->Write();
    printf("%d deger bulundu\n",nlines);
    h1->SetXTitle("pi");
    h1->SetYTitle("Olay");
    h1->Draw();
}