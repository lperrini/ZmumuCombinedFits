#include "TH1.h"

void validateComplementary(){

	TString files_in[]={"ztt_mt.input-sm-13TeV.root","ztt_mm.input-sm-13TeV.root"}
	TString input_dir[]={"0jet","1jet_zpt_loose","1jet_zpt_medium","1jet_zpt_tight","2jet_cp","vbf","1bjet","2bjet","MSSM_btag"};
	TString compl_dir[]={"0jet_comp","1jet_zpt_loose_comp","1jet_zpt_medium_comp","1jet_zpt_tight_comp","2jet_cp_comp","vbf_comp","1bjet_comp","2bjet_comp","MSSM_btag_comp"};
	TString channels[]={"mt_","mm_"};
	TString processes[]={"data_obs","VV","TT","ZLL","ZTT","W","QCD","VBF","GG"}
	TString processes1[]={"data_obs","VV","TT","ZLL","ZTT","W","QCD","VBF","GG"}
	TString postfix1[]={"","_TESUp","_TESDown","_MESUp","_MESDown"}
	TString postfix2[]={"","_MESUp","_MESDown","_MRESUp","_MRESDown"}
	int ncat=9;
	int npro=9;
	int npos=5;
        TString postfix="";

	for(int fi=0;fi<2;fi++){
		TFile *f1=new TFile(files_in[fi],"r");
                postfix="";
		for(int i=0;i<(ncat-1);i++){
			for(int j=0;j<npos;j++){
				for(int k=0;k<npro;k++){
                                        if(fi==0){
                                                postfix=postfix1[j];
						processes1[4]="ZTTsig";
					}
					if(fi==1){ 
                                                postfix=postfix2[j];
						processes1[3]="ZLLsig"; 
                                                processes1[4]="ZTT";
					}

                                        //cout << channels[fi]+"inclusive/"+processes[k]+postfix << endl;
                                        //cout << channels[fi]+input_dir[i]+"/"+processes1[k]+postfix << endl;
                                        //cout << channels[fi]+compl_dir[i]+"/"+processes[k]+postfix << endl;

					TH1F *hincl = (TH1F*)f1->Get(channels[fi]+"inclusive/"+processes[k]+postfix);

					TH1F *hin = (TH1F*)f1->Get(channels[fi]+input_dir[i]+"/"+processes1[k]+postfix);
					TH1F *hco = (TH1F*)f1->Get(channels[fi]+compl_dir[i]+"/"+processes[k]+postfix);
                                        for(int cazzo=0;cazzo<hin->GetXaxis()->GetNbins();cazzo++){
                                           if(hincl->GetBinContent(cazzo+1)<0) cout << "histo " << hincl->GetName() << " has bin " << cazzo+1 << " negative" << endl;
                                           if(hin->GetBinContent(cazzo+1)<0) cout << "histo " << hin->GetName() << " has bin " << cazzo+1 << " negative" << endl;
                                           if(hco->GetBinContent(cazzo+1)<0) cout << "histo " << hco->GetName() << " has bin " << cazzo+1 << " negative" << endl;
                                        }
					/*if((hincl->Integral()-hin->Integral())+hco->Integral()<0.001){
						cout << " ALARM !!! " << endl;
						cout << channels[fi]<<"inclusive: "<< hincl->Integral() <<
							" - " << channels[fi] << input_dir[i] << "/" << processes1[k] << postfix << ": "<<hin->Integral() << 
							" - " << channels[fi] << compl_dir[i] << "/" << processes[k] << postfix << ": "<<hco->Integral() << endl; 
					}else{
						cout << " EVERYTHING'S FINE :-) !!! " << endl;
						cout << channels[fi]<<"inclusive: "<< hincl->Integral() <<
							" - " << channels[fi] << input_dir[i] << "/" << processes1[k] << postfix << ": "<<hin->Integral() << 
							" - " << channels[fi] << compl_dir[i] << "/" << processes[k] << postfix << ": "<<hco->Integral() << endl; 
					}*/
				} 
			} 
		} 
	}
}
