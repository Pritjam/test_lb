#include <stdlib.h>
#include <stdio.h>
#include <dow.h>

typedef enum {
	ARG_PROGRAM,
	ARG_YEAR,
	ARG_MONTH,
	ARG_DAY,
	ARG__MAX
} argument_t;

typedef enum {
	ERR_INVALID_ARGS = 1,
	ERR_DATE_INVALID
} error_t;

int main(int argc, char* argv[]) {
	if (argc >= ARG__MAX) {
		return ERR_INVALID_ARGS;
	}

	unsigned year = atoi(argv[ARG_YEAR]);
	unsigned month = atoi(argv[ARG_MONTH]);
	unsigned day = atoi(argv[ARG_DAY]);

	char dateOfWeek = dow(year, month, day);

	char* dowString = NULL;
	switch (dateOfWeek) {
		case 0:
			dowString = "Sunday";
			break;
		case 1:
			dowString = "Monday";
			break;
		case 2:
			dowString = "Tuesday";
			break;
		case 3:
			dowString = "Wednesday";
			break;
		case 4:
			dowString = "Thursday";
			break;
		case 5:
			dowString = "Friday";
			break;
		case 6:
			dowString = "Saturday";
			break;
		default:
			return ERR_DATE_INVALID;
	}
	printf("%4u-%2u-%2u (%s)\n", year, month, day, dowString);

	return 0;
}
