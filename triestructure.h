#include <vector>
#include <locale>
#include <math.h>

using namespace std;

struct TrieStruct{
	int MAX;
	int switcharr[52];
	vector<char> symbol;
	vector<int> next;
	int last;
} theStructure;

void printSwitchTable();
void printSymbolTable();
void initTrieStruct();
void insertToTrie(string);

void printSwitchTable(){
    printf("\nSwitch Table:");
    char cs[52];
    for(int i = 65;i < 91; i++){
        cs[i-65] = (char) i;
    }
    for(int i = 97; i < 123; i++){
        cs[i-97+26] = (char) i;

    }
    int gothru = 1,gothru2 = 1;
    for(int i = 0,b=0,a=0; i < 5;i++){
        printf("\n");
        for(;b<52;b++){
            printf("%2c ", cs[b]);

            if((b+1)%11 == 0 && gothru){
                gothru = 0;
                ++b;
                break;
            }
            gothru = 1;

        }
        printf("\n");
        for(;a<52;a++){
            printf("%2d ", theStructure.switcharr[a]);
            if((a+1)%11 == 0 && gothru2){
                gothru2 = 0;
                ++a;
                break;
            }
            gothru2 = 1;

        }
    }
}

void printSymbolTable(){
    int p = theStructure.last + 1;
    printf("\nSymbol Table:\n");
    int gothru1 = 1, gothru2 = 1, gothru3 = 1;
    for(int i = 0,b=0,a=0,c=0; i < (p/10+1);i++){
        for(;c < p;c++){

            printf("%3d ", c);
            if((c+1)%11 == 0 && gothru1){
                gothru1 = 0;
                ++c;
                break;
            }
            gothru1 = 1;

        }
        printf("\n");
        for(; b < p;b++){

            printf("%3c ", theStructure.symbol[b]);
            if((b+1)%11 == 0 && gothru2){
                gothru2 = 0;
                ++b;
                break;
            }
            gothru2 = 1;

        }
        printf("\n");
        for(;a < p;a++){

            printf("%3d ", theStructure.next[a]);
            if((a+1)%11 == 0 && gothru3){
                gothru3 = 0;
                ++a;
                printf("\n");
                break;
            }
            gothru3 = 1;

        }
    }
}

void initTrieStruct(){

    theStructure.symbol = vector<char>(100,'|');
    theStructure.next = vector<int>(100,-1);
	theStructure.MAX = 100;
	theStructure.last = 0;
	for(int i = 0; i < 52; i++) {
		theStructure.switcharr[i] = -1;
	}


}

void insertToTrie(char *chars){


	if(strlen(chars) + 1 > (theStructure.MAX - theStructure.last + 1)){
		theStructure.symbol.resize(theStructure.MAX*2,'|');
		theStructure.next.resize(theStructure.MAX*2, -1);
		theStructure.MAX = theStructure.MAX*2;
	}

    int ios;
    if(isupper(chars[0])){
		ios = chars[0] - 'A';
	}else{
		ios = (chars[0] - 'a') + 26;
	}
    int nextnext = theStructure.switcharr[ios];

    if (nextnext == -1) {

        int slot = theStructure.last;
        theStructure.switcharr[ios] = slot;



        for(int i = 1; i < strlen(chars);i++,slot++,theStructure.last++){
            theStructure.symbol[slot] = chars[i];

        }
        theStructure.symbol[slot] = '*';
        theStructure.last++;

    } else {

        int exit = false;

        // check how many characters match
        int i = 1, p = nextnext;

        while (i < strlen(chars)) {
            if (chars[i] == theStructure.symbol[p]) {
                i++;
                p++;
            } else {
                if(theStructure.next[p]!= -1){
                    p = theStructure.next[p];
                    continue;
                }
                exit = true;
                break;
            }
        }


        if (exit == true) {

            int next;
            if (theStructure.next[p] == -1){

                next = theStructure.last;
            }else
                next = theStructure.next[p];




            theStructure.next[p] = next;

            while (i < strlen(chars)){
                theStructure.symbol[next++] = chars[i++];
                theStructure.last++;
            }
            theStructure.symbol[next] = '*';
            theStructure.last++;

        }


    }
}

