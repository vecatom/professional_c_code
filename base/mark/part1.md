
# 第一章 C 语言的探索


## 关于C语言的工程项目管理
> 创建工程目录  test

```shell

mkdir test   # 创建项目根目录
mkdir -p test/srg      # 创建源代码目录
mkdir -p test/inc      # 创建链接库存放目录
mkdir -p test/obj      # 创建存放编译后的对象目录
mkdir -p test/bin      # 创建可执行程序目录


```

> 在src 下创建 test_main.c 文件

```c
# test_main.c   

int main(int argc,char *argv[]){
	return argc;

}

```

> 编译过程


```shell

gcc -c src/test_main.c -o obj/test_main.o   # 编译源文件为
gcc -c obj/test_main.o -o bin/test_main     # 链接为可执行程序
bin/test_main                  # 执行
echo $?                        # 查看返回值
bin/test_main 1 2
echo $?
bin/test_main 1 2 3
echo $?

```



> 编译有引入头文件的C源码

```shell

gcc -C -Iinc src/test.c -o obc/test.o
gcc obj/test.o bin/test
bin/test


```

> 查看预编译引用文件的处理结果

```shell
gcc src/test.c -E -p       # 无头文件引入
gcc -Iinc src/test.c -E -P  # 有头文件引入

```
