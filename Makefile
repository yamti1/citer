build:
	gcc -g ./src/*.c -o main.out

run: build
	./main.out

clean:
	rm ./main.out