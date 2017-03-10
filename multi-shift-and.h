//License MIT 2017 Ahmad Retha

#define WORD unsigned long int
#define WORDSIZE sizeof(WORD)
#define BITSINWORD WORDSIZE * 8
#define CHARLIMIT 127

void search(char * t, unsigned int n, char ** patterns, unsigned int c);
