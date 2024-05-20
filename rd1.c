#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
char input[100];
char name[20];
char rollno[20];
int i;
int E();
int T();
int EPrime();
int F();
int TPrime();
int main(void)
{
printf("\nRecursive Descent Parsing for the following grammar\n\n"); 
printf("\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/id\n\n"); 
printf("\nEnter the String to be Checked:");
gets(input);
printf("\n Enter the Name:");
scanf("%s",name);
printf("\n Enter the Roll No:");
scanf("%s",rollno);
if(E())
{
if(input[i+1]=='\0')
printf("\nString is ACCEPTED");
else
printf("\nString is NOT ACCEPTED");
}
else
printf("\nString is NOT ACCEPTED");
getch();
}
int E()
{
if(T())
{
if(EPrime())
return 1;
else
return 0;
}
else
return 0;
}
int EPrime()
{
if(input[i]=='+')
{
i++;
if(T())
{
if(EPrime())
return 1;
else
return 0;
}
else
return 0;
}
else
return 1;
}
int T()
{
if(F())
{
if(TPrime())
return 1;
else
return 0;
}
else
return 0;
}
int TPrime()
{
if(input[i]=='*')
{
i++;
if(F())
{
if(TPrime())
return 1;
else
return 0;
}
else
return 0;
}
else
return 1;
}
int F()
{
if(input[i]=='(')
{
i++;
if(E())
{
if(input[i]==')')
{
i++;
return 1;
}
else
return 0;
}
else
return 0;
}
else 
if(input[i]>='a'&&input[i]<='z'||input[i]>='A'&&input[i]<='Z')
{
i++;
return 1;
}
else
return 0;
}