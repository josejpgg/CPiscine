/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamarra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:23:58 by jgamarra          #+#    #+#             */
/*   Updated: 2023/11/21 21:24:00 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 32;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + j;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if ((str[i] >= 97 && str[i] <= 122) && (f == 0))
		{
			str[i] = str[i] - 32;
			f = 1;
		}
		else if ((str[i] >= 65 && str[i] <= 90) && f == 1)
			str[i] = str[i] + 32;
		else if (str[i] >= 48 && str[i] <= 57)
			f = 1;
		else if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
			f = 0;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>
char *ft_strcapitalize(char *str);
int main(void){
	char s1[100] = "SALUT, comment tu vas ? 42mots quarante-deux; cinquante+ET+UN";
	//char s1[100] = "gfhdhjd skcnv 3jfl d:d:ertd_vx";

	printf("%s\n",ft_strcapitalize(s1));
}*/
