CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o menu.o character.o barbarian.o game.o vampire.o bluemen.o medusa.o harrypotter.o

SRCS = main.cpp menu.cpp character.cpp barbarian.cpp game.cpp vampire.cpp bluemen.cpp medusa.cpp harrypotter.cpp

HEADERS = menu.hpp character.hpp barbarian.hpp game.hpp vampire.hpp bluemen.hpp medusa.hpp harrypotter.hpp

all: prog

prog: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o prog

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o prog
