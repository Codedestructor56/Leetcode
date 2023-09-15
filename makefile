CXX=g++
CXXFLAGS=-g
SOURCES=src/groupPeople.cpp src/candy.cpp src/mergeKlist.cpp
TARGET=build/recbuild

$(TARGET):$(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@ 

clean:
	rm -f $(TARGET)