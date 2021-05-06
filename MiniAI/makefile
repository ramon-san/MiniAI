#makefile for perceptron.exe

.PHONY = all clean PRINT

CC = gcc
LINKERS = -lm
FLAGS = -C0

#variables
#funciones
deps = $(wildcard *.c)
BINS = $(deps:%.c=%.o)

all: ${BINS} perceptron.exe

${BINS}: ${deps}
	@echo "\nGenerating binary objects"
	${CC} -c $^

perceptron.exe: ${BINS}
	@echo "\nGenerating executable"
	${CC} $^ -o $@ ${LINKERS}
	@echo "\n"

clean:
	@echo "\nRemoving all binary and executable files\n"
	@rm -rvf *.o
	@rm -rvf *.exe
	@echo "\n"
