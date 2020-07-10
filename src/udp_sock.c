#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <ctype.h>

#include "udp_sock.h"


typedef struct _sock_st
{
	struct sockaddr_in serv;
	int cfd;
}

_sock_st st;

int create_udp_connect(void)
{
	int cfd = socket(AF_INET,SOCK_DGRAM,0);

	st.serv.sin_port = htons(8888);
	inet_pton(AF_INET,"127.0.0.1",&serv.sin_addr.s_addr);
	st.cfd = cfd;
	
	return cfd;

}

int send_udp(const char *str,int strlen)
{	
	int send_len = sendto(st.cfd,str,strlen,0,(struct sockaddr *)&st.serv,sizeof(st.serv));

	return send_len;
}





