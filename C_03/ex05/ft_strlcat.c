/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamarra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:30:15 by jgamarra          #+#    #+#             */
/*   Updated: 2023/11/29 22:23:46 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	count_string(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned	int	count_string_size(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && i < size)
	{
		i++;
	}
	return (i);
}

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	left;
	unsigned int	j;
	unsigned int	len_dest;
	unsigned int	len_src;

	len_dest = count_string_size(dest, size);
	len_src = count_string(src);
	left = size - len_dest - 1;
	j = 0;
	while (j < left && src[j] != '\0')
	{
		dest[len_dest + j] = src[j];
		j++;
	}
	dest[len_dest + j] = '\0';
	return (len_dest + len_src);
}
/*
#include <stdio.h>
#include <string.h>
int main(void){
	char s1[10] = "123";
	char s2[20] = "abcdefghi";
	printf("%u\n",ft_strlcat(s1,s2, sizeof(s1)));
	printf("%s\n",s1);

	char s3[10] = "123";
	char s4[20] = "abcdefghi";
	printf("%zu\n",strlcat(s3,s4, sizeof(s1)));
	printf("%s\n",s3);
}
*/
