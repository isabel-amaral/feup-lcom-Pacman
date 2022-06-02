# name of the program (Minix service)
PROG=proj

# source code files to be compiled
SRCS = proj.c utils/utils.c devices/timer/timer.c devices/kbc/keyboard/keyboard.c devices/kbc/mouse/mouse.c devices/graphics/graphics.c

# additional compilation flags
# "-Wall -Wextra -Werror -I . -std=c11 -Wno-unused-parameter" are already set
CFLAGS += -pedantic

# list of library dependencies (for Lab 2, only LCF library)
DPADD += ${LIBLCF}
LDADD += -llcf

devices/timer/timer.o: devices/timer/timer.c devices/timer/timer.h
	cc $(CFLAGS) -o devices/timer/timer.o -c devices/timer/timer.c
devices/kbc/keyboard/keyboard.o: devices/kbc/keyboard/keyboard.c devices/kbc/keyboard/keyboard.h
	cc $(CFLAGS) -o devices/kbc/keyboard/keyboard.o -c devices/kbc/keyboard/keyboard.c
devices/kbc/mouse/mouse.o: devices/kbc/mouse/mouse.c devices/kbc/mouse/mouse.h
	cc $(CFLAGS) -o devices/kbc/mouse/mouse.o -c devices/kbc/mouse/mouse.c	
devices/graphics/graphics.o: devices/graphics/graphics.c devices/graphics/graphics.h
	cc $(CFLAGS) -o devices/graphics/graphics.o -c devices/graphics/graphics.c	

utils/utils.o: utils/utils.c utils/utils.h
	cc $(CFLAGS) -o utils/utils.o -c utils/utils.c	

# include LCOM's makefile that does all the "heavy lifting"
.include <minix.lcom.mk>
