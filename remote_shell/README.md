# remote_shell
### Use

1. Serve [Server](./server.c) 

```shell
>_ gcc -o puppet.out server.c
>_ ./puppet.out PORT
```

2. Make Contact From [Client](./client.c)
```shell
>_ gcc -o string.out client.c
>_ ./string.out HOST PORT
```
### Defaults
* PORT  :  8080
* HOST  :  "127.0.0.1" ( "localhost" )
