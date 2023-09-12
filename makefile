CXX=g++
CXXFLAGS=-g
SOURCES=src/groupPeople.cpp
TARGET=build/groupPeople

$(TARGET):$(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@ 

clean:
	rm -f $(TARGET)