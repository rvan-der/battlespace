#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char	*str = "plouf";
	while (*str++)
		printf("%c\n", *str);
	return 0;
}

/* print armies and ships data
	char			*army_name;
	t_army			army;
	t_ship_config	**normal;
	t_ship_config	**annex;

	for (int a = 0; a < 3; a++) {
		army = game-> armies[a];
		army_name = "nation";
		if (a == 1)
			army_name = "mercenaires";
		if (a == 2)
			army_name = "aliens";
		printf(":%s\n", army_name);
		for (int s = 0; s < 5; s++) {
			normal = (t_ship_config**)army.ships[s].normal_configs;
			annex = (t_ship_config**)army.ships[s].annex_configs;
			printf("*ship %d\n-normal\n", s);
			for (int n = 0; normal[n] != NULL; n++) {
				for (int c = 0; normal[n]->coords[c] != NULL; c++) {
					printf("(%d, %d) ", normal[n]->coords[c]->x, normal[n]->coords[c]->y);
				}
				printf("\n");
			}
			printf("-annex\n");
			for (int an = 0; annex[an] != NULL; an++) {
				for (int c = 0; annex[an]->coords[c] != NULL; c++) {
					printf("(%d, %d) ", annex[an]->coords[c]->x, annex[an]->coords[c]->y);
				}
				printf("\n");
			}
		}
	}
*/
 