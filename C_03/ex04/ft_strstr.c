/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamarra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:29:12 by jgamarra          #+#    #+#             */
/*   Updated: 2023/11/29 22:26:31 by jgamarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*find;
	char	*string;

	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str != '\0')
	{
		find = to_find;
		string = str;
		while ((*find != '\0') && (*string == *find))
		{
			string++;
			find++;
		}
		if (*find == '\0')
		{
			return (str);
		}
		str++;
	}
	return (0);
}
/*
#include <string.h>
int main(void){
	char s1[50] = "a+bc";
	char s2[] = "+-";
	char *ptr1 = ft_strstr(s1,s2);
	printf("%s\n",ptr1);
	
	char s3[50] = "a+bc";
	char s4[] = "+-";
	char *ptr2 = strstr(s3,s4);;
	printf("%s\n",ptr2);
	return 0;
}
*/
