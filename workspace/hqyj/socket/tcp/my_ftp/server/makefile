server:main.o server.o Passwd.o pool.o que.o
	gcc main.o server.o Passwd.o pool.o que.o -o server -lsqlite3 -lpthread
main.o:main.c
	gcc -c main.c
server.o:server.c
	gcc -c server.c
Passwd.o:Passwd.c
	gcc -c Passwd.c
pool.o:pool.c
	gcc -c pool.c
que.o:que.c
	gcc -c que.c
clean:
	rm *.o