#! bin/sh
# Gabbie Rohde
# bash code for making a makefile for arbitrary directory

# create makefile 
touch Makefile

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


# checking each file and saving it depending on if it has main or not
for i in "${fileNames}"
do
    # looks for file containing main
    if grep -iq 'main' ${i} 
    then
        mainStr=$( grep -i 'main' ${i} | sed 's/\:.*//g' )
        files=${i}
    else
        temp=${i}
    fi
done

echo $mainStr

# now that we have the files plus know the main file, we can echo stuff to Makefile
# note that tab is for each command
# taking each cpp then seeing if it has an hpp 
for file in "$fileNames" 
    
