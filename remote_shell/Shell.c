
#include "Shell.h"

int main() {
	//startDisplay();
	while(1) {
		displayPrompt();
		getline(&command, &capline, stdin);
		//printf("%s",command);
		if(strcmp(command,"\n")==0){
			perror("Please type in a command " );
			continue;
		}
		makeTokens(command);
		if (strcmp( tokens[0] , EXIT_SHELL ) == 0) {
			printf("SYSTEM : Shell is exiting from shell ...\n");
			return 0;
		}
		//print_tokens();
		execute(tokens);
	}
	return 0;
}
