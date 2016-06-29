CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

#CXXFLAGS += =03
LDFLAGS = -lboost_date_time

OBJS = creature.o barbarian.o bluemen.o harrypotter.o medusa.o vampire.o lineup.o pile.o game.o main.o 

SRCS = creature.cpp barbarian.cpp bluemen.cpp harrypotter.cpp medusa.cpp vampire.cpp lineup.cpp pile.cpp game.cpp main.cpp

HEADERS = creature.hpp barbarian.hpp bluemen.hpp harrypotter.hpp medusa.hpp vampire.hpp lineup.hpp pile.hpp game.hpp 

#target: dependencies
#	rule to build 
#	

dieGame: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o game4

${OBJS}: ${SRC}
	${CXX} ${CXXFLAGS} ${SRCS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} game4
