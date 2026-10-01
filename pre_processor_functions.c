#include "pre_processor_struct.h"
#include <string.h>
#include "stack_functions.h"
#define ON 1
#define OFF 0
#define LINE_EATER while(c!='\n' && c!=EOF) c=getchar();
WORDS_GROUP d_words_group[]={
    [0].word="define",[0].category=5,
    [1].word="",[1].category=0
};

WORDS_GROUP e_words_group[]={
    [0].word="elif",[0].category=4,
    [1].word="elifdef",[1].category=4,
    [2].word="elifndef",[2].category=4,
    [3].word="else",[3].category=3,
    [4].word="embed",[4].category=1,
    [5].word="endif",[5].category=3,
    [6].word="error",[6].category=4,
    [7].word="",[7].category=0
};

WORDS_GROUP i_words_group[]={
    [0].word="if",[0].category=4,
    [1].word="ifdef",[1].category=2,
    [2].word="ifndef",[2].category=2,
    [3].word="include",[3].category=1,
    [4].word="",[4].category=0
};

WORDS_GROUP l_words_group[]={
    [0].word="line",[0].category=4,
    [1].word="",[1].category=0
};

WORDS_GROUP p_words_group[]={
    [0].word="pragma",[0].category=4,
    [1].word="",[1].category=0
};

WORDS_GROUP u_words_group[]={
    [0].word="undef",[0].category=2,
    [1].word="",[1].category=0
};

WORDS_GROUP w_words_group[]={
    [0].word="warning",[0].category=4,
    [1].word="",[1].category=0
};

FIRST_LETTERS first_letter[]={
    {'d',d_words_group,2},
    {'e',e_words_group,8},
    {'i',i_words_group,5},
    {'l',l_words_group,2},
    {'p',p_words_group,2},
    {'u',u_words_group,2},
    {'w',w_words_group,2},
    {'\n',NULL,0},
    {'\0',NULL,0}
};

RESULT preprocessor_directive_checker(WORDS_GROUP*,int);
int rest_line_checker(int);

int preprocessor_directive_line_checker(){
    int c=0,error_occured=0,i=0,first_letter_matched=0,error=OFF;
    RESULT result={0,0};
    WORDS_GROUP* word_group_ptr;
    int word_group_size=0;
    c=getchar();
    if(c==EOF){
        return 0;  
    }
    else if(c==' ' || c =='\t'){
        while(c==' ' || c=='\t'){
            c=getchar();
        }
    }
    while(first_letter_matched==0 && first_letter[i].first_letter!='\0'){
        if(c==first_letter[i].first_letter){
            first_letter_matched=1;
            word_group_ptr=first_letter[i].first_letter_ptr;
            word_group_size=first_letter[i].word_group_size;
            i=0;
        }
        i++;
    }
    if(first_letter_matched==1 && word_group_ptr==NULL){
        return 0;
    }
    else if(first_letter_matched==1){
        ungetc(c,stdin);
        result=preprocessor_directive_checker(word_group_ptr,word_group_size);
        if(result.result){
            return 1;   
        }
        else{
        //ungetc(c,stdin);
        if(rest_line_checker(result.category)){
            return 1; 
        };
        return 0;
    }
    }
    else{
        if(c!='\n'){
        while((c=getchar())!='\n' && c!=EOF);
        return 1;
        }
        else
            return 0;
        
    }
}

RESULT preprocessor_directive_checker(WORDS_GROUP* word_group,int size){
    int c=0 , i=0;
    char word[9];
    for(i=0;i<9;i++){
        word[i]='\0';
    }
    RESULT result={1,0};
    i=0;
    while((c=getchar())!=' ' && c !='\t' && c!='\n' && c!=EOF && c!='<' && c!='"'){
        if(i>=8){
            while((c=getchar())!='\n' && c!=EOF);
            return result;
        }
        word[i]=c;
        i++;
    }
    ungetc(c,stdin);
    if(size==2){
        if(strcmp(word,word_group->word)==0){                
            result.result=0;
            result.category=word_group->category;
        }

    }

    else{
        for(i=0;(i<size-1);i++){
            if(strcmp(word,(word_group+i)->word)==0){
                result.result=0;
                result.category=(word_group+i)->category;
            }
        }
    }
    if(result.result == 1){
        LINE_EATER
    }
    return result;
}

int rest_line_checker(int category){
    stack_engine(stack_builder(NULL,10));
    int c =0 , error_state=OFF , counter_inside_enclouser=0;
    if(category==1){
        while((c=getchar())==' ' || c=='\t'){
            ;
        }
        if(c=='<'||c=='"'){
            push(c);
            error_state=ON;
        }
        else{
            LINE_EATER
            return 1;
        }
        while((c=getchar())!='\n' && c!=EOF){
            if(error_state==OFF){
                if(c!=' ' && c!='\t'){
                    error_state=ON;}
            }
            if((c=='"' || c=='>') && counter_inside_enclouser!=0){
                if(c=='"'){
                    if(*(stack.current-1)=='"'){
                        pop();
                        error_state= OFF;
                    }}
                else{
                    if(*(stack.current-1)=='<'){
                        pop();
                        error_state= OFF;
                    }
                }
            }
            
            counter_inside_enclouser++;}
        
        if(error_state==ON)
            return 1;
        else
            return 0;

    }
    else if(category==2){
        if((c=getchar())!=' ' && c!='\t'){
            LINE_EATER
            return 1;}
        else{
            while(c==' ' || c=='\t'){
                c=getchar();
            }
            if(!((c>=65 && c<=90) || (c>=97 && c<=122) || c=='_')){
                LINE_EATER
                return 1;
            }            
            while((c>=65 && c<=90) || (c>=97 && c<=122) || c=='_' || (c>=48 && c<=57)){
                c=getchar();
            }
            if(!(c==' ' || c=='\t' || c=='\n')){
                LINE_EATER
                return 1;}
            else{
                while(c!='\n' && c!=EOF){
                    if(c!=' '&&c!='\t')
                        error_state=ON;
                    c=getchar();
                }
                if(error_state==ON)
                    return 1;
            }
            
        }
            return 0;
    }
    else if(category==3){
        while((c=getchar())!='\n' && c!=EOF){
            if(c!=' ' && c!='\t')
                error_state=ON ;
        }
        if(error_state==ON)
            return 1;
        else
            return 0;
    }
    else if(category==4){
        while((c=getchar())!='\n' && c!=EOF){
            ;
        }
        return 0;
    }

    else if(category==5){
        if((c=getchar())!=' ' && c!='\t'){
            LINE_EATER;
            return 1;}
        else{
            while(c==' ' || c=='\t'){
                c=getchar();
            }
            if(!((c>=65 && c<=90) || (c>=97 && c<=122) || c=='_')){
                LINE_EATER
                return 1;
            }
            while((c>=65 && c<=90) || (c>=97 && c<=122) || c=='_' || (c>=48 && c<=57)){
                c = getchar();
            }
            if(c==' ' || c=='\t' || c=='(' || c=='\n' || c==EOF){
                while(c!='\n' && c!=EOF){
                    c=getchar();
                }
            }
            else{
                LINE_EATER;
                return 1;}
        }
        return 0;
    }
}

