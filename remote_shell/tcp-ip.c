#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>    
#include <sys/wait.h>
#include<sys/socket.h> 
#include<arpa/inet.h>

int make_contact( struct sockaddr_in s_in ,int socket,char * inet_address, int port ){
	s_in.sin_addr.s_addr = inet_addr( inet_address );
	s_in.sin_family      = AF_INET;
	s_in.sin_port        = htons(port);

	if ( connect( socket , (struct sockaddr *)&s_in , sizeof(s_in) ) < 0 )
		return 1;
	else
		return 0;
}

int serve(int server_fd,int socket){

}

int send_over(int socket,char* data){
	if( send( socket , data , strlen(data) , 0) < 0)
		return 1;
	else
		return 0;
}

char* listan_to(int socket,int length){
	char* data  =  (char *) malloc( sizeof(char)*length );
	if( recv(socket,data, length , 0) < 0 )
		return NULL;
	else
		return data;
}

int main(int argc , char *argv[]){
	char server_reply[2000];
	int socket_desc;
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	struct sockaddr_in server;
	
	if( socket_desc == -1 )
	{
		printf("Could not create socket");
	}else{
		printf("Socket is ready!");
	}
	if( make_contact(server,socket_desc,"74.125.235.20",9999) != 0 )
		puts("connection failed ! ");
	else
		puts("connected!");


	/*
	server.sin_addr.s_addr = inet_addr("74.125.235.20");
	server.sin_family = AF_INET;
	server.sin_port = htons( 80 );

	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connection failed ! ");
		return 1;
	}
	
	puts("connected!");
	*/


	//Send some data
	/*
	char * message = "GET / HTTP/1.1\r\n\r\n";
	if( send(socket_desc , message , strlen(message) , 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");
	*/
	

	/*
	if(send_over(socket_desc,"HelloWorld")==0)
		printf("Data Sent!");
	else
		printf("Can't Send Data!");
	*/

	/*
	
	char server_reply[2000];

	char* reply = listan_to(socket_desc,2000);
	
	if(reply!=NULL){
		puts("incomming!");
		puts(reply);
	}else{
		puts("lol");
	}

	*/

	/*
	//Receive a reply from the server
	if( recv(socket_desc, server_reply , 2000 , 0) < 0)
	{
		puts("recv failed");
	}
	puts("Reply received\n");
	printf("%s",server_reply);

	read(socket_desc, server_reply , 2000);
	puts(server_reply);
	
	printf("%lu",strlen(server_reply));
	printf("%c",*server_reply);
	printf("%d",*server_reply);
	*/

	if(argc==1){
		printf("client %d",argc);
		char* reply = listan_to(socket_desc,2000);
		puts(reply);
	}else{	
		printf("server %d",argc);
		//send_over(socket_desc,"HelloWorld");

		while(send_over(socket_desc,"HelloWorld")!=0){
		}
	}
	close(socket_desc);
	return 0;
}
