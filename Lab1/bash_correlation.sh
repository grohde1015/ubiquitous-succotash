#! bin/sh

# Gabbie Rohde
# Date: February 9, 2022
# Calculating correlation coefficient between epochs of data 

echo "Enter concentration (either 0 or 5): "
read concentration
echo "Concentration is ${concentration}"

if [ -f conc_corr_0${concentration}.csv ]
then 
    rm conc_corr_0${concentration}.csv
fi

g++ -o corr_test RohdeG_corr_test.cpp

if [ ${concentration} == 0 ]  
then 
    touch conc_corr_0${concentration}.csv
    for i in {1..59}
    do
        echo -n "${i} vs $((i+1))," >> conc_corr_0${concentration}.csv
        ./corr_test "./EEG_DATA/ERP0${concentration}${i}.txt" "./EEG_DATA/ERP0${concentration}$((i+1)).txt"  >> conc_corr_0${concentration}.csv
    
done

elif [ ${concentration} == 5 ]
then 
    touch conc_corr_0${concentration}.csv
    for i in {1..59}
    do
        echo -n "${i} vs $((i+1))," >> conc_corr_0${concentration}.csv
        
        ./corr_test "./EEG_DATA/ERP0${concentration}.${i}.txt" "./EEG_DATA/ERP0${concentration}.$((i+1)).txt" >> conc_corr_0${concentration}.csv

done

else
    echo "Invalid argument. Enter concentration as 0 or 5"
    exit 1
fi 


