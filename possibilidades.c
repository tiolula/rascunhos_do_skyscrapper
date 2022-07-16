#include <stdio.h>
#include <stdlib.h>

void avaliar_possibilidades(int a, int b);
int avaliar_possibilidade(int n, int p1, int p2, int p3, int p4);
int tem_1234(int p1, int p2, int p3, int p4);
int predios_visiveis(char p1, char p2, char p3, char p4);

int main()
{
	int i = 1;
	int j = 1;

	while (i <= 4)
	{
		j = 1;
		while (j <= 4)
		{
			avaliar_possibilidades(j, i);
			j++;
		}
		i++;
	}
}

void avaliar_possibilidades(int b, int a)
{
	int p1;
	int p2;
	int p3;
	int p4;
	int ida;
	int volta;

	p1 = 1;
	
	while (p1 <= 4)
	{
		p2 = 1;
		while (p2 <= 4)
		{
			p3 = 1;
			while (p3 <= 4)
			{
				p4 = 1;
				while (p4 <= 4)
				{
					ida = avaliar_possibilidade(b, p1, p2, p3, p4);
					volta = avaliar_possibilidade(a, p4, p3, p2, p1);

					if (ida != 0 && volta != 0)
						printf("%d, %d:  [%d, %d, %d, %d]\n", b, a, p1, p2, p3, p4);

					p4++;
				}
				
				p3++;
			}
			
			p2++;
		}
		
		p1++;
	}


}

// Retorna 0 se for impossível
int avaliar_possibilidade(int n, int p1, int p2, int p3, int p4)
{
	int pv;

	if (tem_1234(p1, p2, p3, p4) == 0)
		return 0;

	pv = predios_visiveis(p1, p2, p3, p4);

	if (pv == n)
		return 1;

	return 0;
}

// retorna 0 se não tiver 1, 2, 3 e 4 entre p1, p2, p3 e p4
int tem_1234(int p1, int p2, int p3, int p4)
{
	int total = 0;
	int i = 1;

	while (i <= 4)
	{
		if (p1 == i || p2 == i || p3 == i || p4 == i)
			total++;
		
		i++;
	}

	if (total == 4)
		return 1;

	return 0;

}

int predios_visiveis(char p1, char p2, char p3, char p4)
{
	int pv;

	pv = 1;

	if (p2 > p1)
		pv++;

	if (p3 > p2 && p3 > p1)
		pv++;

	if (p4 > p3 && p4 > p2 && p4 > p1)
		pv++;

	return pv;
}
