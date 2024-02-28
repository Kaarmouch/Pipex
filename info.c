/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 23:49:55 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/15 15:47:04 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	feed_info(t_info *doc, char *cmd, char **envp)
{
	doc->cmd_args = ft_split(cmd, ' ');
	doc->cmd_path = ft_getpath_clean(envp, doc->cmd_args[0]);
}

void	ft_testinfo(t_info *d, t_info *c)
{
	int	bug;

	bug = 0;
	if (d->fd < 0 || c->fd < 0)
	{
		ft_down(d);
		ft_down(c);
		bug += 1;
	}
	if (d->cmd_args == 0 || c->cmd_args == 0)
	{
		ft_down(d);
		ft_down(c);
		bug += 1;
	}
	if (d->cmd_path == 0 || c->cmd_path == 0)
	{
		ft_down(d);
		ft_down(c);
		bug += 1;
	}
	if (bug != 0)
		ft_out(0);
}

char	*ft_getpath_clean(char **envp, char *cmd)
{
	int		i;
	char	**path;
	char	*t_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strcmp(envp[i], "PATH="))
		{
			path = ft_split(&envp[i][5], ':');
			t_path = tru_path(path, cmd);
			return (t_path);
		}
		i++;
	}
	return (0);
}

char	*tru_path(char **clean_path, char *cmd)
{
	int		i;
	char	**s_cmd;
	char	*test_path;

	s_cmd = ft_split(cmd, ' ');
	i = 0;
	while (clean_path[i])
	{
		test_path = ft_strjoin_t(clean_path[i], "/", s_cmd[0]);
		if (access(test_path, F_OK | X_OK) == 0)
		{
			free_free(clean_path);
			free_free(s_cmd);
			return (test_path);
		}
		free(test_path);
		i++;
	}
	free_free(s_cmd);
	free_free(clean_path);
	return (0);
}
