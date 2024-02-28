/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 23:49:55 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/15 15:47:04 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_down(t_info *doc)
{
	if (doc->cmd_args)
		free_free(doc->cmd_args);
	if (doc->cmd_path)
		free(doc->cmd_path);
	if (doc->fd)
		close(doc->fd);
}

void	free_free(char **tabs)
{
	int	i;

	i = 0;
	while (tabs[i])
	{
		free(tabs[i]);
		i++;
	}
	free(tabs);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_getnxt(s, '\0'));
}

void	ft_out(int p)
{
	if (p == 3)
		ft_putstr_fd("We broke the pipe !!!\n", 2);
	if (p == 0)
		ft_putstr_fd("Wrong input patern\n", 2);
	if (p == 1)
		ft_putstr_fd("file problemes\n", 2);
	if (p == 2)
		ft_putstr_fd("CMD unacesible\n", 2);
	exit(EXIT_FAILURE);
}
