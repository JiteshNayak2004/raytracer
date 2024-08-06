# Rule to build the executable
a.out: main.cpp
	g++ main.cpp -o a.out

# Rule to generate the image and display it
raytracer: a.out
	./a.out >> image.ppm
	feh image.ppm

# Default rule to compile and run
all: raytracer

# Clean rule
.PHONY: clean
clean:
	rm -f a.out image.ppm



