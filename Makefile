HDRS = ic_type.h ic_call.h
SRCS = $(HDRS:.h=.c)
OBJS = $(SRCS:.c=.o)
SRCS_T = $(HDRS:.h=.t.c)
OBJS_T = $(SRCS_T:.c=.o)

all: ic ic.t

# static analysis flags
SFLAGS = -Wall -Wextra -Wcast-align -Wcast-qual -Wdisabled-optimization \
	-Wformat=2 -Winit-self -Wlogical-op \
	-Wmissing-include-dirs -Wredundant-decls -Wsign-conversion \
	-Wswitch-default -Wundef -Wno-unused-function -fno-strict-aliasing
#-Wmissing-declarations \
CFLAGS = -g $(SFLAGS)
lac.t: CFLAGS += -D_DEBUG
# link to static lib
LDLIBS = -ldl -lffi

ic: ic.o $(OBJS)

ic.t: ic.t.o $(OBJS) $(OBJS_T)

test: ic.t
	./ic.t

.PHONY : clean
clean:
	rm -f ic ic.t *.o *~

valgrind: lac
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./ic

valgrind_t: lac.t
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./ic.t

IFLAGS = -kr

indent: ic.c ic.t.c $(SRCS) $(SRCS_T) $(HDRS)
	indent $(IFLAGS) $^

clang-format: ic.c ic.t.c $(SRCS) $(SRCS_T) $(HDRS)
	clang-format -i $^

print: ic.c ic.t.c $(SRCS) $(SRCS_T) $(HDRS)
	enscript -i4 -p - $^ | ps2pdf - ic.pdf

deps: ic.c ic.t.c $(SRCS) $(SRCS_T)
	@$(foreach c, $^, cc -MM $(c);)

cmake:
	@rm -rf build
	cmake . -B build
	(cd build; make)

# :r!make deps
ic.o: ic.c ic.h ic_call.h ic_type.h
ic.t.o: ic.t.c ic.h ic_call.h ic_type.h
ic_type.o: ic_type.c ic_type.h
ic_call.o: ic_call.c ic_call.h ic_type.h
ic_type.t.o: ic_type.t.c
ic_call.t.o: ic_call.t.c ic_call.h ic_type.h
