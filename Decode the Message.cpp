class Solution {
public:
    string decodeMessage(string key, string message) {
        //key se code banana ha
        //message ko decode krna ha
        int character=97;
        unordered_map<char,char>mp;
        for(int i=0 ; i<key.size() ; i++){
            // if(key[i]==' ') continue;
            // else{
            //     mp[key[i]]=char(character);
            //     character++;
            // }
            if(key[i]!=' ' && mp.find(key[i])==mp.end()){
                mp[key[i]]=character;
                character++;
            }
        }
        string str;
        
        // for(int i=0 ; i<message.size() ; i++){
        //     auto it=mp.find(message[i]);
        //     str.push_back(it->second);
        // }
        //here i need to decode the message
        //uske liye sbse pehle find the key in the map and replace it with map->second
        for(int i=0 ; i<message.size() ; i++){
//             for(auto it : mp){
//                 if(message[i]==' '){
//                     str.push_back(' ');
//                     break;
//                 }
//                 if(message[i]==it.first){
//                     str.push_back(it.second);
//                     break;
//                 }
                
//             }
            if(message[i]!=' ') str+=mp[message[i]];
            else str+=" ";
        }
        return str;
    }
};