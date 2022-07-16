#include <stdio.h>

int predios_visiveis(char p1, char p2, char p3, char p4);

int main(int argc, char *argv[])
{
	char p1;
	char p2;
	char p3;
	char p4;

	printf("Nome do programa: %s\n", argv[0]);
	printf("Quantidade de parâmetros recebidos: %d\n", argc);

	if (argc != 5)
	{
		printf("Reveja sua chamada, parça.\nTá cagado o numero de argumentos.\nPassa 4, vai!\n");
		return 0;
	}
	p1 = *argv[1];
	p2 = *argv[2];
	p3 = *argv[3];
	p4 = *argv[4];

	printf("Vai começar, hein...\n");
	printf("Temos %d prédios visíveis!\n", predios_visiveis(p1, p2, p3, p4));
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
