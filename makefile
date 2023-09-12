CXX=g++
CXXFLAGS=-g
SOURCES=src/groupPeople.cpp src/minDeletions.cpp
TARGET=build/recbuild

$(TARGET):$(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@ 

clean:
	rm -f $(TARGET)