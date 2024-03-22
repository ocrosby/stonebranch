demo: src/main.c
	gcc -o demo src/main.c

run: demo
	./demo

test: clean demo
	./demo

clean:
	rm -f demo
	rm -f *.o
