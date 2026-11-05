
namespace siruri{
    int str_length(const char *s){
        if(s==nullptr)
            return 0;
        const char *p=s;
        int lungime=0;
        while(*p!='\0'){
            lungime++;
            p++;
        }
        return lungime;

    }
    bool eq_mask(const char *sir ,const char *mask){
        if(str_length(sir)!=str_length(mask))
            return 0;
        else{   
            int i=0;
            while(sir[i]!='\0' && mask[i]!='\0'){
                if(mask[i]!='?' && mask[i]!=sir[i])
                    return false;
                i++;
            }
            return (sir[i]=='\0' && mask[i]=='\0');
        }
        
    }
    bool eq_cuv(const char *cuv , const char *tablou[]){
        if(cuv == nullptr && tablou == nullptr)
            return false;
        int i=0;
        while(tablou[i]!=nullptr){
            if(eq_mask(cuv,tablou[i])){
                return true;
            }
            i++;
        }
        return false;

    }
    char *strdel(char *s,int pos , int n){
        if(s == nullptr || pos<0 || n<=0){
            return s;
        }
        int lenght=str_length(s);
        if(pos>=lenght){
            return s;
        }
        int i=pos;
        while(s[i+n]!='\0'){
            s[i]=s[i+n];
            i++;
        }
        s[i]='\0';
        return s;
    }
    char *strins(char *s1,int pos,const char *s2){
        if(s1 == nullptr || s2 == nullptr || pos<0 )
            return s1;
        int len_s1=str_length(s1);
        if(len_s1<pos){
            pos=len_s1;
        }
        int len_s2=str_length(s2);
        if(len_s2==0)
            return s1;
        for(int i=len_s1;i>=pos;i--){
            s1[i+len_s2]=s1[i];
        }
        for (int j=0;j<len_s2;j++){
            s1[pos+j]=s2[j];
        }
        return s1;
    }
}