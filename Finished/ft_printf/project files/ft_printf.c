/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:15:48 by gpenaran          #+#    #+#             */
/*   Updated: 2020/12/03 08:04:55 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags			ft_initialize(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.asterisk = 0;
	flags.type = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	return (flags);
}

/*
** FT_DISCOVER
** ------------
** Aqui se manejan las flags que pide el proyecto, que son:
** "-0.*" en cualquier combiancion de las mismas.
** ------------
** Se va a encargar de comprobar que tipo de elemento esta tratando,
** permitiendo descubrir si se trata de un modificador o de una flag
** para ello comprueba con las funciones (ft_checkconversion),
** (ft_isflag) y (is_digit) si sen encuentra algun valor que se pueda
** tratar, como por ejemplo la flag "-" o el modificador "s" o si se
** trata de un numero, en caso contrario simplemente se realiza un break
** despues, se va comprobando las coincidencias, primero se comprueban
** las flag, debido a como funciona el printf original algunas flags
** se anulan entre si, por ello se ponen en un orden concreto y se
** comprueba que se cumplan las condiciones, por ejemplo en el caso
** del flag 0, se anula tanto con el flag "*" como con el flag "-"
** dependiendo de la flag se requieren acciones adicionales, por ello
** se llama a distintas funciones como (ft_width_flag) o (ft_minus_flag)
** pasandole los parametros que necesite, como los flag que se han
** activado por ejemplo.
** si no hay coincidencia de flag, se mirara si es un numero
** distinto de 0 y se modificaran las flags, si tampoco es un numero,
** se comprobará si es una conversion (Llegado a este punto como ya
** se ha comprobado en una funcion anterior, deberia entrar siempre al if)
** se activara un flag y se saldra de la funcion para que se encarge
** otra funcion de gestionarlo.
*/

static int				ft_discover(const char *str, int i,
t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_checkconversion(str[i]) && !ft_isflag(str[i])
		&& !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_width_flag(args, *flags);
		if (str[i] == '.')
			i = ft_dot_flag(str, i, flags, args);
		if (str[i] == '-')
			*flags = ft_minus_flag(*flags);
		if (ft_isdigit(str[i]))
			*flags = ft_digit_flag(str[i], *flags);
		if (ft_checkconversion(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

/*
** FT_INPUT
** Recibe de (ft_printf) tanto la lista de argumentos como la cadena de
** "instrucciones" es decir las flag y los modificadores.
** Primero de todo genera una variable flags que sigue una estructura,
** esto sirve para llevar la cuenta de las flags que se han declarado
** y poder tratar los datos de forma acorde a esto.
** esto esta dentro de un bucle por lo que se "regenera" el struct
** cada vez que da una vuelta, este bucle es el que se ejecuta
** siempre que exista un valor en las "instrucciones", por ello
** se van a comprobar 3 cosas, si no existen mas valores, se saldra
** de bucle ya que significa que no quedan cosas que tratar,
** por otro lado si se encuentra algo que no sea un simbolo "%",
** significara que es un caracter que se debera escribir, por ello
** se llama a (ft_putchar), si por el contrario se encuentra
** el simbolo "%" se haran varias cosas, la primera se mirara si
** el siguiente simbolo existe ya que en caso de no existir se
** ignorará el "%", si en cambio lo encuentra, llamara a la
** funcion (ft_discover) pasandole el puntero de los argumentos
** el "flag" o "modificador" que sigue al "%" y la lista de
** "instrucciones".
** Si en la funcion (ft_discover) se detecta una conversion,
** se volvera a esta funcion con una flag activa (type)
** en este momento se comprobara si el valor "actual" es una
** conversion, si lo es, lo mandará a la funcion (ft_handle)
** la cual se encargará de TODO TODO
** si en cambio no es una conversion, significará que es un
** carácter y se debera imprimir con la funcion (ft_putchar).
*/

static int				ft_input(const char *str, va_list args)
{
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	while (1)
	{
		flags = ft_initialize();
		if (str[i] == 0)
			break ;
		else if (str[i] != '%')
			count = count + ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_discover(str, ++i, &flags, args);
			if (ft_checkconversion(str[i]))
				count = count + ft_handle((char)flags.type, flags, args);
			else if (str[i])
				count = count + ft_putchar(str[i]);
		}
		i++;
	}
	return (count);
}

/*
** FT_PRINTF
** Se crea una copia de los argumentos que llegan desde la llamada a ft_printf
** y se genera un puntero a esta copia (ft_strdup).
** Si no se ha recibido ningun argumento, se retorna 0.
** En este punto se crea una lista variadica, que permitira recorrer
** los argumentos que se han recibido mas adelante.
** Una vez se ha asignado el puntero y se ha comprobado que no es nulo
** se da como valor a count la cantidad de carácteres que se han escrito
** en la salida, para luego devolverlo al terminar.
** Por ultimo se libera tanto la lista que se ha creado
** Como el puntero generado con los argumentos recibidos.
*/

int						ft_printf(const char *fmt, ...)
{
	va_list		args;
	const char	*str;
	int			count;

	count = 0;
	if (!(str = ft_strdup(fmt)))
		return (0);
	va_start(args, fmt);
	count = count + ft_input(str, args);
	va_end(args);
	free((char*)str);
	return (count);
}
