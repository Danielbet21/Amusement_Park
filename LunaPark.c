#include "LunaPark.h"


int initLunaPark(LunaPark* lunaPark, char* name) {
	//check if name is valid (only letters)
	if (validName(name) == 0) {
		return 0;
	}

	// init Time
	Time openTime;
	initTime(&openTime, DEFALUT_OPEN_HOUR, DEFALUT_OPEN_MINUTE);

	Time closeTime;
	initTime(&closeTime, DEFALUT_CLOSE_HOUR, DEFALUT_CLOSE_MINUTE);

	// init TicketMaster
	TicketMaster ticketMaster;
	initTicketMaster(&ticketMaster);

	// init Weather
	Weather weather;
	initWeather(&weather, DEFALUT_WEATHER, DEFALUT_TEMPERATURE);

	// init linked list of facilities
	if (L_init(&lunaPark->facilities) == 0) {
		return 0;
	}


	//init lunaPark
	lunaPark->name = name;
	lunaPark->openTime = openTime;
	lunaPark->closeTime = closeTime;
	lunaPark->workers = NULL;
	lunaPark->numOfWorkers = 0;
	lunaPark->ticketMasters = ticketMaster;
	lunaPark->weather = weather;
	lunaPark->shops = NULL;
	lunaPark->numOfShops = 0;
	lunaPark->todayVisitors = 0;
	return 1;
}
int initLunaParkByUser(LunaPark* lunaPark) {
	int flag = 0;
	char* name = NULL;
	do {
		if (flag > 0) {
			printf("Invalid name, please try again\n");
			free(name);
		}

		name = getStrExactName("Please enter the Luna Park name\n");
		flag = 1;

	} while (!initLunaPark(lunaPark, name));

}

void printLunaParkInfo(const LunaPark* lunaPark) {
	if (lunaPark == NULL || validName(lunaPark->name) == 0) {
		return;
	}

	printf("Name: %s\n", lunaPark->name);
	printf("Open Time: ");
	printTime(&lunaPark->openTime);
	printf("\nClose Time: ");
	printTime(&lunaPark->closeTime);
	printf("\nNumber of Workers: %d\n", lunaPark->numOfWorkers);
	for (int i = 0; i < lunaPark->numOfWorkers; i++)
	{
		lunaPark->workers[i]->printPerson(lunaPark->workers[i]);
		printf("\n");
	}

	printf("Number of Shops: %d\n", lunaPark->numOfShops);
	generalArrayFunction((void*)&lunaPark->shops, lunaPark->numOfShops, sizeof(Shop), (void*)printShop); // TODO need to check

	int numOfFacilities = L_count(&lunaPark->facilities);
	printf("Number of Facilities: %d\n", numOfFacilities);
	printf("Facilities: \n");
	L_print(&lunaPark->facilities, printFacility);

	printf("Ticket Master: \n");
	printTicketMaster(&lunaPark->ticketMasters);

	printf("\n");
	printf("Today Visitors: %d\n", lunaPark->todayVisitors);
	printWeather(&lunaPark->weather);

}

void printLunaParkMenu(const LunaPark* lunaPark) {
	if (lunaPark == NULL || validName(lunaPark->name) == 0) {
		return;
	}
	printf("\n\n--------------------  %s  -------------------\n", lunaPark->name);
	printf("Welcome Back!\n");
	printf("Today's is %s,", WeatherTypeStr[lunaPark->weather.condition]);
	printWeatherForcastTemp(lunaPark->weather.temp);
	printf("We are open from ");
	printTime(&lunaPark->openTime);
	printf(" to ");
	printTime(&lunaPark->closeTime);
	printf("\n---------------------------------------------\n");
	printf("\n\n");
}




void freeLunaPark(LunaPark* lunaPark) {
	if (lunaPark == NULL) {
		return;
	}

	// free name
	free(lunaPark->name);
	// free facilities

	L_free(&lunaPark->facilities, freeFacility);








	//// free workers
	//for (int i = 0; i < lunaPark->numOfWorkers; i++) {
	//	lunaPark->workers[i].freePerson(lunaPark->workers[i]); // NEED To check
	//}
	//free(lunaPark->workers);

	//// free ticketMasters
	//freeTicketMaster(lunaPark->ticketMasters);

	//// free shops
	generalArrayFunction((void*)&lunaPark->shops, lunaPark->numOfShops, sizeof(Shop), (void*)freeShop); // TODO need to check








}


int addFacilityToLunaPark(LunaPark* lunaPark, Facility* facility) {
	if (lunaPark == NULL || facility == NULL) {
		return 0;
	}
	NODE* ptr = L_insert(&lunaPark->facilities.head, facility);
	if (ptr == NULL) {
		return 0;
	}

	return 1;
}

void addFacilityToLunaParkByUser(LunaPark* lunaPark) {

	Facility* facility = (Facility*)malloc(sizeof(Facility));
	if (facility == NULL) {
		return;
	}
	initFacilityByUser(facility);
	printFacility(facility);
	addFacilityToLunaPark(lunaPark, facility);
}



int addShopToLunaPark(LunaPark* lunaPark, Shop* shop) {}
void addShopToLunaParkByUser(LunaPark* lunaPark) {}
int changeLunaParkTimeByUser(LunaPark* lunaPark) {
	if (lunaPark == NULL) {
		return 0;
	}

	int userOption = 0;
	Time tempOpenTime = lunaPark->openTime;
	Time tempCloseTime = lunaPark->closeTime;
	int flag = 0;
	while (userOption != 3) {
		printf("Please choose an option:\n");
		printf("1. Change Open Time\n");
		printf("2. Change Close Time\n");
		printf("3. Exit\n");
		scanf("%d", &userOption);
		switch (userOption)
		{
		case 1:
			initTimeByUser(&tempOpenTime);
			flag = 1;
			break;
		case 2:
			initTimeByUser(&tempCloseTime);
			flag = 1;
			break;
		case 3:
			break;
		default:
			printf("Invalid option, please try again\n");
			break;
		}

		if (flag > 0 && compareTime(&tempOpenTime, &tempCloseTime) == 1) {
			printf("Open Time need to be before Close Time\n");
			flag = 0; // reset flag to allow user to re-enter times
		}
	}

	if (flag > 0) {
		// If valid times were entered, update the LunaPark times
		lunaPark->openTime = tempOpenTime;
		lunaPark->closeTime = tempCloseTime;
	}

	return 1;
}
int changeLunaParkWeatherByUser(LunaPark* lunaPark) {
	if (lunaPark == NULL) {
		return 0;
	}
	Weather tempWeather;
	initWeatherByUser(&tempWeather);
	lunaPark->weather = tempWeather;

	return 1;
}

















// save and load functions
int saveLunaParkToTextFile(const LunaPark* lunaPark, const char* fileName) {}
int loadLunaParkFromTextFile(LunaPark* lunaPark, const char* fileName) {}
int saveLunaParkToBinFile(const LunaPark* lunaPark, const char* fileName) {}
int loadLunaParkFromBinFile(LunaPark* lunaPark, const char* fileName) {}