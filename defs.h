#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C_OK       0
#define C_NOK     -1

#define MAX_STR   32
#define MAX_CAP    2

typedef struct {
    int   id;
    char  room[MAX_STR];
    char  device[MAX_STR];
    float value;
    int   timestamp;
} EvidenceType;

typedef struct {
    EvidenceType *elements;
    int capacity;
    int size;
} EvidenceArray;

// Helper
typedef enum {
    E_EMF = 1,
    E_THERMAL = 2,
    E_SOUND = 3
} deviceType;

void printMenu(int*);
void loadEvidenceData(EvidenceArray*);

void initEvidenceArray(EvidenceArray*, int);
void initEvidence(int, char*, char*, float, int, EvidenceType*);

void addEvidence(EvidenceArray*, EvidenceType* );
int  delEvidence(EvidenceArray*, int);
void copyEvidence(EvidenceType*, EvidenceType*);
void printEvidence(EvidenceType*);
void growEvidenceArray(EvidenceArray*);

// Helper function
int validateEvidence(int, deviceType*);
void convertDevice(deviceType, char*);

void printEvidenceArray(EvidenceArray*);
void cleanupEvidenceArray(EvidenceArray*);

