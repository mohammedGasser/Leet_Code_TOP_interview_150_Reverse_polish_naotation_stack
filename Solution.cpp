
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s: tokens){
             if(s=="+" || s=="-" || s=="/" || s=="*"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int ans;
                  if(s=="+")ans=y+x;
                  else if(s=="*") ans=y*x;
                  else if(s=="-")  ans=y-x;
                  else if(s=="/")  ans=y/x;
                      
                st.push(ans);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};


class Another_Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st  ;
        static int op1=0,op2=0; 
        for(auto c : tokens)
        {
           if(c=="+")
             { 
                op1= st.top();
                st.pop();
                op2=st.top();
                st.pop();
                op1+=op2;
                st.push(op1);
             }
           else if(c=="-")
             {
                op1= st.top();
                st.pop();
                op2=st.top();
                st.pop();
                op2-=op1;
                st.push(op2);
             }
           else if(c=="/")
             {
                op1= st.top();
                st.pop();
                op2=st.top();
                st.pop();
                op2/=op1;
                st.push(op2);
             }  
           else if(c=="*")
             {
                op1= st.top();
                st.pop();
                op2=st.top();
                st.pop();
                op1*=op2;
                st.push(op1);
             }
           else
           {
              st.push(stoi(c));
           }
            
           }
    return st.top();      } 

              
    
};
