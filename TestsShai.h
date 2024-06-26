#ifndef __TESTS_SHAI__
#define __TESTS_SHAI__

#include <crtdbg.h> // TODO: remove before release
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "General.h"


void runAllTestsShai();

// Date tests
void DateTests();
void initDateTest();
void isDateValidTest();
void compareDatesTest();
// Weather Tests
void WeatherTest();
void initWeatherTest();
void isValidWeatherTest();
void compareWeatherByTempTest();
// Time tests
void TimeTests();
void initTimeTest();
void isValidTimeTest();
void compareTimeTest();
// Shop tests
void ShopTests();
void initShopTest();
void isValidShopTest();
void compareShopsByNameTest();
// Ticket tests
void TicketTests();
void initTicketTest();
void isValidTicketTest();
void compareTicketsByIDTest();
void compareTicketsByDateTest();
void compareTicketsByGuestTypeTest();
// TicketMaster tests
void TicketMasterTests();
void initTicketMasterTest();
void addTicketTest();
void calcDailyTest();
void sortTicketsByIDTest();
void sortTicketsByDateTest();
void sortTicketsByGuestTypeTest();
void sortTicketsUserTestManual();
void buyTicketTestManual();
void findTicketByUserTestManual();
// initializes By User Manuals Tests
void initByUserManualsTest();
void initDateByUserManualsTest();
void initWeatherByUserManualsTest();
void initTimeByUserManualsTest();
void initShopByUserManualsTest();
void initTicketByUserManualsTest();
// Tests general functions
void generalLibaryTests();
void printIntArray(const void* element);
void generalArrayFunctionTest();




#endif 

