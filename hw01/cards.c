/*
 * Program to evaluate face values.
 * Released under the Vegas Public License.
 * (c)2014 The College Blackjack Team.
 */

#include <stdio.h>
#include <stdlib.h>

void getinput(char *card_name)
{
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
}

void print_value(int val)
{
	printf("The card value is: %i\n", val);
}

int check_valid_value(int val)
{
	if ((val<11) || (val>10)) {
		return 0;
	}
	else{
		return 1;
	}
}

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

void update_count(int val, int* count)
{
	if ((val>2) && (val<7)) {
		*count = *count + 1;
	} else if (val==10) {
		*count = *count -1;
	}
	printf("Current count: %i\n", *count);
}

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