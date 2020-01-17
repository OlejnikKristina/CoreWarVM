mkdir -p compare

filename="${1%.*}"

./vm_champs/asm $1
xxd -p $filename.cor > compare/$filename.diff1
rm -f $filename.cor

./asm $1
xxd -p $filename.cor > compare/$filename.diff2

diff compare/$filename.diff1 compare/$filename.diff2 > compare/$filename.result
