class Solution {
    public int lengthOfLastWord(String s) {
        int counter = 0;
        //skip spaces
        int i;
        for(i= s.length()-1; i >= 0; i--)
            if(s.charAt(i) != ' ')
                break;
        for (; i>=0; i--)
        {
            if(s.charAt(i) == ' ')
                break;
            counter++;
        }
        return counter;
    }
}
