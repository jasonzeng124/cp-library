// {{{1
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
#include <stdio.h>

// china io template
#define BUFSZ (1<<22)
char ibuf[BUFSZ],obuf[BUFSZ];
char* ip=ibuf, * op=obuf;
#define gc() (ip<ibuf+BUFSZ?*ip++:(fread(ip=ibuf,1,BUFSZ,stdin),*ip++))

ll read() {
        char c;
        int sgn=0;
        while((c=gc())<'0')sgn|=c=='-';
        ll x=-(c-'0');
        while((c=gc())>' ')x=x*10-(c-'0');
        return sgn?x:-x;
}
char* read_str(char* x) { // note no null termination; returns past-end pointer
        char c;
        while((c=gc())<=' ');
        *x++=c;
        while((c=gc())>' ')*x++=c;
        return x;
}
void write_(ll x) {
        if(x<-9) write(x/10);
        *op++=-(x%10)+'0';
}
void write(ll x) {
        if(x<0) return *op++='-',write_(x);
        write_(-x);
}

void flush() { fwrite(obuf,1,op-obuf,stdout), op=obuf; }

#ifdef CHINAIO_TEST
int main() {
        ll x=read();write(x);
        *op++='\n';
        flush();
        char buf[20];
        char* e=read_str(buf);
        for(char* p=buf;p<e;p++)*op++=*p;
        *op++='\n';
        flush();
}
#endif
// 1}}}
