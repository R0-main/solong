/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/07 10:37:33 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>
// int	main()
// {

// 	char	*str = "1";
// 	char	*str2 = "2";
// 	t_list	*my_new_list = ft_lstnew(str2);
// 	t_list	*my_pile = ft_lstnew(str);

// 	ft_lstadd_back(&my_pile, my_new_list);
// 	printf("%s", (char *)my_pile->content);
// 	return (0);
// }
