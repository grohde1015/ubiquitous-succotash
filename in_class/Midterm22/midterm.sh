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

#echo $mainStr
mainForMake=$( echo "${mainStr}" | sed 's/.cpp//g' )
#echo $mainForMake

# now that we have the files plus know the main file, we can echo stuff to Makefile
# note that tab is for each command
# taking each cpp then seeing if it has an hpp 

# issue with argument $@ so making a variable thats the argument for makefile
echo "UHH = $@" >> Makefile

numFiles=$( echo "${fileNames}" | grep -o "\." | wc -l )

# iterate through string based on number of files then deleting as i go through
for((i=1;i<=${numFiles};i++))
do 
    tempString=${fileNames}
    #echo ${tempString}
    tempSub=$(echo $tempString | cut -d' ' -f ${i})
    #echo ${tempSub}

    # cpp 
    if [[ "$tempSub" == *".cpp" ]]
    then
        oPartcpp=${tempSub}
        oPartCut=$( echo "${tempSub}" | sed 's/.cpp//g' )
    elif [[ "$tempSub" == *".hpp" ]]
    # hpp
    then
        oParthpp=${tempSub}
        #echo "hpp: ${oParthpp}"
    else
        echo "oh error checking"
    fi

    # making sure main isnt duplicated
    if [[ "$oPartCut" == "$mainForMake" ]]
    then   
        echo "${oPartCut}.o: ${oPartcpp} ${oParthpp}" >> Makefile
        echo -e "\tg++ -o UHH $^" >> Makefile
    else
        echo "${oPartCut}.o: ${oPartcpp} ${oParthpp}" >> Makefile
        echo -e "\tg++ -c $^" >> Makefile
    fi

done

# parse through makefile to check if there are any 
# repeated .o files (which there are) and i would delete 
# the first instance of the repeated .o plus the line
# below it--i need to delete the first instance since theres 
# a weird formatting issue with how i currently implemented the makefile 
# just ran out of time to make it work :( 

# possible idea though: use uniq -d to display only duplicates, then go 
# through file and delete first occurance of that plus line after 




# able to print to makefile with tabs and commands
echo "all: ${mainForMake}.o" >> Makefile
echo "clean:" >> Makefile
echo -e "\t-rm -f *.o" >> Makefile
echo -e	"\t-rm -f *.gch" >> Makefile