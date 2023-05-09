#Archivo para construir el programa Hola Mundo
#Autor: Paulo Ogando Gulias

CC = g++

#Encargado de hacer el "linking" (enlace entre biblioteca estandar y documento)
hello: hello.o
	$(CC) hello.o -o hello
	./hello

#Encargado de compilar
hello.o: hello.cpp
	echo Voy a compilar
	$(CC) -c hello.cpp

clean:
#No colocar archivos .cpp
	rm -f hello hello.o
