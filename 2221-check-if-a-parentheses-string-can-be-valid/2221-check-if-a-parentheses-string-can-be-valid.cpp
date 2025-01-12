class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n%2 != 0) return false;
        stack<int> openStack;   // index where we cannot change 
        stack<int> flexible;    // flexible indexes - s[i] = 0

        // checking whether each ')' has 1 '('
        for(int i=0; i<s.length(); i++) {
            if(locked[i]==1) {      // fixed
                if(s[0]=='(') openStack.push(i);
                else {      // fixed ')'
                    if(!openStack.empty()) openStack.pop();
                    else if(!flexible.empty()) flexible.pop();
                    else return false;
                }
            }
            else flexible.push(i);
        }

        while(!openStack.empty()) {
            if(flexible.empty()) return false;  // kise change b nai kar skte to balance '('
            else if(flexible.top() < openStack.top()) return false;
            openStack.pop();
            flexible.pop();
        }

         stack<int> closeStack; // Tracks indices of fixed ')'.
        stack<int> flexStack;  // Tracks indices of flexible characters.

        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                if (s[i] == ')') {
                    closeStack.push(i); // Fixed ')'.
                } else { // Fixed '('.
                    if (!closeStack.empty()) {
                        closeStack.pop(); // Match with a fixed ')'.
                    } else if (!flexStack.empty()) {
                        flexStack.pop(); // Match with a flexible ')'.
                    } else {
                        return false; // Too many '('.
                    }
                }
            } else {
                flexStack.push(i); // Flexible position.
            }
        }

        // After the second pass, there might still be unmatched ')' in closeStack.
        // Use flexible characters to balance them.
        while (!closeStack.empty()) {
            if (flexStack.empty() || flexStack.top() > closeStack.top()) {
                // If no flexible character is available before the unmatched ')'.
                return false;
            }
            closeStack.pop();
            flexStack.pop();
        }


        return true;
    }
};