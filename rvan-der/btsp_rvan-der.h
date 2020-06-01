/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btsp_rvan-der.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 01:31:32 by rvan-der          #+#    #+#             */
/*   Updated: 2020/06/01 03:19:37 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTSP_RVAN_DER_H
# define BTSP_RVAN_DER_H

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BOARD_SZ 100
# define MAX_MOVES 200
# define MAX_SHIPS 500
# define MAX_COORDS 10

typedef enum			e_config_type
{
	normal,
	annex
}						t_config_type;

typedef enum			e_army_name
{
	nation,
	mercenaires,
	aliens,
	nul
}						t_army_name;

typedef enum			e_state
{
	hidden,
	miss,
	hit,
	sunk,
	mine
}						t_state;

typedef struct			s_coords
{
	int					x;
	int					y;
}						t_coords;

typedef struct			s_ship_config
{
	unsigned			index;
	t_config_type		type;
	unsigned			width;
	unsigned			height;
	t_coords			*coords[10];
}						t_ship_config;

typedef struct			s_ship
{
	t_ship_config		*normal_configs[4];
	t_ship_config		*annex_configs[80];
}						t_ship;

typedef struct			s_army
{
	t_ship				ships[5];
	unsigned			**configs;
}						t_army;

typedef struct			s_cell
{
	char				name[3];
	t_state				state;
}						t_cell;

typedef struct			s_game
{
	t_cell				*board;					
	t_ship_config		*shipyard[MAX_SHIPS];
	t_army				armies[3];
	t_army_name			identified[4];
	char				*moves[MAX_MOVES];
	unsigned			mine_found;
	unsigned			shield_found;
	unsigned			hits;
	unsigned			sunken;
	unsigned			blocked;
	unsigned			missed;
}						t_game;

int						read_armies(t_game *game);
t_coords				*new_coords(int x, int y);
void					push_to_array(void *elem, void **array);
void					scrap_file(int fd, char **content);
void					clean_game(t_game **game_adress);

#endif
