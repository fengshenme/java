#include <stdio.h>
#define SEC_YEAR 3.1536e7

int main(void)
{
	short age;
	float seconds;
	printf("how old are you(between 0 -- 100):");

	int ret1,ret2;

	while((ret1=scanf("%hd", &age)) != 1 ||
			(ret2=getchar()) != '\n' || age > 100 || age < 0)
	{
		if(ret1 != 1 || ret2 != '\n')
		{
			while(getchar() != '\n') ;
			printf("input invalid!\n");
		}
		else
			printf("invalid age!\n");

		printf("how old are you(between 0 -- 100");
	}
	seconds = age * SEC_YEAR;
	printf("you have pass%.0lf seconds in your life!\n", seconds);
	return 0;
}

