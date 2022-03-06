#include<stdio.h>
#define n 4
int main(void)
{
	int D[n][n], S[n], Sum, I, j, K, L, Dtemp, Found;
	S[0] = 0;
	Sum = 0;
	D[0][1] = 2;
	D[0][2] = 6;
	D[0][3] = 5;
	D[1][0] = 2;
	D[1][2] = 4;
	D[1][3] = 4;
	D[2][0] = 6;
	D[2][1] = 4;
	D[2][3] = 2;
	D[3][0] = 5;
	D[3][1] = 4;
	D[3][2] = 2;
	I = 1;/*please notice that the process begin from 0,but the graph begin from 1,following is the same as what i have said.*/
	do {/*I circles from 1 to n-1*/
		K = 1;
		Dtemp = 10000;
		do {/*K circles from 1 to n-1*/
			L = 0;
			Found = 0;
			do {/*L circles from 1 to I*/
				if (S[L] == K)
				{
					Found = 1;
					break;
				}
				else L += 1;
			} while (L < I);/*L circles from 1 to I*/
			if (Found == 0 && D[K][S[I - 1]] < Dtemp)
			{
				j = K;
				Dtemp = D[K][S[I - 1]];
			}
			K += 1;
		} while (K < n);/*K circles from 1 to n-1*/
		S[I] = j;
		I += 1;
		Sum += Dtemp;
	} while (I < n);/*I circles from 1 to n-1*/
	Sum += D[1][j];
	for (j = 0; j < n; j++)
	{
		printf("%d", S[j]);
	}/*output the numbers of the cities*/
	printf("\n");
	printf("total length:%d", Sum);
}