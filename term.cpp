
#include <bits/stdc++.h>
#include <cstdlib> //good for built in function like sort and unique
#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include "TimeInterval.h"
using namespace std;



class HashTable{
private:
int Bucket;
list<string> *table;
public:
HashTable(int V);
void insert(string val);
int hashfunction(string val);
void print();//print function to see if my words hashed properly
void search(string val);//this function will be for case 1
void rec(string val); //this will be for case 2
void test(); //this is for case 3
void suggest(string val); //this will return letters with the same 2 starting
};

TimeInterval ntime;

HashTable::HashTable(int b){
this->Bucket = b; //create the hashtable
table = new list<string>[Bucket]; //size it to 26
}

int HashTable::hashfunction(string val){
int letter = val[0]; //get the hashvlue of the first 
return(letter%26); //hash the first letter by 26 
}

void HashTable::insert(string val){
int index = hashfunction(val);
table[index].push_back(val);//insert the words based on hashvalue 
}


void HashTable::print(){ //print out the  table visually
for (int i = 0; i < Bucket; i++) {
cout << i;
for (auto x : table[i])
cout << " --> " << x;
cout << endl;
}
}

void HashTable::test(){
  cout<<"false"; //case 3
}


void HashTable::suggest(string val){
  int index = hashfunction(val); //hash the incoming word
  for(auto i :table[index]){ //iterate through the table at the index
    if(val[0]==i[0]&&val[1]==i[1]){ //for words witht eh same two letters 
      cout<<i<<"\n"; //print them
    }
  }
}



void HashTable::rec(string val){
//counter++;
string mean; 
bool c;
string sug=""; //empty string
int index = hashfunction(val); //hash the incoming misspelled word
for (auto i:table[index]){
ntime.start();//start the time
if(i.length()==val.length()){
sug = i; //if the word and the current i value have the same length then  assign that word to sug
	}
}

  if(sug!=""){ //as long as sug is not empty meaning a match has been found
cout<<"did you mean "<<sug<<" (y/n)"<<"\n";
cin>>mean; //as the user if they meant this word
if(mean=="y"||mean=="Y"||mean=="Yes"||mean=="yes"){
c=true; //if they respond yes then c =true and stop the timer 
ntime.stop();
}
else if(mean=="n"||mean=="N"||mean=="No"||mean=="no"){
c=false; //if they didnt mean that word then c = false
}

//cout<<c<<"\n";
if(c==1){ //if c = true 
cout<<"true"<<"\n"; //print out true
cout<<ntime.GetInterval()<<" micro-second(s)"<<"\n"; //return the time 
suggest(sug); //send the word that is matched to return the words of the same 2 letters
}
else{  
cout<<"false";
	}    
}
else{
test(); //if the above case returns false then go to case 3
}
/*if(c==1){
cout<<"true";
}
else{
cout<<"false";
}
*/
}

void HashTable::search(string val){
bool exist;
int index = hashfunction(val); //get the hashvalue for input
list <string> :: iterator i;

for (i = table[index].begin(); i != table[index].end(); i++) {//beginin of the table at the point of hashvalue

if(*i ==val){
break; //if the value is found then break
}
}

if (i != table[index].end()){//if i exists in the table before it reaches the end
exist = true;

}
else{
exist = false;
}

// cout<<exist;
if(exist==1){ //if exist is equal to one
ntime.stop(); //stop the time
cout<<"true"<<"\n"; //print out true
cout<<ntime.GetInterval()<<" micro-second(s)"<<"\n";
suggest(val);
}
else{ //if else is anything but 1 (since its bool it will be either 1 or 0)
// cout<<"false";
rec(val);
}

//return ntime.GetInterval();

}

int main() {
  ifstream dict("Dictionary.txt");
  string words;
  vector <string> text;
  while (getline(dict, words)) {
  // Output the text from the file
    text.push_back(words);
}
  sort(text.begin(),text.end());//sort the words (doesnt really make any difference)
  HashTable m(26);
  for(int i=0;i<text.size();i++){
    m.insert(text[i]);
  }
  string inp;
  cout<<"Enter a word: ";
  cin>>inp;
  ntime.start();
  m.search(inp);
  dict.close();
  return(0);
}


