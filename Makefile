# Variables
CC      := clang++
DIRS    := . events entities ext common
EXT_CPP := cpp
EXT_CC  := cc
PROJNAME := vicefury-plugin-template

INCDIRS = -I.
LIBDIRS = 
STCLIBS = 
DYNLIBS = -ldl -lpthread
BASEOBJDIR = objdir

CFLAGS  = -Wall -O2 -lm -fPIC -c -std=c++20 -DLINUX -DNDEBUG -DELPP_NO_DEFAULT_LOG_FILE -DELPP_THREAD_SAFE $(INCDIRS)
PCHFLAGS = -include pch.h

# Define sources and objects
SOURCES_CPP = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.$(EXT_CPP)))
SOURCES_CC = $(wildcard ext/*.cc)
SOURCES = $(SOURCES_CPP) $(SOURCES_CC)
OBJDIR = $(BASEOBJDIR)/$(BUILDTYPE)$(BITCOUNT)
OBJS_CPP = $(patsubst %.$(EXT_CPP), $(OBJDIR)/%.o, $(SOURCES_CPP))
OBJS_CC = $(patsubst %.$(EXT_CC), $(OBJDIR)/%.o, $(SOURCES_CC))
OBJS = $(OBJS_CPP) $(OBJS_CC)
PROG = $(PROJNAME).so
PROGPATH = $(OBJDIR)/$(PROG)

LDFLAGS = -Wl,-Bsymbolic $(LIBDIRS) -shared
LDLIBS = -Wl,-Bstatic $(STCLIBS) -Wl,-Bdynamic $(DYNLIBS)
COMMONFLAGS = -m$(BITCOUNT)

ifeq ($(BUILDTYPE), dbg)
	COMMONFLAGS += -g
else
	COMMONFLAGS += -s
endif

# Targets
build: build64

build64:
	$(MAKE) BITCOUNT=64 BUILDTYPE=rel xbuild

debug: debug64

debug64:
	$(MAKE) BITCOUNT=64 BUILDTYPE=dbg xbuild

xbuild: $(PROGPATH)
	@mkdir -p ../build
	cp $(PROGPATH) ../build/$(PROG)

$(PROGPATH): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $(COMMONFLAGS) -o $(PROGPATH) $(OBJS) $(LDLIBS)

-include $(OBJS:.o=.o.d)

# Precompiled Header
PCH = $(OBJDIR)/pch.pch

$(PCH): pch.cpp pch.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(COMMONFLAGS) -x c++-header pch.cpp -o $@

# Compile .cpp files with PCH
$(OBJDIR)/%.o: %.$(EXT_CPP) $(PCH)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(COMMONFLAGS) $(PCHFLAGS) -c $< -o $@
	$(CC) -MM $(CFLAGS) $< > $@.d
	@mv -f $@.d $@.d.tmp
	@sed -e 's|.*:|$@:|' < $@.d.tmp > $@.d
	@sed -e 's/.*://' -e 's/\\$$//' < $@.d.tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $@.d
	@rm -f $@.d.tmp

# Compile .cc files without PCH
$(OBJDIR)/%.o: %.$(EXT_CC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(COMMONFLAGS) -c $< -o $@
	$(CC) -MM $(CFLAGS) $< > $@.d
	@mv -f $@.d $@.d.tmp
	@sed -e 's|.*:|$@:|' < $@.d.tmp > $@.d
	@sed -e 's/.*://' -e 's/\\$$//' < $@.d.tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $@.d
	@rm -f $@.d.tmp

clean:
	-@rm -R -f $(BASEOBJDIR)
