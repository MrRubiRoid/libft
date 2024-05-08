/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbalando <nbalando@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:08:00 by nbalando          #+#    #+#             */
/*   Updated: 2024/05/06 16:58:06 by nbalando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	int		i;
	char	*trimmed;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	begin = 0;
	while (s1[begin] != '\0' && ft_strchr(set, s1[begin]))
		begin++;
	end = ft_strlen(s1);
	while (end > begin && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed = (char *)malloc(sizeof(*s1) * (end - begin + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (begin < end)
		trimmed[i++] = s1[begin++];
	trimmed[i] = '\0';
	free(trimmed);
	return (trimmed);
}

int	main(int argc, char *argv[])
{
	char	*d;

	if (argc != 3)
	{
		printf("INPUT:      %s <string> <set>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	d = ft_strtrim(argv[1], argv[2]);
	printf("%s\n", d);
	return (0);
}