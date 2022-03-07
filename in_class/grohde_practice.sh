#! bin/sh

# wget https://raw.githubusercontent.com/grohde1015/ubiquitous-succotash/main/Lab1/RohdeG_stats.cpp

touch newFile.txt

# class name to text
class=$( grep -w "include" "RohdeG_stats.cpp" | sed 's/#include//g' )
echo "Class : $class" > newFile.txt

# namespace to text
namespaceVar=$( grep -w "namespace" "RohdeG_stats.cpp" | sed -e 's/using namespace \(.*\);/\1/' )

echo "Namespace: $namespaceVar" >> newFile.txt


# I am not sure why but it's not making a new line 
var=$( grep "GabeTheBabe::" "RohdeG_stats.cpp" | sed 's/.*GabeTheBabe\(.*\){.*/\1/' | sed 's/.*::\(.*\)::/\1/' )
newVar="${var//') '/')\n'}"
echo $newVar >> newFile.txt


# in class example from 3/7
#readarray -t caps < "../captains.txt"

#for ((i=0;i< ${#caps[@]}; i++ ))
#do
#    echo "does it contain a s"
#    echo ${caps[$i]} | grep "s" -c # counts number of s 