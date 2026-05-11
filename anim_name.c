/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:46:21 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/10 19:08:05 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	free_mem(void *pointer)
{
	if (pointer)
		free(pointer);
}

char	*make_filename(char *directory, int indicies)
{
	char	*indicies_str;
	char	*temp;
	char	*file_name;

	indicies_str = ft_itoa(indicies);
	temp = ft_strjoin(directory, indicies_str);
	file_name = ft_strjoin(temp, ".xpm");
	free(indicies_str);
	free(temp);
	return (file_name);
}

char	*while_split(char *directory, int indicies)
{
	int		i;
	char	*res;
	char	*temp;
	char	*temp2;

	i = 1;
	temp = ft_strdup("");
	temp2 = ft_strdup("");
	res = ft_strdup("");
	while (i < indicies + 1)
	{
		free_mem(temp);
		temp = make_filename(directory, i);
		free_mem(temp2);
		temp2 = ft_strjoin(res, temp);
		free_mem(res);
		if (i < indicies)
			res = ft_strjoin(temp2, ",");
		else
			res = ft_strdup(temp2);
		i++;
	}
	free_mem(temp);
	free_mem(temp2);
	return (res);
}

char	**anim_name(char *directory, int indicies)
{
	char	**split_res;
	char	*result;

	result = while_split(directory, indicies);
	if (!result)
		return (NULL);
	split_res = ft_split(result, ',');
	if (!split_res)
		return (free(result), NULL);
	free(result);
	return (split_res);
}
