#! bin/sh

# run bash "Name of file" whatever China Chile

# making sure file exists before getting file size
if [ ! -f owid-covid-data.csv ]
then 
    echo "file does not exist"
    exit 1
fi

# file size
fileSize=$( wc -l < owid-covid-data.csv )
# getting ref country data as array
echo $fileSize
refCountrysum=0.0


rowNum=1 # this is for iterating through the whole file
#https://www.xmodulo.com/read-column-data-text-file-bash.html#:~:text=To%20read%20column%20data%20from%20a%20file%20in%20bash%2C%20you,%2Dof%2Dfile%20is%20reached.
# ifs reads a file and the , is the delimiter
# -ra keeps backslashes and makes each field an array argument to iterate through
while IFS=, read -ra fields; do 

    # first argument temporary location
    tempLoc[rowNum]=${fields[2]}
    if [[ ${tempLoc[rowNum]} == *"$2"* ]]
    then 
        # puts country argument 2 and date field 3 to reference location
        echo "${fields[2]},${fields[3]},${fields[10]}" >> refLocation

        refCountrysum=$(echo "$refCountrysum + ${field[10]}" | bc -l)
        
    fi

    # same as above but looking at 3rd argument instead of 2
    if [[ ${tempLoc[rowNum]} == *"$3"* ]]
    then 
        echo "${fields[2]},${fields[3]},${fields[10]}" >> compLocation
    fi
    ((rowNum=rowNum+1))
done < "owid-covid-data.csv"
    
echo ${refCountrysum}


