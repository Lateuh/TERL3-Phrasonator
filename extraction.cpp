#include <fstream>
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <time.h>

using namespace std;

//ce programme a un temps d'execution de pres de 14131.57s presque 4h
int main(int argc,char** argv){
  clock_t tStart = clock();
  string id,mot,ligne,line,output;
  ifstream sport,relation;
  ofstream lexic;
  bool found = false;
  int l,compt=0;
  sport.open("mots.txt",ifstream::in);
  lexic.open("generateur.pl",ofstream::out);
  relation.open("relations.txt",ifstream::in);
  if(sport.is_open()){
    sport.seekg (0, sport.beg);
    while(getline(sport,ligne)){
      //recuperer le mot et son id
      for(int i=0;i<ligne.length();i++){
        if(found){
          compt++;
        }
        if(ligne[i] == '='){
          l = i;
          found = true;
        }
        if(ligne[i] == '|' && found){
          if(id.empty()){
            id = ligne.substr(l+1,compt-1);
          }else{
            mot = ligne.substr(l+1,compt-1);
          }
          found = false;
          compt = 0;
          if(!id.empty() && !mot.empty()){
            break;
          }
        }
      }
      // Le fichier jeuxdemots contient des relations inclus dans certains mots.
      // Ces relations sont definis par un > puis le mot auquel il est liée.
      // Cette partie est censé retiré ces relations car elle nous sont inutiles.
      for(int i=0;i<mot.length();i++){
        if(mot[i] == '>'){
          mot = mot.substr(0,i);
        }
      }
      //Passage du mot en langage prolog
      if(relation.is_open()){
        relation.seekg (0, relation.beg);
        while(getline(relation,line)){
          //verifie si le mot designe un être vivant
          if(line.find("71624")!=-1 && line.find(id)!=-1){
            found = true;
            break;
          }
        }
        relation.clear();
        relation.seekg (0, relation.beg);
        //L'utilisation de isupper va egalement nous servir a distinguer
        //les noms des noms propres.
        while(getline(relation,line)){
          char c = mot[0];
          //verifie si le mot est un nom:sing+fem
          if(line.find("146881")!=-1 && line.find(id)!=-1){
            if (found) {
              if(isupper(c)){
                output = "np("+mot+",P,Q,sing,fem,hum).";
                lexic<<output;
                lexic<<"\n";
              }else{
                output = "n("+mot+",P,Q,sing,fem,hum).";
                lexic<<output;
                lexic<<"\n";
              }
            }else{
              if(isupper(c)){
                output = "np("+mot+",P,Q,sing,fem,nhum).";
                lexic<<output;
                lexic<<"\n";
              }else{
                output = "n("+mot+",P,Q,sing,fem,nhum).";
                lexic<<output;
                lexic<<"\n";
              }
            }
            break;
          }
          //verifie si le mot est un nom:plur+fem
          if(line.find("146893")!=-1 && line.find(id)!=-1){
            if (found) {
              if(isupper(c)){
                output = "np("+mot+",P,Q,plur,fem,hum).";
                lexic<<output;
                lexic<<"\n";
              }else{
                output = "n("+mot+",P,Q,plur,fem,hum).";
                lexic<<output;
                lexic<<"\n";
              }
            }else{
              if(isupper(c)){
                output = "np("+mot+",P,Q,plur,fem,nhum).";
                lexic<<output;
                lexic<<"\n";
              }else{
                output = "n("+mot+",P,Q,plur,fem,nhum).";
                lexic<<output;
                lexic<<"\n";
              }
            }
            break;
          }
          //verifie si le mot est un nom:sing+masc
          if(line.find("146885")!=-1 && line.find(id)!=-1){
            if (found) {
              if(isupper(c)){
                output = "np("+mot+",P,Q,sing,masc,hum).";
                lexic<<output;
                lexic<<"\n";
              }else{
                output = "n("+mot+",P,Q,sing,masc,hum).";
                lexic<<output;
                lexic<<"\n";
              }
            }else{
              if(isupper(c)){
                output = "np("+mot+",P,Q,sing,masc,nhum).";
                lexic<<output;
                lexic<<"\n";
              }else{
                output = "n("+mot+",P,Q,sing,masc,nhum).";
                lexic<<output;
                lexic<<"\n";
              }
            }
            break;
          }
          //verifie si le mot est un nom:plur+masc
          if(line.find("146887")!=-1 && line.find(id)!=-1){
            if (found) {
              if(isupper(c)){
                output = "np("+mot+",P,Q,plur,masc,hum).";
                lexic<<output;
                lexic<<"\n";
              }else{
                output = "n("+mot+",P,Q,plur,masc,hum).";
                lexic<<output;
                lexic<<"\n";
              }
            }else{
              if(isupper(c)){
                output = "np("+mot+",P,Q,plur,masc,nhum).";
                lexic<<output;
                lexic<<"\n";
              }else{
                output = "n("+mot+",P,Q,plur,masc,nhum).";
                lexic<<output;
                lexic<<"\n";
              }
            }
            break;
          }
        }
        relation.clear();
      }
      found = false;
      id="";
      mot="";
      line="";
      output="";
    }
  }
  sport.close();
  lexic.close();
  relation.close();
  printf("Temps d'execution: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
}
