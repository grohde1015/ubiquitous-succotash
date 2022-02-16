#! bin/sh

# Gabbie Rohde 
# Date: February 16, 2022
# This script is about bash conditionals


oh="Oh-oh-oh-oh-oh, oh-oh-oh-oh, oh-oh-oh"
caught="Caught in a bad romance"
rah="rah rah oh oh oh"
gaga="Gaga Ooh la-la"
roma="roma roma ma"
want="want your bad romance"
i=1
for i in {1..12}
do
    if [[ ($i -eq 1) || ($i -eq 3) ]] 
    then
        echo $oh
    elif [[ ($i -eq 2) || ($i -eq 4) ]] 
    then 
        echo $caught
    elif [[ ($i -eq 5) || ($i -eq 9) ]] 
    then 
        echo $rah
    elif [[ ($i -eq 7) || ($i -eq 11) ]] 
    then 
        echo $gaga
    elif [[ ($i -eq 6) || ($i -eq 10) ]] 
    then 
        echo $roma
    elif [[ ($i -eq 8) || ($i -eq 12) ]] 
    then 
        echo $want
    else
        echo $i
fi
done


# while IFS = read_line
