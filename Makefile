RTPABP_SRC=rtp_abp.c prog2.c
RTPGBN_SRC=rtp_gbn.c prog2.c
HEADERS=prog2.h

all: abp gbn

main: abp

abp: $(RTPABP_SRC) $(HEADERS) Makefile
	gcc -o $@ $(RTPABP_SRC) -Wall -I -g -lm -DBIDIRECTIONAL=0

gbn: $(RTPGBN_SRC) $(HEADERS) Makefile
	gcc -o $@ $(RTPGBN_SRC) -Wall -g -lm -DBIDIRECTIONAL=1

clean:
	rm -f *~ *.o *.exe *.stackdump abp gbn