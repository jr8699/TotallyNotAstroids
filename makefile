totallynotastroids.exe: main.o common.o com_graphics.o
	gcc -o totallynotastroids.exe main.o common.o com_graphics.o -lGL -lGLU -lglut -lm

main.o: main.c main.h common.h com_graphics.h macros.h
	gcc -c main.c -lm -lGL -lGLU -lglut

common.o: common.c common.h com_graphics.h macros.h
	gcc -c common.c -lm -lGL -lGLU -lglut

com_graphics.o: com_graphics.c com_graphics.h macros.h
	gcc -c com_graphics.c -lm -lGL -lGLU -lglut
