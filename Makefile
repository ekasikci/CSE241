target: compile output

compile:
	g++ -std=c++11 hw6.cpp -o hw6
output:
	./hw6
clean:
	rm hw6
