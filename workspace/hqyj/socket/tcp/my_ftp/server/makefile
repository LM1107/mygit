server:main.o server.o Passwd.o
	gcc main.o server.o Passwd.o -o server -lsqlite3
main.o:main.c
	gcc -c main.c
server.o:server.c
	gcc -c server.c
Passwd.o:Passwd.c
	gcc -c Passwd.c
clean:
	rm *.o