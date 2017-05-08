int main(){
    char a[1024];
    int fd = 5;
    int cc = read(fd,&a[0],1);
    puts(a);
    return 0;
}
