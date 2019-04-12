#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#include <errno.h>
#include <sys/wait.h>
#include <arpa/inet.h>

#include <ifaddrs.h>

#define buffer_size 2048

char buffer[buffer_size] = {0};

char* buff;

//server
int server_fd,new_socket,valread;
struct sockaddr_in address;
int opt = 1;
int addrlen = sizeof(address);


struct hostent *host_entry;
char hostbuffer[256];
char* IP_buffer;
int hostname;

struct ifaddrs *id ;


void print_host(){
  /*
  hostname = gethostbyname(hostbuffer);
  checkHostEntry(hostname);

  host_entry = gethostbyname(hostbuffer);
  checkHostEntry(host_entry);

  IP_buffer = inet_ntoa( *((struct in_addr*) host_entry->h_addr_list[0]) );

  printf("Hostname : %s",hostbuffer);
  printf("Host IP  : %s",IP_buffer);
  */

  int val = getifaddrs(&id);
  printf("Network Interface Name : %s \n",id->ifa_name);
  printf("Network Address of %s : %d \n",id->ifa_name,id->ifa_addr);
  printf("Network Data : %d \n",id->ifa_data);
  printf("Socket Data : %d \n",id->ifa_addr->sa_data);




}


//client
//struct sockaddr_in address;
int sock = 0;
struct sockaddr_in serv_addr;


int serve(int port){
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
      perror("socket failed");
      exit(EXIT_FAILURE);
  }
  if ( setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) ){
      perror("setsockopt failed");
      exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( port );

  printf("Binding...");
  if ( bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
      perror("\tFailed!\n");
      exit(EXIT_FAILURE);
  }else{
  printf("\tDONE!\n");
  }
  printf("Listening...");
  if (listen(server_fd, 3) < 0){
      perror("\tFailed\n");
      exit(EXIT_FAILURE);
  }else{
    printf("\tDONE!\n");
  }
  printf("Accepting...");
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
      perror("accept\n");
      exit(EXIT_FAILURE);
  }else{
    printf("\tDONE!\tSERVER ONLINE\n");
  }
}

int make_contact(char * inet,int port){
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		//printf("\n Socket creation error \n");
		return -1;
	}

	memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons( port );

	if(inet_pton(AF_INET, inet , &serv_addr.sin_addr)<=0){
		//printf("\nInvalid address/ Address not supported \n");
		return -1;
	}
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
		//printf("\nConnection Failed \n");
		return -1;
	}
}

void clear_buffer(){
  memset(buffer,'\0',buffer_size);
}
