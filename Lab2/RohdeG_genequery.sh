#!/bin/bash

# gene query

echo "Gene sequence: "
read geneSequence

for i in {0..6}
do
    if grep -Fq "$geneSequence" supressed_genes_${i}.txt
    then 
        echo "Time ${i} gene is Supressed"
    elif grep -Fq "$geneSequence" stationary_genes_${i}.txt
    then
        echo "Time ${i} gene is Stationary"
    elif grep -Fq "$geneSequence" expressed_genes_${i}.txt
    then
        echo "Time ${i} gene is Expressed"
    else
        echo "uh oh"
    fi
done