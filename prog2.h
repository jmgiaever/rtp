
#ifndef PROG2_H
#define PROG2_H

/* change to 1 if you're doing extra credit */
/* and write a routine called B_output */
//#define BIDIRECTIONAL 1

typedef struct msg msg_t;
typedef struct pkt pkt_t;
typedef struct event event_t;

/* a "msg" is the data unit passed from layer 5 (teachers code) to layer  */
/* 4 (students' code).  It contains the data (characters) to be delivered */
/* to layer 5 via the students transport level protocol entities.         */
struct msg {
    char data[20];
};

/* a packet is the data unit passed from layer 4 (students code) to layer */
/* 3 (teachers code).  Note the pre-defined packet structure, which all   */
/* students must follow. */
struct pkt {
    int seqnum;
    int acknum;
    int checksum;
    char payload[20];
};

struct event {
    float evtime;           /* event time */
    int evtype;             /* event type code */
    int eventity;           /* entity where event occurs */
    pkt_t *pktptr;          /* ptr to packet (if any) assoc w/ this event */
    event_t *prev;
    event_t *next;
};

void insertevent(struct event *p);
void init();
void generate_next_arrival();

/********* STUDENTS WRITE THE NEXT SEVEN ROUTINES *********/

/* The following routine will be called once (only) before any other */
/* entity A routines are called. You can use it to do any initialization */
void A_init();

/* called from layer 3, when a packet arrives for layer 4 */
void A_input( pkt_t packet );

/* called from layer 5, passed the data to be sent to other side */
void A_output( msg_t message );

/* called when A's timer goes off */
void A_timerinterrupt();

/* the following rouytine will be called once (only) before any other */
/* entity B routines are called. You can use it to do any initialization */
void B_init();

/* called from layer 3, when a packet arrives for layer 4 at B*/
void B_input( pkt_t packet );

/* Note that with simplex transfer from a-to-B, there is no B_output() */
void B_output( msg_t message ); /* need be completed only for extra credit */

/* called when B's timer goes off */
void B_timerinterrupt();

/** 
 * STUDENT CALLABLE FUNCTIONS: Dont implement (they allready are, int prog2.c)
 **/
void starttimer( int AorB, float increment );
/* called by students routine to cancel a previously-started timer */
void stoptimer(int AorB);
/* TOLAYER3 */
void tolayer3( int AorB, pkt_t packet );
/* TOLAYER5 */
void tolayer5(int AorB, char datasent[20]);
#endif