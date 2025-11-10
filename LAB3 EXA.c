 #include<stdio.h>
 #include<string.h>
 #include<ctype.h>
 //The following definitions are for your Morse code,do NOT modify
 static const char*MORSE_AZ[26]=
 {
     ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
     "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
     "..-","...-",".--","-..-","-.--","--.."
 };
 static const char*MORSE_09[10]=
 {
     "-----",".----","..---","...--","....-",".....","-....","--...","---.."
     ,"----."
 };
 int main()
 {
     char inText[256];
     char outMorse[4096]="";//plenty for worst-case line
        printf("Please enter text to convert to Morse code:\n");
        fgets(inText, sizeof(inText), stdin);
        size_t len = strlen(inText);
        for(size_t i=0; i<len; i++)
        {
            char ch = toupper((unsigned char)inText[i]);
            if(ch>='A' && ch<='Z')
            {
                strcat(outMorse, MORSE_AZ[ch-'A']);
                strcat(outMorse, " ");
            }
            else if(ch>='0' && ch<='9')
            {
                strcat(outMorse, MORSE_09[ch-'0']);
                strcat(outMorse," ");
            }
            else if(ch == ',' || ch == '.' || ch == '?' || ch == '!' || ch == ';' || ch == ':' || ch == '-'  || ch == '\"' || ch == '\'' )
            {
                //skip punctuation
            }
            else if(ch == ' ')
            {
                if(i == 0)
                {
                    // leading space: ignore
                }
                else if(i == len - 1)
                {
                    // trailing space: ignore
                }
                else if(inText[i - 1] == ' ')
                {
                    // multiple spaces: ignore
                }
                else
                {
                    // separate words in Morse with a slash and a space
                    strcat(outMorse, "/");
                }
            }
            else if(ch == '\n')
            {
                // ignore newlines
            }
            else
            {
                printf("ERROR");
                outMorse[0] = '\0'; // clear output
                break;
            }
        }
     puts(outMorse);
     return 0;
 }
