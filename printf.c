// Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
// --------------------------------------------------------------------------------

// Write a function named `ft_printf` that will mimic the real printf with the following constraints:

// - It will manage only the following conversions: s,d and x
// - It will manage the minimum field width. (we will never test with a field with of 0)
// - It will manage only the precison flag `.`.

// Your function must be declared as follows:

// int ft_printf(const char *, ... );

// Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
// To test your program compare your results with the true printf.

int		count;

int		ft_printf(char *str, ...)
{
	va_list ap;
	int i;

	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i = parse(str, &ap, i);
		else
			i += printer(str);
	}
	return (i);
}

int		parse(char *str, va_list *ap, int i)
{
	i++;
	i = get_width(str, ap, i);
	if (str[i] == 's')
	{
		
	}

}

int		printer(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}
