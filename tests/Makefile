CXXFLAGS  = -O2 -m64
CXXFLAGS += -I../src

WARNINGS  = -Wall
WARNINGS += -Wextra
WARNINGS += -pedantic
WARNINGS += -Weffc++
WARNINGS += -std=c++17

all: compile link run
	@echo No errors

compile:
	g++ -c Golden_rc4.cpp -o Golden_rc4.o ${CXXFLAGS} ${WARNINGS}
	g++ -c Test_rc4.cpp -o Test_rc4.o ${CXXFLAGS} ${WARNINGS}
	g++ -c main.cpp -o main.o ${CXXFLAGS} ${WARNINGS}

link:
	g++ Golden_rc4.o Test_rc4.o main.o ../src/rc4func.o -o rc4test.exe ${CXXFLAGS} ${WARNINGS}

run:
	./rc4test.exe
