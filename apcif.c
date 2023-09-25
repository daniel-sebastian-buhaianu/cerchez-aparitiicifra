#include <stdio.h>

int apcif(int n, int k);

int main()
{
	int n, k;

	printf("n = ");
	scanf("%d", &n);

	printf("k = ");
	scanf("%d", &k);

	printf("apcif(%d, %d) = %d\n", n, k, apcif(n, k));

	return 0;
}

int apcif(int n, int k)
{
	if (n < 10)
	{
		return n >= k ? 1 : 0;
	} 
	else if (n < 100)
	{
		if (n < k*10)
		{
			return n/10 + (n%10 >= k);
		}
		else if (n >= k*10 && n <= (k+1)*10)
		{
			return k + (n - k*10 + 1);
		}
		else
		{
			return k + 10 + (n/10 - (k+1)) + (n%10 >= k);
		}
	}
	else
	{
		int aux, p;

		for (aux = n, p = 1; n; n /= 10, p *= 10);

		p /= 10, n = aux;

		if (n < k*p)
		{
			return n/100*apcif(99, k) + apcif(n%100, k);
		}
		else if (n >= k*p && n < (k+1)*p)
		{
			return n/p * p/100*apcif(99, k) + (n - k*p + 1);
		}
		else
		{
			return apcif((k+1)*p-1, k) + (n/100 - (k+1)*p/100)*apcif(99, k) + apcif(n%100, k);
		}

	}
}
