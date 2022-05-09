/*
           my nice code
*/

#include <iostream>

#include "TFile.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TDirectory.h"
#include "TLegend.h"




void drawhist(){

    TFile *f =TFile::Open("test2.root","READ");
    cout << "1. Open the root file" << endl;
    TCanvas *c = new TCanvas("c","Draw Histogram",1800,1000);
    cout << "2. Declare the canvas" << endl;
    gStyle->SetOptStat(0);
    cout << "3. Remove the statics box" << endl;

    //TLegend *leg = new TLegend(0.6, 0.5, 0.89, 0.89);
    //auto leg = new TLegend(0.59,0.6,0.65,0.4);
    cout << "4. Declare Legend" << endl;

    TProfile *h1;
    TProfile *h2;
    TProfile *h3;
    TProfile *h4;
    TProfile *h5;
    cout << "5. Declare the histogram type" << endl;

    h1=(TProfile*)f->Get("run_310000/HLT/TauMon/EFVsTruth/HLT_tau25_mediumRNN_tracktwoMVABDT_L1TAU12IM/Etratio_vs_pt_vis");
    h2=(TProfile*)f->Get("run_310000/HLT/TauMon/EFVsTruth/HLT_tau35_mediumRNN_tracktwoMVABDT_L1TAU20IM/Etratio_vs_pt_vis");
    h3=(TProfile*)f->Get("run_310000/HLT/TauMon/EFVsTruth/HLT_tau60_mediumRNN_tracktwoMVABDT_L1TAU40/Etratio_vs_pt_vis");
    h4=(TProfile*)f->Get("run_310000/HLT/TauMon/EFVsTruth/HLT_tau80_mediumRNN_tracktwoMVABDT_L1TAU60/Etratio_vs_pt_vis");
    h5=(TProfile*)f->Get("run_310000/HLT/TauMon/EFVsTruth/HLT_tau160_mediumRNN_tracktwoMVABDT_L1TAU100/Etratio_vs_pt_vis");
    cout << "6. Copy the histograms from the root file" << endl;
    
    c->cd();
    cout << "7. Canvas position" << endl;

    h1->SetLineColor(4);
    h1->SetLineWidth(2);
    h1->SetMarkerStyle(20);
    h1->SetMarkerSize(2.3);
    h1->SetMarkerColor(4);
    
    h2->SetLineColor(2);
    h2->SetLineWidth(2);
    h2->SetMarkerStyle(21);
    h2->SetMarkerSize(2.3);
    h2->SetMarkerColor(2);

    h3->SetLineColor(3);
    h3->SetLineWidth(2);
    h3->SetMarkerStyle(21);
    h3->SetMarkerSize(2.3);
    h3->SetMarkerColor(3);

    h4->SetLineColor(6);
    h4->SetLineWidth(2);
    h4->SetMarkerStyle(22);
    h4->SetMarkerSize(2.3);
    h4->SetMarkerColor(6);

    h5->SetLineColor(1);
    h5->SetLineWidth(2);
    h5->SetMarkerStyle(23);
    h5->SetMarkerSize(2.3);
    h5->SetMarkerColor(1); 

    cout << "8. Set the curve style for each histogram" << endl;

    h1->GetYaxis()->SetRangeUser(-0.2, 0.3);
    h1->GetXaxis()->SetRangeUser(0, 250);
    cout << "9. Set Range of axis" << endl;

    h1->Draw("E1");
    h2->Draw("SAME E1");
    h3->Draw("SAME E1");
    h4->Draw("SAME E1");
    h5->Draw("SAME E1");
    cout << "10. Draw the histograms " << endl;

    auto legend = new TLegend(0.5,0.5,0.6,0.6);
    legend->SetHeader("The Legend Title","C");
    legend->AddEntry(h1,"Histogram filled with random numbers","lep");
    cout << "11. Legend" << endl;

    TLatex l;
    l.SetNDC();
    l.SetTextFont(42);
    l.SetTextColor(1);
    l.DrawLatex(0.26,0.85,"Internal");

    TLatex l2;
    l2.SetNDC();
    l2.SetTextFont(72);
    l2.SetTextColor(1);
    l2.DrawLatex(0.13,0.85,"ATLAS");

    TPaveText *pText = new TPaveText(0.12,0.73,0.42,0.83,"NDC NB");
    pText->AddText("#int{}_{}Ldt = 139 fb^{-1}; #sqrt{s} = 14 [TeV]");
    pText->SetFillColor(0);
    pText->SetTextAlign(11);
    pText->SetTextFont(42);
    pText->Draw();

    cout << "12. ATLAS internal text" << endl;

    //t = new TLine(100,0,100,4.5);
    //t->Draw();
    TLine *le = new TLine(25,-0.2,25,0.2);
    le->SetLineColor(4);
    le->Draw();
    
    TLine *le2 = new TLine(35,-0.2,35,0.2);
    le2->SetLineColor(2);
    le2->Draw();

    TLine *le3 = new TLine(60,-0.2,60,0.2);
    le3->SetLineColor(3);
    le3->Draw();

    TLine *le4 = new TLine(80,-0.2,80,0.2);
    le4->SetLineColor(6);
    le4->Draw();

    TLine *le5 = new TLine(160,-0.2,160,0.3);
    le5->SetLineColor(1);
    le5->Draw();


    c->SaveAs("testimage3.pdf");
    cout << "13. Save the canvas" << endl;

};

