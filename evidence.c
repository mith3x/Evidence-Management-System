#include "defs.h"

/*
 * Function: void addEvidence(EvidenceArray* dest, EvidenceType* src)
 * Purpose: Makes a deep copy of the provided EvidenceType structure
            and placed the evidence directly into its correct, sorted
            position in the provided EvidenceArray
 * Input: The evidence type and their rooms and time stamps
 * Output: The new updated array.
 */

void addEvidence(EvidenceArray* dest, EvidenceType* src){

    // Double the capacity if needed
    if(dest->size + 1 > dest->capacity){
        growEvidenceArray(dest);
    }

    // Find the insertion point for the new evidence
    int insertIndex = dest->size;
    while(insertIndex > 0){
        EvidenceType* currentEvidence = &(dest->elements[insertIndex - 1]);
         if(strcmp(src->room, currentEvidence->room) < 0 || (strcmp(src->room, currentEvidence->room) == 0 && src->timestamp > currentEvidence->timestamp)){
            break;
        }
        insertIndex--;
    }

    // Shift existing evidence to make for the new evidence
    for(int i = dest->size - 1; i >=insertIndex; --i){
        copyEvidence(&(dest->elements[i+1]), &(dest->elements[i]));
    }

    // Copy the new evidence to its insertion point
    copyEvidence(&(dest->elements[insertIndex]), src);

    // increment the array size
    dest->size++;
}

/*
 * Function: delEvidence(EvidenceArray* src , int id)
 * Purpose: Finds a provided ID inside the provided EvidenceArray.
            if it exists, the element is removed from the EvidenceArray and a success flag
            is returned
            if not, then the appropriate code is returned.
 * Input: Collection of evidence with their corresponding ID
 * Output: C_OK if the operation was successful or C_NOK if the operation was not successful
 */

int  delEvidence(EvidenceArray* src , int id){
    int currentIndex = -1;
    for (int i = 0; i < src->size; ++i){
        if(src->elements[i].id == id){
            currentIndex = i;
            break;
        }
    }
    if(currentIndex < 0){
        return C_NOK;
    }
    for (int i = currentIndex + 1; i < src->size; ++i){
        copyEvidence(&src->elements[i-1], &src->elements[i]);
    }

    src->size--;
    return C_OK;
}

/* Function: validateEvidence
 * Purpose: checks the user input with the device to see if the
 * selected device matches with a valid device
 * Input: int choice
 * Output: if valid: C_OK
 *         if not valid: C_NOK
 */
int validateEvidence(int choice, deviceType *evidenceDevice){
    switch(choice){
        case 1:
            *evidenceDevice = E_EMF;
            return C_OK;

        case 2:
            *evidenceDevice = E_THERMAL;
            return C_OK;
        case 3:
            *evidenceDevice = E_SOUND;
            return C_OK;
        default:
            return C_NOK;
    }
}

/*
 * Function: convertDevice(deviceType, char*)
 * Purpose: Convert the integer value entered by user to a string device type
 * Input: Integer entered by user
 * Output: Corresponding device type
 */
void convertDevice(deviceType userDevice, char *device){
    if(userDevice == E_EMF){
        strcpy(device, "EMF");
    }
    if (userDevice == E_THERMAL){
        strcpy(device, "THERMAL");
    }
    if (userDevice == E_SOUND){
        strcpy(device, "SOUND");
    }
}

/*
 * Function: printEvidence(EvidenceType *evArr)
 * Purpose: function that prints each field of evidence as clearly
 *          separated columns which are wide enough to keep all the
 *          data in a single line
 * Input: Array where elements are printed to the console
 * Output: New array where the corresponding evidence with the description is printed
*/

void printEvidence(EvidenceType *evArr){

    int hours = evArr->timestamp / 3600;
    int minutes = (evArr->timestamp % 3600) / 60;
    int seconds = evArr->timestamp % 60;

    printf("%2d |%18s |%12s |  ", evArr->id, evArr->room, evArr->device);

    if((strcmp(evArr->device, "EMF")) == 0){
        if (evArr->value > 4.0){
            printf("%5.1f (HIGH) ", evArr->value);
        } else {
            printf("%12.1f ", evArr->value);
        }
    } else if((strcmp(evArr->device, "THERMAL")) == 0) {
        if (evArr->value < 0.0) {
            printf("%.2f (COLD) ", evArr->value);
        } else {
            printf("%12.2f ", evArr->value);
        }
    } else if((strcmp(evArr->device, "SOUND")) == 0) {
        if(evArr->value < 35.0){
            printf("%.1f (WHISPER)", evArr->value);
        } else if (evArr->value > 70.0){
            printf("%.1f (SCREAM)", evArr->value);
        } else {
            printf("%12.1f ", evArr->value);
        }
    } else {
        printf("%.1f", evArr->value);
    }

    printf("|  %.2d:%.2d:%.2d\n", hours, minutes, seconds);

}

/*
 * Function: growEvidenceArray(EvidenceArray*)
 * Purpose: doubles the capacity of the Evidence Array
 * Input: old array
 * Output: new array with double the size
 */

void growEvidenceArray(EvidenceArray *evidenceArray){
    EvidenceArray* evidenceTemp = (EvidenceArray*)malloc(sizeof(EvidenceArray));

    evidenceTemp->capacity = evidenceArray->capacity * 2;
    evidenceTemp->size = evidenceArray->size;
    evidenceTemp->elements = (EvidenceType*) malloc(evidenceTemp->capacity * sizeof(EvidenceType));

    for(int i = 0; i < evidenceArray->size; ++i){
        copyEvidence(&evidenceTemp->elements[i], &evidenceArray->elements[i]);
    }

    free(evidenceArray->elements);
    evidenceArray->elements = evidenceTemp->elements;
    evidenceArray->capacity = evidenceTemp->capacity;
    free(evidenceTemp);
}

/*
 * Function: copyEvidence
 * Purpose: performs a deep copy of the evidence found in the src parameter
 *          in the dest parameter
 * In: src parameter values
 * Out: dest parameter values
*/

void copyEvidence(EvidenceType* dest, EvidenceType* src){
    initEvidence(src->id, src->room, src->device, src->value, src->timestamp, dest);
}

/*
 * Function: printEvidenceArray(EvidenceArray*)
 * Purpose: prints all the evidence of the given title
 * Input: An array of evidence
 * Output: An array of evidence that matches with the descriptions
*/

void printEvidenceArray(EvidenceArray *evArr){
    printf("%6s %19s %13s %15s %10s\n", "ID |", "ROOM |", "DEVICE |", "VALUE |", "TIMESTAMP");
    for(int i = 0; i < evArr->size; ++i){
        printEvidence(&(evArr->elements[i]));
    }
}

/*
 * Function: cleanupEvidenceArray
 * Purpose: Deallocates memory block associated with the array parameter
 * In: Nothing
 * Out: EvidenceArrayTye to have its data deallocated
*/

void cleanupEvidenceArray(EvidenceArray *evArr){
    free(evArr->elements);
    free(evArr);
}
