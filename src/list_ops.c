/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:46:42 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:49:38 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_lstadd_room(t_rooms *alst, t_rooms *new)
{
	t_rooms	*tmp;

	tmp = alst;
	alst->start = alst;
	while (alst->next)
		alst = alst->next;
	alst->next = new;
	new->start = tmp;
}

char	**dup_tab_path(char **path, char *str)
{
	char	**result;
	int		i;

	i = 0;
	while (path[i])
		i++;
	if (!(result = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	while (path[i])
	{
		result[i] = ft_strnew(1);
		result[i] = ft_strdup(path[i]);
		i++;
	}
	result[i] = ft_strdup(str);
	i++;
	result[i] = NULL;
	return (result);
}

void	free_list(t_rooms *start)
{
	int		i;

	i = 0;
	ft_strdel(&start->name);
	ft_strdel(&start->positiony);
	ft_strdel(&start->positionx);
	ft_strdel(&start->from);
	ft_strdel(&start->to);
	if (start->isroom == 1)
	{
		while (start->links[i]->from)
		{
			ft_strdel(&start->links[i]->from);
			i++;
		}
	}
}

void	clear_list(t_rooms *start)
{
	while (start)
	{
		free_list(start);
		start = start->next;
	}
}

void	free_char_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
}
