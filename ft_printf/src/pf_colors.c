/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_colors.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/27 20:58:17 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_palette_reg_colors(char *palette[][2])
{
	palette[8][0] = "GREEN}";
	palette[8][1] = GREEN;
	palette[9][0] = "YELLOW}";
	palette[9][1] = YELLOW;
	palette[10][0] = "DARKBLUE}";
	palette[10][1] = DARKBLUE;
	palette[11][0] = "BLUE}";
	palette[11][1] = BLUE;
	palette[12][0] = "WHITE}";
	palette[12][1] = WHITE;
	palette[13][0] = "GRAY}";
	palette[13][1] = GRAY;
	palette[14][0] = "PINK}";
	palette[14][1] = PINK;
	palette[15][0] = "RESET}";
	palette[15][1] = RESET;
	palette[16][0] = "RED}";
	palette[16][1] = RED;
	palette[17][0] = "PINK_B}";
	palette[17][1] = PINK_B;
	palette[18][0] = "ORANGE_B}";
	palette[18][1] = ORANGE_B;
}

void	fill_palette_bold_colors(char *palette[][2])
{
	palette[0][0] = "RED_B}";
	palette[0][1] = RED_B;
	palette[1][0] = "PINK_B}";
	palette[1][1] = PINK_B;
	palette[2][0] = "YELLOW_B}";
	palette[2][1] = YELLOW_B;
	palette[3][0] = "DARK_BLUE_B}";
	palette[3][1] = DARK_BLUE_B;
	palette[4][0] = "GREEN_B}";
	palette[4][1] = GREEN_B;
	palette[5][0] = "BLUE_B}";
	palette[5][1] = BLUE_B;
	palette[6][0] = "WHITE_B}";
	palette[6][1] = WHITE_B;
	palette[7][0] = "GRAY_B}";
	palette[7][1] = GRAY_B;
}

bool	set_color(t_format_spec *specifier, t_placeholder *result, char **input)
{
	char	*palette[19][2];
	char	*color;
	int		i;

	color = NULL;
	i = 0;
	fill_palette_bold_colors(palette);
	fill_palette_reg_colors(palette);
	while (i < 19 && color == NULL)
	{
		color = ft_strnstr(*input, palette[i][0], 12);
		if (color)
			break ;
		i++;
	}
	if (color)
	{
		result->str = ft_strdup(palette[i][1]);
		(*input) += ft_strlen(palette[i][0]);
	}
	else
		result->str = ft_strdup("");
	return (true);
}
