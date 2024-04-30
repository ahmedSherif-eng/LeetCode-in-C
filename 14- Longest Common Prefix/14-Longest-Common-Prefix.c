#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* longestCommonPrefix(char** strs, int strsSize);
char smallestString(char** strs, int strsSize);
int main()
{
	char* strs[] = {"flower","flow","flight"};
	longestCommonPrefix(strs,3);
	return 0;
}
char* longestCommonPrefix(char** strs, int strsSize) {
    char minIndex = smallestString(strs,strsSize);
	char counter = 0;
	char flag = 0;
	char *subString = NULL;
	for(int i = 0; i < strlen(strs[minIndex]); i++)
	{
		for ( int j = 0; j < strsSize; j++)
		{
			if(strs[minIndex][i] == strs[j][i])
				flag = 1;
			else{
				flag = 0;
				break;
			}
		}
		if(flag == 0)
			break;
		else
			counter ++;
	}
	if( counter == 0)
		subString ="";
	else{
		subString =(char *)malloc(counter); 
		strncpy(subString,strs[0],counter);
		subString[counter]='\0';
	}
	printf("counter = %d subString =%s ",counter,subString);	
	return subString;
}
char smallestString(char** strs, int strsSize){
	char min = 0;
	for(int i = 1; i < strsSize; i++)
	{
		if(strlen(strs[min]) > strlen(strs[i]))
			min = i;
	}
	return min;
}