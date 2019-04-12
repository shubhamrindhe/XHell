/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
*/
#define EXIT_SHELL "exit"

//char* command = NULL;
char command[512] = {0};
size_t capline = 0;
int i = 0;
char *token;
char *tokens[512];


void makeTokens(char *input){
	i = 0;
	token = strtok(input, "\n ");
	while (token != NULL) {
		tokens[i++] = token;
		token = strtok(NULL, "\n ");
	}
	tokens[i] = NULL;
}

void execute(char* cmd_tokens[]){
	int pid = fork();
	if (pid != 0) {
		int s;
		waitpid(-1, &s, 0);
	}else{
		if(strcmp(tokens[0],"cd")==0){
			chdir(tokens[1]);
			//exit(0);
			return 0;
		}
		if(execvp(cmd_tokens[0], cmd_tokens) == -1){
			perror("Wrong command");
			exit(errno);
		}
	}
}
void displayPrompt(){
	printf(">_ ");
}
void print_tokens(){
	i=0;
	char* cmd;
	printf("\n tokens are :\n");
	while( ( cmd = tokens[i] ) != NULL ){
		printf("\t%s\n",cmd);
		++i;
	}
	printf("\n");
}
