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
#include "pipex.h"

void	ft_child(t_info *s_info, int *pipes)
{
	dup2(s_info->fd, 0);
	dup2(pipes[1], 1);
	close(pipes[0]);
	execve(s_info->cmd_path, s_info->cmd_args, NULL);
	ft_down(s_info);
}

void	ft_parent(t_info *s_info, int *pipes)
{
	dup2(s_info->fd, 1);
	dup2(pipes[0], 0);
	close(pipes[1]);
	execve(s_info->cmd_path, s_info->cmd_args, NULL);
	ft_down(s_info);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipes_fd[2];
	t_info	d_info;
	t_info	c_info;
	pid_t	pid;

	(&d_info)->fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	(&c_info)->fd = open(argv[1], O_RDONLY, 0777);
	feed_info(&d_info, argv[3], envp);
	feed_info(&c_info, argv[2], envp);
	ft_testinfo(&d_info, &c_info);
	if (pipe(pipes_fd) == -1)
		ft_out(0);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		ft_child(&c_info, pipes_fd);
	ft_parent(&d_info, pipes_fd);
	return (argc);
}
