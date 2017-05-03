/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:33:10 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:49:49 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		print_error(void)
{
	ft_printf("ERROR\n");
	return (0);
}

int		check_format(t_rooms *start)
{
	t_rooms	*tmp;
	int		count;

	tmp = start;
	count = 0;
	while (tmp)
	{
		count = count + tmp->position;
		tmp = tmp->next;
	}
	if (count != 3)
		return (0);
	tmp = start;
	count = 0;
	while (tmp)
	{
		if (tmp->isroom == 0)
			count++;
		tmp = tmp->next;
	}
	if (count == 0)
		return (0);
	return (1);
}

void	clean_tracked(t_rooms *start)
{
	while (start->isroom == 1)
	{
		start->tracked = 0;
		start = start->next;
	}
}

int		is_already_in_tab(char *str, char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], str) == 0)
			return (0);
		i++;
	}
	return (1);
}

t_rooms	*find_room(char *str, t_rooms *start)
{
	while (ft_strcmp(str, start->name) != 0)
		start = start->next;
	return (start);
}
