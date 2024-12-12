/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2124/17/13 11:37:37 by sbruck            #+#    #+#             */
/*   Updated: 2024/07/14 13:34:49 by sbruck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush_1_2(void);
void	rush_2_1(void);
void	rush_normal(int x, int y);

void	rush(int x, int y)
{
	if (x == 1 && y == 2)
		rush_1_2();
	else if (x == 2 && y == 1)
		rush_2_1();
	else
		rush_normal(x, y);
}

void	rush_1_2(void)
{
	ft_putchar('o');
	ft_putchar('o');
}

void	rush_2_1(void)
{
	ft_putchar('o');
	ft_putchar('\n');
	ft_putchar('o');
}

void	rush_normal(int x, int y)
{
	int	a;
	int	b;

	b = 1;
	while (b <= y)
	{
		a = 1;
		while (a <= x)
		{
			if ((a == 1 && b == 1) || (a == x && b == y))
				ft_putchar('o');
			else if ((a == 1 && b == y) || (a == x && b == 1))
				ft_putchar('o');
			else if ((b == 1 || b == y) && (a > 1 && a < x))
				ft_putchar('-');
			else if ((b > 1 && a == 1) || (b < y && a == x))
				ft_putchar('|');
			else if ((b > 1 && a > 1) && (b < y && a < x))
				ft_putchar(' ');
			if (a == x)
				ft_putchar('\n');
			a++;
		}
		b++;
	}
}
