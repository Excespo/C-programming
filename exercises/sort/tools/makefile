final: test.o tools.o
	gcc -o final test.o tools.o
test.o: test.c
	gcc -c test.c
tools.o: tools.c
	gcc -c tools.c
clean:
	rm *.o