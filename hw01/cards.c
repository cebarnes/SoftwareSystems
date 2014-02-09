/*
 * Program to evaluate face values.
 * Released under the Vegas Public License.
 * (c)2014 The College Blackjack Team.
 */

#include <stdio.h>
#include <stdlib.h>

/* Prompts user to input card name
truncates input after 2 characters
modifies contents of card_name to user input*/
void getinput(char *card_name)
{
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
}

/* Prints formatted value*/
void print_value(int val)
{
	printf("The card value is: %i\n", val);
}

/* Takes in value and checks if value is in desired range
returns 1 or 0*/
int check_valid_value(int val)
{
	if ((val<11) || (val>10)) {
		return 0;
	}
	else{
		return 1;
	}
}

/* Takes in card array
Returns value of the card*/
int card_value(char *card)
{
	int val = 0;
		switch(*card){
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		default:
			val = atoi(card);
		}
	return val;
}

/* Increments count integer by 1 or -1 if
card value in appropriate range
prints the count after it is updated*/
void update_count(int val, int* count)
{
	if ((val>2) && (val<7)) {
		*count = *count + 1;
	} else if (val==10) {
		*count = *count -1;
	}
	printf("Current count: %i\n", *count);
}

/* Takes user input, checks value of card,
updates the count and repeats until the user inputs X*/
void card_loop()
{
	char card[3];
	int val = 0;
	int count = 0;
	while(card[0] != 'X') {
		getinput(card);
		val = card_value(card);
		if (check_valid_value(val)){
			puts("I don't understand that value!");
		} else {
			print_value(val);
			update_count(val,&count);
		}
	}
}


int main()
{
	card_loop();
	return 0;
}