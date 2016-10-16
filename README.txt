###check-out the code
export SCRAM_ARCH=slc6_amd64_gcc481
mkdir working_dir
cd working_dir
scram project CMSSW CMSSW_7_1_5
cd CMSSW_7_1_5/src
cmsenv
git clone https://github.com/cms-analysis/HiggsAnalysis-CombinedLimit.git HiggsAnalysis/CombinedLimit
git clone https://github.com/cms-analysis/CombineHarvester.git CombineHarvester
git clone https://github.com/lperrini/ZmumuCombinedFits.git tmp
mv tmp/BuildFile.xml CombineHarvester/CombineTools/bin/
mv tmp/*.cpp CombineHarvester/CombineTools/bin/
mkdir auxiliaries/      
mkdir auxiliaries/shapes
mv tmp/TALLINN/ auxiliaries/shapes/
mv tmp/output .
mkdir CombineHarvester/ZtautauRatio
mv tmp/* CombineHarvester/ZtautauRatio/
rm -rf tmp/

scram b -j 9

###########################################################################
#### NB: you have already all the datacards, fit and plot results stored
#### datacards --> auxiliaries/shapes/TALLINN && output/cards/
#### fits --> CombineHarvester/ZtautauRatio/fit_XXX_CHANNEL_XXX
#### plots --> CombineHarvester/ZtautauRatio/plots_XXX_CHANNEL_XXX
###########################################################################
### if you want to rerun the fit, follow the steps below

###datacards are located in
auxiliaries/shapes/TALLINN
### those with *input-sm.* are the ones to be used to run the fit. These root
### files contain already the inclusive-exclusive directories
### the original datacards as they come from the main analysis are *inputs-sm.*
### you can obtain *input-sm.* from *inputs-sm.* running

root -l getComplementary_no_EB.C ### without embedding
root -l getComplementary_EB.C ### with the embedding

### codes to create *.txt datacards are in CombineHarvester/CombineTools/bin/
### from working_dir/CMSSW_7_1_5/src run the exclutables

ZtautauInclusiveEmbedding
ZtautauExclusiveEmbedding

### you have to do this channel by channel
### you will get datacards for each category in 
### output/cards/

###perform the fit
cd CombineHarvester/ZtautauRatio/script
mkdir ../../../output/cards/cmbcards_XXX_CHANNEL_XXX
### before running all these scripts be sure you are pointing to the correct
### channel

sh combineCards.sh
sh createWorskspace.sh
mkdir ../fit_XXX_CHANNEL_XXX
sh runMLfit.sh
mkdir ../output_XXX_CHANNEL_XXX
runPostfit.sh
python drawPostfit.py
mkdir ../plots_XXX_CHANNEL_XXX
mv mvis* ../plots_XXX_CHANNEL_XXX








