// EXERCISE 12   Automatic recept generator

/*
you have to fill in value to a template letter.txt
Letter.txt looks like something this:
Thanks {{name}} for purchasing {{item}} from our outlet {{outlet}}.
Please visit our outlet {{outlet}} for any kind of problem.
We plan to serve you again soon.

you have to read this file and replace these values:
{{name}} - Harry
{{item}} - Table fan
{{outlet}} - ram laxmi fan outlet

use file functions in c to accomplish the same*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replaceWord(const char *str, const char *oldWord, const char *newWord)
{
    char *resultstring;
    int i, count = 0;
    int newWordLength = strlen(newWord);
    int oldWordLength = strlen(oldWord);

    // lets count the number of times old word occurs in string
    for (i = 0; str[i] != '\0'; i++)
    {
        if (strstr(&str[i], oldWord) == &str[i])
        {
            count++;

            // jump over this word
            i = i + oldWordLength - 1;
        }
    }

    // making a new string to fit in the replaced words
    resultstring = (char *)malloc(i + count * (newWordLength - oldWordLength) + 1); //+1 for the null character
    i = 0;
    while (*str)
    {
        // compare the substring with result
        if (strstr(str, oldWord) == str)
        {
            strcpy(&resultstring[i], newWord);
            i += newWordLength;
            str += oldWordLength;
        }
        else
        {
            resultstring[i] = *str;
            i += 1;
            str += 1;
        }
    }
    resultstring[i] = '\0';
    return resultstring;
}
int main(int argc, char const *argv[])
{
    FILE *ptr = NULL;
    FILE *ptr2 = NULL;
    ptr = fopen("letter.txt", "r");
    ptr2 = fopen("genBill.txt", "w");
    char str[200];
    fgets(str, 200, ptr);
    printf("The given bill template was: %s\n\n", str);

    // call the function to replace the word
    char *newstr;
    newstr = replaceWord(str, "{{item}}", "table fan");
    newstr = replaceWord(newstr, "{{name}}", "harry");
    newstr = replaceWord(newstr, "{{outlet}}", "Ram Laxmi fan outlet");
    printf("The actual bill generatad is: %s\n", newstr);

    fprintf(ptr2, "%s", newstr);
    fclose(ptr);
    fclose(ptr2);

    return 0;
}