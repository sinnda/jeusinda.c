prog:*.h *.c
	gcc *.h *.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lm  -o prog -g 
main.o:main.c
	gcc -c main.c -g
fonction.o:fonction.c
	gcc -c menu.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
