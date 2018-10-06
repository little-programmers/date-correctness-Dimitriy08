#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool date_correctness(int day, int month, int year) {
	if (year < 0 || month <= 0 || month > 12) {
		return false;
	}
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day > 0 && day <= 31)
				return true;
			else
				return false;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 0 && day < 31)
				return true;
			else
				return false;
		}
		else if (month == 2) {
			if (day > 0 && day <= 29)
				return true;
			else
				return false;
		}
	}
	else
		if (month == 2) {
			if (day > 0 && day < 29)
				return true;
			else
				return false;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day > 0 && day <= 31)
				return true;
			else
				return false;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day > 0 && day < 31)
				return true;
			else
				return false;
		}
	return false;
}

void test_date_correctness() {
	assert(date_correctness(1, 1, 2018));
	assert(date_correctness(30, 5, 1999));
	assert(date_correctness(31, 12, 100));
	assert(date_correctness(31, 8, 2016));
	assert(date_correctness(29, 2, 2400));
	assert(!date_correctness(31, 4, 3000));
	assert(!date_correctness(-1, 3, 1));
	assert(!date_correctness(1, -3, 1));
	assert(!date_correctness(1, 3, -1));
	assert(!date_correctness(2, 13, 2001));
	assert(!date_correctness(40, 5, 777));
	assert(!date_correctness(29, 2, 1900));

	printf("Òåñòû ïðîøëè óñïåøíî!\n");
}

int main() {
	test_date_correctness();
	return 0;
}