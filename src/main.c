/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:22:36 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:49:41 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	t_rooms		*lst;
	t_rooms		*start;
	int			test;
	char		*line;

	test = 0;
	line = NULL;
	lst = malloc(sizeof(t_rooms));
	initiate_map();
	if (count_ants() <= 0)
		return (print_error());
	start = create_rooms(lst, line);
	if (check_format(start) == 0)
		return (print_error());
	find_start_end(start);
	fill_links(start);
	find_path(start);
	if (!g_result || !g_result[0])
		return (print_error());
	print_char_tab(g_map);
	walk_ants(g_result);
	clear_list(start);
	return (0);
}
