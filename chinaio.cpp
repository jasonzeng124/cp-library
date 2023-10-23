#define ll long long
#include <stdio.h>

// china io template
// 1<<20 is 1mb (around 5e2 ll's)
#define BUFSZ (1<<22)
char ibuf[BUFSZ],obuf[BUFSZ];
char* ip=ibuf, * op=obuf;
#define gc() (ip<ibuf+BUFSZ?*ip++:(fread(ip=ibuf,1,BUFSZ,stdin),*ip++))

ll read() {
        char c;
        while((c=gc())<=' ');
        ll x=c-'0';
        while((c=gc())>' ')x=x*10+c-'0';
        return x;
}

char* read_str(char* x) { // note no null termination; returns past-end pointer
        char c;
        while((c=gc())<=' ');
        *x++=c;
        while((c=gc())>' ')*x++=c;
        return x;
}

void write(ll x) {
        if(x>9) write(x/10);
        *op++=x%10+'0';
}

void flush() { fwrite(op=obuf,1,BUFSZ,stdout); }

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
