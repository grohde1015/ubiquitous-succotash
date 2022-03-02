# prompts user for number of microarray points to be read and processed
# calibrates data from each of 7 time points
# script copies log ratio out to log_ratio_input.dat
# cluster output files to files with clear name
# summary file of cluster means and total numbers of sup, stat, and exp genes

make all

echo "Number of microarray points: "
read numMicroPoints

if [ ${numMicroPoints} -ne 6118 ]
then
    echo "Incorrect number of points"
    exit 1
fi

# making sure log file does not already exist 
if [ -f "log_ratio_input.dat" ]
then
    rm -r "log_ratio_input.dat"
    echo "deleting log file"
fi 

# making sure summary does not already exist
if [ -f "summaryData.dat" ]
then
    rm -r "summaryData.dat"
    echo "deleting summaryData file"
fi 

# calibrate data for each of 7 logs -- log_ratio_[0-6].dat and pre_processing

for i in {0..6}
do
    ./RohdeG_pre_processing.o "red_${i}.dat" "red_background_${i}.dat" "green_${i}.dat" "green_background_${i}.dat" "log_ratio_input_${i}.dat" ${numMicroPoints}

    # putting log to file 
    cp log_ratio_input_${i}.dat log_ratio_input.dat
    # summary file that lists the final cluster means and the total number of expressed, supressed, and stationary

    ./RohdeG_k_means.o "log_ratio_input_${i}.dat" >> summaryData.txt 

    echo Number of supressed genes:  $(wc -l supressed_genes.txt) >> summaryData.txt
    echo Number of stationary genes:  $(wc -l stationary_genes.txt) >> summaryData.txt
    echo Number of expressed genes:  $(wc -l expressed_genes.txt) >> summaryData.txt

    touch supressed_genes_${i}.txt
    touch stationary_genes_${i}.txt
    touch expressed_genes_${i}.txt

    cp supressed_genes.txt supressed_genes_${i}.txt
    cp stationary_genes.txt stationary_genes_${i}.txt
    cp expressed_genes.txt expressed_genes_${i}.txt

done 