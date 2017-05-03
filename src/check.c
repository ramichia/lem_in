/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:06:54 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:49:23 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_numbers(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			i++;
		else
			return (0);
	}
	if (10 < ft_strlen(str))
		return (0);
	return (1);
}

t_rooms	*check_map(t_rooms *room, t_rooms *start)
{
	int		i;

	i = 0;
	while (room->name[i])
	{
		if (room->name[i] == '-' || room->name[i] == '#')
			return (NULL);
		else
			i++;
	}
	if (room->name[0] == 'L' || room->name[0] == '#')
		return (NULL);
	if (check_numbers(room->positionx) == 0 || \
		check_numbers(room->positiony) == 0)
		return (NULL);
	room->x = ft_atoi(room->positionx);
	room->y = ft_atoi(room->positiony);
	while (start)
	{
		if (room->x == start->x && room->y == start->y)
			return (NULL);
		start = start->next;
	}
	return (room);
}

int		check_name_tube(char *str, t_rooms *start)
{
	while (start->isroom == 1)
	{
		if (ft_strcmp(str, start->name) == 0)
			return (1);
		start = start->next;
	}
	return (0);
}

int		check_name_rooms(t_rooms *lst, t_rooms *start)
{
	start = start->next;
	while (start)
	{
		if ((start->x == lst->x && start->y == lst->y) || \
			(ft_strcmp(start->name, lst->name) == 0))
			return (0);
		start = start->next;
	}
	return (1);
}

int		check_link_start(t_rooms *lst)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (lst->position == 1)
	{
		while (lst->links[i]->from)
		{
			if (lst->links[i]->dest->tracked == 0)
				count++;
			i++;
		}
		return (count);
	}
	return (0);
}
