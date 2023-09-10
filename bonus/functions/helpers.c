#include "../main.h"

void	get_philos(t_philo *philos)
{
	t_philo	*philo;
	int		end;

	philo = philos;
	end = philo->info->nbr_philo;
	while (end)
	{
		if (philo->id_proc)
			printf("id phiolo :%d - pid : %d \n", philo->id_philo, philo->id_proc);
		philo = philo->next;
		end --;
	}
}