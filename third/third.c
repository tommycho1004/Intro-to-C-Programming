#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	//create local variables
	int num, n, v, temp;
	char line[25], func[10];
	FILE *f = fopen(argv[1], "r");
	
	fgets(line,24,f);
	sscanf(line,"%d", &num);
	while(fgets(line,24,f))
	{
		sscanf(line, "%s%d%d", func, &n, &v);
		//create a switch that runs the function for us
		switch(func[0])
		{
			case 'g':
			temp=1;
			temp = temp<<n;
			printf("%d\n",(num&temp)&&1);
			break;
			
			case 's':
			temp=1;
			temp=temp<<n;
			//grab v variable we got earlier
			if (!v)
			{
				temp=~temp;
				num=num & temp;
			}
			else
			{
				num=num | temp;
			}
			printf("%d\n",num);
			break;
			
			case 'c':
			temp=1;
			temp=temp<<n;
			num=num ^ temp;
			printf("%d\n",num);
			break;
			default:printf("error");
		}
	}
	return 0;
}

