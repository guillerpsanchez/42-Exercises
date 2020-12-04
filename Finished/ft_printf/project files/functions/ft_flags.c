/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:58:24 by gpenaran          #+#    #+#             */
/*   Updated: 2020/12/03 08:05:56 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** El flag "-" sirve para dar a enteneder que se quiere que se
** "justifique" la salida en el lado izquierdo en vez de en el lado
** derecho, debido a que el flag 0 se ignora cuando existe el flag -
** se desactiva el flag 0.
*/

t_flags	ft_minus_flag(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

/*
** El flag digit va a determinar el tamaño del width
** para ello cambia el valor de la flag width con el tamaño
** determinado por el numero que llega (un char), en caso de
** que el flag asterisk este activo, como el width se coge de otro
** lado, se le dara una valor al width de 0, si por el contrario
** hay por ejemplo un 12, primero se cogera el 1, y en la segunda
** iteraccion llegara el 2, por lo que multiplicara el 1 por 10
** y se le sumara el 2 par mantener la cantidad que se deseaba.
*/

t_flags	ft_digit_flag(char c, t_flags flags)
{
	if (flags.asterisk == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - 48);
	return (flags);
}

/*
** El "flag" * sirve para especificar que el tamaño o "width" se pasa en el
** siguiente argumento, es decir: (%.*s), var_tamaño, "STRING", el tamaño
** se recibirá como int.
** ------------
** Primero se activara la flag asterisk y se obtendra el tamaño desde
** el argumento siguiente, si el tamaño es positivo, se devolveran las
** flags, pero is por el contrario es negativo, se activara la flag de minus
** para saber que se debera, se pasara el tamaño a positivo para poder
** trabajar con el y se pondra la flag zero a valor 0 ya que el flag "-"
** lo anula  , devolviendo como en el otro caso las flag en el return.
*/

t_flags	ft_width_flag(va_list args, t_flags flags)
{
	flags.asterisk = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width = flags.width * -1;
		flags.zero = 0;
	}
	return (flags);
}

/*
** el flag "." va a indicar que se debe de tener en cuenta la precision
** dependiendo del tipo de dato funcionara de una forma u otra,
** como por ejemplo la cantidad de caracteres, la cantidad de decimales
** o la cantidad de numeros minimos a imprimir.
** --------------
** La funcion primero comprueba si la posicion siguiente al flag
** es el flag "*", ay que esto significaria que el tamaño de la
** precision vendria dado por un argumento.
** En cualquier otro caso, se desactivara la flag "." y se comprobara
** si el siguiente valor es un numero, si lo es se almacenara en el flag
** dot, el cual guardara el valor, si se llegara  a iterar de nuevo,
** el valor guardado anteriormente se multiplicaria por 10 para
** mantener el valor dado.
*/

int		ft_dot_flag(const char *str, int init, t_flags *flags,
va_list args)
{
	int i;

	i = init;
	i = i + 1;
	if (str[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i = i + 1;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[i]))
		{
			flags->dot = (flags->dot * 10) + (str[i] - 48);
			i = i + 1;
		}
	}
	return (i);
}
