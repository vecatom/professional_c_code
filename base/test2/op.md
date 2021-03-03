
### 查看预编译后的命令

> gcc src/main.c -E -P

```
int chk_param(int argc,char *argv[]){
 if(argc < 3 ){
  return 0;
 }else{
  return 1;
 }
}
int main(int argc ,char *argv[]){
 return chk_param(argc ,argv);
}
```

### 将mian.c放置接口和主方法，在param.c 放置接口实现
正确的build方法：
> build:
```
 gcc -c src/main.c -o obj/main.o
 gcc -c src/param.c -o obj/param.o
 gcc obj/param.o obj/main.o -o bin/main
```
错误方法：
> build:
```
gcc -c src/main.c -o obj/main.o
gcc -c src/param.c -o obj/param.o
gcc obj/main.o -0 bin/main
```
> 错误提示：
> obj/main.o: In function `main`:
> main.c:(.text+0x1c): undefined reference to `chk_param`
> collect2: error: ld returned 1 exit status

