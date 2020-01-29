/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_digit.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 23:15:05 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/14 16:21:55 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_digit(int num)
{
	int	counter;

	counter = 1;
	num /= 10;
	while (num != 0)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}
