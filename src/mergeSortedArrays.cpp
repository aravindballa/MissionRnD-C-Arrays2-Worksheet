/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int IsSmaller(char *date1, char *date2)
{
	int i;

	for (i = 6; i <= 9; i++)
	{
		if (date1[i] > date2[i]) return 2;
		else if (date1[i] < date2[i]) return 1;
		else {}
	}

	for (i = 3; i <= 4; i++)
	{
		if (date1[i] > date2[i]) return 2;
		else if (date1[i] < date2[i]) return 1;
		else {}
	}

	for (i = 0; i <= 1; i++)
	{
		if (date1[i] > date2[i]) return 2;
		else if (date1[i] < date2[i]) return 1;
		else {}
	}

	return 0;
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, j = 0, k = 0;
	if (A == NULL || ALen < 1 || B == NULL || BLen < 1)
		return NULL;
	struct transaction *output = (struct transaction*)malloc(sizeof(struct transaction) * (ALen + BLen));

	while (i < ALen && j < BLen)
	{
		if (IsSmaller(A[i].date, B[j].date) == 1)
		{
			output[k++] = A[i];
			i++;
		}
		else if (IsSmaller(A[i].date, B[j].date) == 2)
		{
			output[k++] = B[j];
			j++;
		}
		else
		{
			output[k++] = B[j];
			output[k++] = B[j];
			j++; i++;
		}
	}

	if (j>=BLen)
		for (; i < ALen; i++)
			output[k++] = A[i];
	if (i>=ALen)
		for (; j < BLen; j++)
			output[k++] = B[j];

	return output;
}