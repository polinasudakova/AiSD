typedef struct BinTree{
	char data;
	int left;
	int right;
        int size;
}BinTree;

void printSpaces(int deep);
int isSimilar(BinTree* firstTree, BinTree* secTree, int level, int* isEqual);
int isMirrored(BinTree* firstTree, BinTree* secTree, int level, int* isSymm);
int createElem(BinTree* tree, char data, int size, int isAtom);
int createTree(BinTree* tree, char* str, int level, int size);
int isCorrect(char* str);
