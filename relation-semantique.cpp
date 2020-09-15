#include <fstream>
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <time.h>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc,char** argv){
  clock_t tStart = clock();
  string id,mot,ligne,line,output;
  ifstream sport,relation;
  ofstream lexic;
  bool found = false;
  int l,compt=0,size=0;
  string listeid1[3129],listeid2[3129],type[3129];
  map<string, string> listemots;
  sport.open("mots.txt",ifstream::in);
  lexic.open("generateur3.pl",ofstream::out);
  relation.open("relations.txt",ifstream::in);
  if(relation.is_open()){
    relation.seekg (0, relation.beg);
    while(getline(relation,ligne)){
      //recuperer les ids des mots en relations
        if(ligne.find("|t=13|")!=-1 || ligne.find("|t=14|")!=-1 || ligne.find("|t=24|")!=-1 || ligne.find("|t=26|")!=-1){
        for(int i=0;i<ligne.length();i++){
          if(found){
            compt++;
          }
          if(ligne[i-1] == '1' && ligne[i] == '='){
            l = i+1;
            found = true;
          }
          if(ligne[i-1] == '2' && ligne[i] == '='){
            l = i+1;
            found = true;
          }
          if(ligne[i] == '|' && found){
            if(listeid1[size].empty()){
              listeid1[size]=ligne.substr(l,compt-1);
            }else if(listeid2[size].empty()){
                listeid2[size]=ligne.substr(l,compt-1);
            }
            found = false;
            compt = 0;
            if(!listeid2[size].empty()){
              if(ligne.find("|t=13|")!=-1){
                type[size]="|t=13|";
              }else if(ligne.find("|t=14|")!=-1){
                type[size]="|t=14|";
              }else if(ligne.find("|t=24|")!=-1){
                type[size]="|t=24|";
              }else if(ligne.find("|t=26|")!=-1){
                type[size]="|t=26|";
              }
              size++;
              break;
            }
          }
        }
      }
    }
  }
  //on recupere les mots correspondant aux ids precedemment recupérés
  if(sport.is_open()){
    sport.seekg (0, sport.beg);
    while(getline(sport,line)){
      //on recupere les mots et leurs ids
      for(int i=0;i<line.length();i++){
        if(found){
          compt++;
        }
        if(line[i] == '='){
          l = i;
          found = true;
        }
        if(line[i] == '|' && found){
          if(id.empty()){
            id=line.substr(l+1,compt-1);
          }else{
            listemots[id] = line.substr(l+1,compt-1);
          }
          found = false;
          compt = 0;
          if(!listemots[id].empty()){
            break;
          }
        }
      }
      id="";
      line="";
    }
  }
  for(int i=0;i<2149;i++){
    if(type[i].find("|t=14|")!=-1){
      output="relsem(patient,"+listemots[listeid2[i]]+","+listemots[listeid1[i]]+").";
      lexic<<output;
      lexic<<"\n";
    }else if(type[i].find("|t=13|")!=-1){
      output="relsem(agent,"+listemots[listeid2[i]]+","+listemots[listeid1[i]]+").";
      lexic<<output;
      lexic<<"\n";
    }
    // else if(type[i].find("|t=24|")!=-1){
    //   output="relsem(agent,"+listemots[listeid1[i]]+","+listemots[listeid2[i]]+").";
    // }else if(type[i].find("|t=26|")!=-1){
    //   output="relsem(patient,"+listemots[listeid1[i]]+","+listemots[listeid2[i]]+").";
    // }
  }
  listemots.clear();
  sport.close();
  lexic.close();
  relation.close();
  printf("Temps d'execution: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
}
