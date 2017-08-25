#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char s[]={"www.baidu.com"};
	int len=sizeof(s);
	int rt;
	if(remove("./example.txt") == 0)
	{
		printf("删除遗留的example.txt成功\n");
	}
	else
	{
		perror("file delete");
	}
	if((fp = fopen("./example.txt","a+")) == NULL)	//rb+以读写方式打开一个二进制文件，只允许读写数据
	{
		perror("file open");
		exit(1);
	}
	else
	{
		printf("文件创建成功\n");
	}
	
	rt=fwrite(s,sizeof(char),len-1,fp);
	printf("写入文件的字符长度为%d\n",rt);
	if(rt != (len-1))
	{
		perror("wirte file");
		exit(1);
	}
	else
	{
		printf("文件写入成功\n");
	}
	
	fseek(fp, 0, SEEK_END);//指向文件结尾
	len= ftell(fp);		//返回指针到文件头的长度
	rewind(fp);			//重新指向文件开头
	
	char *back_s=(char *)malloc(sizeof(char)*len);
	rt=fread(back_s,sizeof(char),len,fp);
	printf("读出数据的长度为%d\n",rt);
	
	if(rt != len)
	{
		perror("read file");
		exit(1);
	}
	else
	{
		printf("读出的数据是%s\n",back_s);
	}
	free(back_s); //释放申请的内存
	fclose(fp);
	return 0;
}
