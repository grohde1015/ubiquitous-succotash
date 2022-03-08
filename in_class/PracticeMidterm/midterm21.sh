#! bin/sh


# making sure file exists before getting file size
if [ ! -f owid-covid-data.csv ]
then 
    echo "file does not exist"
    exit 1
fi

fileSize=$( wc -l < owid-covid-data.csv )
# getting ref country data as array
echo $fileSize


rowNum=1
while IFS=, read -ra fields; do 

    # first argument
    tempLoc[rowNum]=${fields[2]}
    if [[ ${tempLoc[rowNum]} == *"$2"* ]]
    then 
        echo "${fields[2]},${fields[3]}"
    fi
    ((rowNum=rowNum+1))
done < "owid-covid-data.csv"

