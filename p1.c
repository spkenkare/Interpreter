#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MISSING() printf("missing %s:%d\n",__FILE__,__LINE__)

long alphabet[26];


void interpret(char program[]) {
	int state = 0;
	int place = 0; //place in program
	char letter = ' '; //current letter
	char num[9]; //current number
	int numDigits = 0; //number of digits after last leading zero
	int zeroes=0; //number of leading zeroes
	
	while(state<4 && place<strlen(program)) {
		switch(state) {
			case 0: //looking for letter, reset all vars
				letter=' ';
				num[0] = '\0';
				numDigits=0;
				zeroes=0;
				if(program[place]>='a'&&program[place]<='z') {
					state=1;
					letter=program[place];
					place++;
				}
				else {
					place++;
				}
				break;
			case 1: //looking for equals
				if(program[place]=='=') {
					place++;
					state=2;
				}
				
				else {
					place++;
				}
				break;

			case 2: //looking for first nonzero number

                                if(isdigit(program[place]) && program[place]!='0') {
                                        numDigits++;
					int len = strlen(num);
     					num[len] = program[place];
     					num[len+1] = '\0';
                                        state=3;
                                        place++;
                                }
				else if(program[place]=='0') { //leading zero
					int len = strlen(num);
                                        zeroes++;
					num[len+1] = '\0';
                                        state=2;
                                        place++;
				}
				else if(program[place]==';'&&zeroes>0) { //reset var to zero
                                        alphabet[(int)letter-97]=0;
					place++;
                                        state=0;
                                }
                                else {
                                        place++;
                                }
                                break;
			case 3:
                                if(numDigits<9&&isdigit(program[place])) { //after leading zeroes
                                        numDigits++;
                                        int len = strlen(num);
                                        num[len] = program[place];
                                        num[len+1] = '\0';
                                        place++;
                                        state=3;
                                }
                                else if(program[place]==';') {
					place++;
                                        state=0;
					alphabet[(int)letter-97]=atol(num); //set the array
                                }
                                else {
                                        place++;
                                }
                                break;

			default:		
				state=5; //break out of loop
				break;

		}
	}

	for(int i=0; i<26; i++) {
		if(alphabet[i]!=0) {
        		printf("%c:", i+97);
        		printf("%ld \n", alphabet[i]);
		}
	}


}


int main(int argc, char* argv[]) {
	interpret(argv[1]);
	return 0;
}


