#include<stdio.h>

typedef struct Complex
{
	double x;
	double y;
} complex;

complex oneover(complex a)
{
	complex result;
	result.x = a.x/(a.x*a.x + a.y*a.y);
	result.y = -a.y/(a.x*a.x + a.y*a.y);
	return result;
}

int main()
{
	int steps = 1000000;
	double step = 1./steps;
	complex result;
	result.x = 0;
	result.y = 0;
	complex point;
	complex temp;
	for(int i = 0; i < steps; i++)
	{
		point.x = -0.5 + i*step;
		point.y = -0.5;
		temp = oneover(point);
		result.x += temp.x*step;
		result.y += temp.y*step;
	}
	for(int i = 0; i < steps; i++)
	{
		point.x = 0.5 ;
		point.y = -0.5 + i*step;
		temp = oneover(point);
		result.x += -temp.y*step;
		result.y += temp.x*step;
	}
	for(int i = 0; i < steps; i++)
	{
		point.x = 0.5 - i*step;
		point.y = 0.5;
		temp = oneover(point);
		result.x += -temp.x*step;
		result.y += -temp.y*step;
	}
	for(int i = 0; i < steps; i++)
	{
		point.x = -0.5;
		point.y = 0.5 - i*step;
		temp = oneover(point);
		result.x += temp.y*step;
		result.y += -temp.x*step;
	}
	printf("%.16f\n",result.y/2);
	return 0;
}
