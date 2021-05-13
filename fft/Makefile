all:
	gcc main.c
	./a.out 2>&1 | tee main.txt

ref:
	gcc -Wl,--as-needed ref.c
	./a.out 2>&1 | tee ref.txt

clean:
	rm -rf a.out
