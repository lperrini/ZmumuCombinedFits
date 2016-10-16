#fit 1
PostFitShapesFromWorkspace -d ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_0jet_1.txt -w ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_0jet_1.root -o ../outputs_wTauSpinner_embedding/ztt_mm.output-sm-13TeV-0jet.root -f ../fit_wTauSpinner_embedding/mlfit_mm_0jet_1.root:fit_s --postfit --sampling --print

#fit 2
PostFitShapesFromWorkspace -d ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_1jet_zpt_loose_2.txt -w ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_1jet_zpt_loose_2.root -o ../outputs_wTauSpinner_embedding/ztt_mm.output-sm-13TeV-1jet_zpt_loose.root -f ../fit_wTauSpinner_embedding/mlfit_mm_1jet_zpt_loose_2.root:fit_s --postfit --sampling --print

#fit 3
PostFitShapesFromWorkspace -d ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_1jet_zpt_medium_3.txt -w ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_1jet_zpt_medium_3.root -o ../outputs_wTauSpinner_embedding/ztt_mm.output-sm-13TeV-1jet_zpt_medium.root -f ../fit_wTauSpinner_embedding/mlfit_mm_1jet_zpt_medium_3.root:fit_s --postfit --sampling --print

#fit 4
PostFitShapesFromWorkspace -d ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_1jet_zpt_tight_4.txt -w ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_1jet_zpt_tight_4.root -o ../outputs_wTauSpinner_embedding/ztt_mm.output-sm-13TeV-1jet_zpt_tight.root -f ../fit_wTauSpinner_embedding/mlfit_mm_1jet_zpt_tight_4.root:fit_s --postfit --sampling --print

#fit 5
PostFitShapesFromWorkspace -d ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_2jet_cp_5.txt -w ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_2jet_cp_5.root -o ../outputs_wTauSpinner_embedding/ztt_mm.output-sm-13TeV-2jet_cp.root -f ../fit_wTauSpinner_embedding/mlfit_mm_2jet_cp_5.root:fit_s --postfit --sampling --print

#fit 6
PostFitShapesFromWorkspace -d ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_vbf_6.txt -w ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_vbf_6.root -o ../outputs_wTauSpinner_embedding/ztt_mm.output-sm-13TeV-vbf.root -f ../fit_wTauSpinner_embedding/mlfit_mm_vbf_6.root:fit_s --postfit --sampling --print

#fit 7
PostFitShapesFromWorkspace -d ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_1bjet_7.txt -w ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_1bjet_7.root -o ../outputs_wTauSpinner_embedding/ztt_mm.output-sm-13TeV-1bjet.root -f ../fit_wTauSpinner_embedding/mlfit_mm_1bjet_7.root:fit_s --postfit --sampling --print

#fit 8
PostFitShapesFromWorkspace -d ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_2bjet_8.txt -w ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_2bjet_8.root -o ../outputs_wTauSpinner_embedding/ztt_mm.output-sm-13TeV-2bjet.root -f ../fit_wTauSpinner_embedding/mlfit_mm_2bjet_8.root:fit_s --postfit --sampling --print

#fit 9
PostFitShapesFromWorkspace -d ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_MSSM_btag_9.txt -w ../../../output/cards/cmbcards_wTauSpinner_embedding/ztt_mm_MSSM_btag_9.root -o ../outputs_wTauSpinner_embedding/ztt_mm.output-sm-13TeV-MSSM_btag.root -f ../fit_wTauSpinner_embedding/mlfit_mm_MSSM_btag_9.root:fit_s --postfit --sampling --print














