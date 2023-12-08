// impl of appointment


#include "appointment.h"

#include <string.h>
#include <stdlib.h>


//return true when they are conflict
bool CheckConflict(APPOINTMENT a, APPOINTMENT b) {
	time_t start_a = mktime(&a.start_time);
	time_t end_a = start_a + a.duration_minutes;

	time_t start_b = mktime(&b.start_time);
	time_t end_b = start_b + b.duration_minutes;

	return (start_a < end_b) && (end_a > start_b); 
}


// TODO: generate Id
APPOINTMENT CreateAppt(int id, char* title, struct tm start_time, int duration, char* location, char* description) {
    APPOINTMENT a;
    a.id = id;  // 8-digit   yyMMddxx
    strncpy(a.title, title, MAXSIZE);
    a.start_time = start_time;
    a.duration_minutes = duration;
    strncpy(a.location, location, MAXSIZE);
    strncpy(a.description, description, MAXTEXT);
    a.appointment_status = NONE;
    return a;
}




void DestroyAppt(APPOINTMENT a) {

}




bool CopyAppt(APPOINTMENT* dest, APPOINTMENT src) {
    if (dest == NULL)
        return false;

    dest->id = src.id;
    strncpy(dest->title, src.title, MAXSIZE);
    dest->start_time = src.start_time;
    dest->duration_minutes = src.duration_minutes;
    strncpy(dest->location, src.location, MAXSIZE);
    strncpy(dest->description, src.description, MAXTEXT);
    dest->appointment_status = src.appointment_status;
    return true;
}


// TODO: more compare?
bool CompareAppt(APPOINTMENT a, APPOINTMENT b) {
    //time_t start_a = mktime(&a.start_time);
    //time_t start_b = mktime(&b.start_time);

    if (a.id = b.id)
        return true;
    else
        return false;
    //if (start_a < start_b) {
    //    return -1;
    //}
    //else if (start_a > start_b) {
    //    return 1;
    //}
    //else { // start_a == start_b
    //    return 0;
    //}
}


void PrintAppt(APPOINTMENT appt) {
    char start_time_str[MAXSIZE];

    //Dec 5   not sure
    strftime(start_time_str, MAXSIZE, "%Y-%m-%d %H:%M", &appt.start_time);

    printf("Appointment ID: %d\n", appt.id);
    printf("Title: %s\n", appt.title);
    printf("Start Time: %s\n", start_time_str);
    printf("Duration: %d minutes\n", appt.duration_minutes);
    printf("Location: %s\n", appt.location);
    printf("Description: %s\n", appt.description);

    char* status_str;
    switch (appt.appointment_status) {
    case NONE:
        status_str = "None";
        break;
    case NOT_EXPIRED:
        status_str = "Not Expired";
        break;
    case EXPIRED:
        status_str = "Expired";
        break;
    case CANCELED:
        status_str = "Canceled";
        break;
    default :
        status_str = "None";
    }
    printf("Status: %s\n", status_str);
}


// get set
int GetAppId(APPOINTMENT appt) {
    return appt.id;
}

void SetAppId(APPOINTMENT* appt, int id) {
    appt->id = id;
}

void GetAppTitle(APPOINTMENT appt, char* title) {
    strncpy(title, appt.title, MAXSIZE);
}

void SetApptTitle(APPOINTMENT* appt, char* title) {
    strncpy(appt->title, title, MAXSIZE);
}

struct tm GetApptStartTime(APPOINTMENT appt) {
    return appt.start_time;
}

void SetApptStartTime(APPOINTMENT* appt, struct tm start_time) {
    appt->start_time = start_time;
}

int GetApptDuration(APPOINTMENT appt) {
    return appt.duration_minutes;
}

void SetApptDuration(APPOINTMENT* appt, int duration_minutes) {
    appt->duration_minutes = duration_minutes;
}



void GetApptLocation(APPOINTMENT appt, char* location) {
    strncpy(location, appt.location, MAXSIZE);
}

void SetApptLocation(APPOINTMENT* appt, char* location) {
    strncpy(appt->location, location, MAXSIZE);
}

void GetApptDescription(APPOINTMENT appt, char* description) {
    strncpy(description, appt.description, MAXTEXT);
}

void SetApptDescription(APPOINTMENT* appt, char* description) {
    strncpy(appt->description, description, MAXTEXT);
}

STATUS_ENUM GetApptStatus(APPOINTMENT appt) {
    return appt.appointment_status;
}

void SetApptStatus(APPOINTMENT* appt, STATUS_ENUM status) {
    appt->appointment_status = status;
}




void DestroyAppointment(APPOINTMENT* appt) {
    if (appt != NULL)
        free(appt);
}

void saveApptToDisk(APPOINTMENT appt, FILE* fp) {
    char start_time_str[MAXSIZE];

    //Dec 5   not sure
    strftime(start_time_str, MAXSIZE, "%Y-%m-%d %H:%M", &appt.start_time);

    fprintf(fp,"Appointment ID: %d\n", appt.id);
    fprintf(fp,"Title: %s\n", appt.title);
    fprintf(fp,"Start Time: %s\n", start_time_str);
    fprintf(fp,"Duration: %d minutes\n", appt.duration_minutes);
    fprintf(fp,"Location: %s\n", appt.location);
    fprintf(fp,"Description: %s\n", appt.description);
}

