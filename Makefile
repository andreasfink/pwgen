##
# File: Makefile
# Project "pwgen"
# Create: Andreas Fink (andreas@fink.org)
#
#

EXEDIR=/usr/local/bin
MANDIR=/usr/local/share/man
EXE=pwgen
MANFILE=pwgen.1
CC=gcc
	
CFILES = pwgen.c
OFILES = $(CFILES:.c=.o)

${EXE}: ${OFILES}
	${CC} ${CFLAGS} -o ${EXE} ${LDFLAGS} ${OFILES} ${LIBS}

install: ${EXE} ${MANFILE}
	-mkdir -p -m 755 ${EXEDIR}
	-install -b -g bin -o root -m 755 ${EXE} ${DESTDIR}${EXEDIR}/${EXE}
	mkdir -p /usr/local/share/man/man1
	-install -b -g bin -o root -m 644 ${MANFILE} ${DESTDIR}${MANDIR}/man1/${MANFILE}

clean:
	-rm ${EXE}
	-rm ${OFILES}

