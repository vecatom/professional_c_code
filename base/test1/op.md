
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

