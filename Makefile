all:
	mkdir -p bin/
	g++ src/Programa1.cpp -o bin/programa1
	g++ src/Programa2.cpp -o bin/programa2

clean:
	rm bin/* -rf