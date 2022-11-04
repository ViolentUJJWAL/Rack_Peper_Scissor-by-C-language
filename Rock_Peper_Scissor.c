#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rendonNum(){
	srand(time(NULL));
	int r = rand()%3; 
	return r;
}

int computerScore(){
	static int cs = 0;
	cs++;
	return cs;
}

int userScore(){
	static int us = 0;
	us++;
	return us;
}

void greet(char name[]){
	printf("*****Welcome to Game World*****\n\aDear, ");
	puts(name);
}

char winning(int user, int rendom){
	if (user==1){
		printf("You Choose the Rock\n\a");
		if (rendom==1){
			printf("Computer Choose the Rock\n\a");
			printf("Rock Boxing\n\a");
			return 's';
		}
		else if (rendom==2){
			printf("Computer Choose the Pepar\n\a");
			printf("Paper Covers Rock\n\a");
			return 'c';
		}
		else{
			printf("Computer Choose the Scissor\n\a");
			printf("Rock Breaks Scissor\n\a");
			return 'u';
		}
	}
	else if (user==2){
		printf("Your Choose the Paper\n\a");
		if (rendom==1){
			printf("Computer Choose the Rock\n\a");
			printf("Paper Covers Rock\n\a");
			return 'u';
		}
		else if (rendom==2){
			printf("Computer Choose the Pepar\n\a");
			printf("Paper Smackdown\n\a");
			return 's';
		}
		else{
			printf("Computer Choose the Scissor\n\a");
			printf("Scissor Cuts paper\n\a");
			return 'c';
		}
	}
	else {
		printf("Your Choose the Scissor\n\a");
		if (rendom==1){
			printf("Computer choose the Rock\n\a");
			printf("Rock Breaks Scissor\n\a");
			return 'c';
		}
		else if (rendom==2){
			printf("Computer Choose the Pepar\n\a");
			printf("Scissor Cuts paper\n\a");
			return 'u';
		}
		else{
			printf("Computer Choose the Scissor\n\a");
			printf("Scissor Fight\n\a");
			return 's';
		}
	}
}

int main()
{
	char name[12];
	printf("Enter your Name:\a ");
	gets(name);
	greet(name);
	int* ptr;
	ptr = (int *)malloc(sizeof(int));
	int n;
	printf("   1 for 5 Round\n   2 for 10 Round\n   3 for Coustem Round\nEnter--> \a");
	scanf("%d", &ptr[0]);
	if (ptr[0]==2){
		n=10;
	}
	else if (ptr[0]==3){
		printf("Enter the no. of Round: \a");
		scanf("%d",&n);
	}
	else{
		n=5;
	}
	free(ptr);
	for (n; n>0; n--){
		printf("<<----------------------------->>");
		printf("Round %d\n",n);
		ptr = (int *)malloc(2*sizeof(int));
		ptr[0]= rendonNum()+1;
		while (-1){
		printf("1 for Rock\n2 for Paper\n3 for Scissor\nChoose any one--> \a");
		scanf("%d", &ptr[1]);
			if (0<ptr[1] && ptr[1]<4){
				break;
			}
			else{
				printf("Please Enter only 1,2 and 3\n\a");
				continue;
			}
		}
		char win=winning(ptr[1], ptr[0]);
		if (win=='u'){
			userScore();
			printf("------->>>>> %s win\n", name);
		}
		else if (win=='c'){
			computerScore();
			printf("------->>>>> Computer win\n\a");
		}
		else{
			printf("------->>>>> Both are Same\n\a");
		}
		free(ptr);
	}
	printf("<<----------------------------->>\n\a");
	ptr = (int *)malloc(2*sizeof(int));
	ptr[1]= userScore()-1;
	ptr[0]= computerScore()-1;
	printf("Your score is %d\a\ncomputer score is %d\n\a", ptr[1],ptr[0]);
	if (ptr[0]==ptr[1]){
		printf("<<<< Both are same point >>>>\n\a");
	}
	else if (ptr[0]<ptr[1]){
		printf("<<<< %s you win the game >>>>\n\a", name);
	}
	else{
		printf("<<<< %s you lose the game >>>>\n\a", name);	
	}
	free(ptr);

	return 0;
}
