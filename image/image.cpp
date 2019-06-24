#include<stdio.h>
#include<fstream>
#include<math.h>
using namespace std;
int abs(int x){ return x>0?x:-x; }
FILE *fin=fopen("input.bmp","rb");
FILE *fout=fopen("output.bmp","wb");
int R[5010][5010], G[5010][5010], B[5010][5010], head[55];
int p[5010][5010];
int width, height;
int main()
{
    int i, j, c;
    for(i=1; i<=54; ++i) head[i]=getc(fin);
    width = head[19] + head[20]*256 + head[21]*256*256 + head[22]*256*256*256;
    height = head[23] + head[24]*256 + head[25]*256*256 + head[26]*256*256*256;
    for(i=1; i<=height; ++i)
    {
        for(j=1; j<=width; ++j)
        {
            B[i][j]=getc(fin);
            G[i][j]=getc(fin);
            R[i][j]=getc(fin);
        }
        if((width*3)%4==3) getc(fin);
        if((width*3)%4==2){getc(fin);getc(fin);}
        if((width*3)%4==1){getc(fin);getc(fin);getc(fin);}
    }
    for(i=1; i<=54; ++i) putc(head[i], fout);
    for(i=1; i<=height; ++i)
    {
        for(j=1; j<=width; ++j)
        {
            c=0;
            if(i>1){
                ++c;
                p[i][j]+=abs(R[i][j]-R[i-1][j]);
                p[i][j]+=abs(G[i][j]-G[i-1][j]);
                p[i][j]+=abs(B[i][j]-B[i-1][j]);
            }
            if(j>1){
                ++c;
                p[i][j]+=abs(R[i][j]-R[i][j-1]);
                p[i][j]+=abs(G[i][j]-G[i][j-1]);
                p[i][j]+=abs(B[i][j]-B[i][j-1]);
            }
            if(i<height){
                ++c;
                p[i][j]+=abs(R[i][j]-R[i+1][j]);
                p[i][j]+=abs(G[i][j]-G[i+1][j]);
                p[i][j]+=abs(B[i][j]-B[i+1][j]);
            }
            if(j<width){
                ++c;
                p[i][j]+=abs(R[i][j]-R[i][j+1]);
                p[i][j]+=abs(G[i][j]-G[i][j+1]);
                p[i][j]+=abs(B[i][j]-B[i][j+1]);
            }
            p[i][j]/=3;p[i][j]/=c;
            p[i][j]=255-p[i][j];
            p[i][j]=p[i][j]*p[i][j]/255*p[i][j]/255*p[i][j]/255*p[i][j]/255*p[i][j]/255*p[i][j]/255;
            //if(p[i][j]>250){putc(255,fout);putc(255,fout);putc(255,fout);}
            //else{putc(0,fout);putc(0,fout);putc(0,fout);}
            /*
             * p[i][j]=255-p[i][j];
             * putc(B[i][j]-p[i][j]<0?0:B[i][j]-p[i][j],fout);
             * putc(G[i][j]-p[i][j]<0?0:G[i][j]-p[i][j],fout);
             * putc(R[i][j]-p[i][j]<0?0:R[i][j]-p[i][j],fout);
             */
            putc(p[i][j],fout);
            putc(p[i][j],fout);
            putc(p[i][j],fout);
        }
        if((width*3)%4==3){putc(0,fout);}
        if((width*3)%4==2){putc(0,fout);putc(0,fout);}
        if((width*3)%4==1){putc(0,fout);putc(0,fout);putc(0,fout);}
    }
    return 0;
}

