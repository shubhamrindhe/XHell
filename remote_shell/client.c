
#include "net.h"
#include "Shell.h"

int main(int argc, char const *argv[]){
	int port;
	char* host;
	if(argc == 1 ){
		//make_contact("127.0.0.1",8080);
		port = 8080;
		host = "127.0.0.1";
		make_contact("127.0.0.1",port);
	}else{
		port = atoi(argv[2]);
		host = argv[1];
		make_contact(argv[1],port);
	}

	printf("HOST %s\n",host);
	printf("PORT NO. %d\n",port);



	while(1){

		displayPrompt();

		fgets(buffer,1024,stdin);

		/*
		buff = readline(">_");
		add_history(buff);
		strcpy(buffer,buff);
		*/
		
		write( sock , buffer , strlen(buffer));
		//clear_buffer();
		
		makeTokens(buffer);
		if (
			strcmp( tokens[0] , "cd" ) == 0 || 
			strcmp( tokens[0] , "touch" ) == 0 || 
			strcmp( tokens[0] , "mkdir" ) == 0 
		){
			//printf("%s",tokens[0]);

			valread = read( sock , buffer , buffer_size );
			clear_buffer();
 		
		}else{
			valread = read( sock , buffer , buffer_size );
			clear_buffer();

			valread = read( sock , buffer , buffer_size );
			printf("%s",buffer);
			clear_buffer();
		}
		
	}
	return 0;
}
