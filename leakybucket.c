#include<stdio.h>
#include<stdlib.h>
void leakybkt(bs,ps,or,i)
{
int remain=0;
int count=0;
if(ps>bs)
{
printf("Packet is discarded due to overflow\n");
}
else
{
while(ps>=or)
{
	remain=or+remain;
	ps=ps-or;
	printf("%d bytes is sent\n",remain);
	count++;
}
if(ps>0)
{
printf("%d bytes are sent\n",ps);
count ++;
}
if(count>1)
printf("The packet %d was fragmented %d times and sent successfully\n",(i+1),count);
else
printf("The packet %d was sent successfully without fragmentation\n",(i+1));

}

}


int main()
{
	int n,ps,bs,or;
	int i;
	clrscr();
	printf("Enter the number of packets to be sent\n");
	scanf("%d",&n);
	printf("Enter the bucket size\n");
	scanf("%d",&bs);
	printf("Enter the output rate\n");
	scanf("%d",&or);
	for(i=0;i<n;i++)
	{
		printf("Enter the packet size of packet %d\n",(i+1));
		scanf("%d",&ps);
		leakybkt(bs,ps,or,i);
	}
	getch();
	return 0;
}
