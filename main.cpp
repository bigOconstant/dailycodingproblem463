#include <iostream>

using std::cout;
using std::endl;
using std::string;

bool reduce(int start_position,string &input) {
  if(input.size() <2 || start_position > input.size()-2){
    return false;
  }
  
  bool retVal = false;
  string substring = input.substr(start_position,2);

  if(substring == "rg" || substring == "gr"){
    input.replace(start_position,2,"b");
    retVal = true;
  }
  else if(substring == "rb" || substring == "br"){
     input.replace(start_position,2,"g");
     retVal = true;
  }
  else if(substring == "gb" || substring == "bg"){
    input.replace(start_position,2,"r");
    retVal = true;
  }
  
  return retVal;  
}


int main() {
  
  string test1 = "rgbgb";
  
  top: 
  for(int i = 0; i < test1.length(); ++i){
    if(reduce(i,test1))
      goto top;
  }
  
  cout<<test1<<endl;;
  
  return 0;
}
