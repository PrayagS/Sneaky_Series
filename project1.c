#include<stdio.h>
#include <math.h>

void square_series(float w, float x, float y, float z, float* t1, float* t2);
void cube_series(float w, float x, float y, float z, float* t1, float* t2);
void factorial_series(float w, float x, float y, float z, float* t1, float* t2);
void squaresum_series(float w, float x, float y, float z, float* t1, float* t2);
void productpretwo_series(float w, float x, float y, float z, float* t1, float* t2);
float factorial(float x);

int main()
{
  float t[6];
  for(int i=0; i<4; i++)
  {
    printf("Enter number %d: ",i+1);
    scanf("%f", &t[i]);
  }
   productpretwo_series(t[0],t[1],t[2],t[3],&t[4],&t[5]);
   printf("Next terms: %f, %f", t[4], t[5]);
  return 0;
}

void square_series(float w, float x, float y, float z, float* t1, float* t2)
{
  float w1, x1, y1, z1, a1, b1;
  w1 = sqrt(w);
  x1 = sqrt(x);
  y1 = sqrt(y);
  z1 = sqrt(z);
  if ((z1-y1) == (y1-x1) == (x1-w1))
  {
    a1 = z1+1;
    b1 = z1+2;
    *t1 = pow(a1,2);
    *t2 = pow(b1,2);
  } 
}

void cube_series(float w, float x, float y, float z, float* t1, float* t2)
{
  float w1, x1, y1, z1, a1, b1;
  w1 = cbrt(w);
  x1 = cbrt(x);
  y1 = cbrt(y);
  z1 = cbrt(z);
  if ((z1-y1) == (y1-x1) == (x1-w1))
  {
    a1 = z1+1;
    b1 = z1+2;
    *t1 = pow(a1,3);
    *t2 = pow(b1,3);
  }
}

float factorial(float x)
{
	float fact = 1;
	for (int i = 1; i <= x; ++i)
	{
		fact = fact * i;
	}
	return fact;
}

void factorial_series(float w, float x, float y, float z, float* t1, float* t2)
{
	int flags[4], flag, w1, x1, y1, z1;
	for (int i = 0; i < 4; ++i)
	{
		flags[i] = 0;
	}
	for (int i = 0; i < 8; ++i)
	{
		if (w == factorial(i))
		{
			flags[0] = 1;
			w1 = i;
		}
		if (x == factorial(i))
		{
			flags[1] = 1;
			x1 = i;
		}
		if (y == factorial(i))
		{
			flags[2] = 1;
			y1 = i;
		}
		if (z == factorial(i))
		{
			flags[3] = 1;
			z1 = i;
		}
		else{
			continue;
		}
	}

	if (flags[0] == 1 && flags[1] == 1 && flags[2] == 1 && flags[3] == 1 && (z1-y1) == (y1-x1) && (y1-x1) == (x1-w1)) 
	{
		float a = z1+1, b=z1+2;
		*t1 = factorial(a);
		*t2 = factorial(b);
	}
}

void squaresum_series(float w, float x, float y, float z, float* t1, float* t2)
{
	float w1, x1, y1, z1, u[2];
	for (int i = -100; i <= 100; ++i)
	{
	 	if (i < 0)
	 	{
	 		w1 = w + abs(i);
	 		x1 = x + abs(i);
	 		y1 = y + abs(i);
			z1 = z + abs(i);
	 	}
	 	else
	 	{
	 		w1 = w - i;
	 		x1 = x - i;
	 		y1 = y - i;
			z1 = z - i;
	 	}
		w1 = sqrt(w1);
		x1 = sqrt(x1);
		y1 = sqrt(y1);
		z1 = sqrt(z1);
		if ((z1-y1) == (y1-x1) && (y1-x1) == (x1-w1))
			{
		 		printf("Series\n");
		 		u[0] = pow((z1+1),2) + i;
		 		u[1] = pow((z1+2),2) + i;
		 		*t1 = u[0];
		 		*t2 = u[1];
		 	} 		
	}
}

void productpretwo_series(float w, float x, float y, float z, float* t1, float* t2)
{
	float u[2];
	for (int i = -100; i <= 100; ++i)
	{
		if (y == (i*w*x) && z == (i*y*x))
		{
			printf("Series\n");
			u[0] = i*z*y;
			u[1] = i*z*u[0];
			*t1 = u[0];
			*t2 = u[1];
		}
	}
}