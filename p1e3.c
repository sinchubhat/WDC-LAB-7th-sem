/* Write a program for a HLDC frame to perform character stuffing and de-stuffing in a single frame

Aim: To write and execute program for character stuffing and de-stuffing.
Theory: In character stuffing, at the starting an ASCII sequence DLESTX
and at the end DLEETX is transmitted for synchronization
But when DLE occurs in the data itself then the systems adds one more DLE alone with present one
so at the receiver it detects one DLE such that DLE of data will be safe.
Example:
Original data RAMA
Stuffed data: DLESTXRAMADLEETX
Destuffed data: RAMA
Original data DLE RAMADLE
Stuffed data: DLESTXDLE RAMADLEDLEETX
Destuffed data: DLE RAMADLE

STX - start of the string
ETX - end of the string
*/
#include<stdio.h>
#include<conio.h>
#define DLE 16
#define STX 2
#define ETX 3
void main()
{
char ch,arr[50]={DLE,STX},rec[50];
int len=2,i,j;
//clrscr();
printf("enter the data stream:ctrl+p->DLE ctrl+b->STX ctrl+c->ETX \n");
while((ch=getch())!='\r')
{
if(ch==DLE)
{
arr[len++]=DLE;
printf("DLE");
}
else if(ch==STX)
printf("STX");
else if(ch==ETX)
printf("ETX");
else printf("%c",ch);
arr[len++]=ch;
}
arr[len++]=DLE;
arr[len++]=ETX;
printf("\n the stuffed stream is:\n");
for(i=0;i<len;i++)
{
ch=arr[i];
if(ch==DLE)
printf("DLE");
else if(ch==STX)
printf("STX");
else if(ch==ETX)
printf("ETX");
else printf("%c",ch);
}
//destuffing
printf("\n the destuffed data stream is:\n");
for(j=2;j<len-2;j++)
{
ch=arr[j];
if(ch==DLE)
{
printf("DLE");
j++;

}
else if(ch==STX)
printf("STX");
else if(ch==ETX)
printf("ETX");
else printf("%c",ch);
}
getch();
}
