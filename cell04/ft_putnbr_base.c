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
void ft_putnbr(int nb) {
    if (nb < 0) {
        ft_putchar('-');
        nb = -nb;
    }

    if (nb >= 10)
        ft_putnbr(nb / 10);

    ft_putchar('0' + nb % 10);
}
void ft_putstr(char *str)
{
	int len = ft_strlen(str);

	for (int i = 0; i < len; i++)
		write(1, &str[i], 1);
}
void ft_reversestr(char *str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        // Swap characters at start and end indices
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}


void ft_putnbr_base(int nbr, char *base)
{
    // Get base
    int len = ft_strlen(base);

	if (len < 2)
		return;
		
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
		bin[i] = '\0';
		ft_reversestr(bin, ft_strlen(bin));
		
        // Print
    	ft_putstr(bin);
    }
    // Base Hexa
    if (len == 16)
    {
		char dec[33]; // Taille suffisante pour contenir le résultat

        int i = 0;
        while (nbr > 0) {
            int remain = nbr % 16;
            dec[i] = base[remain];
            nbr = nbr / 16;
            i++;
        }

        dec[i] = '\0';
		ft_reversestr(dec, ft_strlen(dec));

        // Afficher la séquence directement sans inversion
        ft_putstr(dec);
	}
    // Base 8
    else if (len == 8)
    {
		char octa[33];

		int i = 0;

		while (nbr > 0)
		{
			int remain = nbr % 8;
			octa[i] = base[remain];
			nbr = nbr / 8;
			i++;
		}

		octa[i] = '\0';
		ft_reversestr(octa, ft_strlen(octa));

		ft_putstr(octa);
    }
	else
	{
		ft_putnbr(nbr);
	}
}

int main(void)
{
    ft_putnbr_base(45, "0123456789");
}
