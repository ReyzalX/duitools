// duirc.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <stdio.h>
#include <Windows.h>
#include <ShellAPI.h>
//ʹ��7z�����Դ�ļ�
//����1 uires����·��
//����2 Ŀ��zip�ļ�Ŀ¼
int main(int argc, char* argv[])
{
	for (size_t i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	if (argc < 3)
	{
		printf("����̫��\n");
		return 0;
	}

	char szPath[260];
	char szDst[260];
	char szExePath[260];
	char szCmdLine[1024];
	strcpy(szPath, argv[1]);
	strcpy(szDst, szPath);
	strcat(szDst, "\\duires.zip");
	strcat(szPath, "\\uires\\*");
	strcpy(szExePath, argv[0]);
	*strrchr(szExePath, '\\') = '\0';
	strcat(szExePath, "\\7z.exe");
	sprintf(szCmdLine, "%s a -tzip \"%s\" \"%s\"", szExePath, szDst, szPath);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	memset(&si, 0, sizeof(STARTUPINFO));
	si.wShowWindow = SW_HIDE;
	memset(&pi, 0, sizeof(PROCESS_INFORMATION));
	si.cb = sizeof(STARTUPINFO);
	CreateProcess(NULL, szCmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, 5 * 60 * 1000);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	printf("%s\n", szCmdLine);
    return 0;
}

