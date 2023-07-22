/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamounib <mamounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:43:16 by mamounib          #+#    #+#             */
/*   Updated: 2023/07/22 11:44:54 by mamounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>


int main(int argc, char **argv)
{
	t_info info;
	
	if (argc == 5 || argc == 6)
	{
		ft_parce(argc, argv, &info);
		get_info(info);
	}
	else
		printf("error: syntax error: too many or less arguments");
	return 0;
}
