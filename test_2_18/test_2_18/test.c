#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//strstr  查找字符串

char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	char* s1 = p1;
	char* s2 = p2;
	char* cur =(char*) p1;

	//如果字符串p2是空字符串，直接返回p1字符串首地址
	if (*p2 == '\0')
	{
		return (char*)p1;
	}

	//开始寻找
	while (*cur)//利用cur保存比较开始的地址，方便返回
	{
		//初始s1,s2记录各自比较字符串的首地址
		s1 = cur;
		s2 = (char*)p2;
		
		//比较条件
		while (*s1 && *s2 && (*s1 == *s2))
		{
			//依次往后进行比较
			s1++;
			s2++;
		}
		//如果跳出循环后，*s2是'\0'就说明p2比较完成，属于p1的子字符串
		if (!*s2)
		{
			return cur;
		}
		//如果跳出循环后，*s2是'\0'，就说明p1已经比较到头了，而p2还未比较完，
		//如"abcde"和"defj"
		if (!*s1)
		{
			return NULL;
		}
		//从下一个字符开始往后比较
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
		printf("字串不存在\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}