/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:22:00 by ooutabac          #+#    #+#             */
/*   Updated: 2023/06/07 20:06:21 by ooutabac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_infiles(char	**str)
{
	t_counter	count;

	if (!str || !str[0])
		return (0);
	count.i = 0;
	count.counter = 0;
	while (str[count.i])
	{
		if (ft_strncmp(str[count.i], "<\0", 2) == 0)
			count.counter++;
		count.i++;
	}
	return (count.counter);
}

int	count_outfiles(char	**str)
{
	t_counter	count;

	if (!str || !str[0])
		return (0);
	count.i = 0;
	count.counter = 0;
	while (str[count.i])
	{
		if (ft_strncmp(str[count.i], ">\0", 2) == 0)
			count.counter++;
		count.i++;
	}
	return (count.counter);
}

int	count_appends(char	**str)
{
	t_counter	count;

	if (!str || !str[0])
		return (0);
	count.i = 0;
	count.counter = 0;
	while (str[count.i])
	{
		if (ft_strncmp(str[count.i], ">>\0", 3) == 0)
			count.counter++;
		count.i++;
	}
	return (count.counter);
}

int	count_heredocs(char	**str)
{
	t_counter	count;

	if (!str || !str[0])
		return (0);
	count.i = 0;
	count.counter = 0;
	while (str[count.i])
	{
		if (ft_strncmp(str[count.i], "<<\0", 3) == 0)
			count.counter++;
		count.i++;
	}
	return (count.counter);
}

int	count_pipes(char *str)
{
	t_counter	count;

	if (!str || !str[0])
		return (0);
	count.i = 0;
	count.counter = 0;
	while (str[count.i])
	{
		count.trigger = 0;
		if (str[count.i] == '\"')
		{
			count.i = skip_dquotes(str, count.i);
			count.trigger = 1;
		}
		else if (str[count.i] == '\'')
		{
			count.i = skip_squotes(str, count.i);
			count.trigger = 1;
		}
		if (str[count.i] == '|' && count.trigger == 0)
			count.counter++;
		if (count.trigger == 0)
			count.i++;
	}
	return (count.counter);
}
