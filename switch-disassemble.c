/* Challenge to illuminate disassembly. Displays flag from sequential case statement*/
/* sends "MCA-" plus 8 hex digits to terminal if user enters "012345678" at keyboard */
/* To be provided in executable form only.  Can be made more challenging by randomizing the case order */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>

bool isCorrect(int a[]);

int main()
{
  int arr[10] = {0};
  bool pass = 0;
  int i = 0;
  char check;
  
  puts("Enter ten characters...");
  
  do {
    check = getchar();

    if(isdigit(check) && i < 10)
    {
        arr[i] = atoi(&check);
        i++;
    }

    if(i >= 10)
    {
      for(int j = 0; j < 10; j++)
      {
        switch (arr[j])
        {
          case 0:
            printf("MCA-");
            break;
          case 1:
            printf("B"); 
            break;
          case 2:
            printf("C");
            break;
          case 3:
            printf("0");
            break;
          case 4:
            printf("5");
            break;
          case 5:
            printf("F");
            break;
          case 6:
            printf("1");
            break;
          case 7:
            printf("3");
            break;
          case 8:
            printf("7");
            break;
          case 9:
            printf(" Done\n");
            pass = isCorrect(arr);
            break;
          default:
            printf("What?");
            break;
        }
        
        i = 0;

      }
    }

  }while (pass == 0);

  return(0);
}


bool isCorrect(int a[])
{
  char combo[11];
  unsigned char transfer[MD5_DIGEST_LENGTH];
  char md5sum[33];

  for(int i = 0; i < 10; i++)
  {
    sprintf(&combo[i], "%d", a[i]);
  }

  combo[10] = '\0';

  MD5((unsigned char*) &combo, strlen(combo), (unsigned char*) &transfer);

  for(int i = 0; i < 16; i++)
  {
    sprintf(&md5sum[i*2], "%02x", (unsigned int)transfer[i]);
  }

  if(strcmp(md5sum, "9252dbaf507078d3ee4e491d0e7cc716") == 0)
  {
    puts("Granted!");
    return 1;
  }
  else
  {
    puts("NO");
    return 0;
  }
}

//Key: MCA-5FC91730
//Correct input: 0452168739