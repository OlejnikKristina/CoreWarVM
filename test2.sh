pl1="/Users/krioliin/Desktop/corewar/VM/examples/bee_gees.cor"
i="3950"
while [$i -lt $1]
do
	./VM/corewar pl1 -dump $i > diff/your_output
	./corewar pl1 -dump $i > diff/origin_output
	diff diff/onze_output diff/hun_output
i=$[i + 1]
done
