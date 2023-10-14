CXXFLAGS := -std=c++20 -Wall -Wextra $(CXXFLAGS)

%: %.cpp
	/usr/local/bin/g++ $(CXXFLAGS) $< -o ./bin/$@
