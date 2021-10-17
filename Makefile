CC ?= gcc

CFLAGS = -O2 -Wall -s $(shell pkg-config --cflags gtk+-2.0)
LIBS = $(shell pkg-config --libs gtk+-2.0)
CFLAGS += -DGTK_DISABLE_BROKEN -DGTK_DISABLE_DEPRECATED

all: main.c
	${CC} -o gtk2-refresh main.c ${CFLAGS} ${LIBS}
