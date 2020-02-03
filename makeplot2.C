#include "TFile.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TDirectory.h"
#include <iostream>
#include <TLegend.h>

void makeplot2(){

   TFile *f=TFile::Open("physval-21.3test.root","READ");
   cout<<"1. Open root file"<<endl;
   TCanvas *c = new TCanvas("c","TProfile Histogram",1800,1000);
   cout<<"2. Set the canvas"<<endl;
    
	std::vector<TString>Hist=
    {
      "tau25_idperf_tracktwoMVA",
      "tau25_idperf_tracktwoRNN",
      "tau25_idperf_tracktwoMVABDT",
      "tau25_perf_tracktwoMVA",
      "tau25_perf_tracktwoRNN",
      "tau25_perf_tracktwoMVABDT",
      "tau25_mediumRNN_tracktwoMVA",
      "tau25_mediumRNN_tracktwoRNN",
      "tau25_mediumRNN_tracktwoMVA",            
      
    };
   cout<<"2. Set the vector of string"<<endl;
   c->Divide(1,3);
   cout<<"3. Divide the canvas"<<endl;
   TProfile *h;
   cout<<"4. Set h pointer as TProfile histogram empty"<<endl;
   int n=0;
   cout<<"5. Set number n="<< n <<endl; 
   int p=1;
   cout<<"6. Set number p="<< p <<endl;
   for (int i=1; i<1+Hist.size() ; i++) {
   cout<<"7. Enter inside the FOR structure with i="<< i <<endl;
     h=(TProfile*)f->Get("run_1/HLT/TauMon/Expert/"+Hist[i-1]+"/TurnOnCurves/RecoEfficiency/TProfRecoL1PtEfficiency");


      cout<<"8. Copy the TProfile histogram from the root file to the element"<< Hist [i-1] <<endl;
      n++;
      cout<<"9. raise the n="<< n <<endl;
      
      h->SetLineColor(n+1);
      cout<<"10. Set the color with the number="<< n+1 <<endl;
      
      
      if (n==1) {
         cout<<"11. Enter to if with i= "<< i <<endl;
         cout<<"and n="<< n << endl;
         c->cd(p);
         cout<<"13. Set the canvas in p="<< p <<endl;
         h->Draw();
         cout<<"14. Draw the histogram"<<endl;
	 gDirectory->cd("../../../");
         cout<<"15. Come back to the directory"<<endl;
      } else if (n==3) {
         cout<<"16. Enter to else if with i="<< i <<endl;
         n = 0;
         cout<<"17. Put n="<< n <<endl;
         p++;
         cout<<"18.raise p="<< p << endl;
         h->Draw("SAME");
         cout<<"19. Draw histogram"<<endl;
	 gDirectory->cd("../../../");
         cout<<"20. Come back to the dorectory"<<endl;
	 gStyle->SetOptStat(0);
         cout<<"21. Erase the statics box"<<endl;
      } else {
         cout<<"22. Enter to else structure with i="<< i <<endl;
         h->Draw("SAME");
         cout<<"23. Draw the histogram"<<endl;
	 gDirectory->cd("../../../");
         cout<<"24. Come back to the dorectory"<<endl;
      }
   }
   
}
