#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>

int main()
{
 FILE *fp;
 char s[40],s1[40],c,ch[35],res[35],check[35];
 char s2[40],s3[40];
 int i=1,b,v,top=-1,len,a[40],sum=0,j,z,r,flag=0,flag10=0,len1=0;
 int result=1;
 
 system("clear"); //clear the console.
 
 fp=fopen("hangman.txt","r"); //open the file containing the words in  read mode.
 if(fp==NULL)
 {
  printf("File cannot be opened");
  exit(0);
 }
  
  srand(time(NULL)); //Generate random each time.
  i=rand()%11;
  
  for(j=0;j<=i;j++)
   fscanf(fp,"%s %s %s %s",s1,s2,s3,s); //retrieve the random data.
  
  //The word to be Identified is present in s.
  
  fclose(fp);//Close the opened file, once the data is obtained.
  
  //The main game code begins.
  
  printf("Welcome to HANGMAN.\n");
  printf("\nPlease guess the word given below:\n");
  printf("\nIf the word contains a 'space' it is identified by '_'.\n");
  printf("\nThe vowels present in the word are identified previously.");
  printf("\nYou have 10 chances to identify\n");
  printf("\nThe clue is:");
  printf("\nThe Word belongs to a %s and is Name of %s.",s2,s3);
  len=strlen(s);
  printf("\nThe length of word including 'space'(if exist) is %d.\n",len);
  
  for(i=0;i<len;i++)//Initialize the res array with '-'.
    res[i]='-';
  res[i]='\0';
  
 
  for(i=0;i<strlen(s);i++) //Identify vowels present in s, and replace them in res.
  {
    if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='_'){
     len1++; //The no of vowels present in s.
     res[i]=s[i];
     printf("%c ",s[i]);
     }
    else
     printf("- ");
  }
  //Initialize the stack(check) with vowels, so that vowel repeatation is avoided.
  check[0]='A';check[1]='E';check[2]='I';check[3]='O';check[4]='U';
  top=5;//Current top of stack.
  len=strlen(s)-len1; //len=No of consonants.
  
  printf("\n\nYou have 10 chances!!\n");
  printf("\n\nGuess an character:");
  
  while(result<11) //user has 10 chances to identify given word.
  {
      scanf("%s",&c); //Get user input.
      if(c>=97 && c<=122) //if entered character is in lowercase convert it to corressponding uppercase.
         c=c-32; //char=char-32 gives uppercase of given lowercase char.
      
      fflush(stdin); //flush both stdin and stdout.
      fflush(stdout);
      
      for(v=0;v<=top;v++){ //check for repeatition of letters.
	       if(check[v]==c) //if input char is present in the stack, display 'repeat'.
	        {
	         printf("Please don't repeat!!\n");
	         printf("you have %d chances left!!",10-result++);//Decrease the no of chances by one.
	         goto check_flag1; //go to check_flag1.
	        } 
	    }

      for(j=0;j<strlen(s);j++) //check for occurence of given char in s.
      {
	     if(c==s[j] && (c!='A' || c!='E' || c!='I' || c!='O' || c!='U')) //if c==s[j] and c is not a vowel.
	     {
	        res[j]=c;//place c in res.
	        flag=1;//set flag=1, so as to display updated res.
	        sum++;//increase sum of chars in res by one.
	        check[++top]=c;//push char c on stack.
	     }
	      
	      if(sum==len){ //if(sum==len), indicates given word is identified, hence flag10 is set.
	        flag10=1;
	        goto check_flag;
	        }
	        
      }
     
     if(flag==1)
     { //if flag==1, then entered char is present in s.
       for(r=0;r!=strlen(res);r++) //print the res arr, with the entered input char.
           printf("%c ",res[r]);
     }
     else
     { //if flag!=1, then entered char is not present in s.
      printf("Wrong guess!!");
      printf("you have %d chances left!!",10-result++);//Decrease the chances count by 1.
     }
     
   check_flag1:  flag=0; //set flag back to 0.
                 printf("\nEnter the next character:"); //Get new input.
                 fflush(stdin);//flush both stdin and stdout.
                 fflush(stdout);
  }
  
 check_flag:
             if(flag10==1)
             { //if flag10==1, indicates given word is identified.
               printf("\n\nYou won!!!Congratulations");
               printf("\nThe word was %s\n",s);
             }
             else
             { //if flag10==0, indicates player has failed to identify given word.
               printf("\n\nYou lose!!!"); 
               printf("\nThe word was %s\n",s);
             }
             
 printf("\nThanks for playing!!!Greatings!!!!\n");//if player wins or looses, he is greated.
 
 return 0;
}
