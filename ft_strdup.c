/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:54:28 by brehaili          #+#    #+#             */
/*   Updated: 2013/12/15 13:31:31 by thenice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		len;

	len = ft_strlen(s1);
	ret = (char *) malloc(sizeof(char) * len + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, len);
	ret[len] = '\0';
	return (ret);
}
