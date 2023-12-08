// handle I/O stream
// program71985 - fall23 - zongping cui
#pragma once

#include <stdio.h>
#include <stdbool.h>

typedef enum readStatus {
	LINEFINISH = 1, LINENOTEND = 2, NOTREAD = 0
} READSTATUS;

// read part of stream
// return int:  1 finish reading a line
//				2 buffer full but line not end
//				0 error
int ReadStream(char* buffer, int size, FILE* fp);

// read only letters
bool ReadLettersInStream(char* buffer, int size, FILE* fp);

// convert and write
bool WriteToOutput(char* buffer, FILE* fp);

// remove trailing new line in buffer
void rmNewline(char* buffer);

bool format_check_letter(char* buffer);


