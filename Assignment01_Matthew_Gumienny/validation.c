#include "validation.h"

/******************************************************************************************
*Function name:              validateInt
*Purpose:                    Reads input and validates an integer
*Function In parameters:     None
*Function Out parameters:    The validated student number
*Version:                    1
*Author:                    Mateusz Gumienny
******************************************************************************************/
int validateInt()
{
  int value;
  while (scanf("%d", &value) != 1 || value <= 0) {
      printf("ERROR: Invalid input. Please enter a valid positive integer: ");
      while (getchar() != '\n');  
  }
  return value;
}

/******************************************************************************************
*Function name:              validateSN
*Purpose:                    Reads input and validates a student number
*Function In parameters:     None
*Function Out parameters:    The validated student number
*Version:                    1
*Author:                    Surbhi Bahri
******************************************************************************************/
int validateSN()
{
  int student = -1;
  int returnCode;

  /* read input and validate value */
  returnCode = scanf("%d", &student);
  /* if not a number, otherwise check range */
  if (returnCode != 1)
  {
    printf("Error: student number must consist of integers only \n");
    student = -1;
  }
  else if ((student < 10000) || (student > 99999))
  {
    printf("Error: enter a valid 5 digit number that does not start with 0 \n");
    student = -1;
  }
  while (getchar() != '\n')
    ;

  return student;
}

/******************************************************************************************
*Function name:              validateCourse
*Purpose:                    Reads input and validates it is correct format for a course name
*Function In parameters:     None
*Function Out parameters:    None
*Version:                    1
*Author:                    Surbhi Bahri
******************************************************************************************/
void validateCourse(char *course)
{
  int i;

  /* read input */
  scanf("%8[^\n]*c", course);
  /* if the first char is null, or the 8th is not, print error */
  if (course[0] == '\0')
  {
    printf("Error: enter a course code in the format LLLNNNN where L is a letter and N is a number \n");
  }
  else if (course[7] != '\0')
  {
    printf("Error: course code is too long. Must be 7 characters. \n");
    course[0] = '\0';
  }
  else
  {
    /* check that the first 3 are letters, last 4 are numbers */
    for (i = 0; i < 3; i++)
    {
      if (course[i] >= 'a' && course[i] <= 'z')
      {
        /* do nothing */
      }
      else if (course[i] >= 'A' && course[i] <= 'Z')
      {
        /* do nothing */
      }
      else
      {
        course[0] = '\0';
        i = 10;
        printf("Error: first three characters must be letters \n");
      }
    }

    if (i == 3)
    {
      for (i = 3; i < 7; i++)
      {
        if (course[i] >= '0' && course[i] <= '9')
        {
          /* do nothing */
        }
        else
        {
          course[0] = '\0';
          i = 10;
          printf("Error: last four characters must be digits \n");
        }
      }
    }
  }
  while (getchar() != '\n');
}
