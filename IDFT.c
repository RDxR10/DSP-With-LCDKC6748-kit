#include<stdio.h>
#include<math.h>
float x[4], Xreal[4], Ximag[4], theta;
int k, n, N;
void main ()
{
  printf ("\t\t Inverse Discrete Fourier Transform (IDFT)\n");
  printf ("\nEnter the length of the DFT N= ");
  scanf ("%d", &N);
  printf ("Enter the real and imaginary parts of X(k) as follows: \n"
	  "X(k) = Re{X(k)} Im{X(k)}\n");
  for (k = 0; k < N; k++)
    {
      printf ("X(%1.0f)=", k);
      scanf ("%f %f", &Xreal[k], &Ximag[k]);
    }
  for (n = 0; n < N; n++)
    {
      x[n] = 0;
      for (k = 0; k < N; k++)
	{
	  theta = (2 * 3.141592 * k * n) / N;
	  x[n] = x[n] + Xreal[k] * cos (theta) - Ximag[k] * sin (theta);
	}
      x[n] = x[n] / N;
    }
  printf ("\n The sequence x(n) is as follows:... ");
  for (n = 0; n < N; n++)
    {
      printf ("\nx(%1.0f) = %0.2f", n, x[n]);
    }
}
