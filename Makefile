CFLAGS_CC=-std=c++11 -Wall -DDEBUG
LDFLAGS_CC=-lstdc++ 

FACTORY_METHOD=creational/factory_method.cpp
ABSTRACT_FACTORY=creational/abstract_factory.cpp
SINGLETON=creational/singleton.cpp

PROGRAMS=factory_method abstract_factory singleton
OUTPUT=out

all: ${PROGRAMS}

factory_method:
	${CC} ${CFLAGS_CC} -o $(OUTPUT)/$@ $(FACTORY_METHOD) ${LDFLAGS_CC}
abstract_factory:
	${CC} ${CFLAGS_CC} -o $(OUTPUT)/$@ $(ABSTRACT_FACTORY) ${LDFLAGS_CC}
singleton:
	${CC} -pthread -lrt ${CFLAGS_CC} -o $(OUTPUT)/$@ $(SINGLETON) ${LDFLAGS_CC} 
clean:
	@rm -rf $(OUTPUT)/*
	
recompile:	clean all
