class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            int totalChars = words[index].length();
            int last = index + 1;

            // Find how many words fit in one line
            while (last < n) {
                if (totalChars + 1 + words[last].length() > maxWidth) break;
                totalChars += 1 + words[last].length();
                last++;
            }

            string line;
            int gaps = last - index - 1;

            // If it's the last line OR only one word → left justify
            if (last == n || gaps == 0) {
                line = words[index];
                for (int i = index + 1; i < last; i++) {
                    line += " " + words[i];
                }
                // Fill the remaining spaces
                while (line.length() < maxWidth)
                    line += " ";
            } 
            else {
                // Fully justify
                int totalSpaces = maxWidth;
                for (int i = index; i < last; i++) {
                    totalSpaces -= words[i].length();
                }

                int spaces = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int i = index; i < last - 1; i++) {
                    line += words[i];
                    line += string(spaces + (i - index < extra ? 1 : 0), ' ');
                }
                line += words[last - 1];
            }

            result.push_back(line);
            index = last;
        }

        return result;
    }
};
