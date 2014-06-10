/* Challenge to illuminate disassembly. Displays flag from sequential case statement*/
/* sends "MCA-" plus 8 hex digits to terminal if user enters "012345678" at keyboard */
/* To be provided in executable form only.  Can be made more challenging by randomizing the case order */
#include <stdio.h>

int main()
{
  char check;
  
  do {
    check = getchar();
    switch (check)
    {
      case '0':
        printf("MCA-");
        break;
      case '1':
        printf("B"); /* first of 8 hex digits*/
        break;
      case '2':
        printf("C");
        break;
      case '3':
        printf("0");
        break;
      case '4':
        printf("5");
        break;
      case '5':
        printf("F");
        break;
      case '6':
        printf("1");
        break;
      case '7':
        printf("3");
        break;
      case '8':
        printf("7");
        break;
      case '!':
        printf(" Done\n");
        break;
      default:
        printf(" Oops\n");
        break;
    }
  }while (check != '!');
}


//Key: MCA-5FC91730
//Correct input: 045216873!