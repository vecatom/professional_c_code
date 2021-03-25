
## 使用gcc将C代码转化为汇编代码
> 将C代码转换为汇编代码，后缀为 xxxx.s ,可以直接查看汇编代码
```sh
# 转换为汇编代码
gcc -Og -S mstore.c
# 查看汇编代码
cat mstore.s  
```


## 使用gcc 将C语言代码编译成机器码

```sh
# 将C代码编译成机器码
gcc -Og -c mstore.c

# 将机器码进行反编译
objdump -d mstore.o

```


