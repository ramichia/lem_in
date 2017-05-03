/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:17:34 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:57:33 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef	struct				s_rooms
{
	char					*name;
	char					*positionx;
	char					*positiony;
	int						x;
	int						y;
	int						tracked;
	int						position;
	int						isroom;
	char					*from;
	char					*to;
	struct s_rooms			*next;
	struct s_rooms			*start;
	struct s_links			**links;
}							t_rooms;

typedef	struct				s_links
{
	char					*from;
	struct s_rooms			*dest;
}							t_links;

typedef	struct				s_ants
{
	int						name;
	int						room;
	int						done;
}							t_ants;

char						*g_start;
char						*g_end;
char						**g_result;
int							g_nbants;
char						**g_map;
int							g_index;

int							count_ants(void);
void						ft_lstadd_room(t_rooms *alst, t_rooms *new);
t_rooms						*read_rooms(char *line, t_rooms *start);
t_rooms						*create_rooms(t_rooms *lst, char *line);
t_rooms						*read_tube(char *line);
t_rooms						*check_map(t_rooms *room, t_rooms *start);
int							check_name_tube(char *str, t_rooms *start);
int							check_name_rooms(t_rooms *lst, t_rooms *start);
char						**dup_tab_path(char	**path, char *str);
void						find_start_end(t_rooms *start);
void						fill_links(t_rooms *start);
void						ft_lstadd_links(t_links *alst, t_links *new);
void						find_path(t_rooms *start);
void						cut_last_room(char **tab, t_rooms *start);
t_rooms						*get_next_room(t_links **tab, char **tabus);
char						**rec_path(char **tab, int i, t_rooms *start);
int							last_index(char **tab);
int							get_last_tab(char **tab, t_rooms *start);
char						**initiate_tab(void);
int							is_already_in_tab(char *str, char **tab);
char						**copytab(char **tab);
void						real_rec_path(char **tab, int i, t_rooms *start);
int							check_link_end(t_rooms *start);
int							check_format(t_rooms *start);
int							print_error(void);
int							check_link_start(t_rooms *lst);
int							walk_ants(char **path);
int							print_map(t_rooms *start);
void						clear_list(t_rooms *start);
void						free_char_tab(char **tab);
void						free_list(t_rooms *start);
int							start_end(char *line);
void						clean_tracked(t_rooms *start);
int							is_already_in_tab(char *str, char **tab);
t_rooms						*find_room(char *str, t_rooms *start);
void						initiate_map(void);

#endif
