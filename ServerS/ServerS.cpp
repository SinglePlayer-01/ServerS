#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#include<iostream>

#pragma warning(disable: 4996)

int main(int args, char* argv[])
{

	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("192.168.1.204");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConenction;
	newConenction = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

	if (newConenction == 0)
	{
		std::cout << "Error #2" << std::endl;
	}
	else
	{
		std::cout << "Client Connected!\n";
	}

	system("pause");

	return 0;
}