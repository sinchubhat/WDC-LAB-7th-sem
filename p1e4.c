/* Write a program for encryption and decryption of text.

Aim: To write and execute a program for encryption and decryption by Using substitution method
Theory: Cryptography (the branch of cryptology dealing with the design of algorithm for encryption and decryption
intended entirely for the secrecy and /or authentically of messages) is used for network data protection, privacy and security.
In which the message to be encrypted known as plain text are transformed by a function that is a Parameterized by a key.
The output of encryption process known as cipher text is then transmitted.
In substitution method each letter or group of letters is replaced by another letter or group of letters to disguise it.
The cipher text alphabets to be shifted by K letters.
In this case K becomes a key to the generous method of circularly shifted alphabets.

Example:
1. Plain text: RAMA
Key=2
Cipher text: TCOC
2. Plain text: XYZ
Key=3
Cipher text: ABC
Algorithm:
1. Get the message to be encrypted into plain text
2. Initialize the number of shifts per character for encryption
3. Remove non alphabetical character from the plain text and capitalize them
4. Replace each character of the plain text by shifting letters along the forward direction and put
the encrypted message to the cipher text.
5. For decrypting initialize the key K
6. Replace each character of cipher text by shifting k letters along the reverse direction and put
the decrypted message to plain text.
*/
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#define MAX 1000

int main()
{
	{
int s, pi, ci;
char plain[MAX], cipher[MAX];

printf("*** Encryption & decryption using substitution cipher ***\n\n");
printf("Enter the plain text:\n");
gets(plain);
while(1)
{
printf("\nKey (number of shifts per character) for encryption : ");
scanf("%d", &s);
if(s < 1 || s > 25)
printf("Bad input! Enter a value between 1 and 25.");
else
break;
}
printf("\nAfter removing non alphabetical characters and capitalizing:\n");
for(ci = 0, pi = 0; plain[pi] != '\0'; pi++)
if(isalpha(plain[pi]))
{
putchar(toupper(plain[pi]));

cipher[ci++] = ((toupper(plain[pi]) - 'A') + s% 26) % 26 + 'A';
}
cipher[ci] = '\0';
printf("\n\nAfter encryption:\n%s\n", cipher);
while(1)
{
printf("\nKey for decryption : ");
scanf("%d", &s);
if(s< 1 || s> 25)
printf("Bad input! Enter a value between 1 and 25.");
else
break;
}
for(pi = 0, ci = 0; cipher[ci] != '\0'; ci++)
plain[pi++] = ((cipher[ci] - 'A') + (26 - s)) % 26 + 'A';
plain[pi] = '\0';
printf("\nAfter decryption:\n%s", plain);
//return 0;
	}
getch();

}
