/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:31:48 by rvan-der          #+#    #+#             */
/*   Updated: 2020/06/01 03:23:28 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp_rvan-der.h"

t_coords				*new_coords(int x, int y)
{
	t_coords			*coords;

	coords = (t_coords*)malloc(sizeof(t_coords));
	coords->x = x;
	coords->y = y;
	return (coords);
}

void					push_to_array(void *elem, void **array)
{
	int					i;

	i = 0;
	while (array[i] != NULL)
		i++;
	array[i] = elem;
}

void					scrap_file(int fd, char **content)
{
	char				buff[8192];
	int					ret;
	unsigned			i;
	size_t				len;
	int					content_top;

	ret = read(fd, buff, 8192);
	buff[ret] = '\0';
	i = 0;
	while (buff[i] != '\0')
	{
		while (buff[i] == '\n')
			i++;
		len = 0;
		while (buff[i + len] != '\0' && buff[i + len] != '\n')
			len++;
		if (len > 0)
			content[content_top++] = ft_strsub(buff, i, len);
		i += len;
	}
	content[content_top] = NULL;
}