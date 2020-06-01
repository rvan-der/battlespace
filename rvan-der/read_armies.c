/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_armies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:51:36 by rvan-der          #+#    #+#             */
/*   Updated: 2020/06/01 03:33:47 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp_rvan-der.h"

/*
** WARNING: this is horrible code but my hands are forced by the coding norm
** of 42
*/

t_army_name				parse_army_name(char *name)
{
	if (!ft_strncmp("NATION", name, 6))
		return (nation);
	if (!ft_strncmp("MERCENAIRES", name, 11))
		return (mercenaires);
	if (!ft_strncmp("ALIENS", name, 6))
		return (aliens);
	return (nul);
}

t_ship_config			*new_ship_config(t_config_type type, unsigned index)
{
	t_ship_config		*config;
	unsigned			i;

	config = (t_ship_config*)malloc(sizeof(t_ship_config));
	config->index = index;
	config->type = type;
	i = 0;
	while (i < MAX_COORDS)
		config->coords[i++] = NULL;
	return (config);
}

t_ship_config			*parse_shp_cfg(t_ship *ship, t_config_type type, \
									char **content, unsigned shipyard_index)
{
	t_coords			i;
	t_ship_config		*config;
	unsigned			top_coords;

	top_coords = 0;
	config = new_ship_config(type, shipyard_index);
	config->width = ft_atoi(content[0]);
	config->height = ft_atoi(content[0] + 2);
	i.y = -1;
	while (++(i.y) < (int)config->height)
	{
		i.x = -1;
		while (++(i.x) < (int)config->width)
			if (content[i.y + 1][i.x] == '#')
				config->coords[top_coords++] = new_coords(i.x, i.y);
	}
	if (type == normal)
		push_to_array((void*)config, (void**)ship->normal_configs);
	else
		push_to_array((void*)config, (void**)ship->annex_configs);
	return (config);
}

void					parse_armies(char **content, t_game *game)
{
	int					i;
	unsigned			ind;
	t_army				*army;
	t_ship				*ship;
	t_config_type		type;

	i = -1;
	ind = 0;
	while (content[++i] != NULL)
	{
		if (content[i][0] == ':')
			army = &(game->armies[parse_army_name(content[i] + 1)]);
		else if (content[i][0] == '*')
			ship = &(army->ships[ft_atoi(content[i] + 5)]);
		else if (content[i][0] == '-')
			type = !ft_strncmp(content[i] + 1, "annex", 5) ? annex : normal;
		else
		{
			game->shipyard[ind] = parse_shp_cfg(ship, type, content + i, ind);
			i += game->shipyard[ind++]->height;
		}
	}
}

int						read_armies(t_game *game) {
	int					fd;
	int					i;
	char				*content[2000];

	if ((fd = open("armies.txt", O_RDONLY)) < 0)
		return (1);
	scrap_file(fd, (char**)content);
	close(fd);
	parse_armies((char**)content, game);
	i = 0;
	while (content[i] != NULL)
		free(content[i++]);
	return (0);
}