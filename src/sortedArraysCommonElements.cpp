/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int Compare(char *date1, char *date2)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		if (date1[i] != date2[i])
			return 0;
	}

	return 1;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i, j, k = 0;
	if (A == NULL || ALen < 1 || B == NULL || BLen < 1)
		return NULL;

	struct transaction *output = (struct transaction*)malloc(sizeof(struct transaction)*3);

	for(i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			if (Compare(A[i].date, B[j].date) == 1)
			{
				output[k++] = B[j];
			}
		}
	}

	if (k == 0)
		return NULL;

	return output;
}