#! bin/sh

# arguments taken in
echo "Enter header: "
read header

echo "Reference country name: "
read refCountry

echo "Comparison country:"
read compCountry

fileSize=$( wc -l < owid-covid-data.csv )
# getting ref country data as array
echo $fileSize

for (( i=0;i<$fileSize;i++ ))
do
    if sed 's/${refCountry}//g' -eq 1 
    then
        echo "hi"
    fi
done