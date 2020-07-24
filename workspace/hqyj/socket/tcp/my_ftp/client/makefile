server:main.o client.o
	gcc main.o client.o -o client
main.o:main.c
	gcc -c main.c
server.o:client.c
	gcc -c client.c
clean:
	rm *.o