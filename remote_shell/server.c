
#include "net.h"
#include "Shell.h"

int main(int argc, char const *argv[]){
	int port;
	char* host;
	if(argc == 1 ){
		port = 8080;
	}else{
		port = atoi(argv[1]);
	}

	print_host();

	printf("PORT NO. %d\n",port);
	serve(port);

	dup2(new_socket,STDOUT_FILENO);

	while(1){
		valread = read( new_socket , buffer , buffer_size );
		printf("%s",buffer);
		//clear_buffer();

		displayPrompt();
		//getline(&command, &capline, stdin);
		//printf("%s",command);

		strcpy(command,buffer);
		//printf("COMMAND : %s ",command);

		if(strcmp(command,"\n")==0){
			perror("Please type in a command " );
			continue;
  		}
		makeTokens(command);
		if (strcmp( tokens[0] , EXIT_SHELL ) == 0) {
			printf("SYSTEM : Shell is exiting from shell ...\n");
			return 0;
 		}
		execute(tokens);

		clear_buffer();
	}
}
