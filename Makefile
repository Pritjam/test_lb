hello:
	gcc src/hello.c src/private.o
	mv a.out build/hello

clean:
	rm -f build/hello
	rm -f out.log

deploy: clean hello
	build/hello > out.log