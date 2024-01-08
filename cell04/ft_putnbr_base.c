#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (!(str[i] == '\0'))
		i++;

	return (i);
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if (nb >= 10)
        ft_putnbr(nb / 10);
        
    ft_putchar('0'+nb%10);
}
void ft_putstr(char *str)
{
	int len = ft_strlen(str);

	for (int i = 0; i < len; i++)
		write(1, &str[i], 1);
}

void ft_putnbr_base(int nbr, char *base)
{
    // Get base
    int len = ft_strlen(base);

    // Base 2
    if (len == 2)
    {
        // Convert to base 2
        char bin[33];
        int i = 0;
        
        while (nbr > 0)
        {
            bin[i] = (nbr%2) + '0';
            nbr = nbr / 2;
            i++;
        }

        // Reverse list
		int bin_len = ft_strlen(bin);
		int final_i = 0;
		char final[bin_len];

		for (int i = (bin_len-1); i != -1; i--)
		{
			final[final_i] = bin[i];
			final_i++;
		}
		final[final_i] = '\0';

        // Print
    	ft_putstr(final);
    }
    // Base Hexa
    if (len == 16)
    {
		char dec[33];
		int i = 0;

		while (nbr > 0)
		{
			int	remain = nbr % 16;
			dec[i] = base[remain];

			nbr = nbr / 16;
			i++;
		}
		printf("%s", dec);

		// Reverse list
		int dec_len = ft_strlen(dec);
		int final_i = 0;
		char final[dec_len];

		for (int i = (dec_len-1); i != -1; i--)
		{
			final[final_i] = dec[i];
			final_i++;
		}
		final[final_i] = '\0';
		printf("%s", final);
	}
    // Base 8
    else if (len == 8)
    {
        
    }
}

int main(void)
{
    ft_putnbr_base(45, "0123456789ABCDEF");
}
