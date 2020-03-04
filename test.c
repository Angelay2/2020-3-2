#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

// 文件指针 (FILE*)
//FILE* fopen(const char* filename, const char* mode)
// 第一个参数是你要打印的文件(能带路径就带路径),路径可以把盘符那些都带上
// 第二个参数是打印的方式(w), fopen 是接口
// 返回值为 FILE*, FILE也是类型 其实是一个结构体 包含了文件的很多属性
// 不同C编译器的FILE类型包含的内容不完全相同
// 除了第一次打开文件 往后任何一次对文件的操作都必须有FILE*函数
// 挟天子以令诸侯 掌天下之柄 => 句柄(FILE*)
// 对文件的任何操作 都必须通过FILE*(汉献帝) 我们的天下就是文件 
// 想对文件进行任何操作 必须通过FILE*
// fopen 帮我们打开文件,返回值是指针(指向FILE) FILE不是我们定义的,
// 我们只定义了FILE* 还帮我们创建了一个FILE结构的变量

// fclose帮我们关闭文件的同时还把文件对应的结构体释放掉
// FILE* fopen(const char* filename, const char* mode)
// int fclose(FILE* stream);
// 最终把fopen的返回值 作为fclose的一个返回值传进去

//文件使用方式 (操作文件的内容)
// 'r'(只读), 'w'(只写) 从头开始覆盖式的写, 'a'(追加)从文件的后面写
// 'wb',带b 的都表示的是二进制文件, 不带b的都为文本文件
// 'r+'表示打开是为了读和写, 'w+'表示打开为了读和写, 两个区别是倘若没有要写的文件 后者会自动创建一个文件 再写入,
// 带+ 表示打开文件 'rb+' 表示为了读和写打开一个二进制文件
// int fputs(const char* str, FILE* stream) 往文件里放字符串
// 第一个参数是要往文件里放的字符串是什么 第二个参数表示往哪个文件里放
int main1(){
	// FILE* fp = fopen("C:\\Users\\Administrator\\Desktop\\my.txt", "w");// 在桌面创建一个文件
	FILE* fp = fopen("my.txt", "w");// 在当前文件目录创建一个文件 
	// 除了第一步的fopen之外 后面的所有步骤都必须包含一个参数fp 要通过fp来进行相关操作
	if (NULL == fp){
			printf("fopen error!\n");
			return 1;
	}

	const char* str = "1234abcd";
	fputs(str, fp);

	fclose(fp);
	system("pause");
	return 0;
}


















