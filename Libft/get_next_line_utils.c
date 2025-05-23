/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:12:48 by flima             #+#    #+#             */
/*   Updated: 2024/12/05 18:34:10 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	i;

	if (s == NULL)
		return (NULL);
	slen = gnl_strlen(s);
	if (start > slen)
		return (gnl_strdup(""));
	if (len > slen - start)
		len = slen - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;
	size_t	totallen;

	if (!s1 || !s2)
		return (NULL);
	totallen = gnl_strlen(s1) + gnl_strlen(s2);
	newstr = (char *)malloc((totallen + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i++] = s2[j++];
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*gnl_strdup(const char *s)
{
	char			*dupstr;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	dupstr = (char *)malloc((gnl_strlen(s) + 1) * sizeof(char));
	if (dupstr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dupstr[i] = s[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(const char *str, int c)
{
	size_t	i;
	char	chr;

	i = 0;
	chr = (char)c;
	while (str[i])
	{
		if (str[i] == chr)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == chr)
		return ((char *)str + i);
	return (NULL);
}
