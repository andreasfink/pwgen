##
# File: Makefile
# Project "pwgen"
# Create: Andreas Fink (andreas@fink.org)
#
#

EXEDIR=/usr/local/bin
EXE=pwgen
CC=gcc
	
CFILES = pwgen.c
OFILES = $(CFILES:.c=.o)

${EXE}: ${OFILES}
	${CC} ${CFLAGS} -o ${EXE} ${LDFLAGS} ${OFILES} ${LIBS}

install: ${EXE}
	-mkdir -p -m 755 ${EXEDIR}
	-install -b -g bin -o root -m 755 ${EXE} ${EXEDIR}/${EXE}

clean:
	-rm ${EXE}
	-rm ${OFILES}

