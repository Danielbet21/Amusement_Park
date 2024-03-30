#ifndef __TICKET_MASTER__
#define __TICKET_MASTER__

#include <crtdbg.h> // TODO: remove before release
#include <stdio.h>
#include "Ticket.h"

typedef enum {
	eNotSorted, eSortedByID, eSortedByDate, eSortedByGuestType
} eSortType;

static const char* sortTypeStr[] = { "None", "ID", "Date", "Guest Type" };

typedef struct {
	Ticket* tickets;
	int numOfTickets;
	eSortType sortType;
} TicketMaster;


void initTicketMaster(TicketMaster* ticketMaster);
int addTicket(TicketMaster* ticketMaster, Ticket* ticket);
void printTicketMaster(const TicketMaster* ticketMaster);
void freeTicketMaster(TicketMaster* ticketMaster);
double calcDaily(const TicketMaster* ticketMaster, Date* date);
void printDailyIncome(const TicketMaster* ticketMaster, Date* date);
void sortTicketsByID(TicketMaster* ticketMaster);
void sortTicketsByDate(TicketMaster* ticketMaster);
void sortTicketsByGuestType(TicketMaster* ticketMaster);
void sortTicketsUser(TicketMaster* ticketMaster);

#endif 