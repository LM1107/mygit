#include <client.c>

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

	//绑定函数bind()
	int ret = bind(connfd,(struct sockaddr*)&dest_addr,sizeof(dest_addr));
	if(ret < 0)
        PERROR("bind");
	
	int ret = -1;
	//请求连接目标地址
 
	ret = connect(connfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
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
			perror("recv");
			exit(-1);
		}
        size += ret;
	}
	return size;
}

int upload(int connfd,char *filename)
{
	char file_path[128] = {0};//文件路径
	char file_info[2048] = {0};//文件信息
	char buf[1024] = {0};
	
	//获取用户输入的文件路径
	printf("Please enter file path: ");
	scanf("%s", file_path);
	
	//从文件路径中获取文件名，如"test/a.txt" ==> "a.txt"
	char file_name[128] = {0};
	//basename():从路径中获取文件名及后缀
	strncpy(file_name, basename(file_path), sizeof(file_name));
	
	//打开文件
	int fd = open(file_path, O_RDWR);
	if (fd == -1)
	{
		printf("open [%s]  failed", file_path);
		return -1;
	}	
	
	//计算文件大小
	int len = lseek(fd, 0, SEEK_END);
 
	//文件光标偏移到文件开始位置
	lseek(fd, 0, SEEK_SET);
	
	//将文件大小和文件名存放到file_info
	sprintf(file_info, "%d", len);
	strcpy(file_info + 16, file_name);
		
	// 将需要上传的文件名告诉对方 
	write(tcp_socket, file_info, 144);
 
	int send_len = 0;//记录发送了多少字节
	
}