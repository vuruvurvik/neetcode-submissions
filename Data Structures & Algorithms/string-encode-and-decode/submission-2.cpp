class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;

        for (const string& str : strs) {
            encoded += to_string(str.size());
            encoded += '#';
            encoded += str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;

        while (i < s.size()) {
            // Find the '#' separating the length from the string.
            int delimiter = s.find('#', i);

            // Parse the string length.
            int length = stoi(s.substr(i, delimiter - i));

            // Move past "length#".
            i = delimiter + 1;

            // Read exactly `length` characters.
            decoded.push_back(s.substr(i, length));

            // Move to the beginning of the next encoded string.
            i += length;
        }

        return decoded;
    }
};