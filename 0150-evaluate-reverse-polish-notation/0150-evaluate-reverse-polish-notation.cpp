class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto it: tokens) {
            if(it != "+" && it != "/" && it != "*" && it != "-"){
                long long int num=0, chk=1;
                for(int j=0; j<it.size(); j++) {
                    if(it[j]=='-'){chk=-1; continue;}
                    num+=(it[j]-'0');
                    num*=10;
                }
                num/=10;
                if(chk==-1){num*=(-1);}
                s.push(num);
            }
            else if(it == "+"){
                long long int t1=s.top();
                s.pop();
                long long int t2=s.top();
                s.pop();
                s.push(t1+t2);
            }
            else if(it == "-"){
                long long int t1=s.top();
                s.pop();
                long long int t2=s.top();
                s.pop();
                s.push(t2-t1);
            }
            else if(it == "*"){
                long long int t1=s.top();
                s.pop();
                long long int t2=s.top();
                s.pop();
                s.push(t1*t2);
            }
            else if(it == "/"){
                long long int t1=s.top();
                s.pop();
                long long int t2=s.top();
                s.pop();
                s.push(t2/t1);
            }
        }
        return s.top();
    }
};