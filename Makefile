CFLAGS_CC=-std=c++11 -Wall -DDEBUG
LDFLAGS_CC=-lstdc++ 

FACTORY_METHOD=creational/factory_method.cpp
PROGRAMS=factory_method
OUTPUT=out

all: ${PROGRAMS}

factory_method:
	${CC} ${CFLAGS_CC} -o $(OUTPUT)/$@ $(FACTORY_METHOD) ${LDFLAGS_CC}
clean:
	@rm -rf $(OUTPUT)/*
	
recompile:	clean all
