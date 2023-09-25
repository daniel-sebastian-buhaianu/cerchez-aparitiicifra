#include <stdio.h>

#define CIFREMAX 10

int N, K, NT = 0;
int C[CIFREMAX], P10[CIFREMAX]={1};

int main()
{
	int i, p, pcifra, aux;

	printf("n = ");
	scanf("%d", &N);
	aux = N;

	printf("k = ");
	scanf("%d", &K);

	for (i = 1; i < CIFREMAX; i++)
	{
		C[i] = 9*C[i-1] + P10[i-1];
		P10[i] = P10[i-1]*10;
	}

	for (p = CIFREMAX-1; p+1; p--)
	{
		if (N >= P10[p])
		{
			pcifra = N/P10[p]; // determin prima cifra a lui N

			if (pcifra > K)
			{
				NT += P10[p];
				NT += (pcifra-1)*C[p];
			}

			if (pcifra == K)
			{
				NT += pcifra*C[p];
				NT += N%P10[p]+1;
				break;
			}

			if (pcifra < K)
			{
				NT += pcifra*C[p];
			}

			N %= P10[p]; // eliminam prima cifra a lui N
		}
	}

	N = aux;

	printf("apcif(%d, %d) = %d\n", N, K, NT);

	return 0;
}
// sol oficiala
