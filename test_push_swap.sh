for ((c = 6;c < 500;c++))
do
    ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')");
    gcc *.c -w && ./a.out $ARG | wc -l
done
