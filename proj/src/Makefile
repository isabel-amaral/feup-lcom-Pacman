# name of the program (Minix service)
PROG=proj

# source code files to be compiled
SRCS = proj.c utils/utils.c devices/timer/timer.c devices/kbc/keyboard/keyboard.c devices/kbc/mouse/mouse.c devices/graphics/graphics.c view/initialize_pixmaps.c view/maze_view/maze_view.c view/pacman_view/pacman_view.c view/ghosts_view/ghosts_view.c

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

view/initialize_pixmaps.o: view/initialize_pixmaps.c view/initialize_pixmaps.h
	cc $(CFLAGS) -o view/initialize_pixmaps.o -c view/initialize_pixmaps.c
view/maze_view/maze_view.o: view/maze_view/maze_view.c view/maze_view/maze_view.h
	cc $(CFLAGS) -o view/maze_view/maze_view.o -c view/maze_view/maze_view.c
view/pacman_view/pacman_view.o: view/pacman_view/pacman_view.c view/pacman_view/pacman_view.h
	cc $(CFLAGS) -o view/pacman_view/pacman_view.o -c view/pacman_view/pacman_view.c
view/ghosts_view/ghosts_view.o: view/ghosts_view/ghosts_view.c view/ghosts_view/ghosts_view.h
	cc $(CFLAGS) -o view/ghosts_view/ghosts_view.o -c view/ghosts_view/ghosts_view.c


# include LCOM's makefile that does all the "heavy lifting"
.include <minix.lcom.mk>
