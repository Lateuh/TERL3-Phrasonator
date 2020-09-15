#include <fstream>
#include <string.h>
#include <iostream>
#include <time.h>

using namespace std;
//retire les occurences de mots: 0.20s
int main(int argc,char** argv){
  clock_t tStart = clock();
  string ligne;
  ifstream sport;
  ofstream lexic;
  int compt=0;
  sport.open("generateur.pl",ifstream::in);
  lexic.open("generateur1.pl",ofstream::out);
  string contenu[3925],n[3925],np[3925];
  int k=0,l=0;
  if(sport.is_open()){
    sport.seekg (0, sport.beg);
    while(getline(sport,ligne)){
      contenu[compt]=ligne;
      compt++;
    }
  }
  //occurences
  for(int i=0;i<3925;i++){
    for(int j=0;j<3925;j++){
      if(contenu[i]==contenu[j] && i!=j){
        contenu[j]="";
      }
    }
  }
  //separer nom et nom propre
  for(int i=0;i<3925;i++){
    if(contenu[i][1]=='p'){
      np[k]=contenu[i];
      k++;
    }else if(contenu[i]!=""){
      n[l]=contenu[i];
      l++;
    }
  }
  for(int i=0;i<3925;i++){
    lexic<<n[i];
    lexic<<"\n";
  }
  for(int i=0;i<3925;i++){
    lexic<<np[i];
    lexic<<"\n";
  }
  lexic.close();
  sport.close();
  printf("Temps d'execution: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
}
