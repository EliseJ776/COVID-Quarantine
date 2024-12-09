all: main.out

run: main.out
	./main.out

main.out: main.cpp Date.cpp calcDays.cpp
	g++ -Wall main.cpp Date.cpp calcDays.cpp -o main.out

clean:
	rm -f main.out