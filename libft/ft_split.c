/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:53:49 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/03 21:44:21 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **result, int count)
{
	int	j;

	j = 0;
	while (j < count)
		free(result[j++]);
	free(result);
}

static int	set_split(char const *s, char **result, char c)
{
	int	i;
	int	k;
	int	start;

	i = 0;
	k = 0;
	start = 0;
	while (s[k])
	{
		if (s[k] != c && (k == 0 || s[k - 1] == c))
			start = k;
		if (s[k] != c && (s[k + 1] == c || s[k + 1] == '\0'))
		{
			result[i] = ft_substr(s, start, k - start + 1);
			if (!result[i])
			{
				free_split(result, i);
				return (0);
			}
			i++;
		}
		k++;
	}
	result[i] = NULL;
	return (1);
}

static int	count_words(char const *s, char c)
{
	int		character_count;
	int		i;
	int		k;

	k = 0;
	character_count = 0;
	i = 0;
	while (s[k])
	{
		if (s[k] != c && i == 0)
		{
			character_count++;
			i = 1;
		}
		else if (s[k] == c)
			i = 0;
		k++;
	}
	return (character_count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!set_split(s, result, c))
		return (NULL);
	return (result);
}
