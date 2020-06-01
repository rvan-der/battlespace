/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 21:30:09 by rvan-der          #+#    #+#             */
/*   Updated: 2020/06/01 03:39:10 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp_rvan-der.h"

void				clean_ship_config(t_ship_config *config)
{
	int				i;

	i = 0;
	while (config->coords[i] != NULL)
		free(config->coords[i++]);
	free(config);
}

void				clean_game(t_game **game_adress)
{
	int				i;
	t_game			*game;

	game = *game_adress;
	i = 0;
	while (game->shipyard[i] != NULL)
		clean_ship_config(game->shipyard[i++]);
	free(game->board);
	free(game);
}