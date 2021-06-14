# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"


void ft_exit_error()
{
    printf("error only integer numbers\n");
    exit(1);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (0);
	return (1);
}

int	ft_is_integer(char *str)
{
	int	i;
	int	flsig;
	int	flnb;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_int(const char *str)
{
	int						sign;
	unsigned long long int	result;

	sign = 1;
	result = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	if (*str == '\0')
		ft_exit_error();
	while (!ft_isdigit(*str) && *str)
	{
		result = result * 10 + *str - '0';
		str++;
		if ((result > 2147483647) && sign >= 0)
			ft_exit_error();
		if ((result > 2147483648) && sign < 0)
			ft_exit_error();
	}
	return (sign * result);
} 

int main(int argn, char **args)
{
    if (argn!=3)
    {
        printf(" No arguments, [initial number] [total numbers]\n");
        exit(0);
    }

    int nb_begin;
    int nb_max;
    int *m1;
    int *m2;

    nb_begin = ft_atoi_int(args[1]);
    nb_max = ft_atoi_int(args[2]);
    m1 = malloc(sizeof(int)*nb_max);
    m2 = malloc(sizeof(int)*nb_max);
    srand(getpid());
    int i;
    i = 0;
    while(i < nb_max)
    {
        m1[i]=nb_begin+i;
        i++;
    }
    i = 0;
    while(i < nb_max)
    {
        //printf("%i ",m1[i]);
        i++;
    }
    int nb_rand;
    int prov;
    i = 0;
    prov = nb_max;
    while(i < nb_max)
    {
        nb_rand = rand()%(prov); //numero al azar
        //printf(" alea %i \n",nb_rand);
        m2[i]=m1[nb_rand];
        int j;
        j = nb_rand;
        while (j < prov)
        {
            m1[j]=m1[j+1];
            j++;
        }
        prov--;
        i++;
    }
    printf("\n\n ARG=\" ");
    i = 0;
    while(i < nb_max)
    {
        printf("%i ",m2[i]);
        i++;
    }
    printf("\" ; ./push_swap $ARG | ./checker $ARG ; ./push_swap $ARG | wc -l \n\n");
    //numero = rand() % (N+1);

    return(0);


}