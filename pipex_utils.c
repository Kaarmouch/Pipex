/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 23:49:55 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/15 15:47:04 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_strcpy(char *str, char *dest)
{
	int	id;

	id = 0;
	while (str[id])
	{
		dest[id] = str[id];
		id += 1;
	}
	dest[id] = '\0';
}

int	ft_strcmp(char *test, char *goal)
{
	int	i;

	i = 0;
	while (goal[i])
	{
		if (test[i] == goal[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_getnxt(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin_t(char *strt, char *mid, char *end)
{
	int		i;
	int		nb_char;
	char	*new_str;

	if (!strt || !mid || !end)
		return (0);
	nb_char = (ft_getnxt(strt, '\0') + ft_getnxt(end, '\0'));
	new_str = malloc(sizeof(char) * (nb_char + 1 + ft_getnxt(mid, '\0')));
	if (!new_str)
		return (0);
	i = 0;
	ft_strcpy(strt, &new_str[i]);
	i = ft_strlen(new_str);
	ft_strcpy(mid, &new_str[i]);
	i = ft_strlen(new_str);
	ft_strcpy(end, &new_str[i]);
	return (new_str);
}
