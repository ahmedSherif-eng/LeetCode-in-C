char freq(char* word, char* chars, char ch);
int countCharacters(char** words, int wordsSize, char* chars) {
    char matched = 0;
    int counter = 0;
    for(int j = 0; j < wordsSize;j++){
        for(char i = 0; i < strlen(words[j]); i++)
        {
            if(!freq(words[j], chars, words[j][i])) 
                break;
            for(char k = 0; k < strlen(chars); k++)
            { 
                if(words[j][i] - chars[k] != 0)
                    continue;
                else
                {
                    matched ++;
                    break;
                }
            }
            if(matched == strlen(words[j]))
            {
                counter += matched;
                printf("%s matched\n",words[j]);
            }
                
        }
        matched = 0;
    }
    return counter;
}
char freq(char* word, char* chars, char ch)
{
    char counter1 = 0;
    char counter2 = 0;
    for(char i = 0; i < strlen(word); i++)
        if(word[i]==ch)
            counter1++;
    for(char i = 0; i < strlen(chars); i++)
        if(chars[i]==ch)
            counter2++;
    return counter2>=counter1? 1 : 0;
}
