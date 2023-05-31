#@author mb
#Compatible by interface with r.cmd.
#Unsure if it is ever called that way.

if [[ "$1" == "clean" ]]
then
    rm -f *.log *.mpx
    STOP=0
    for (( i = 1 ; $STOP == 0 ; ++i ))
    do
        for j in *.$i
        do
            if [[ -f "$j" ]]
            then
                rm "$j"
            else
                STOP=1
            fi
        done
    done
else
    for i in *.mp
    do
        if [[ -f "$i" ]]
        then
            if [[ $i != "hatching.mp" ]]
            then
                #TeXLive uses this one
                mpost "$i"
            fi
        fi
    done
fi

