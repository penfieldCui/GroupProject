// impl of appointment
// program71985 - fall23
// zongping cui
#include "appointment.h"
#include "StreamIO.h"

#include <string.h>
#include <stdlib.h>


//return true when they are conflict
bool CheckConflict(APPOINTMENT a, APPOINTMENT b) {
    //if (a.id == 0) {
    //    return false;
    //}
	time_t start_a = mktime(&a.start_time);
	time_t end_a = start_a + a.duration_minutes * 60;

	time_t start_b = mktime(&b.start_time);
	time_t end_b = start_b + b.duration_minutes * 60;

	return (start_a < end_b) && (end_a > start_b); 
}


// TODO: generate Id
APPOINTMENT CreateAppt(int id, char* title, struct tm start_time, int duration,  char* description, int appointment_status) {
    APPOINTMENT a;
    a.id = id;  // 8-digit   yyMMddId
    strncpy(a.title, title, MAXSIZE);
    a.start_time = start_time;
    a.duration_minutes = duration;
    //strncpy(a.location, location, MAXSIZE);
    strncpy(a.description, description, MAXTEXT);
    a.appointment_status = appointment_status;
    return a;
}




void DestroyAppt(APPOINTMENT* a) {

}




bool CopyAppt(APPOINTMENT* dest, APPOINTMENT src) {
    if (dest == NULL)
        return false;

    dest->id = src.id;
    strncpy(dest->title, src.title, MAXSIZE);
    dest->start_time = src.start_time;
    dest->duration_minutes = src.duration_minutes;
    //strncpy(dest->location, src.location, MAXSIZE);
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

    printf("Appointment ID: %d  ", appt.id);
    printf("  Title: %s , \n", appt.title);
    printf("  -Start Time: %s  ", start_time_str);
    printf("  Duration: %d minutes, \n", appt.duration_minutes);
    //printf("  -Location: %s\n", appt.location);
    printf("  -Description: %s\n", appt.description);

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
    case CANCELED: //outdated
        status_str = "Canceled";
        break;
    default :
        status_str = "None";
    }
    printf("  -Status: %s\n", status_str);
}


// get set
int GetApptId(APPOINTMENT appt) {
    return appt.id;
}

//edit uid not allowed
//void SetApptId(APPOINTMENT* appt, int id) {
//    appt->id = id;
//} 

void GetApptTitle(APPOINTMENT appt, char* title) {
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



//void GetApptLocation(APPOINTMENT appt, char* location) {
//    strncpy(location, appt.location, MAXSIZE);
//}
//
//void SetApptLocation(APPOINTMENT* appt, char* location) {
//    strncpy(appt->location, location, MAXSIZE);
//}

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


// I/O

void saveApptToDisk(APPOINTMENT appt, FILE* fp) {
    char start_time_str[MAXSIZE];

    //Dec 5   not sure
    strftime(start_time_str, MAXSIZE, "%Y-%m-%d %H:%M", &appt.start_time);

    //
    fprintf(fp,"appointment ID: %d\n", appt.id);
    fprintf(fp,"appointment_status: %d\n", appt.appointment_status);
    fprintf(fp,"title: %s\n", appt.title);
    fprintf(fp,"start Time: %s\n", start_time_str);
    fprintf(fp,"duration: %d minutes\n", appt.duration_minutes);
    //fprintf(fp,"location: %s\n", appt.location);
    fprintf(fp,"description: %s\n", appt.description);

}

APPOINTMENT LoadApptFromDisk(FILE* fp) {
    int num = 0;
    char line[MAXREAD];
    
    // properties
    int id;
    int appointment_status = NONE;
    char title[MAXSIZE];

    struct tm tm = { 0 }; // use struct tm to represent start time
    int duration_minutes; // duration minutes

    //char location[MAXSIZE];
    char description[MAXTEXT];

    // id
    fgets(line, MAXREAD, fp);
    num = sscanf(line, "appointment ID: %d", &id);
    // appointment_status
    fgets(line, MAXREAD, fp);
    num = sscanf(line, "appointment_status: %d", &appointment_status);
    // title
    fgets(line, MAXREAD, fp);
    if (sscanf(line, "title: %[^\n]", title) != 1)
        title[0] = '\0';
    // start_time
    fgets(line, MAXREAD, fp);
    int dd, mm, yy;
    num = sscanf(line, "start Time: %d-%d-%d %d:%d",
            &yy, &mm, &dd,
            &tm.tm_hour, &tm.tm_min);
    tm.tm_mday = dd;
    tm.tm_mon = mm - 1;
    tm.tm_year = yy - 1900;
    // duration
    fgets(line, MAXREAD, fp);
    num = sscanf(line, "duration: %d minutes", &duration_minutes);
    // location
    /*fgets(line, MAXREAD, fp);
    if (sscanf(line, "location: %[^\n]", location) != 1)
        location[0] = '\0';*/
    // description
    fgets(line, MAXREAD, fp);
    if (sscanf(line, "description: %[^\n]", description) != 1)
        description[0] = '\0';

    return CreateAppt(id, title, tm, duration_minutes, description, appointment_status);
}



