#include "monty.h"

/**
 * _strcmp - Function that compares two strings.
 * @s1: String 1.
 * @s2: String 2.
 *
 * Return: comparation.
 */

int _strcmp(char *s1, char *s2)
{
	int x = 0;

	while (s1[x])
	{
		if ((s1[x] > s2[x]) || (s1[x] < s2[x]))
		{
			return (s1[x] - s2[x]);
		}
		x++;
	}
	return (0);
}
