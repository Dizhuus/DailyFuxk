#include<stdio.h>
#include<memory.h>

#define INF 999999

int father[4001],value[4001][4001],vis[4001],dis[4001];

int dj(int n){
  int pos,i,j;
  for(i=1;i<n;i++){
    pos=-1;
    for(j=1;j<n;j++){
      if(!vis[j] && (pos==-1||dis[pos]>dis[j])){
        pos=j;
      }  
    }
    vis[pos]=1;
    for(j=1;j<=n;j++){
      if(!vis[j] && dis[j]>dis[pos]+value[pos][j]){
        dis[j]=dis[pos]+value[pos][j];
        father[j]=pos;
      }
    }
  }
  return dis[n];
}

int scan(){
  int x,y,i,j,n,m;
  scanf("%d %d",&n,&m);
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      value[i][j]=INF;
  for(i=0;i<m;i++){
    scanf("%d %d",&x,&y);
    scanf("%d",&value[x][y]);
    value[y][x]=value[x][y];
  }
  return n;
}

void init(){
  memset(vis,0,sizeof(vis));
  memset(dis,INF,sizeof(dis));
  memset(father,0,sizeof(father));
  dis[1]=0;
  return;
}

int main(){
  int j,fa[4001],sec=INF,sectemp=INF,temp,n=scan(),i=n;
  init();  
  dj(n);
  for(j=0;j<=n;j++)fa[j]=father[j];
  init();
  do{
    temp=value[i][fa[i]];
    value[i][fa[i]]=INF;
    value[fa[i]][i]=INF;
    sectemp=dj(n);
    init();
    if(sectemp<sec)sec=sectemp;
    value[i][fa[i]]=temp;
    value[fa[i]][i]=temp;
    i=fa[i];
  }while(fa[i]!=0);
  printf("%d",sec);
  return 0;
}
