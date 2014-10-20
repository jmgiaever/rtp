#include <stdlib.h>
#include <stdio.h>
#include "prog2.h"

/* The following routine will be called once (only) before any other */
/* entity A routines are called. You can use it to do any initialization */
void A_init() {

}

/* called from layer 3, when a packet arrives for layer 4 */
void A_input( pkt_t packet ) {

}

/* called from layer 5, passed the data to be sent to other side */
void A_output( msg_t message ) {

}

/* called when A's timer goes off */
void A_timerinterrupt() {

}

/* the following rouytine will be called once (only) before any other */
/* entity B routines are called. You can use it to do any initialization */
void B_init() {

}

/* called from layer 3, when a packet arrives for layer 4 at B*/
void B_input( pkt_t packet ) {

}

/* Note that with simplex transfer from a-to-B, there is no B_output() */
void B_output( msg_t message ) {
	/* need be completed only for extra credit */
}

/* called when B's timer goes off */
void B_timerinterrupt() {

}