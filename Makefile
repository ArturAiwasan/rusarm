CXX = g++
LDFLAGS = -Wall -no-pie

SOURCES = main.cpp

OBJECTS = $(SOURCES: .cpp = .o)

TARGET = rusarm

$(TARGET): $(OBJECTS)
	$(CXX) $^ $(LDFLAGS) -o $@

clean:
	$(RM) $(TARGET) $(OBJECTS)


