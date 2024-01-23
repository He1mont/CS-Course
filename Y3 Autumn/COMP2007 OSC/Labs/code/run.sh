# connect ssh
ssh -J scygs2@canal.cs.nott.ac.uk:2222 scygs2@bann
ssh -J scyjc8@canal.cs.nott.ac.uk:2222 scyjc8@bann

# start docker
docker run -it --rm -v .:/proj bann
docker run -it --rm -v .:/proj gcc_new
scl enable devtoolset-7 bash

gcc -std=gnu99 task09.c -g
gcc -std=gnu99 simulator10.c -g -lpthread -fsanitize=ddress

rm -rf ../out/ && mkdir ../out/

for i in {1..20}; do
    ./a.out
done

for i in {1..50}; do
    echo "running $i";
    ./a.out > "../out/output${i}.txt";
done

valgrind --leak-check=full ./a.out > output.txt
valgrind --leak-check=full --show-leak-kinds=all ./a.out > output.txt

# use valgrind to check memory leak
for i in {1..50}; do
    valgrind --leak-check=full ./a.out > ../out/output${i}.txt 2>&1
done