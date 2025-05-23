/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:06:44 by flima             #+#    #+#             */
/*   Updated: 2025/04/27 16:19:40 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char	**ft_makearray(char **array, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	nstr;
	size_t	lenstr;

	i = 0;
	nstr = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			lenstr = i - start;
			array[nstr] = ft_substr(s, start, lenstr);
			if (array[nstr] == NULL)
				return (ft_free(array));
			nstr++;
		}
	}
	array[nstr] = NULL;
	return (array);
}

static size_t	ft_countchr(char const *s, char c)
{
	unsigned int	counter;
	int				i;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			counter++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**array_strs;
	char	**temp;

	if (s == NULL || s[0] == '\0')
		return (NULL);
	array_strs = (char **)malloc((ft_countchr(s, c) + 1) * sizeof(char *));
	if (!array_strs)
		return (NULL);
	temp = ft_makearray(array_strs, s, c);
	if (temp == NULL)
		return (NULL);
	return (array_strs);
}

// int main()
// {
// 	char **array_strs;
//     // char str[] = "ccccccccccccccctcf";
//     // char c = 'c';
// 	unsigned int i;

// 	// printf("%zu\n", ft_countchr(str, c));
// 	i = 0;
// 	array_strs = ft_split("hello!", ' ');
// 	while (array_strs[i])
// 	{
// 		printf("%s\n", array_strs[i]);
// 		i++;
// 	}
// 	ft_free(array_strs);
// 	return (0);
// }
