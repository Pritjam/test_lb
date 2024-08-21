typedef enum {
	GREGORIAN, // Begins 1752-09-14
	JULIAN     // Ends 1752-09-02
} Calendar;

int dow(unsigned year, unsigned month, unsigned day) {

	// Determine validity
	char isValid = !(year == 1752 && month == 9 && (day > 2 && day < 14));
	isValid &= year < 2400; // I don't have gregorian codes past 2400
	if (!isValid) {
		return -1;
	}

        // Determine gregorian or Julian
	char isJulian = year < 1752 || (year == 1752 && month < 9) ||
		(year == 1752 && month == 9 && day < 2);
	Calendar cal = isJulian ? JULIAN : GREGORIAN;

	// Calc year code
  unsigned yearCode = ((year % 100) + ((year % 100) / 4)) % 7;

	// Calc month Code
  static unsigned char monthCodes[] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };
	unsigned monthCode = monthCodes[month - 1];

	// Calc century code
	unsigned centuryCode;
	switch (cal) {
		case JULIAN:
			centuryCode = (18 - (year / 100)) % 7;
		case GREGORIAN:
			static unsigned char centuryCodes[] = {4,2,0,6,4,2,0};
			centuryCode = centuryCodes[(year / 100) - 17];
			break;
	}
	
	// Calc leap year (if it matters)
	char isLeapYear = month <= 2;
	switch (cal) {
		case JULIAN:
			isLeapYear &= year / 4;
			break;
		case GREGORIAN:
				isLeapYear &= ((year % 4) == 0) && (((year % 100) != 0) || 
			((year % 400) == 0));
			break;
	}

	// Calc DoW
	unsigned dayOfWeek = (yearCode + monthCode + centuryCode + day - isLeapYear) % 7;
	
	return dayOfWeek;
}
