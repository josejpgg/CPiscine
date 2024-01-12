/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamarra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:24:26 by jgamarra          #+#    #+#             */
/*   Updated: 2023/11/24 20:46:12 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
char *ft_strncpy(char *dest, char *src, unsigned int n);
int main(void){
	char s1[] = "123456";
	char s2[] = "321";
	printf("%s\n",ft_strncpy(s1,s2,sizeof(s1)));

	char s3[] = "123456";
	char s4[] = "321";
	printf("%s\n",ft_strncpy(s3,s4,sizeof(s3)));
}
*/