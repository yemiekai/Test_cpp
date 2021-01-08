# build app which can run in ubuntu, the entry of this program is in main.cpp
CXX=g++
CXXFLAGS= -std=c++11 -O2 #-DVERIFY_LICENSE

LIBS_SHARE= 
INCPATH=-I./include \
		-I.
	
SOURCES=main.cpp \
src/1_TwoSum.cpp\
src/2_AddTwoNums.cpp

OBJECTS=$(SOURCES:.cpp=.o)
TARGET=main

####### Implicit rules

.SUFFIXES: .cpp .cxx .cc .C .c

.cpp.o:
	$(CXX) -g -c $(CXXFLAGS) $(INCPATH) -g -o $@ $<
.cxx.o:
	$(CXX) -g -c $(CXXFLAGS) $(INCPATH) -g -o $@ $<        
.c.o:
	$(CC) -g -c $(CXXFLAGS) $(INCPATH) -g -o $@ $<

####### Build rules


all: $(TARGET)
$(TARGET):$(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) $(LIBS_SHARE) $(LIBS) $(INCPATH) $(CXXFLAGS)
#	$(STRIP) $(TARGET)


clean:
	rm -f $(EXECUTABLE) $(OBJECTS) $(TARGET)




