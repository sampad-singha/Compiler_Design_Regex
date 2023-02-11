#include<bits/stdc++.h>
using namespace std;
string spaceRemove(string line){
    int i=0;
    while(line[i]==' '){
        line.erase(line.begin());
    }
    return line;
}
void codeCheck(vector<pair<int,string>> &code){
    string reg[7] = {"^(#[ \t]*include[ \t]*[<\"]stdio.h[ \t]*[\">][ \t]*)$",
                     "^(int|void)[ \t]*main[ \t]*\\([ \t]*\\)$",
                     "^\\{[ \t]*$",
                     "^(int[ \t]*([a-zA-Z_]+[a-zA-Z_[0-9]*)[ \t]*,[ \t]*([a-zA-Z_]+[a-zA-Z_[0-9]*)[ \t]*,[ \t]*([a-zA-Z_]+[a-zA-Z_[0-9]*)[ \t]*;[ \t]*)$",
                     "^(printf[ \t]*\\([ \t]*\".*\"[ \t]*,[ \t]*([a-zA-Z_]+[a-zA-Z_[0-9]*)[ \t]*,[ \t]*([a-zA-Z_]+[a-zA-Z_[0-9]*)[ \t]*,[ \t]*([a-zA-Z_]+[a-zA-Z_[0-9]*)[ \t]*\\)[ \t]*;[ \t]*)$",
                     "^return[ \t]*\\d*[ \t]*;[ \t]*$",
                     "^\\}[ \t]*$"};
    int j=0;
    for(auto i:code){
        regex rgx(reg[j]);
        if(!regex_match(i.second,rgx)){
            cout<<"Error in line "<<i.first<<endl;
        }
        j++;
    }

}

int main  (  ){
    ifstream file("source.txt");
    string line;
    vector<pair<int,string>> code;
    int lineNum=1;
    while(!file.eof()){
        getline(file,line);
        line=spaceRemove(line);
        if(!line.empty()){
            code.push_back(make_pair(lineNum,line));
        }
        lineNum++;
    }
    file.close();
    codeCheck(code);

//    for(auto i:code)
//        cout<<i.first<<" "<<i.second<<endl;

    return 0;
}