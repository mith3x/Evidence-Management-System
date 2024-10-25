#include <stdio.h>
#include <string.h>

#include "defs.h"

int main(){

    EvidenceArray* evidence = malloc(sizeof(EvidenceType));
    initEvidenceArray(evidence, MAX_CAP);
    loadEvidenceData(evidence);

    int userChoice;
    int count = 1;
    int id;
    char roomName[MAX_STR];
    char device[MAX_STR];
    float value;
    int timeHour;
    int timeMinute;
    int timeSecond;
    int timeStamp = 0;
    int removeID;
    deviceType typeDevice;
    int userDevice = 0;


    while (count == 1){
        printMenu(&userChoice);
        switch (userChoice){
            case 0:
                // If user chooses 0: Exit
                count = 0;
                break;
            case 1:
                // If user chooses 1: Add evidence

                // Evidence ID
                printf("%s\n", "Enter the evidence ID: ");
                scanf("%d", &id);
                while(getchar()!='\n');

                // Get Evidence Name
                printf("%s\n", "Enter the room name: ");
                fgets(roomName,MAX_STR,stdin);
                roomName[strlen(roomName) -1] = '\0';

                // Evidence Device Code
                printf("%s\n", "Enter the device code as an Integer[EMF : 1, THERMAL: 2, SOUND: 3]: ");
                scanf("%d", &userDevice);
                while(getchar()!='\n');
                validateEvidence(userDevice, &typeDevice);
                convertDevice(userDevice, device);


                //printf("Value: %d", userDevice);

                // Device Reading Value
                printf("%s\n", "Enter the evidence value: ");
                scanf("%f", &value);
                while(getchar()!='\n');

                // Timestamp
                printf("%s\n", "Enter the timestamp (Hours minutes seconds, space seperated): ");
                scanf("%d %d %d", &timeHour, &timeMinute, &timeSecond);
                while(getchar()!='\n');
                timeStamp = timeSecond + (timeMinute * 60) + (timeHour * 3600);

                //initialize the Evidence Array
                EvidenceType newEvidence;
                initEvidence(id, roomName, device, value, timeStamp, &newEvidence);
                addEvidence(evidence, &newEvidence);
                break;
            case 2:
                // If user enters 2, Delete evidence
                printf("%s\n", "Enter Evidence ID to remove: ");
                scanf("%d", &removeID);
                int isDeleted = delEvidence(evidence, removeID);
                if(isDeleted == C_OK){
                    printf("%s (%d) %s\n", "Evidence", removeID, "has been removed");
                } else {
                    printf("%s: %d\n", "Invalid ID Entry", removeID);
                }
                break;
            case 3:
                // If user Enters 3: Printing Evidence
                printEvidenceArray(evidence);
                break;
            default:
                printf("%s\n", "Please Enter a number from 0 to 3");
                break;
        }
    }
    cleanupEvidenceArray(evidence);
    return(0);
}

/* 
  Function: Print Menu
  Purpose:  Print the main menu and get the user's choice via user input
  Params:   
    Output: int* choice - the choice typed by the user
*/
void printMenu(int* choice){
    int c = -1;
    int numOptions = 3;

    printf("\nMAIN MENU\n");
    printf("  (1) Add evidence\n");
    printf("  (2) Delete evidence\n");
    printf("  (3) Print evidence\n");
    printf("  (0) Exit\n\n");

    printf("Please enter your selection: ");
    scanf("%d", &c);

    if (c == 0) {
        *choice = c;
        return;
    }

    while (c < 0 || c > numOptions) {
        printf("Please enter your selection: ");
        scanf("%d", &c);
    }
    *choice = c;
}

