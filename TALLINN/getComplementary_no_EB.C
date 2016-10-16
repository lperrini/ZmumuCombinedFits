#include "TH1.h"

void getComplementary_no_EB(){

	TString files_in[]   = {"ztt_mt.inputs-sm-13TeV.root"} //datacard from tau_mu-tau_had (mutau) event selection
	TString files_ou[]   = {"ztt_mt.input-sm-13TeV.root"}
	TString dirs[]       = {"inclusive","0jet","1jet_zpt_loose","1jet_zpt_medium","1jet_zpt_tight","2jet_cp","vbf","1bjet","2bjet","MSSM_btag"};
	TString channels[]   = {"mt_"};
	TString processes[]  = {"data_obs","VV","TT","ZTT","ZLL","W","QCD","VBFH125","GGH125","EWKW"}
        //NB: in the mutau channel, the ZTT has to be treated as a signal in all the categories, therefore ZTT --> ZTTsig 
	TString processes2[] = {"data_obs","VV","TT","ZTTsig","ZLL","W","QCD","VBFH125","GGH125","EWKW"}
        //### good systematics for mutau selection
        TString postfix2[]   = {"","_TESUp","_TESDown","_MESUp","_MESDown","_JECUp","_JECDown","_bTagUp","_bTagDown","_RWeight1Up","_RWeight1Down","_RWeight2Up","_RWeight2Down"}
	
        int ncat=10;
	int npro=10;
	int npos=13;
        TString postfix="";

        
	for(int fi=0;fi<1;fi++){
		TFile *f1 = new TFile(files_in[fi],"r");
		TFile *f2 = new TFile(files_ou[fi],"recreate");
                postfix="";
		for(int i=0;i<ncat;i++){
			f2->cd();
			f2->mkdir(channels[fi]+dirs[i]);
			f2->cd(channels[fi]+dirs[i]);
			for(int j=0;j<npos;j++){
				postfix = postfix2[j];
				for(int k=0;k<npro;k++){
					TH1F *h = (TH1F*)f1->Get(channels[fi]+dirs[i]+"/"+processes[k]+postfix);
					string name = h->GetName();
                                        if(name.find("ZTT") != string::npos){
                                            TString newname = "ZTTsig"+postfix;
                                            h->SetName(newname);
                                            h->Write();
                                        }else h->Write();
				} 
			} 
		} //first thing done: you have renamed the process ZTT as ZTTsig in all the categories. 

                //Now we want to create additional categories, the complementary to the inclusive --> example: 0jet_comp = inclusive = 0jet 
                //This is crucial for the combined fit in which we will fit simultaneously the fail region (inclusive-exclusive=comp) and the pass region (exclusive).
        
		for(int i=1;i<ncat;i++){ //NB: now you start the loop from 1, which means you are excluding the inclusive category
			f2->cd();
			f2->mkdir(channels[fi]+dirs[i]+"_comp");
			f2->cd(channels[fi]+dirs[i]+"_comp");
			for(int j=0;j<npos;j++){
				postfix = postfix2[j];
				for(int k=0;k<npro;k++){
                                        
					TH1F *hincl = (TH1F*)f1->Get(channels[fi]+"inclusive/"+processes2[k]+postfix);
					TH1F *hexcl = (TH1F*)f1->Get(channels[fi]+dirs[i]+"/"+processes2[k]+postfix);
					TH1F* hcomp = (TH1F*)hincl->Clone();
					hcomp->Add(hexcl,-1);
					float oldIntegral=hcomp->Integral();
					TH1F* hcomp2 = (TH1F*)hincl->Clone();

                                        cout << " cat " << dirs[i] << " Process " << processes2[k] << " SYS " << postfix << endl;
                                        for(int ii=0;ii<hcomp->GetXaxis()->GetNbins()+1;ii++){
                                            cout << " bin " << ii << " inclusive = " << hincl->GetBinContent(ii) << endl;
                                            cout << " bin " << ii << " exclusive = " << hexcl->GetBinContent(ii) << endl;
                                            cout << " bin " << ii << " OLD comp  = " << hcomp->GetBinContent(ii) << endl;
                                            double bincontent = hincl->GetBinContent(ii) - hexcl->GetBinContent(ii);
                                            double binerror = TMath::Sqrt(TMath::Power(hincl->GetBinError(ii),2) + TMath::Power(hexcl->GetBinError(ii),2));
                                            double newbincontent;
                                            double newbinerror;
                                            if(bincontent<0){
                                                   float diff=0.1-bincontent;
                                                   float newErr=TMath::Sqrt(TMath::Power(binerror,2)+TMath::Power(diff,2));
                                                   newbincontent=0.1;
                                                   newbinerror=newErr;
                                            }else{
                                                   newbincontent=bincontent;
                                                   newbinerror=binerror;
                                            }
                                               
                                            hcomp2->SetBinContent(ii,newbincontent);
                                            hcomp2->SetBinError(ii,newbinerror);

                                            /*cout << " bin " << ii << " NEW comp2  = " << hcomp2->GetBinContent(ii) << endl;
                                            if(hcomp->GetBinContent(ii)<0){
                                                int oldContent=hcomp->GetBinContent(ii);
                                                float diff=0.1-oldContent;
                                                float oldErr=hcomp->GetBinError(ii);
                                                float newErr=TMath::Sqrt(TMath::Power(oldErr,2)+TMath::Power(diff,2));

                                                hcomp->SetBinContent(ii,0.1);
                                                hcomp->SetBinError(ii,newErr);
                                                cout << " bin " << ii << " NEW comp  = " << hcomp2->GetBinContent(ii) << endl;
                                            }*/
                                        }
                                        hcomp2->Scale(oldIntegral/hcomp2->Integral());
                                        hcomp2->Write();
				} 
			} 
		}
 
		f2->Close();
	}
}
