#include <stdio.h>
#include <math.h>
#include <time.h>
int is_prime(int);
int is_composite(int);
int is_even(int);
int is_odd(int);
void factors(int);
void info();
void delay(unsigned long );
void prime_fators(int);

int main(int argc, char *argv[])
{
	int i=0;
	info();
	delay(500);
	printf("PLEASE ENTER AN INTEGER: ");
	scanf("%d",&i);
	
	printf("%d IS %s\n",i, is_even(i)? "EVEN": "ODD");
	
	printf("%d IS %s\n",i, is_prime(i)? "PRIME": "COMPOSITE");
	printf("\n");

	factors(i);
	printf("\n");
	prime_fators(i);
	
	return 0;
}
void factors(int i)
{
	int d=0, _i=0;
	_i = abs(i); /**/
	int m=(int)ceil(sqrt(_i)); /*to the square root of the number*/
	printf("FACTORS OF %d ARE:\n\n",i);
	for (d=1;d<=m;d++)
	{
		if (_i%d==0)
		{
			printf("%d x %d = %d\n", d,i/d, i );
		}
	}
}
int is_prime(int i)
{
	int d=0,m=0;
	m=(int)ceil(sqrt(i)); /*to the square root of the number*/
	i = abs(i); 
	
	/*
	divide i by all these numbers one by one
	stop at the first complete division
	*/
	for (d=2;d<=m;d++)
	{
		
		if (i!=2 && i%d==0)
		{
			return 0;
		}
	}
	return 1;
}
int is_composite(int i)
{

	return !is_prime(i);
}

int is_even(int i)
{
	if (i%2==0)
	{
		return 1;
	}
	
	return 0;

}
int is_odd(int i)
{
	return !is_even(i);
}
void delay(unsigned long milliseconds)
{

    clock_t now,then;
    now = then = clock();
    while( (now-then) < milliseconds ){
        now = clock();
	}
}
void info()
{
	printf(" = + - * / NUMBER STATISTICS / * - + =\n\n");
	printf("THIS PROGRAM ALLOWS YOU TO ENTER A NUMBER\nAND FIND OUT IF  THE  NUMBER IS PRIME  OR\nCOMPOSITE. THIS  PROGRAM ALSO ALLOWS  YOU\nTO SEE IF  THE NUMBER  IS EVEN OR ODD, IT\nALSO DETERMINES THE FACTORS OF THE NUMBER\n\n");
	
}
void prime_fators(int n)
{	
	int d;
	n = abs(n);
	
	printf("THE PRIME FACTORS OF %d ARE:\n\n",n);
	if(is_prime(n)){
		printf("%d x ",n);
	}
	else{
		for (d=2;d<=n;)
		{
			if(n==1)
				break;
			if (is_prime(d))
			{
				if (n%d==0)
				{
					n = n/d;
					printf("%d x ",d);
					continue;
				}
			}
			d++;
		}
	}
	printf("%d\n",1);
}



