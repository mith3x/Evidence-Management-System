#include "defs.h"

/*  Note: This function may prevent compilation until you have implemented addEvidence().

    To fix this, either comment out this function or implement an empty, placeholder 
    addEvidence() function until you are finished.
*/
void loadEvidenceData(EvidenceArray* arr){
    EvidenceType a;
    // Add sample evidence data
    // Evidence has an ID, room location, type (EMF/THERMAL/SOUND), value, and timestamp in seconds
    initEvidence(1000, "Living Room", "EMF", 4.869, 19554, &a);
    addEvidence(arr, &a);
    initEvidence(1001, "Nursery", "EMF", 2.08, 4260, &a);
    addEvidence(arr, &a);
    initEvidence(1002, "Nursery", "SOUND", 88.8, 4120, &a);
    addEvidence(arr, &a);
    initEvidence(1003, "Living Room", "EMF", 4.9, 17157, &a);
    addEvidence(arr, &a);
    initEvidence(1004, "Living Room", "SOUND", 35.154, 20970, &a);
    addEvidence(arr, &a);
    initEvidence(1005, "Bathroom", "THERMAL", 16.22806, 15936, &a);
    addEvidence(arr, &a);
    initEvidence(1006, "Kitchen", "EMF", 0.439, 609, &a);
    addEvidence(arr, &a);
    initEvidence(1007, "Kitchen", "THERMAL", 9.3643, 11797, &a);
    addEvidence(arr, &a);
    initEvidence(1008, "Bathroom", "EMF", 2.1254, 20166, &a);
    addEvidence(arr, &a);
    initEvidence(1009, "Living Room", "SOUND", 44.8, 12701, &a);
    addEvidence(arr, &a);
    initEvidence(1010, "Dining Room", "EMF", 3.871087, 17593, &a);
    addEvidence(arr, &a);
    initEvidence(1011, "Main Bedroom", "SOUND", 79.0739, 2862, &a);
    addEvidence(arr, &a);
    initEvidence(1012, "Bathroom", "THERMAL", 10.649717, 9292, &a);
    addEvidence(arr, &a);
    initEvidence(1013, "Living Room", "EMF", 4.142, 8384, &a);
    addEvidence(arr, &a);
    initEvidence(1014, "Nursery", "THERMAL", -8.2, 328, &a);
    addEvidence(arr, &a);
    initEvidence(1015, "Dining Room", "SOUND", 49.9, 20757, &a);
    addEvidence(arr, &a);
    initEvidence(1016, "Living Room", "THERMAL", 3.4364, 16043, &a);
    addEvidence(arr, &a);
    initEvidence(1017, "Dining Room", "THERMAL", -1.462089, 14241, &a);
    addEvidence(arr, &a);
    initEvidence(1018, "Living Room", "EMF", 3.484842, 6222, &a);
    addEvidence(arr, &a);
    initEvidence(1019, "Living Room", "EMF", 2.87804, 15926, &a);
    addEvidence(arr, &a);
    initEvidence(1020, "Living Room", "EMF", 4.782, 19880, &a);
    addEvidence(arr, &a);
    initEvidence(1021, "Nursery", "THERMAL", -6.9681, 2905, &a);
    addEvidence(arr, &a);

}

/*Function: initEvidenceArray
 * Purpose: Initializes every field of the provided Evidence Array
 * Input: maximum capacity of array
 * Output: Array of evidence
 */
void initEvidenceArray(EvidenceArray* evArr, int cap){
    evArr->elements = malloc(sizeof(EvidenceType) * cap);
    evArr->capacity = cap;
    evArr->size = 0;
}

/*Function: initEvidence
 * Purpose: Initialize an EvidenceType structure with output variable ev
 * Input: Evidence ID, Room, Device, Value, and timestamp
 * Output: evidence to be initialized as output variable ev.
 */
void initEvidence(int id, char* room, char* device, float value, int timestamp, EvidenceType* ev){
    ev -> id = id;
    strcpy(ev->room, room);
    strcpy(ev->device, device);
    ev->value = value;
    ev->timestamp = timestamp;
}


