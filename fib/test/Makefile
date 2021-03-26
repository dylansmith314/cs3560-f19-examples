CXXFLAGS=-I../lib -I../

all: build runall

build: test_fib

test_fib: test_fib.o fib.o
	$(CXX) -o test_fib $^

fib.o: ../fib.cc ../fib.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

test_fib.o: test_fib.cc ../fib.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

runall:
	./test_fib

clean:
	-rm -f test_fib *.o