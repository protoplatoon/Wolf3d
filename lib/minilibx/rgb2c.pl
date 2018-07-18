#
# Generate a .c file with encoded colors, from the XFree86 rgb.txt file.
#

open(RGB, "/usr/X11/lib/X11/rgb.txt");


printf("/*\n** This is a generated file with rgb2c.pl and rgb.txt from\n");
printf("** the XFree86 distribution.\n*/\n\n");
printf("struct s_col_name mlx_col_name[] =\n{\n");

while (<RGB>)
{
    @tab = split;
    if ($tab[0] ne "!")
    {
	$color = $tab[3];
	if ("$tab[4]" ne "")
	{
	    $color = "$tab[3] $tab[4]";
	}
	printf(" { \"%s\" , 0x%x },\n", $color, $tab[0]*65536+$tab[1]*256+$tab[2]);
    }
}

printf(" { 0, 0 }\n};\n");
