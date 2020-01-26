    #!/bin/bash

    PATH_YOUR_CW="./CoreWarYours/corewar_kristinas"
    PATH_ORGN_CW="./CoreWarOrigin/corewar"
    PATH_PLAYERS="./champions/"

    players=("zork" "bee_gees" "bigzork" "turtle" "fluttershy" "helltrain" "toto" "doge" "Gagnant")

    function    test_players()
    {
		CYCLES=10000

        for player in ${players[@]}
        do
            for (( i=1; i <= $CYCLES; i+=10))
            do
                $PATH_ORGN_CW $PATH_PLAYERS+$player+".cor" -d $i | sed -n -e '/^0x/p' > diff/origin_output1
                $PATH_YOUR_CW PATH_PLAYERS+$player+".cor" -dump $i | sed -n -e'/^0x/p' > diff/yours_output2
                if ! cmp -s "diff/origin_output1" "diff/yours_output2"; then
				 	printf '\033[0m[%10s] ' "$player"
					((i=i-1))
                    printf "\033[0;31mmemory is NOT the same at cycle [%d]\n\033[0m" "$i" ;
                fi
            done
                printf '\033[0m[%10s] ' "$player"
				((i=i-1))
                printf '\033[0;32mPerfect! Memory is the same at all cycles until %s\n\033[0m' "$i"
        done
    }

	if [ $1 == "-help" ] ; then
        echo "usage: sh vm_tester.sh <filename1.cor> <filename2.cor> <cycles>"
		exit 1
    elif [ $# -lt 2 ] ; then
       test_players
	   exit 1
    fi

    CYCLES=${@: -1}
    n=$(($# - 1))
    for arg do
      [ "$n" -gt 0 ] && set -- "$@" "$arg"
      shift
      n=$((n - 1))
    done
    for arg do
        if [ ! -f $arg ]; then
            echo "error: file $arg does not exist" ; exit 1
        fi
    done
    re='^[0-9]+$'
    if ! [[ $CYCLES =~ $re ]]; then
        echo "error: $CYCLES is not a number" >&2 ; exit 1
    fi
    for (( i=1; i <= $CYCLES; i+=10))
    do
        $PATH_ORGN_CW $@ -d $i | sed -n -e '/^0x/p' > diff/origin_output1
        $PATH_YOUR_CW $@ -dump $i | sed -n -e'/^0x/p' > diff/yours_output2
        if ! cmp -s "diff/origin_output1" "diff/yours_output2"; then
            printf "\033[0;31mmemory is NOT the same at cycle [%d]\n\033[0m" "$i" ; exit 1
        fi
    done
        printf '\033[0;32mperfect! memory is the same at all cycles until %s\n\033[0m' "$CYCLES"
