//Jacqueline Vermette
//Cop4530
//Assignment1

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>



using namespace std;





bool orderString(const pair<string, int>& a, const pair<string, int>& b){


    if(a.second != b.second){
        return a.second > b.second; //if they are not the same, then it decends , otherwise it does the latter
}
    
    return a.first < b.first;  


}





bool orderChar(const pair<char, int>& a, const pair<char, int>& b){

if(a.second != b.second){

    return a.second > b.second;  
}


    return a.first < b.first; 
}


//Printing for strings

void printItems(const unordered_map<string, int>& items, size_t topCount, const string& itemCat){

    vector<pair<string, int>> orgItems(items.begin(), items.end());

//Organizes items by number of times they appear then by ASCII value 
    sort(orgItems.begin(), orgItems.end(), orderString);


size_t maxWidth = 0;


//Formatting output 
for(const auto& item : items){

    maxWidth = max(maxWidth, item.first.size());

}
    maxWidth += 5;  


cout << "Total " << orgItems.size() << " different " << itemCat << ", " << topCount << " most used " << itemCat << ":\n";




for(size_t i = 0; i < min(topCount, orgItems.size()); ++i){

    cout << "No. " << i << ": " << orgItems[i].first << string(maxWidth - orgItems[i].first.size(), ' ') << orgItems[i].second << "\n";


}

}

//Printing for characters


void printItems(const unordered_map<char, int>& items, size_t topCount, const string& itemCat){


    vector<pair<char, int>> orgItems(items.begin(), items.end());



sort(orgItems.begin(), orgItems.end(), orderChar);

size_t maxWidth = 6;  

cout << "Total " << orgItems.size() << " different " << itemCat << ", " << topCount << " most used " << itemCat << ":\n";


for(size_t i = 0; i < min(topCount, orgItems.size()); ++i){

    cout << "No. " << i << ": " << orgItems[i].first << string(maxWidth - 1, ' ') << orgItems[i].second << "\n";

}

}

string wordInsensitive(const string& str);

int main(){


    unordered_map<char, int> charCount;
    unordered_map<string, int> wordCount;
    unordered_map<string, int> numberCount;



    string word;
    string number;
    char ch;

//getting the characters one by one
while(cin.get(ch)){  
   
    ++charCount[ch];  
//checks if it is a number and adds to the list
if (isalpha(ch)){
    if (!number.empty()){  
        
        ++numberCount[number];  
        number.clear();  

}
    word += ch;  
} 
else{
    //if there is a word then it is saved/ created
    if(!word.empty()){ 
        
        string lowerWord = wordInsensitive(word);

        ++wordCount[lowerWord];
        word.clear(); 
}

//Checks if the character is a number which then adds it to the list.
if(isdigit(ch)){

number += ch; 
} 
else{

    
    if(!number.empty()){

        ++numberCount[number];  
        number.clear();  
}
}
}
}

//Checking to make sure nothing was left out
if(!word.empty()){

    string lowerWord = wordInsensitive(word);
    ++wordCount[lowerWord];

}

if(!number.empty()){

    ++numberCount[number];
}

const size_t topCount = 10;

  
//Printing statements
printItems(charCount, topCount, "characters");
cout << "\n"; 

printItems(numberCount, topCount, "numbers");
cout << "\n";

printItems(wordCount, topCount, "words");




return 0;
}


//========================================================


//Changing the words to be case insensitive 


string wordInsensitive(const string& str) {
    string lowerStr;
    for (char ch : str) {
        lowerStr += tolower(ch);
    }
    return lowerStr;
}

