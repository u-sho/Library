CXXFLAGS := -std=c++17 -Wall

%: %.cpp
	/usr/local/bin/g++ $(CXXFLAGS) $< -o ./bin/$@
