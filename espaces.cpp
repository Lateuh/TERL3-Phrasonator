#include <fstream>
#include <string.h>
#include <iostream>
#include <time.h>

using namespace std;

//retrait des mots avec des espaces: 0.02s
int main(int argc,char** argv){
  clock_t tStart = clock();
  string id,mot,ligne,line,output;
  ifstream sport;
  ofstream lexic;
  bool found = false;
  int l,compt=0;
  sport.open("generateur1.pl",ifstream::in);
  lexic.open("generateur2.pl",ofstream::out);
  if(sport.is_open()){
    sport.seekg (0, sport.beg);
    while(getline(sport,ligne)){
      for(int i=0;i<ligne.length();i++){
        if(found){
          compt++;
        }
        if(ligne[i] == '('){
          l = i;
          found = true;
        }
        if(ligne[i] == ',' && found){
          mot = ligne.substr(l+1,compt-1);
          found = false;
          compt = 0;
          break;
        }
      }
      for(int i=0;i<mot.length();i++){
        if(mot[i]==' '){
          found = true;
        }
      }
      if(!found){
        lexic<<ligne;
        lexic<<'\n';
      }
      found=false;
    }
  }
  sport.close();
  lexic.close();
  printf("Temps d'execution: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
}
