#include <stdio.h>
#include <string.h>
#include <math.h>

void rabinK(char txt[], char pat[], int d, int q)
{
	int i, s, m, n, h = 1, hashP = 0, hashT = 0;
	n = strlen(txt);
	m = strlen(pat);
	//	printf("%d %d",m,n);
	h = (int)(pow(d, m - 1)) % q; // remmm
	for (i = 0; i < m; i++)
	{
		hashP = (d * hashP + pat[i]) % q;
		hashT = (d * hashT + txt[i]) % q;
	}
	for (s = 0; s <= n - m; s++)
	{
		if (hashP == hashT)
		{
			for (i = 0; i < m; i++)
			{
				if (pat[i] != txt[s + i])
				{ // forif forif
					break;
				}
			}
			if (i == m)
			{
				printf("Pattern Occured at index %d. \n", s);
			}
		}
		if (s < n - m)
		{
			hashT = (d * (hashT - (txt[s] * h)) + txt[s + m]) % q; // rem impp
			if (hashT < 0)
			{
				hashT += q;
			}
		}
	}
	return;
}

int main()
{
	int d, q;
	char txt[100], pat[100];
	printf("Enter Text: ");
	scanf("%s", &txt);
	printf("Enter Pattern: ");
	scanf("%s", &pat);
	d = 256; // rem
	q = 31;	 // rem
	rabinK(txt, pat, d, q);
	return 0;
}