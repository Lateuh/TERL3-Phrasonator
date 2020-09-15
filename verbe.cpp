#include <fstream>
#include <string.h>
#include <iostream>
#include <time.h>

using namespace std;

//recuperation des verbes
int main(int argc,char** argv){
  clock_t tStart = clock();
  string mot2,mot1,ligne,line,output;
  ifstream sport;
  ofstream lexic;
  bool found = false;
  int l,compt=0;
  string humain[2];
  sport.open("nani.txt",ifstream::in);
  lexic.open("generateur4.pl",ofstream::out);
  if(sport.is_open()){
    sport.seekg (0, sport.beg);
    while(getline(sport,ligne)){
      for(int i=0;i<ligne.length();i++){
        if(found){
          compt++;
        }
        if(ligne[i] == ' '){
          l = i+1;
          found = true;
        }
        if((ligne[i+1] == ' '||i==ligne.length()-1) && found){
          if(mot1.empty()){
            mot1 = ligne.substr(l,compt);
          }else if(mot2.empty()){
            mot2 = ligne.substr(l,compt);
          }else if(humain[0].empty()){
            humain[0]=ligne.substr(l,compt);
          }else{
            humain[1]=ligne.substr(l,compt);
          }
          found = false;
          compt = 0;
        }
      }
      if(ligne[0]=='t'){
        output="vt("+mot1+",P,Q,sing,"+humain[0]+","+humain[1]+").";
        lexic<<output;
        lexic<<'\n';
        output="vt("+mot2+",P,Q,plur,"+humain[0]+","+humain[1]+").";
        lexic<<output;
        lexic<<'\n';
      }
      if(ligne[0]=='i'){
        output="vi("+mot1+",P,Q,sing,"+humain[0]+").";
        lexic<<output;
        lexic<<'\n';
        output="vi("+mot2+",P,Q,plur,"+humain[0]+").";
        lexic<<output;
        lexic<<'\n';
      }
      if(ligne[0]=='X'){
        output="vt("+mot1+",P,Q,sing,"+humain[0]+","+humain[1]+").";
        lexic<<output;
        lexic<<'\n';
        output="vt("+mot2+",P,Q,plur,"+humain[0]+","+humain[1]+").";
        lexic<<output;
        lexic<<'\n';
        output="vi("+mot1+",P,Q,sing,"+humain[0]+").";
        lexic<<output;
        lexic<<'\n';
        output="vi("+mot2+",P,Q,plur,"+humain[0]+").";
        lexic<<output;
        lexic<<'\n';
      }
      mot1="";
      mot2="";
    }
  }
  sport.close();
  lexic.close();
  printf("Temps d'execution: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
}
