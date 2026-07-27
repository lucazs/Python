#!/bin/bash

bs() 
{
    baixo=0
    alto=$(( ${#lista[@]} - 1 ))

    i=0

    while [[ baixo -le alto ]]; do
        ((i++))
        echo "$i - vez."
        
        meio=$(( (baixo+alto) ))
        chute=${lista[meio]}

        (( chute == item )) && { 
                echo "Item $chute encontrado no índice $meio em $i iterações.";
                exit
            }

        (( chute > item )) && { alto=$(( meio - 1 )); continue; }

        baixo=$(( meio + 1))
    done

    return -1
}

item=$1
shift
lista=("$@")
bs || { echo "Item não encontrado após $i iterações..."; exit -1; }
