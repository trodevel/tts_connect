# Makefile for libtts_connect
# Copyright (C) 2015 Sergey Kolevatov

###################################################################

VER := 0

MODE ?= debug

PROJECT := tts_connect

###################################################################

BOOST_PATH := $(shell echo $$BOOST_PATH)

ifeq (,$(BOOST_PATH))
    $(error 'please define path to boost $$BOOST_PATH')
endif

###################################################################

BOOST_INC=$(BOOST_PATH)
BOOST_LIB_PATH=$(BOOST_PATH)/stage/lib

BOOST_LIB_NAMES :=
BOOST_LIBS = $(patsubst %,$(BOOST_LIB_PATH)/lib%.a,$(BOOST_LIB_NAMES))


EXT_LIBS=-lcurl -lportaudio -lespeak $(BOOST_LIBS)

###################################################################

LIBNAME=libtts_connect

###################################################################

ifeq "$(MODE)" "debug"
    OBJDIR=./DBG
    BINDIR=./DBG

    CFLAGS := -Wall -std=c++0x -ggdb -g3
    LFLAGS := -Wall -lstdc++ -lrt -ldl -lm -g
    LFLAGS_TEST := -Wall -lstdc++ -lrt -ldl -g -L.  -lm

    TARGET=example
else
    OBJDIR=./OPT
    BINDIR=./OPT

    CFLAGS := -Wall -std=c++0x
    LFLAGS := -Wall -lstdc++ -lrt -ldl -lm
    LFLAGS_TEST := -Wall -lstdc++ -lrt -ldl -L. -lm

    TARGET=example
endif

###################################################################

CC=gcc

LDSHARED=gcc
CPP=gcc -E
INCL = -I$(BOOST_INC) -I.


STATICLIB=$(LIBNAME).a
SHAREDLIB=
SHAREDLIBV=
SHAREDLIBM=
LIBS=$(STATICLIB) $(SHAREDLIBV)

AR=ar rc
RANLIB=ranlib
LDCONFIG=ldconfig
LDSHAREDLIBC=-lc
TAR=tar
SHELL=/bin/sh
EXE=

#vpath %.cpp .

SRCC = tts_connect.cpp gspeak_wrap.cpp espeak_wrap.cpp svox_wrap.cpp festvox_wrap.cpp
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCC))

LIB_NAMES = espeak_cpp wave gspeak lang_tools utils svox festvox
LIBS = $(patsubst %,$(BINDIR)/lib%.a,$(LIB_NAMES))

all: static

static: $(TARGET)

check: test

test: all teststatic

teststatic: static
	@echo static test is not ready yet, dc10

$(BINDIR)/$(STATICLIB): $(OBJS)
	$(AR) $@ $(OBJS)
	-@ ($(RANLIB) $@ || true) >/dev/null 2>&1

$(OBJDIR)/%.o: %.cpp
	@echo compiling $<
	$(CC) $(CFLAGS) -DPIC -c -o $@ $< $(INCL)

$(TARGET): $(BINDIR) $(BINDIR)/$(TARGET)
	ln -sf $(BINDIR)/$(TARGET) $(TARGET)
	@echo "$@ uptodate - ${MODE}"

$(BINDIR)/$(TARGET): $(LIBS) $(OBJDIR)/$(TARGET).o $(OBJS) $(BINDIR)/$(STATICLIB)
	$(CC) $(CFLAGS) -o $@ $(OBJDIR)/$(TARGET).o $(BINDIR)/$(LIBNAME).a $(LIBS) $(EXT_LIBS) $(LFLAGS_TEST)

$(BINDIR)/lib%.a: %		# somehow this rule doesn't work
	cd ../$<; make; cd $(project)
	ln -sf ../$</$@ $(BINDIR)

$(BINDIR)/libutils.a:
	cd ../utils; make; cd $(project)
	ln -sf ../../utils/$@ $(BINDIR)

$(BINDIR)/libwave.a:
	cd ../wave; make; cd $(project)
	ln -sf ../../wave/$@ $(BINDIR)

$(BINDIR)/libgspeak.a:
	cd ../gspeak; make; cd $(project)
	ln -sf ../../gspeak/$@ $(BINDIR)

$(BINDIR)/libespeak_cpp.a:
	cd ../espeak_cpp; make; cd $(project)
	ln -sf ../../espeak_cpp/$@ $(BINDIR)

$(BINDIR)/liblang_tools.a:
	cd ../lang_tools; make; cd $(project)
	ln -sf ../../lang_tools/$@ $(BINDIR)

$(BINDIR)/libsvox.a:
	cd ../svox; make; cd $(project)
	ln -sf ../../svox/$@ $(BINDIR)

$(BINDIR)/libfestvox.a:
	cd ../festvox; make; cd $(project)
	ln -sf ../../festvox/$@ $(BINDIR)

$(BINDIR):
	@ mkdir -p $(OBJDIR)
	@ mkdir -p $(BINDIR)

clean:
	#rm $(OBJDIR)/*.o *~ $(TARGET)
	rm $(OBJDIR)/*.o $(TARGET) $(BINDIR)/$(TARGET) $(BINDIR)/$(STATICLIB)
