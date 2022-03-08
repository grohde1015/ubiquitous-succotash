#! bin/sh
# Gabbie Rohde
# bash code for making a makefile for arbitrary directory


input=$1

# double check to make sure input exists
if [ ! -e $input ]

then   
    echo "directory to $input does not exist"
    exit 1
fi

# for loop for making array of file names
cd ${input}
fileNames=$(ls)

count=0
# checking each file and saving it depending on if it has main or not
for i in "${fileNames}"
do
    # looks for file containing main
    if grep -iq 'main' ${i} 
    then
        mainStr=$( grep -i 'main' ${i} | sed 's/\:.*//g' )
        files[count]=${i}
    else
        temp[count]=${i}
    fi
    ((count=count+1))
done

echo $mainStr
mainForMake=$( echo "${mainStr}" | sed 's/.cpp//g' )
echo $mainForMake

# now that we have the files plus know the main file, we can echo stuff to Makefile
# note that tab is for each command
# taking each cpp then seeing if it has an hpp 

numFiles=$( echo "${fileNames}" | grep -o "\." | wc -l )

# iterate through string based on number of files then deleting as i go through
for((i=0;i<${numFiles};i++))
do 
    tempString=${fileNames}
    echo ${tempString}
    

done




# able to print to makefile with tabs and commands
echo "all: ${mainForMake}.o" >> Makefile
echo "clean:" >> Makefile
echo -e "\t-rm -f *.o" >> Makefile
echo -e	"\t-rm -f *.gch" >> Makefile