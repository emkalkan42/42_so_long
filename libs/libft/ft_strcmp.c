/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:08:23 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/16 20:03:19 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
	{
		++i;
	}
	return (s1[i] - s2[i]);
}

/*#include <stdio.h>
#include "libft.h"

int main(void)
{
    char *s1 = "Hello";
    char *s2 = "Hello, world!";
    char *s3 = "World";
    int n = 5;

    printf("Comparing s1 and s2 for %d 
	characters: %d\n", n, ft_strncmp(s1, s2, n));
    printf("Comparing s2 and s3 for %d 
	characters: %d\n", n, ft_strncmp(s2, s3, n));
    printf("Comparing s3 and s1 for %d 
	characters: %d\n", n, ft_strncmp(s3, s1, n));

    return 0;
}*/