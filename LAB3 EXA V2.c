 #include<stdio.h>
 #include<string.h>
 #include<ctype.h>
 //The following definitions are for your Morse code,do NOT modify
 //.- .-.. .-..-.-. .- .--. ...   
 static const char *MORSE_AZ[26]=
 {
     ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
     "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
     "..-","...-",".--","-..-","-.--","--.."
 };
 static const char *MORSE_09[10]=
 {
     "-----",".----","..---","...--","....-",".....","-....","--...","---.."
     ,"----."
 };
 int main()
 {
     char inText[256];
     char outMorse[4096]="";//plenty for worst-case line
        fgets(inText, sizeof(inText), stdin);
        size_t len = strlen(inText);
        for(size_t i=0; i<len; i++)
        {
            char ch = toupper((unsigned char)inText[i]);
            char ch2 =toupper((unsigned char)inText[i+1]);
            if(ch>='A' && ch<='Z')
            {
                strcat(outMorse, MORSE_AZ[ch-'A']);
                if (i != len - 1 && ((ch2 >= 'A' && ch2 <= 'Z') || (ch2 >= '0' && ch2 <= '9')))
                {
                    strcat(outMorse, " ");
                }
                
            }
            else if(ch>='0' && ch<='9')
            {
                strcat(outMorse, MORSE_09[ch-'0']);
                if (i != len - 1 && ((ch2 >= 'A' && ch2 <= 'Z') || (ch2 >= '0' && ch2 <= '9')))
                {
                    strcat(outMorse, " ");
                }
            }
            else if(ch == ',' || ch == '.' || ch == '?' || ch == '!' || ch == ';' || ch == ':' || ch == '-'  || ch == '\"' || ch == '\'' )
            {
                if (i != len - 1 && ((ch2 >= 'A' && ch2 <= 'Z') || (ch2 >= '0' && ch2 <= '9')))
                {
                    strcat(outMorse, " ");
                }
            }
            else if(ch == ' ')
            {
                if(i == 0)
                {
                    
                }
                else if(i == len - 1)
                {
                  
                }
                else if(inText[i - 1] == ' ')
                {
             
                }
                else
                {
                    strcat(outMorse, "/");
                }
            }
            else if(ch == '\n' || ch == '\r')
            {
                
            }
            else
            {
                printf("ERROR");
                outMorse[0] = '\0'; 
                break;
            }
        }
     puts(outMorse);
     return 0;
 }
