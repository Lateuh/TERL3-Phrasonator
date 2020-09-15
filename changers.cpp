#include <fstream>
#include <string.h>
#include <iostream>
#include <time.h>

using namespace std;

//recuperation des verbes
int main(int argc,char** argv){
  clock_t tStart = clock();
  string mot,ligne,verbe = "";
  ifstream sport,other;
  ofstream lexic;
  string nom[198],verbes[98];
  bool found = false;
  int l,compt=0,size=0,size1=0;
  sport.open("generateur3.pl",ifstream::in);
  other.open("generateurBis2.pl",ifstream::in);
  lexic.open("generateur4.pl",ofstream::out);
  if(other.is_open()){
    other.seekg (1000, other.beg);
    while(getline(other,ligne)){
      if(ligne.find("n(")!=-1 || ligne.find("vt(")!=-1 || ligne.find("vi(")!=-1){
      for(int i=0;i<ligne.length();i++){
        if(found){
          compt++;
        }
        if((ligne.find("vt(")!=-1 || ligne.find("vi(")!=-1) && ligne[i] == ','){
          l = i;
          compt=0;
          found = true;
        }
        if(ligne[i-1] == 'n' && ligne[i] == '('){
          l = i;
          found = true;
        }
        if(((ligne[i]==',' && ligne.find("n(")!=-1)||(ligne[i]==')' && (ligne.find("vt(")!=-1 || ligne.find("vi(")!=-1)))  && found ){
          if(ligne.find("n(")!=-1){
            nom[size] = ligne.substr(l+1,compt-1);
            size++;
          }else {
            verbes[size1] = ligne.substr(l+1,compt-1);
            size1++;
          }
          found = false;
          compt = 0;
          break;
        }
      }
    }
    }
  }
  // for(int i=0;i<98;i++){
  //   std::cout << verbes[i] << '\n';
  // }
  // for(int i=0;i<198;i++){
  //   std::cout << nom[i] << '\n';
  // }
  if(sport.is_open()){
    sport.seekg (0, sport.beg);
    while(getline(sport,ligne)){
      for(int i=0;i<ligne.length();i++){
        if(found){
          compt++;
        }
        if((ligne[i] == ',' || ligne[i] == ')') && found){
          if(mot == ""){
            mot = ligne.substr(l+1,compt-1);
          }else{
            verbe = ligne.substr(l+1,compt-1);
            found = false;
            compt = 0;
            break;
          }
          found = false;
          compt = 0;
        }
        if(ligne[i] == ','){
          l = i;
          found = true;
          compt=0;
        }
      }
      // cout << mot<<" "<<verbe << '\n';
      for(int i=0;i<198;i++){
        for(int j=0;j<98;j++){
          if(verbe.compare(verbes[j])==0 && mot.compare(nom[i])==0){
            lexic<<ligne;
            lexic<<'\n';
            found=true;
            break;
          }
        }
        if (found) {
          found=false;
          break;
        }
      }
      verbe="";
      mot="";
    }
  }
  sport.close();
  other.close();
  lexic.close();
  printf("Temps d'execution: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
}
