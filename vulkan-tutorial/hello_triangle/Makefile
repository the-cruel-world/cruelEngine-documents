CXX=clang++

LIBS=glm glfw3 vulkan

CFLAGS=$(shell pkg-config --cflags ${LIBS})
LDFLAGS=$(shell pkg-config --libs ${LIBS})

all: main


main: main.cpp Renderer.cpp Renderer.h
	@echo "LIBS   :" ${LIBS}
	@echo "CFLAGS :" ${CFLAGS}
	@echo "LDFLAGS:" ${LDFLAGS}
	${CXX} ${CFLAGS} main.cpp Renderer.cpp ${LDFLAGS} -o main


.PHONY: clean

clean:
	rm main 
