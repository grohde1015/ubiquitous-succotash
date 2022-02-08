#! bin/sh

# Gabbie Rohde
# Date: February 8, 2022
# This is the script about IO stuff


echo "Enter concentration: "
read concentration
echo "Concentration is ${concentration}"

touch allData.txt

##cat ERP0[concentration]??.*txt >> allData.txt

cat /home/rohdeg/Git/ubiquitous-succotash/Lab1/EEG_DATA/ERP0${concentration}??*.txt > allData.txt

mv ./allData.txt ./EEG_DATA/allData.txt

touch catted_input.dat
cp ./EEG_DATA/allData.txt ./catted_input.dat

g++ -o stats_test RohdeG_stats_test.cpp
touch HISTOGRAM_${concentration}_.txt

./stats_test "./catted_input.dat" 
./stats_test "./catted_input.dat" > HISTOGRAM_${concentration}_.txt

mv ./HISTOGRAM_${concentration}_.txt ./EEG_DATA/HISTOGRAM_${concentration}_.txt

echo "File Location: "
readlink -f ./HISTOGRAM_${concentration}_.txt