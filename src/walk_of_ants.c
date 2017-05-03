/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_of_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 20:20:52 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:49:52 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	build_the_struct(t_ants *anthill)
{
	int		i;

	i = 0;
	while (i < g_nbants)
	{
		anthill[i].name = i + 1;
		anthill[i].room = -1;
		anthill[i].done = 0;
		i++;
	}
}

int		print_ants(t_ants *anthill, char **path)
{
	int		i;
	int		k;
	int		count;

	i = 0;
	count = 0;
	k = last_index(path);
	while (anthill[i].name)
	{
		if (k < anthill[i].room)
		{
			anthill[i].done = 1;
			count++;
		}
		if (0 < anthill[i].room && anthill[i].done == 0)
			ft_printf("L%d-%s ", anthill[i].name, path[anthill[i].room]);
		i++;
	}
	if (count == g_nbants)
		return (1);
	ft_printf("\n");
	return (0);
}

int		walk_ants(char **path)
{
	int		i;
	int		j;
	t_ants	*anthill;

	anthill = (t_ants*)malloc(sizeof(t_ants) * (g_nbants));
	build_the_struct(anthill);
	i = 0;
	while (1)
	{
		j = 0;
		while (j <= i && j < g_nbants)
		{
			anthill[j].room++;
			j++;
		}
		if (print_ants(anthill, path) == 1)
		{
			free(anthill);
			return (0);
		}
		i++;
	}
	free(anthill);
	return (0);
}

void	initiate_map(void)
{
	int		i;

	i = 0;
	g_map = (char**)malloc(sizeof(char*) * 10000);
	while (i < 10000)
	{
		g_map[i] = NULL;
		i++;
	}
	g_index = 0;
}
