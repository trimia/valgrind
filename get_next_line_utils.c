/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:04:51 by mmariani          #+#    #+#             */
/*   Updated: 2022/05/27 16:57:29 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		j;
	int		i;
	int		size;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	size = ft_strlen(s1) + ft_strlen(s2);
	if(!s2)
	{
		free(s1);
		return(NULL);
	}
	temp = malloc(sizeof(char) * (size + 1));
	if (temp == NULL)
		return (NULL);
	j = -1;
	while (s1[++j])
		temp[j] = s1[j];
	i = 0;
	while (s2[i])
		temp[j++] = s2[i++];
	temp[size] = '\0';
	free(s1);
	return (temp);
}

char *ft_newline(char *str, int c)
{
	int	i;

	i = -1;
	if(!str)
		return(0);
	if (c == '\0')
		return((char *) &str[ft_strlen(str)]);
	while(str[++i] != '\0')
		if(str[i] == (char) c)
			return((char *)&str[i]);
	return (0);
}

int ft_count(char *str)
{
	int i;

	i = 0;
	if(!str)
		return(0);
	if(str)
	{
		while(str[i] != '\n')
			i++;
		return (i);
	}
	return (0);
}

char	*trim_line(char *save)
{
	char	*toret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	toret = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!toret)
		return (NULL);
	i++;
	while (save[i])
		toret[j++] = save[i++];
	toret[j] = '\0';
	free(save);
	return (toret);
}