/* Write a program for a HLDC frame to perform bit stuffing and de-stuffing in a single frame.

Aim: To write and execute program for bit stuffing and de-stuffing
Theory: When a data stream is transmitted over a channel it may get deviated due to the noise,
interference and other nonlinear Characteristics of the nature.
Therefore for a purpose of error Detection and correction the ordinary raw data is divided into Frames and compute the checksum for that.
Checksum: Error detection method used by the higher level protocol check sum generator divides the data into equal segments of n bits,
add the segments and complement the result called checksum field is added to the end of the original data unit as redundancy bits.
At the reception the checksum is again computed locally calculated checksum are matched if both are same there is no error else there is an error.
In bit stuffing, each frame begins with a special binary code 01111110 called as flag when error data encounter 5 consecutive ones in the data ,
automatically 6th bit is forcibly made 0 at the receiver it sees that 5 ones with o then automatically de stuff or it will detect the 0 to get 1.

// flag bits 01111110
Example 1:
Original Data: 0111000111111010
Stuffed data: 011111100111000111110101001111110

Algorithm for bit stuffing:
1. Input the data bit stream
2. Check for 5 consecutive ones
3. If present add 0 to the sixth bit
4. If not continue to further bit
5. Add start and end frame
6. Transmit and display
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	{
char ch,arr[50]={"01111110"},rec[50]; // rec-receiver
int i,j,k,len=8,cnt=0;
printf("\n enter the data:\n");
while((ch=getche())!='\r') // The not-equal-to (!=) returns true if the operands don't have same values; otherwise it returns false
{
if(ch=='1')
cnt++;
else
cnt=0;
arr[len++]=ch;
if(cnt==5)
{
arr[len++]='0';
cnt=0;
}
}
strcat(arr,"01111110");
printf("\n bit stuffed stream is:\n ");
for(i=0;i<len+8;i++) // 8 - length of flag ( 01111110 )
printf("%c",arr[i]);
//destuffing
cnt=0;
printf("\n the destuffed stream is: \n");
for(j=8,k=0;j<len;j++)
{
if(arr[j]=='1')
cnt++;
else
cnt=0;
rec[k++]=arr[j];
if(cnt==5&&arr[j+1]=='0')
{
j++;
cnt=0;
}
}
for(j=0;j<k;j++)
printf("%c",rec[j]);
}
getch();
}
