/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 23:49:55 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/15 15:47:04 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_info
{
	int		fd;
	char	**cmd_args;
	char	*cmd_path;
}	t_info;

char	*tru_path(char **clean_path, char *cmd);
char	*ft_strjoin_t(char *strt, char *mid, char *end);
char	*ft_getpath_clean(char **envp, char *cmd);
char	**ft_split(char *str, char c);
int		ft_getnxt(char *str, char c);
int		ft_countwrd(char *str, char c);
int		ft_strcmp(char *test, char *goal);
int		ft_strlen(char *s);
void	ft_testinfo(t_info *d, t_info *c);
void	feed_info(t_info *doc, char *cmd, char **envp);
void	ft_strncpt(char *src, char *dest, int n);
void	free_free(char **tabs);
void	ft_down(t_info *doc);
void	ft_strcpy(char *str, char *dest);
void	ft_putstr_fd(char *s, int fd);
void	execute_command(char *cmd, char **clean_path);
void	ft_parent(t_info *s_info, int *pipes);
void	ft_child(t_info *s_info, int *pipes);
void	ft_out(int p);

#endif
