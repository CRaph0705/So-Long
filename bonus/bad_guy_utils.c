/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_guy_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:25:01 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/01 11:26:42 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_bad_guy	*new_bad_guy(int y, int x);
void		add_bad_guy(t_map *map, int y, int x);
void		set_bad_buy_pos(t_bad_guy *bad_guy, int x, int y);

void	add_bad_guy(t_map *map, int y, int x)
{
	t_bad_guy	*new;
	t_bad_guy	*cursor;

	new = new_bad_guy(y, x);
	if (!new)
		return ;
	printf("Ajout d'un bad guy en (%d, %d)\n", x, y);
	if (!map->baddies)
	{
		map->baddies = new;
		return ;
	}
	cursor = map->baddies;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = new;
}

t_bad_guy	*new_bad_guy(int y, int x)
{
	t_bad_guy	*new_bad_guy;

	new_bad_guy = malloc(sizeof(t_bad_guy));
	if (!new_bad_guy)
		return (NULL);
	new_bad_guy->pos_x = x;
	new_bad_guy->pos_y = y;
	new_bad_guy->next = NULL;
	return (new_bad_guy);
}

void	set_bad_buy_pos(t_bad_guy *bad_guy, int x, int y)
{
	if (bad_guy)
	{
		bad_guy->pos_x = x;
		bad_guy->pos_y = y;
	}
}
