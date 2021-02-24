CXXFLAGS := -std=c++17 -Wall $(CXXFLAGS)

%: %.cpp
	/usr/local/bin/g++-10 $(CXXFLAGS) $< -o ./bin/$@
