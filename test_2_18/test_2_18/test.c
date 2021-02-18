#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//strstr  �����ַ���

char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	char* s1 = p1;
	char* s2 = p2;
	char* cur =(char*) p1;

	//����ַ���p2�ǿ��ַ�����ֱ�ӷ���p1�ַ����׵�ַ
	if (*p2 == '\0')
	{
		return (char*)p1;
	}

	//��ʼѰ��
	while (*cur)//����cur����ȽϿ�ʼ�ĵ�ַ�����㷵��
	{
		//��ʼs1,s2��¼���ԱȽ��ַ������׵�ַ
		s1 = cur;
		s2 = (char*)p2;
		
		//�Ƚ�����
		while (*s1 && *s2 && (*s1 == *s2))
		{
			//����������бȽ�
			s1++;
			s2++;
		}
		//�������ѭ����*s2��'\0'��˵��p2�Ƚ���ɣ�����p1�����ַ���
		if (!*s2)
		{
			return cur;
		}
		//�������ѭ����*s2��'\0'����˵��p1�Ѿ��Ƚϵ�ͷ�ˣ���p2��δ�Ƚ��꣬
		//��"abcde"��"defj"
		if (!*s1)
		{
			return NULL;
		}
		//����һ���ַ���ʼ����Ƚ�
		cur++;
	}
	return NULL;

}

int main(void)
{
	char* p1 = "abbbcdef";
	char* p2 = "bbc";
	char* ret = strstr(p1, p2);
	//char* ret = my_strstr(p1, p2);
	if (ret == NULL)
	{
		printf("�ִ�������\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}