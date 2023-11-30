class Solution {
public:
    int minSwaps(string s) {
        if(s.size() == 0) return 0;

        cout<<s.size()<<endl;
        int i = 0, j = s.size()-1;
        int cc = 0;
        int count = 0;

       while(i < j){
            while(s[j] != '['){
                j--;
            }

            if(s[i] == '['){
                cc++;
            }
            else{
                cc--;
            }
            if(cc < 0){
                swap(s[i], s[j]);
                cc+=2;
                count++;
            }

            i++;
        }

        return count;
    }
};
