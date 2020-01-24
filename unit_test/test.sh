pl1="/Users/krioliin/Desktop/corewar/VM/examples/bee_gees.cor"
i="7000"
while [ $i -lt $1 ]
do
    ../VM/corewar pl1 -dump $i > hun_output
	./corewar pl1 -dump $i > onze_output
	diff onze_output hun_output

	# ./hun_corewar champs/Gagnant.cor champs/jumper.cor -d $i > hun_output
	# ./corewar champs/Gagnant.cor champs/jumper.cor -d $i > onze_output
	# diff onze_output hun_output

	./hun_corewar champs/maxidef.cor champs/mortel.cor -d $i > hun_output
	./corewar champs/maxidef.cor champs/mortel.cor -d $i > onze_output
	diff onze_output hun_output

	./hun_corewar champs/Octobre_rouge_V4.2.cor champs/sietse.cor -d $i > hun_output
	./corewar champs/Octobre_rouge_V4.2.cor champs/sietse.cor -d $i > onze_output
	diff onze_output hun_output

	# ./hun_corewar champs/slider2.cor champs/toto.cor -d $i > hun_output
	# ./corewar champs/slider2.cor champs/toto.cor -d $i > onze_output
	# diff onze_output hun_output

	./hun_corewar champs/mortel.cor champs/ex.cor -d $i > hun_output
	./corewar champs/mortel.cor champs/ex.cor -d $i > onze_output
	diff onze_output hun_output

i=$[i + 1]
done
