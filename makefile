cc = g++ -std=c++11
main = miglior_sequenza
obj = miglior_sequenza.o
CF = -O0 -c -fprofile-arcs -ftest-coverage
testcases = basic exception
SRCS := $(shell find . -name *.cpp

all: $(obj)
	$(cc) -o $(main) $(obj) -fprofile-arcs -ftest-coverage -lgcov

main.o: $(SRCS)
	$(cc) $(CF) $(SRCS)


.PHONY: clean cleanall test $(testcases)

clean:
	rm $(obj)

cleanall:
	rm -f $(obj)
