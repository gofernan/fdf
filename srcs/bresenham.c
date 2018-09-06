#include "../include/fdf.h"

int sign(int x)
{
if (x > 0)
 return 1;
else if(x < 0)
 return -1;
else
 return 0;
}

void		draw_line(t_data *pdata, int x1, int y1, int x2, int y2)
{
	/*
	int dx;
	int dy;
	int p;
	int xend;
	int x;
	int y;

	dx = abs(x1 - x2);
	dy = abs(y1 - y2);
	p = 2 * dy - dx;
	if (x1 > x2)
	{
		x = x2;
		y = y2;
		xend = x1;
	}
	else
	{
		x = x1;
		y = y1;
		xend = x2;
	}
	put_pixel(pdata, x, y, 0xFFFFFF);
	while (x < xend)
	{
		x++;
		if (p < 0)
			p = p + (2 * dy);
		else
		{
			y++;
			p = p + (2 * (dy - dx));
		}
		put_pixel(pdata, x, y, 0xFFFFFF);
	}
	*/
int x,y,dx,dy,swap,temp,s1,s2,p,i;

x = x1;
y = y1;
dx = abs(x2-x1);
dy = abs(y2-y1);
s1 = sign(x2-x1);
s2 = sign(y2-y1);
swap = 0;
put_pixel(pdata, x, y, 0xFFFFFF);
if(dy > dx)
{
	temp = dx;
	dx = dy;
	dy = temp;
	swap = 1;
}
p = 2 * dy - dx;
for(i=0;i<dx;i++)
 {
 put_pixel(pdata, x, y, 0xFFFFFF);
 while(p>=0)
  {
  p=p-2*dx;
  if(swap)
   x+=s1;
  else
   y+=s2;
  }
 p=p+2*dy;
 if(swap)
  y+=s2;
 else
  x+=s1;
 }
put_pixel(pdata, x, y, 0xFFFFFF);
}
