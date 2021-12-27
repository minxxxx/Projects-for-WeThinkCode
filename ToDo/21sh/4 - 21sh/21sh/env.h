/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 18:05:57 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 16:55:28 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft/libft.h"
# include "parser.h"

/*
*** rules : add, load, remove, get, update, print && myenv
*/

char	**myenv_control_tower(char **envp, char *var, char *line, char *rule);
char	**ft_load_myenv(char **envp);
char	*ft_join_var_line(char *var, char *line);
char	**ft_add_line_myenv(char **myenv, char *var, char *line);
char	**ft_update_myenv(char **myenv, char *var, char *line);
char	*ft_get_line_myenv(char **myenv, char *var);
char	**ft_remove_line_myenv(char **myenv, char *var);
void	ft_print_myenv(char **myenv);

/*
*** returns 1 when var is found, or 0
*/
int		ft_check_var_exist_myenv(char **myenv, char *var);

/*
*** cd functions
*/
int		ft_check_path_access(char *path);
int		ft_change_dir2(char **split, t_parser **hq);
int		ft_change_dir_to_home(t_parser **hq);
int		ft_change_dir3(char **s, t_parser **hq);
void	ft_update_cd_env(char **new, char **old, char **pwd, t_parser **hq);
void	ft_change_dir(char **split, t_parser **hq);

#endif
