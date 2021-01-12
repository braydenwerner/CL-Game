CXX = g++
CXXFLAGS = -O2
LIBS = -ltermbox

default: game 

dino: game.cpp 
	$(CXX) $(CXXFLAGS) game.cpp -o $@ $(LIBS)

clean:
	$(RM) game