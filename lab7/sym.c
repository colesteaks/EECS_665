/* symbol table management */

# include <stdio.h>
// # include <malloc.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include "cc.h"
# include "sym.h"

# define STABSIZE 119			   /* hash table size for strings */
# define ITABSIZE 37			   /* hash table size for identifiers */
# define MAXSTK   1000

struct sem_rec *stk[MAXSTK];               /* stack of ptrs to semantic recs */
struct sem_rec **top = stk;                /* stack pointer */
struct sem_rec **prevtop = NULL;           /* previous top */

int numrecs = 0;                           /* number of semantic recs */

int level = 0;                             /* current block level */

struct s_chain {
   char *s_ptr;                            /* string pointer */
   struct s_chain *s_next;                 /* next in chain */
   } *str_table[STABSIZE] = {0};           /* string hash table */

struct id_entry *id_table[ITABSIZE] = {0}; /* identifier hash table */

/*
 *  dump - dump identifiers with block level >= blev to f
 */
void dump(int blev, FILE *f)
{
    //fprintf(f, "Dumping \tidentifier \ttable\n");
    printf("Dumping \tidentifier \ttable\n");
    int i = 0;
    for(i; i < ITABSIZE; i++) {
        struct id_entry **q;
        q = &id_table[i];
        if(*q) {
            if((*q)->i_blevel >= blev)
                //fprintf(f, "%s\t%s\n", q->i_name, q->i_blevel);
                printf("%s\t\t%d\n", (*q)->i_name, (*q)->i_blevel);
                id_table[i] = NULL;
        }
    }
   //print correct line, remove it rom hash table with requisite block level
}

/*
 * new_block - save previous stack top and mark a new one
 */
void new_block()
{
   save_rec((struct sem_rec *) prevtop);
   prevtop = top - 1;
}

/*
 * exit_block - exit block, free up semantic records
 */
void exit_block()
{
   for (top--; top > prevtop;) {
      numrecs--;
      free((char *) *top--);
   }
   prevtop = (struct sem_rec **) *top;
}

/*
 * enterblock - enter a new block
 */
void enterblock()
{
   level += 1;
}

/*
 * install - install name with block level blev, return ptr
 */
struct id_entry *install(char *name, int blev)
{
   struct id_entry *ip, **q;
   int index;

   if (blev < 0)
      blev = level;

   /* allocate space */
   ip = (struct id_entry *) alloc(sizeof(struct id_entry));

   /* set fields of symbol table */
   ip->i_name = name;
   ip->i_blevel = blev;
   index = hash(name) % ITABSIZE;
   for (q = &id_table[index]; *q; q = &((*q)->i_link))
      if (blev >= (*q)->i_blevel)
         break;
   ip->i_link = *q;
   *q = ip;
   return (ip);
}

/*
 * leaveblock - exit a block
 */
void leaveblock()
{
    FILE *f = fopen("result.output", "w");
    dump(level, f);
    level -= 1;
   //decrement level and call dump
}

/*
 * lookup - lookup name, return ptr; use default scope if blev == 0
 */
struct id_entry *lookup(char *name, int blev)
{
   struct id_entry *p;

   for (p = id_table[hash(name)%ITABSIZE]; p; p = p->i_link)
      if (name == p->i_name && (blev == 0 || blev == p->i_blevel))
         return (p);
   return (NULL);
}

/*
 * sdump - dump string table to f
 */
void sdump(FILE *f)
{
   struct s_chain **s, *p;

   fprintf(f, "Dumping string table\n");
   for (s = str_table; s < &str_table[STABSIZE]; s++)
      for (p = *s; p; p = p->s_next)
         fprintf(f, "%s\n", p->s_ptr);
}

/*
 * slookup - lookup str in string table, install if necessary, return ptr
 */
char *slookup(char str[])
{
   struct s_chain *p;
   int i, k;

   for (k = i = 0; i < 5; i++)	/* simple hash function */
      if (str[i])
         k += str[i];
      else
         break;

   k %= STABSIZE;
   for (p = str_table[k]; p; p = p->s_next)
      if (strcmp(str, p->s_ptr) == 0)
         return (p->s_ptr);
   p = (struct s_chain *) alloc(sizeof(struct s_chain));
   p->s_next = str_table[k];
   str_table[k] = p;
   p->s_ptr = (char *) alloc((unsigned) strlen((const char*)str) + 1);
   p->s_ptr = strcpy(p->s_ptr, str);
   return (p->s_ptr);
}

/*
 * hash - hash name, turn address into hash number
 */
intptr_t hash(char *s)
{
   return((intptr_t)s);
}

/*
 * alloc - alloc space
 */
char *alloc(unsigned n)
{
   char *p;

   if ((p = calloc(1, n)) == NULL) {
      yyerror("csem: out of space");
      exit (1);
   }
   return (p);
}

/*
 * save_rec - save a semantic record so it can be reclaimed later
 */
void save_rec(struct sem_rec *s)
{
   /* save on stack so can reclaim */
   if (numrecs++ > MAXSTK) {
      fprintf(stderr, "too many semantic records\n");
      exit(1);
   }
   *top++ = s;
}
