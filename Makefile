CXXFLAGS := -std=c++17 -Wall -Wextra $(CXXFLAGS)

%: %.cpp
	/usr/local/bin/g++ $(CXXFLAGS) $< -o ./bin/$@
