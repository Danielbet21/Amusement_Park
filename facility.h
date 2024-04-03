#ifndef __FACILITY_H
#define __FACILITY_H

#include <stdio.h>
#include <crtdbg.h> // TODO: remove before release
#include "General.h"
#include "string.h"
#include "fileHelper.h"



typedef enum { eChildrenFacility, eIntermidateFacility, eAdultFacility, eExtremeFacility, eSuper_ExtremesFacility, eNofTypesFacility } Category;
static const char* facilityTypeTilte[eNofTypesFacility] = { "Childrens","Intermidate","Adults","Extreme","Super_Extremes" };



typedef struct facility {
	char* name;
	int minHeight;
	int maxHeight;
	Category category;
} Facility;

int initFacility(Facility* pFacility,char* name, int minAge, int maxAge, Category category);
void initFacilityByUser(Facility* pFacility);
int validFacility(char* name, int minHeight, int maxHeight, Category category);
int compareFacilitiesByCategory(const Facility* pFacility1, const Facility* pFacility2);
void printFacility(const Facility* pFacility);
void freeFacility(Facility* pFacility);

// save and load functions
int saveFacilityToTextFile(const Facility* facility, FILE* fp);
int loadFacilityFromTextFile(Facility* facility, FILE* fp);
int saveFacilityToBinFile(const Facility* facility, FILE* fp);
int loadFacilityFromBinFile(Facility* facility, FILE* fp);

#endif 