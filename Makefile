all:start
start: main.o algo.o data_struct.o data_struct2.o
	gcc -o start main.o algo.o data_struct.o data_struct2.o
main.o:main.c
	gcc -c main.c
algo.o: algo.c algo.h
	gcc -c algo.c
data_struct.o:data_struct.c data_struct.h
	gcc -c data_struct.c
data_struct2.o:data_struct2.c data_struct2.h
	gcc -c data_struct2.c
clean:
	rm -f *.o
	rm -f start
