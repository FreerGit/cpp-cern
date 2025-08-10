all: asan
solution: asan.sol

clean:
	rm -f *o *so asan *~ asan.sol

asan : asan.cpp
	$(CXX) -std=c++17 -o $@ $^ -fsanitize=address -fno-omit-frame-pointer -g

asan.sol : solution/asan.sol.cpp
	$(CXX) -std=c++17 -o $@ $^
