class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string& str : strs){
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i = 0; 
        while(i < s.size()){
            size_t j = s.find('#', i);
            int len = stoi(s.substr(i, j-i));
            // int length = std::stoi(s.substr(i, j - i));

            string str = s.substr(j+1, len);
            decoded.push_back(str);
            i = j+len+1;
        }

        return decoded;
    }
};
