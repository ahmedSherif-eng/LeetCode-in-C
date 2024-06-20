class Solution {
    public boolean isValid(String s) {
        boolean valid = false;
        Stack<Character> stack = new Stack<>();
        if(s.length() % 2 != 0)
            return false;
        for(int i = 0; i<s.length();i++)
        {
            char currentChar = s.charAt(i);
            if(currentChar == '(' || currentChar == '[' || currentChar == '{')
                stack.push(currentChar);
            else{
                char poped ;
                if(!stack.isEmpty())
                    poped= stack.pop();
                else
                    poped = 'a';
                char expected = ' ';
                switch(currentChar)
                {
                    case ')': expected ='('; break;
                    case ']': expected ='['; break;
                    case '}': expected ='{'; break;
                }
                if (expected == poped)
                    valid = true;
                else
                    return false;
        }
        }
        if(stack.isEmpty())
            return valid;
        else
            return false;
    }
}
