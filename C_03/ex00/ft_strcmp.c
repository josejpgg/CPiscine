/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamarra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:36:53 by jgamarra          #+#    #+#             */
/*   Updated: 2023/11/16 19:36:55 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 != '\0')
	{
		return (-*s2);
	}
	else if (*s1 != '\0' && *s2 == '\0')
	{
		return (*s1);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);
int main(void){
	char s1[] = "hola1";
	char s2[] = "hola1";

	printf("%i\n",ft_strcmp(s1,s2));
	printf("%i",strcmp(s1,s2));
}*/