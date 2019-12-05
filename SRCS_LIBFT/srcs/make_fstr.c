/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_fstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 15:05:22 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/04 21:33:34 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_afterdot(long double numb, t_print *ptr, char *fstr, int i)
{
	int		j;
	int		inumb;

	j = ft_strlen(fstr);
	if (!(!ptr->hash && ptr->pc == 0))
		fstr[j] = '.';
	j++;
	while (i <= ptr->pc + 2)
	{
		numb = numb * 10;
		if (numb < 1)
		{
			fstr[j] = '0';
			j++;
		}
		else
		{
			fstr[j] = (int)numb + '0';
			j++;
		}
		inumb = (int)numb;
		numb -= inumb;
		i++;
	}
}

char		*roundup(char *fstr, t_print *ptr, int i)
{
	int		len;

	fstr[i + 1] = '0';
	len = i - ptr->pc;
	while (fstr[i] == '9' || fstr[i] == '.')
	{
		fstr[i] = '0';
		i--;
		if (i == 0)
		{
			if (fstr[0] == '-')
				fstr[1] = '1';
			else
				fstr[i] = '1';
			fstr[len] = '0';
			fstr[len + 1] = '.';
			return (fstr);
		}
	}
	if (fstr[i] != '9')
		fstr[i] += 1;
	return (fstr);
}

char		*roundup_f_string(char *fstr, t_print *ptr)
{
	int		i;

	i = 0;
	while (fstr[i])
	{
		i++;
		if (fstr[i] == '.')
			break ;
	}
	i += ptr->pc + 1;
	if (fstr[i] >= '5' && fstr[i] <= '9')
	{
		i--;
		if (fstr[i] >= '0' && fstr[i] <= '8')
			fstr[i] += 1;
		else if (fstr[i] == '9')
			return (roundup(fstr, ptr, i));
	}
	return (fstr);
}

void		final_fstring(char *fstr, t_print *ptr)
{
	int		i;

	i = 0;
	while (fstr[i] != '.')
		i++;
	fstr[i + ptr->pc + 1] = 0;
}

char		*f_string(long double numb, t_print *ptr)
{
	long long		inumb;
	char			*fstr;
	char			*tempstr;
	long double		temp;

	temp = numb;
	inumb = (long long)numb;
	fstr = (char *)malloc(sizeof(char) * (ft_nlen(inumb) + 3 + ptr->pc));
	numb = numb - inumb;
	tempstr = ft_itoa((long long)inumb);
	fstr[0] = 0;
	if (temp < 0 && temp > -1)
	{
		fstr[0] = '-';
		fstr[1] = 0;
	}
	fstr = ft_strcat(fstr, tempstr);
	if (numb < 0)
		numb = numb * -1;
	ft_afterdot(numb, ptr, fstr, 0);
	return (fstr);
}
