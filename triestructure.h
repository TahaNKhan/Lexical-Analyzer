#include <vector>
#include <locale>
#include <math.h>

using namespace std;

// trie structure.
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

// this function prints out the switch table
void printSwitchTable(){
    printf("\n\n\nSwitch Table:");
    char cs[52];
    // fill up the cs array with character A-Z and a-z
    for(int i = 65;i < 91; i++){
        cs[i-65] = (char) i;
    }
    for(int i = 97; i < 123; i++){
        cs[i-97+26] = (char) i;

    }
    int gothru = 1,gothru2 = 1,gothru3 = 1, gothru4 = 1;
    for(int i = 0,b=0,a=0; i < 5;i++){
        printf("\n");
        for(;b<52;b++){
            // prints out a space for the first line
            if(gothru3){printf("%-8s"," ");gothru3 = 0;}
            // prints out space for lines after the first one
            if(!gothru)printf("%-8s"," ");
            printf("%5c ", cs[b]);

            if((b+1)%20 == 0 && gothru){

                gothru = 0;
                ++b;
                break;
            }
            gothru = 1;

        }
        printf("\n");
        for(;a<52;a++){
            // prints out switch for the first line
            if(gothru4){printf("%-8s","Switch: ");gothru4 = 0;}
            // prints out switch for lines after first
            if(!gothru2)printf("%-8s","Switch: ");
            printf("%5d ", theStructure.switcharr[a]);
            if((a+1)%20 == 0 && gothru2){
                gothru2 = 0;
                ++a;
                printf("\n\n");
                break;
            }
            gothru2 = 1;

        }
    }
}

// prints out the symbol table
void printSymbolTable(){
    int p = theStructure.last + 1;
    printf("\n\n\nSymbol Table:\n");
    // variables used to go to next lines.
    int gothru1 = 1, gothru2 = 1, gothru3 = 1,gothru5 = 1,gothru6 = 1,gothru7 = 1;
    for(int i = 0,b=0,a=0,c=0; i < (p/10+1);i++){
        for(;c < p;c++){
            if(gothru5)printf("%-8s"," ");
            gothru5 = 0;
            if(!gothru1)printf("%-8s"," ");
            printf("%5d ", c);
            if((c+1)%20 == 0 && gothru1){
                gothru1 = 0;
                ++c;
                break;
            }
            gothru1 = 1;

        }
        printf("\n");
        for(; b < p;b++){
            if(gothru6)printf("%-8s","Symbol:");
            gothru6 = 0;
            if(!gothru2)printf("%-8s","Symbol:");
            printf("%5c ", theStructure.symbol[b]);
            if((b+1)%20 == 0 && gothru2){
                gothru2 = 0;

                ++b;
                break;
            }
            gothru2 = 1;

        }
        printf("\n");
        for(;a < p;a++){
            if(gothru7)printf("%-8s","next:");
            gothru7 = 0;
            if(!gothru3)printf("%-8s","next: ");
            printf("%5d ", theStructure.next[a]);
            if((a+1)%20 == 0 && gothru3){

                gothru3 = 0;
                ++a;
                printf("\n\n\n");
                break;
            }
            gothru3 = 1;

        }
    }
    printf("\n");
}


void initTrieStruct(){
    // initialize the character vector/array
    theStructure.symbol = vector<char>(100,'|');
    // initialize next vector/array
    theStructure.next = vector<int>(100,-1);
    // initial max set to 100
	theStructure.MAX = 100;
	// points to the last symbol
	theStructure.last = 0;
	for(int i = 0; i < 52; i++) {
        // fill up the switch array with -1s
		theStructure.switcharr[i] = -1;
	}


}

void insertToTrie(char *chars){

    // resize the array if there isnt enough space
	if(strlen(chars) + 1 > (theStructure.MAX - theStructure.last + 1)){
		theStructure.symbol.resize(theStructure.MAX*2,'|');
		theStructure.next.resize(theStructure.MAX*2, -1);
		theStructure.MAX = theStructure.MAX*2;
	}
    // idk why i called it ios, initial of switch?
    int ios;
    // check if ios is uppercase or lower case and set index based on that
    if(isupper(chars[0])){
		ios = chars[0] - 'A';
	}else{
		ios = (chars[0] - 'a') + 26;
	}

	// set index found from switch array to nextnext
    int nextnext = theStructure.switcharr[ios];

    // if -1, the string isnt there, add it.
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
                // exit out if no more mathing characters and next table shows a -1
                exit = true;
                break;
            }
        }


        if (exit == true) {
            // probably didnt need a new variable but whatever
            int next;
            if (theStructure.next[p] == -1){

                next = theStructure.last;
            }else
                next = theStructure.next[p];




            theStructure.next[p] = next;
            // add the remaining characters to symbol array/vector
            while (i < strlen(chars)){
                theStructure.symbol[next++] = chars[i++];
                theStructure.last++;
            }
            theStructure.symbol[next] = '*';
            theStructure.last++;

        }


    }
}

