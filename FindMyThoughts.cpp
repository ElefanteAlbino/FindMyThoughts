#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <cctype>
#include <algorithm>
#include <map>
using namespace std;

void lowerCase(string &str)
{
  for(unsigned int i = 0; i < str.size(); i++){
    if(isupper(str[i])){
      str[i] = tolower(str[i]);
    }
  }
}

void filterWords(vector<string> & v){
  //preposiciones y pronombres
  string blacklist[] = {"i","me","we","us","you","she","her","he","him","it",
  "they","them","this","that","these","those","anybody","anyone","each","either",
  "everybody","everyone","eveything","neither","nobody","no","one","nothing",
  "somebody","someone","something","both","few","many","several","all","any",
  "most","none","some","myself","ourselves","yourself","yourselves","himself",
  "herself","itself","themselves","what","who","which","whom","whose","my",
  "it","his","her","its","our","your","their","mine","yours","his","hers",
  "ours","on","theirs","in","at","since","for","ago","before","to","past","till",
  "until","by","next","beside","under","below","over","above","across","through",
  "into","towards","onto","from","of","off","out","about","character","guy",
  "thing","a","when","the","came","around"};
  for(unsigned int i = 0; i < v.size(); i++){
    if(find(begin(blacklist), end(blacklist), v[i]) != end(blacklist)) {
      v.erase(v.begin()+i);
    }
  }
}

vector<string> separateWords(string keyphrase){
  lowerCase(keyphrase);
  vector<string> separatedPhrase;
  string word = "";
  for(auto x : keyphrase){
    if(x == ' '){
      separatedPhrase.push_back(word);
      word = "";
    }
    else{
      word += x;
    }
  }
  separatedPhrase.push_back(word);
  filterWords(separatedPhrase);
  return separatedPhrase;
}

int main(){

  vector<string> separatedPhrase;
  string keyphrase;
  cout << "What do you remember from the game you wish to find?" << endl;
  getline(cin, keyphrase);
  separatedPhrase = separateWords(keyphrase);
  // for(unsigned int i = 0; i < separatedPhrase.size(); i++){
  //   cout << separatedPhrase[i] << endl;
  // }

  multimap<string,string> mmapOfPos = {

    {"konami", "Silent Hill"},
    {"1999","Silent Hill"},
    {"terror", "Silent Hill"},
    {"scares","Silent Hill"},
    {"silent","Silent Hill"},
    {"hill","Silent Hill"},
    {"van","Silent Hill"},
    {"cherly","Silent Hill"},
    {"abandoned","Silent Hill"},
    {"village","Silent Hill"},
    {"town","Silent Hill"},
    {"darkness","Silent Hill"},
    {"worship","Silent Hill"},
    {"harry","Silent Hill"},
    {"cybil","Silent Hill"},
    {"demon","Silent Hill"},
    {"hell","Silent Hill"},
    {"devil","Silent Hill"},
    {"girl","Silent Hill"},
    {"children","Silent Hill"},
    {"follow","Silent Hill"},
    {"search","Silent Hill"},
    {"fight","Silent Hill"},
    {"crash","Silent Hill"},
    {"lisa","Silent Hill"},
    {"michael","Silent Hill"},
    {"alessa","Silent Hill"},
    {"alexia","Silent Hill"},
    {"dahlia","Silent Hill"},
    {"highway","Silent Hill"},
    {"lost","Silent Hill"},
    {"fps","Doom"},

    {"bethesda","Doom"},
    {"1993","Doom"},
    {"shooter","Doom"},
    {"fps","Doom"},
    {"marin","Doom"},
    {"uac","Doom"},
    {"deimos","Doom"},
    {"combat","Doom"},
    {"demons","Doom"},
    {"demon","Doom"},
    {"military","Doom"},
    {"guns","Doom"},
    {"shoots","Doom"},
    {"shoot","Doom"},
    {"kill","Doom"},
    {"strategy","Doom"},
    {"doom","Doom"},

    {"nintendo", "Mario Kart 64"},
    {"1996", "Mario Kart 64"},
    {"racing", "Mario Kart 64"},
    {"mario","Mario Kart 64"},
    {"kart","Mario Kart 64"},
    {"64","Mario Kart 64"},
    {"red","Mario Kart 64"},
    {"races","Mario Kart 64"},
    {"race","Mario Kart 64"},
    {"powers","Mario Kart 64"},
    {"habilitys","Mario Kart 64"},
    {"browser","Mario Kart 64"},
    {"donkey","Mario Kart 64"},
    {"kong","Mario Kart 64"},
    {"luigi","Mario Kart 64"},
    {"peach","Mario Kart 64"},
    {"toad","Mario Kart 64"},
    {"wario","Mario Kart 64"},
    {"yoshi","Mario Kart 64"},
    {"shell","Mario Kart 64"},
    {"shells","Mario Kart 64"},
    {"boxes","Mario Kart 64"},
    {"karts","Mario Kart 64"},
    {"magic","Mario Kart 64"},

    {"konami", "Contra"},
    {"1987", "Contra"},
    {"shooter", "Contra"},
    {"run","Contra"},
    {"gun","Contra"},
    {"probotector","Contra"},
    {"japanese","Contra"},
    {"future","Contra"},
    {"corp","Contra"},
    {"girl","Contra"},
    {"rescue","Contra"},
    {"save","Contra"},
    {"find","Contra"},
    {"escape","Contra"},
    {"releasing","Contra"},
    {"free","Contra"},
    {"island","Contra"},
    {"forest","Contra"},
    {"aliens","Contra"},

    {"capcom", "Street Fighter"},
    {"1987", "Street Fighter"},
    {"fights", "Street Fighter"},
    {"street","Street Fighter"},
    {"fighter","Street Fighter"},
    {"balrog","Street Fighter"},
    {"vega","Street Fighter"},
    {"bison","Street Fighter"},
    {"akuma","Street Fighter"},
    {"charlie","Street Fighter"},
    {"cuffs","Street Fighter"},
    {"hits","Street Fighter"},
    {"habilitys","Street Fighter"},
    {"powrs","Street Fighter"},
    {"fight","Street Fighter"},
    {"arcade","Street Fighter"},

    {"Sega", "Sonic the Hedgehog"},
    {"1991", "Sonic the Hedgehog"},
    {"racing", "Sonic the Hedgehog"},
    {"blue","Sonic the Hedgehog"},
    {"hedgehog","Sonic the Hedgehog"},
    {"rings","Sonic the Hedgehog"},
    {"gold","Sonic the Hedgehog"},
    {"fast","Sonic the Hedgehog"},
    {"light","Sonic the Hedgehog"},
    {"velocity","Sonic the Hedgehog"},
    {"run","Sonic the Hedgehog"},
    {"jumps","Sonic the Hedgehog"},

    {"nintendo", "Pokemon"},
    {"1996", "Pokemon"},
    {"fights", "Pokemon"},
    {"pokeballs","Pokemon"},
    {"pokedex","Pokemon"},
    {"pikachu","Pokemon"},
    {"charmander","Pokemon"},
    {"ash","Pokemon"},
    {"ketchum","Pokemon"},
    {"capture","Pokemon"},
    {"pokemons","Pokemon"},
    {"pokemon","Pokemon"},
    {"cap","Pokemon"},
    {"yellow","Pokemon"},
    {"kanto","Pokemon"},
    {"paleta","Pokemon"},
    {"master","Pokemon"},
    {"snorlax","Pokemon"},
    {"bush","Pokemon"},
    {"animal","Pokemon"},
    {"monster","Pokemon"},
    {"animals","Pokemon"},
    {"monsters","Pokemon"},
    {"fighting","Pokemon"},

    {"nintendo","The legend of Zelda: A Link to the Past"},
    {"1991","The legend of Zelda: A Link to the Past"},
    {"adventure","The legend of Zelda: A Link to the Past"},
    {"zelda","The legend of Zelda: A Link to the Past"},
    {"legend","The legend of Zelda: A Link to the Past"},
    {"link","The legend of Zelda: A Link to the Past"},
    {"action","The legend of Zelda: A Link to the Past"},
    {"open","The legend of Zelda: A Link to the Past"},
    {"world","The legend of Zelda: A Link to the Past"},
    {"free","The legend of Zelda: A Link to the Past"},
    {"missions","The legend of Zelda: A Link to the Past"},
    {"ocarina","The legend of Zelda: A Link to the Past"},
    {"sword","The legend of Zelda: A Link to the Past"},
    {"shield","The legend of Zelda: A Link to the Past"},
    {"japanese","The legend of Zelda: A Link to the Past"},
    {"princess","The legend of Zelda: A Link to the Past"},
    {"agahnim","The legend of Zelda: A Link to the Past"},
    {"castle","The legend of Zelda: A Link to the Past"},
    {"hyrule","The legend of Zelda: A Link to the Past"},
    {"ganon","The legend of Zelda: A Link to the Past"},
    {"triforce","The legend of Zelda: A Link to the Past"},
    {"green","The legend of Zelda: A Link to the Past"},

  };

  typedef multimap<string,string>::iterator MMAPIterator;

  map<string,int> results_map;
  
  for(unsigned int i = 0; i < separatedPhrase.size(); i++){
    pair<MMAPIterator, MMAPIterator> result = mmapOfPos.equal_range(separatedPhrase[i]);
    for (MMAPIterator it = result.first; it != result.second; it++){
      string x = it->second;
      if (results_map.find(x) == results_map.end()) {
        results_map.insert(pair<string, int>(x,1));
      } else {
        results_map[x] += 1;
      }
    }
  }

  string better;
  int count = 0;
  for (const auto &x : results_map){
    if(count == 0){
      better = x.first;
      count = x.second;
    }else if(x.second > count){
      better = x.first;
    }
  }

  results_map.erase(better);
  cout << "Your perfect match is: "<<better<<endl;
  if(not results_map.empty()){
    cout << "\nOther possible matches: " <<endl;
    for (const auto &x : results_map){
      cout<<x.first<<endl;
    }
  }
    return 0;
}

