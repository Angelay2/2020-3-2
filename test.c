#include <stdio.h>
#include <Windows.h>

// 文件指针 (FILE*)
//FILE* fopen(const char* filename, const char* mode)
// 第一个参数是你要打印的文件(能带路径就带路径), 第二个参数是打印的方式(w)
// 返回值为 FILE*, FILE也是类型 其实是一个结构体 包含了文件的很多属性
// 不同C编译器的FILE类型包含的内容不完全相同
// 除了第一次打开文件 往后任何一次对文件的操作都必须有FILE*函数
// 挟天子以令诸侯 掌天下之柄 => 句柄(FILE*)
// 对文件的任何操作 都必须通过FILE*(汉献帝) 我们的天下就是文件 
// 想对文件进行任何操作 必须通过FILE*
// fopen 帮我们打开文件,返回值是指针(指向FILE) FILE不是我们定义的,
// 我们只定义了FILE* 还帮我们创建了一个FILE结构的变量

// fclose帮我们关闭文件的同时还把文件对应的结构体释放掉
int main(){

	system("pause");
	return 0;
}