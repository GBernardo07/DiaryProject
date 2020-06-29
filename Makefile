GCC = g++
OBJECTS = main.o app.o diary.o timing.o currenttime.o date.o
FLAGS = -std=c++11
EXECUTABLE = exe

all: $(EXECUTABLE)

main.o: src/main.cpp
	$(GCC) $(CFLAGS) -c src/main.cpp

diary.o: src/diary.cpp
	$(GCC) $(CFLAGS) -c src/diary.cpp

timing.o: src/timing.cpp
	$(GCC) $(CFLAGS) -c src/timing.cpp

currenttime.o: src/currenttime.cpp
	$(GCC) $(CFLAGS) -c src/currenttime.cpp

date.o: src/date.cpp
	$(GCC) $(CFLAGS) -c src/date.cpp

app.o: src/app.cpp
	$(GCC) $(CFLAGS) -c src/app.cpp

$(EXECUTABLE): $(OBJECTS)
	$(GCC) $(OBJECTS) $(CFLAGS)-o $(EXECUTABLE)