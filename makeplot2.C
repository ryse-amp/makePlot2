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
      
   auto legend = new TLegend(0.99,0.6,0.65,0.4);
   legend->SetHeader("Legend","C");
   auto legend1 = new TLegend(0.99,0.6,0.65,0.4);
   legend1->SetHeader("Legend","C");
   auto legend2 = new TLegend(0.99,0.6,0.65,0.4);
   legend2->SetHeader("Legend","C");
   
    cout<<"3. set the legends"<<endl; 
    
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
      "tau25_mediumRNN_tracktwoMVABDT",            
      
    };

   cout<<"4. Set the vector of string"<<endl;
   c->Divide(2,2);
   cout<<"5. Divide the canvas"<<endl;
   TProfile *h;
   cout<<"6. Set h pointer as TProfile histogram empty"<<endl;
   int n=0;
   cout<<"7. Set number n="<< n <<endl; 
   int p=1;
   cout<<"9. Set number p="<< p <<endl;
  

   for (int i=1; i<1+Hist.size() ; i++) {
   
   cout<<"10. Enter inside the FOR structure with i="<< i <<endl;
     
     h=(TProfile*)f->Get("run_1/HLT/TauMon/Expert/"+Hist[i-1]+"/TurnOnCurves/RecoEfficiency/TProfRecoL1PtEfficiency");

      cout<<"11. Copy the TProfile histogram from the root file to the element"<< Hist [i-1] <<endl;
      n++;
      cout<<"12. raise the n="<< n <<endl;
      
      h->SetLineColor(n+1);
      cout<<"13. Set the color with the number="<< n+1 <<endl;
      
      
        if (n==1) {
        
         cout<<"14. Enter to if with i= "<< i <<endl;
         cout<<"and n="<< n << endl;
         c->cd(p);
         cout<<"15. Set the canvas in p="<< p <<endl;
         h->Draw();   
         cout<<"16. Draw the histogram"<<endl;
         
         if (p==1){
         cout<<"17. Enter to if legend with p="<< p <<endl;
         legend->AddEntry(h,Hist[i-1],"l");
         }
         if (p==2){
         cout<<"18. Enter to if legend with p="<< p <<endl;
         legend1->AddEntry(h,Hist[i-1],"l");
         }
         if (p==3){
         cout<<"19. Enter to if legend with p="<< p <<endl;
         legend2->AddEntry(h,Hist[i-1],"l");
         }

         gDirectory->cd("../../../");
         cout<<"20. Come back to the directory"<<endl;
 
     } else if (n==3) {
         
         cout<<"21. Enter to else if with i="<< i <<endl;
         cout<<"and n="<< n <<endl;
         n = 0;
         cout<<"22. Put n="<< n <<endl;
        
         h->Draw("SAME");
         cout<<"24. Draw histogram SAME"<<endl;
         
         if (p==1){
         cout<<"25. Enter to if legend with p="<< p <<endl;
         legend->AddEntry(h,Hist[i-1],"l");
         legend->Draw();
         }
         if (p==2){
         cout<<"26. Enter to if legend with p="<< p <<endl;
         legend1->AddEntry(h,Hist[i-1],"l");
         legend1->Draw();
         }
         if (p==3){
         cout<<"27. Enter to if legend with p="<< p <<endl;
         legend2->AddEntry(h,Hist[i-1],"l");
         legend2->Draw();
         }
         
          p++;
         cout<<"23.raise p="<< p << endl;
         
         gDirectory->cd("../../../");
         cout<<"28. Come back to the dorectory"<<endl;
	 gStyle->SetOptStat(0);
         cout<<"29. Erase the statics box"<<endl;
      
      } else {
      
         cout<<"30. Enter to else structure with i="<< i <<endl;
         h->Draw("SAME");  
         cout<<"31. Draw the histogram"<<endl;

        if (p==1){
         cout<<"32. Enter to if legend with p="<< p <<endl;
         legend->AddEntry(h,Hist[i-1],"l");
         }
         if (p==2){
         cout<<"33. Enter to if legend with p="<< p <<endl;
         legend1->AddEntry(h,Hist[i-1],"l");
         }
         if (p==3){
         cout<<"34. Enter to if legend with p="<< p <<endl;
         legend2->AddEntry(h,Hist[i-1],"l");
         }
         
         
	 gDirectory->cd("../../../");
         cout<<"35. Come back to the dorectory"<<endl;
      }
   }
   
}
