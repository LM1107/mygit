#include "client.h"

int main()
{
	int ret = TcpServerInit("127.0.0.1",12345);
	if(ret == -1)
	{
		printf("connect failed!\n");
		return -1;
	}
	printf("Connect succeed!\n");

	while (1)
	{	
		bzero(buf, sizeof(buf));
		//读取数据
		ret = read(fd, buf, sizeof(buf));
		if (ret < 0)
        {
            perror("read");
            exit(-1);
        }
        if (ret == 0)
		{
			printf("send file[%s] succeed!!!!\n", file_name);
			break;
		}
			
		//发送数据
		write(tcp_socket, buf, ret);
		
		send_len += ret;//统计发送了多少字节
		
		//上传文件的百分比 // loading()
		printf("uploading %.2f%%\n", (float)send_len/len * 100);
	}

	// 关闭文件 
	close(fd);
	//关闭通信socket 
	close(tcp_socket);
	return 0;
}