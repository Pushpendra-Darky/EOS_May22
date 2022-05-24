(CC)=gcc
exe: main.o add.o sub.o mul.o divs.o
	$(CC) -o exe main.o add.o sub.o mul.o divs.o
main.o:main.c
	$(CC) -c -o main.o main.c
add.o:add.c
	$(CC) -c -o add.o add.c
sub.o:sub.c
	$(CC) -c -o sub.o sub.c
mul.o:mul.c
	$(CC) -c -o mul.o mul.c
div.o:div.c
	$(CC) -c -o divs.o divs.c
run:
	./exe
clean:
	rm -rf *.o exe