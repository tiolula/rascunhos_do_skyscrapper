#include <stdio.h>

int calcular(int *entrada, int *predios_visiveis, int posicao_atual);

int main()
{
	int entrada[] = {3, 1, 2, 4};
	int predios_visiveis;
	int resultado;

	predios_visiveis = 1;
	resultado = calcular(entrada, &predios_visiveis, 0);

	printf("Predios Visíveis: %d\n", resultado);
}

int calcular(int *entrada, int *predios_visiveis, int posicao_atual)
{
	int inicial;
	int atual;
	int i;
	
	i = posicao_atual;
	inicial = *entrada;
	while(i < 4)
	{
		atual = *entrada;
		
		printf("inicial = %d\n", inicial);
		printf("atual = %d\n", atual);	
		printf("\n");
		if(inicial < atual)
		{
			*predios_visiveis = *predios_visiveis + 1;
			printf("Mais um visível, viva! Predios visíveis: %d\n", *predios_visiveis);	
			calcular(entrada, predios_visiveis, i);
			break;
		}
		
		i++;
		entrada++;
	}

	return *predios_visiveis;
}
