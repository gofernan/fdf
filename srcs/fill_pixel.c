void		fill_pixel(char *img_data, int x, int y, unsigned int color)
{
	char *newaddr;

	newaddr = img_data + x + y;
	*newaddr = (char)(color);
	*(newaddr + 1) = (char)(color >> 8);
	*(newaddr + 2) = (char)(color >> 16);
	*(newaddr + 3) = (char)(color >> 24);
}
