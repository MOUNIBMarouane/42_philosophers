/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killwa <killwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 09:50:46 by mamounib          #+#    #+#             */
/*   Updated: 2023/07/09 16:43:07 by killwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	while (s[i])	
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
int	ft_is_positives(t_info *info, int argc)
{
	if (info->nbr_philo <= 0 || info->time_to_die <= 0 
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0 )
		return 0;
	if (argc == 6 && info->times_must_eat <= 0)
		return 0;
	return (1);
	
}

void	ft_setargs(int argc, char **argv, t_info *info)
{
	info->nbr_philo = atoi(argv[1]);
	info->time_to_die = atoi(argv[2]);
	info->time_to_eat = atoi(argv[3]);
	info->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		info->times_must_eat = atoi(argv[5]);
	if (!ft_is_positives(info, argc))
		printf("error: invalid argument must enter a positive number\n");
}
// just positif number
// all is digits

void	ft_parce(int argc, char **argv, t_info *info)
{
	int i;
	
	i = argc;
	while (argc > 1)
	{
		if (ft_isnumber(argv[argc - 1]))
			argc --;
		else
		{
			printf("error: invalid argument");
			break;	
		}
	}
}
int main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
		ft_parce(argc, argv, NULL);
	else
		printf("error: syntax error: too many or less arguments");
	return 0;
}

