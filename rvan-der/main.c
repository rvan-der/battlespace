/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 21:29:09 by rvan-der          #+#    #+#             */
/*   Updated: 2020/06/01 13:07:54 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp_rvan-der.h"
#include <stdio.h>

void				init_static_arrays(t_game *game)
{
	int				i;
	int				j;
	int				k;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 5)
		{
			k = 0;
			while (k < 4)
				game->armies[i].ships[j].normal_configs[k++] = NULL;
			k = 0;
			while (k < 80)
				game->armies[i].ships[j].annex_configs[k++] = NULL;
		}
	}
	i = 0;
	while (i < MAX_MOVES)
		game->moves[i++] = NULL;
	i = 0;
	while (i < MAX_SHIPS)
		game->shipyard[i++] = NULL;
}

t_cell				*init_board(void)
{
	t_cell			*board;
	int				i;

	if ((board = (t_cell*)malloc(sizeof(t_cell) * BOARD_SZ)) == NULL)
		return (NULL);
	i = 0;
	while (i < 100)
	{
		board[i].name[0] = 'A' + i / 10;
		board[i].name[1] = '0' + i % 10;
		board[i].name[2] = '\0';
		board[i].state = hidden;
		i++;
	}
	return (board);
}

t_game				*init_game(void)
{
	t_game			*game;

	if ((game = (t_game*)malloc(sizeof(t_game))) == NULL)
		return (NULL);
	if ((game->board = init_board()) == NULL)
		return (NULL);
	init_static_arrays(game);
	read_armies(game);
	game->identified[0] = nation;
	game->identified[1] = mercenaires;
	game->identified[2] = aliens;
	game->identified[3] = nul;
	game->mine_found = 0;
	game->shield_found = 0;
	game->hits = 0;
	game->sunken = 0;
	game->blocked = 0;
	game->missed = 0;
	return (game);
}

int					main(void)
{
	t_game			*game;
	char			*result;

	if ((game = init_game()) == NULL)
		return 1;
	make_move(game, random_move(game));
	while (scrap_file(0, &result))
	{
		
	}
	clean_game(&game);
	return (0);
}
