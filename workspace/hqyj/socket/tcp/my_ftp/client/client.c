#include "client.h"

int TcpServerInit(const char *IP,int port)
{
	//建立socket连接
	int connfd = socket(AF_INET,SOCK_STREAM,0);
	if(connfd < 0)
		PERROR("socket");

	//设置sockaddr_in 结构体中的相关参数
	struct sockaddr_in dest_addr;
	bzero(&dest_addr,sizeof(dest_addr));
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(port);
	dest_addr.sin_addr.s_addr = inet_addr(IP);
	//dest_addr.sin_addr.s_addr = INADDR_ANY;//让系统自动检测本地网卡IP并绑定

	int ret = connect(connfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
	if(ret != 0)//连接成功
        PERROR("connect");
    return connfd;
}

//内部函数
int recvMsg(int connfd,char *buf,int length)
{
	int ret = 0;
    int size = 0;
	while(size < length)
	{
		ret = read(connfd, buf+size, length-size);
		if(ret < 0)
		{
			perror("\n[recv_%s] recv file failed\n");
			exit(-1);
		}
		if(ret == 0)
			return size;
		size += ret;
	}
	return size;
}

int sendMsg(int connfd,char *buf,int length)
{
	int ret = 0;
	int size = 0;
	while(size<length)
	{
		ret = write(connfd, buf+size, length-size);
		if(ret < 0)
		{
			perror("write");
			exit(-1);
		}
        size += ret;
	}
	return size;
}

int handler(int connfd,char *buf)
{    
    if(0 == strcmp("help", buf) )
    {
        printf("*********************************************\n");
        printf("* help                             #show help\n");
        printf("* show                          #show allfile\n");
        printf("* upload <filename>              #upload file\n");
        printf("* download <filename>          #download file\n");
        printf("* quit                            #quit stuDB\n");
        printf("*********************************************\n");
    }
    else
    if(0 == strcmp("show", buf) )
        sendMsg(connfd,buf,N);
    else
    if(0 == strncmp("upload", buf,6) )
    {    
        upload(connfd,buf);
        return 0;
    }
    else
    if(0 == strncmp("download", buf,8) )
        sendMsg(connfd,buf,N);
    else
    if(0 == strcmp("quit",buf))
        return 1;
    else
        printf("CMD ERR!!!, try help!!!\n");
}
/*
int download(int connfd,char *filename)
{

}
*/
int upload(int connfd,char *temp)
{
    char buf[BUF_SIZE] = {0};
    strcpy(buf,temp);

    write(connfd,buf,sizeof(buf));

    char file_info[BUF_SIZE] = {0};
    char file_name[N] = {0};
    char file_path[N] = {0};

    sscanf(buf,"%*s%s",file_path);

    strncpy(file_name,basename(file_path),sizeof(file_path));
    int fd = open(file_path,O_RDONLY);
    if(fd == -1)
    {
        printf("open [%s] failed",file_name);
        return -1;
    }
    int len = lseek(fd,0,SEEK_END);
    lseek(fd,0,SEEK_SET);
    sprintf(file_info,"%d",len);
    strcpy(file_info+16,file_name);

    write(connfd,file_info,144);

    while(1)
    {
        bzero(buf,sizeof(buf));
        //读取数据
        
        int ret = read(fd,buf,sizeof(buf));
        
        sendMsg(connfd,buf,ret);

        if(ret == 0)
        {
            printf("send file[%s] succeed!!!!", file_name);
            break;
        }
    }
    close(fd);
    return 0;
}

