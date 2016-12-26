/*
//복권
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
FILE *fin=fopen("input.bmp","rb");
FILE *fin1=fopen("5000000.bmp","rb");
FILE *fin2=fopen("fail.bmp","rb");
FILE *fout=fopen("output_1.bmp","wb");
int R[5010][5010], G[5010][5010], B[5010][5010], head[55], head1[55], head2[55], R1[5010][5010], G1[5010][5010], B1[5010][5010];
int width, height, width1, height1, width2, height2;
int main()
{
	int i, j, n, x, y, l, sw, p;
	srand((int)time(NULL));
	for(i=1; i<=54; ++i) head[i]=getc(fin);
	width = head[19] + head[20]*256 + head[21]*256*256 + head[22]*256*256*256;
	height = head[23] + head[24]*256 + head[25]*256*256 + head[26]*256*256*256;
	for(i=1; i<=54; ++i) head1[i]=getc(fin1);
	width1 = head1[19] + head1[20]*256 + head1[21]*256*256 + head1[22]*256*256*256;
	height1 = head1[23] + head1[24]*256 + head1[25]*256*256 + head1[26]*256*256*256;
	for(i=1; i<=54; ++i) head2[i]=getc(fin2);
	width2 = head2[19] + head2[20]*256 + head2[21]*256*256 + head2[22]*256*256*256;
	height2 = head2[23] + head2[24]*256 + head2[25]*256*256 + head2[26]*256*256*256;
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
	p=rand()%1000000;
	if(p%100==0)
	{
		for(i=1; i<=height; ++i)
		{
			for(j=1; j<=width; ++j)
			{
				R1[i][j]=B1[i][j]=G1[i][j]=190;
			}
		}
		for(i=1; i<=height1; ++i)
		{
			for(j=1; j<=width1; ++j)
			{
				B1[i+(height-height1)/2][j+(width-width1)/2]=getc(fin1);
				G1[i+(height-height1)/2][j+(width-width1)/2]=getc(fin1);
				R1[i+(height-height1)/2][j+(width-width1)/2]=getc(fin1);
			}
			if((width1*3)%4==3) getc(fin);
			if((width1*3)%4==2){getc(fin);getc(fin);}
			if((width1*3)%4==1){getc(fin);getc(fin);getc(fin);}
		}
	}
	else
	{
		for(i=1; i<=height; ++i)
		{
			for(j=1; j<=width; ++j)
			{
				R1[i][j]=B1[i][j]=G1[i][j]=190;
			}
		}
		for(i=1; i<=height2; ++i)
		{
			for(j=1; j<=width2; ++j)
			{
				B1[i+(height-height2)/2][j+(width-width2)/2]=getc(fin2);
				G1[i+(height-height2)/2][j+(width-width2)/2]=getc(fin2);
				R1[i+(height-height2)/2][j+(width-width2)/2]=getc(fin2);
			}
			if((width2*3)%4==3) getc(fin);
			if((width2*3)%4==2){getc(fin);getc(fin);}
			if((width2*3)%4==1){getc(fin);getc(fin);getc(fin);}
		}
	}
	n=rand()%20+(width*2)/10+10;
	for(;n--;)
	{
		x=rand()%width+1;
		y=rand()%height+1;
		l=rand()%height/2;
		for(i=(y-(l/2)<0?0:y-(l/2)); i<=(y+(l/2)>height?height:y+(l/2)); ++i)
		{
			sw=rand()%4+1;
			if(sw==1)
			{
				for(j=x-7; j<=x+7; ++j){ R[i][j]=R1[i][j]; G[i][j]=G1[i][j]; B[i][j]=B1[i][j]; }
			}
			else if(sw==2)
			{
				for(j=x-8; j<=x+7; ++j){ R[i][j]=R1[i][j]; G[i][j]=G1[i][j]; B[i][j]=B1[i][j]; }
			}
			else if(sw==3)
			{
				for(j=x-7; j<=x+8; ++j){ R[i][j]=R1[i][j]; G[i][j]=G1[i][j]; B[i][j]=B1[i][j]; }
			}
			else
			{
				for(j=x-8; j<=x+8; ++j){ R[i][j]=R1[i][j]; G[i][j]=G1[i][j]; B[i][j]=B1[i][j]; }
			}
		}
	}
	for(i=1; i<=54; ++i) putc(head[i], fout);
	for(i=1; i<=height; ++i)
	{
		for(j=1; j<=width; ++j)
		{
			putc(B[i][j], fout);
			putc(G[i][j], fout);
			putc(R[i][j], fout);
		}
		if((width*3)%4==3) putc(0,fout);
		if((width*3)%4==2){putc(0,fout);putc(0,fout);}
		if((width*3)%4==1){putc(0,fout);putc(0,fout);putc(0,fout);}
	}
	return 0;
}
*/
/*
//경계찾기 알고리즘
//스케치한 효과
#include<stdio.h>
#include<fstream>
#include<math.h>
using namespace std;
int abs(int x){ return x>0?x:-x; }
FILE *fin=fopen("input.bmp","rb");
FILE *fout=fopen("output_2.bmp","wb");
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
			if(i>1){ ++c; p[i][j]+=abs(R[i][j]-R[i-1][j]); p[i][j]+=abs(G[i][j]-G[i-1][j]); p[i][j]+=abs(B[i][j]-B[i-1][j]); }
			if(j>1){ ++c; p[i][j]+=abs(R[i][j]-R[i][j-1]); p[i][j]+=abs(G[i][j]-G[i][j-1]); p[i][j]+=abs(B[i][j]-B[i][j-1]); }
			if(i<height){ ++c; p[i][j]+=abs(R[i][j]-R[i+1][j]); p[i][j]+=abs(G[i][j]-G[i+1][j]); p[i][j]+=abs(B[i][j]-B[i+1][j]); }
			if(j<width){ ++c; p[i][j]+=abs(R[i][j]-R[i][j+1]); p[i][j]+=abs(G[i][j]-G[i][j+1]); p[i][j]+=abs(B[i][j]-B[i][j+1]); }
			p[i][j]/=3;p[i][j]/=c;
			p[i][j]=255-p[i][j];
			p[i][j]=p[i][j]*p[i][j]/255*p[i][j]/255*p[i][j]/255*p[i][j]/255*p[i][j]/255*p[i][j]/255;
			//if(p[i][j]>250){putc(255,fout);putc(255,fout);putc(255,fout);}
			//else{putc(0,fout);putc(0,fout);putc(0,fout);}
			putc(p[i][j],fout);
			putc(p[i][j],fout);
			putc(p[i][j],fout);
		}
		if((width*3)%4==3) putc(0,fout);
		if((width*3)%4==2){putc(0,fout);putc(0,fout);}
		if((width*3)%4==1){putc(0,fout);putc(0,fout);putc(0,fout);}
	}
	return 0;
}
*/
/*
//경계찾아서 원본과 합치는 알고리즘
//효과는 경계 주변에 스파크 효과
#include<stdio.h>
#include<fstream>
#include<math.h>
using namespace std;
int abs(int x){ return x>0?x:-x; }
FILE *fin=fopen("input.bmp","rb");
FILE *fout=fopen("output_3.bmp","wb");
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
			if(i>1){ ++c; p[i][j]+=abs(R[i][j]-R[i-1][j]); p[i][j]+=abs(G[i][j]-G[i-1][j]); p[i][j]+=abs(B[i][j]-B[i-1][j]); }
			if(j>1){ ++c; p[i][j]+=abs(R[i][j]-R[i][j-1]); p[i][j]+=abs(G[i][j]-G[i][j-1]); p[i][j]+=abs(B[i][j]-B[i][j-1]); }
			if(i<height){ ++c; p[i][j]+=abs(R[i][j]-R[i+1][j]); p[i][j]+=abs(G[i][j]-G[i+1][j]); p[i][j]+=abs(B[i][j]-B[i+1][j]); }
			if(j<width){ ++c; p[i][j]+=abs(R[i][j]-R[i][j+1]); p[i][j]+=abs(G[i][j]-G[i][j+1]); p[i][j]+=abs(B[i][j]-B[i][j+1]); }
			p[i][j]/=3;p[i][j]/=c;
			p[i][j]=255-p[i][j];
			p[i][j]=p[i][j]*p[i][j]/255*p[i][j]/255*p[i][j]/255*p[i][j]/255*p[i][j]/255*p[i][j]/255;
			//if(p[i][j]>250){putc(255,fout);putc(255,fout);putc(255,fout);}
			//else{putc(0,fout);putc(0,fout);putc(0,fout);}
			p[i][j]=255-p[i][j];
			putc(p[i][j]+B[i][j]>255?255:p[i][j]+B[i][j],fout);
			putc(p[i][j]+G[i][j]>255?255:p[i][j]+G[i][j],fout);
			putc(p[i][j]+R[i][j]>255?255:p[i][j]+R[i][j],fout);
		}
		if((width*3)%4==3) putc(0,fout);
		if((width*3)%4==2){putc(0,fout);putc(0,fout);}
		if((width*3)%4==1){putc(0,fout);putc(0,fout);putc(0,fout);}
	}
	return 0;
}
*/
/*
//낡은 종이 효과
#include<stdio.h>
#include<fstream>
#include<math.h>
using namespace std;
int abs(int x){ return x>0?x:-x; }
FILE *fin=fopen("input.bmp","rb");
FILE *fout=fopen("output_4.bmp","wb");
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
			if(i>1){ ++c; p[i][j]+=abs(R[i][j]-R[i-1][j]); p[i][j]+=abs(G[i][j]-G[i-1][j]); p[i][j]+=abs(B[i][j]-B[i-1][j]); }
			if(j>1){ ++c; p[i][j]+=abs(R[i][j]-R[i][j-1]); p[i][j]+=abs(G[i][j]-G[i][j-1]); p[i][j]+=abs(B[i][j]-B[i][j-1]); }
			if(i<height){ ++c; p[i][j]+=abs(R[i][j]-R[i+1][j]); p[i][j]+=abs(G[i][j]-G[i+1][j]); p[i][j]+=abs(B[i][j]-B[i+1][j]); }
			if(j<width){ ++c; p[i][j]+=abs(R[i][j]-R[i][j+1]); p[i][j]+=abs(G[i][j]-G[i][j+1]); p[i][j]+=abs(B[i][j]-B[i][j+1]); }
			p[i][j]/=3;p[i][j]/=c;
			p[i][j]=255-p[i][j];
			p[i][j]=p[i][j]*p[i][j]/256*p[i][j]/256*p[i][j]/256*p[i][j]/256*p[i][j]/256*p[i][j]/256;
			//if(p[i][j]>250){putc(255,fout);putc(255,fout);putc(255,fout);}
			//else{putc(0,fout);putc(0,fout);putc(0,fout);}
			putc(p[i][j]-115<0?0:p[i][j]-115,fout);
			putc(p[i][j]-31<0?0:p[i][j]-31,fout);
			putc(p[i][j]-13<0?0:p[i][j]-13,fout);
		}
		if((width*3)%4==3) putc(0,fout);
		if((width*3)%4==2){putc(0,fout);putc(0,fout);}
		if((width*3)%4==1){putc(0,fout);putc(0,fout);putc(0,fout);}
	}
	return 0;
}
*/

//흐콰한다
#include<stdio.h>
#include<fstream>
#include<math.h>
using namespace std;
int abs(int x){ return x>0?x:-x; }
FILE *fin=fopen("input.bmp","rb");
FILE *fout=fopen("output_5.bmp","wb");
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
			if(i>1){ ++c; p[i][j]+=abs(R[i][j]-R[i-1][j]); p[i][j]+=abs(G[i][j]-G[i-1][j]); p[i][j]+=abs(B[i][j]-B[i-1][j]); }
			if(j>1){ ++c; p[i][j]+=abs(R[i][j]-R[i][j-1]); p[i][j]+=abs(G[i][j]-G[i][j-1]); p[i][j]+=abs(B[i][j]-B[i][j-1]); }
			if(i<height){ ++c; p[i][j]+=abs(R[i][j]-R[i+1][j]); p[i][j]+=abs(G[i][j]-G[i+1][j]); p[i][j]+=abs(B[i][j]-B[i+1][j]); }
			if(j<width){ ++c; p[i][j]+=abs(R[i][j]-R[i][j+1]); p[i][j]+=abs(G[i][j]-G[i][j+1]); p[i][j]+=abs(B[i][j]-B[i][j+1]); }
			p[i][j]/=3;p[i][j]/=c;
			p[i][j]=255-p[i][j];
			p[i][j]=p[i][j]*p[i][j]/255*p[i][j]/255*p[i][j]/255*p[i][j]/255*p[i][j]/255*p[i][j]/255;
			//if(p[i][j]>250){putc(255,fout);putc(255,fout);putc(255,fout);}
			//else{putc(0,fout);putc(0,fout);putc(0,fout);}
			p[i][j]=255-p[i][j];
			putc(B[i][j]-p[i][j]<0?0:B[i][j]-p[i][j],fout);
			putc(G[i][j]-p[i][j]<0?0:G[i][j]-p[i][j],fout);
			putc(R[i][j]-p[i][j]<0?0:R[i][j]-p[i][j],fout);
		}
		if((width*3)%4==3) putc(0,fout);
		if((width*3)%4==2){putc(0,fout);putc(0,fout);}
		if((width*3)%4==1){putc(0,fout);putc(0,fout);putc(0,fout);}
	}
	return 0;
}

/*
//태양빛
#include<stdio.h>
#include<fstream>
#include<math.h>
using namespace std;
FILE *fin=fopen("input.bmp","rb");
FILE *fout=fopen("output_6.bmp","wb");
int R[5010][5010], G[5010][5010], B[5010][5010], head[55];
int p[5010][5010];
int width, height;
int main()
{
	int i, j, p, q, r;
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
			p=((height*3/4)-i);
			q=((width*3/4)-j);
			r=sqrt(p*p+q*q);
			if(height>width) p=width;
			else p=height;
			p/=2;
			q=255-(255*r/p*r/p);
			if(q<0) q=0;
			putc(B[i][j]+q>252?255:B[i][j]+q,fout);
			putc(G[i][j]+q>245?245:G[i][j]+q,fout);
			putc(R[i][j]+q>227?227:R[i][j]+q,fout);
		}
		if((width*3)%4==3) putc(0,fout);
		if((width*3)%4==2){putc(0,fout);putc(0,fout);}
		if((width*3)%4==1){putc(0,fout);putc(0,fout);putc(0,fout);}
	}
	return 0;
}
*/
