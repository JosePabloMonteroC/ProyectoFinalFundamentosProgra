principal.exe: ../Bibliotecas/funciones.o principal.o
	gcc ../Bibliotecas/funciones.o principal.o -o principal

principal: principal.c ../Bibliotecas/funciones.h
	gcc -c principal.c
