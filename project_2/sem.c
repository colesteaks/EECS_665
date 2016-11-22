# include <stdio.h>
# include "cc.h"
# include "semutil.h"
# include "sem.h"
# include "sym.h"
# define MAXSIZE 1024

extern int formalnum;
extern char formaltypes[];
extern int localnum;
extern char localtypes[];
extern int localwidths[];

int numlabels = 0;                      /* total labels in file */
int numblabels = 0;                     /* toal backpatch labels in file */
int gotosize = 0;                       /* total items in goto list */
char *gotolist[MAXSIZE];                /* keep track of existing gotos */

char type_char(int type);
void del_goto(int index);
struct sem_rec *recast_y(struct sem_rec *x, struct sem_rec *y);
int nextnumb();
int nextnum();
int type_width(int type);

/*
 * backpatch - backpatch list of quadruples starting at p with k
 * TODO: check for correctness.
 */
void backpatch(struct sem_rec *p, int k)
{
   printf("B%d=L%d\n", p->s_place, k+1);
   p->s_place = k+1;
}

/*
 * bgnstmt - encountered the beginning of a statement
 * TODO: check for correctness.
 */
void bgnstmt()
{
  extern int lineno;

  printf("bgnstmt %d\n", lineno);
}

/*
 * call - procedure invocation - correct
 */
struct sem_rec *call(char *f, struct sem_rec *args)
{
  int arg_count = 0;
  struct sem_rec *arg = args;

  while(arg)
  {
    printf("arg%c t%d\n", type_char(arg->s_mode), arg->s_place);
    arg = arg->back.s_link;
    arg_count++;
  }

  struct id_entry *p;
  printf("t%d := global %s\n", nexttemp(), f);
  int ret_type = T_INT;
  if((p = lookup(f, 2)) != NULL) {
    ret_type = p->i_type;
  }
  int t = currtemp();
  printf("t%d := f%c t%d %d\n", nexttemp(), type_char(ret_type), t, arg_count);
  return node(currtemp(), ret_type, NULL, NULL);
}

/*
 * ccand - logical and - correct
 */
struct sem_rec *ccand(struct sem_rec *e1, int m, struct sem_rec *e2)
{
  backpatch(e1->back.s_true, m);
  struct sem_rec *res = merge(e1->s_false, e2->s_false);
  return node(0, 0, e2->back.s_true, res);
}

/*
 * ccexpr - convert arithmetic expression to logical expression - given
 */
struct sem_rec *ccexpr(struct sem_rec *e)
{
   struct sem_rec *t1;

   if(e){

     t1 = gen("!=", e, cast(con("0"), e->s_mode), e->s_mode);

     printf("bt t%d B%d\n", t1->s_place, nextnumb());
     printf("br B%d\n", nextnumb());
     return (node(0, 0,
		  node(numblabels-1, 0, (struct sem_rec *) NULL,
		       (struct sem_rec *) NULL),
		  node(numblabels, 0, (struct sem_rec *) NULL,
		       (struct sem_rec *) NULL)));
   }
   else
     fprintf(stderr, "Argument sem_rec is NULL\n");
}

/*
 * ccnot - logical not
 * TODO: check for correctness.
 */
struct sem_rec *ccnot(struct sem_rec *e)
{
   return node(0, 0, e->s_false, e->back.s_true);
}

/*
 * ccor - logical or - correct
 *
 */
struct sem_rec *ccor(struct sem_rec *e1, int m, struct sem_rec *e2)
{
  backpatch(e1->s_false, m);
  return (node(0,0,merge(e1->back.s_true, e2->back.s_true), e2->s_false));
}

/*
 * con - constant reference in an expression - given
 */
struct sem_rec *con(char *x)
{
  struct id_entry *p;

  if((p = lookup(x, 0)) == NULL) {
    p = install(x, 0);
    p->i_type = T_INT;
    p->i_scope = GLOBAL;
    p->i_defined = 1;
  }

  /* print the quad t%d = const */
  printf("t%d := %s\n", nexttemp(), x);

  /* construct a new node corresponding to this constant generation
     into a temporary. This will allow this temporary to be referenced
     in an expression later*/
  return(node(currtemp(), p->i_type, (struct sem_rec *) NULL,
	      (struct sem_rec *) NULL));
}

/*
 * dobreak - break statement
 * TODO: check for correctness.
 */
void dobreak()
{
   n();
   leaveblock();
}

/*
 * docontinue - continue statement
 * TODO: see comments
 */
void docontinue()
{
   //fprintf(stderr, "sem: docontinue not implemented\n");
   //TODO: do we need to do anything here?
}

/*
 * dodo - do statement
 * TODO: check for correctness.
 */
void dodo(int m1, int m2, struct sem_rec *e, int m3)
{
   backpatch(e->back.s_true, m1);
   backpatch(e->s_false, m3);
   backpatch(e, m2);
}

/*
 * dofor - for statement
 * TODO: check for correctness.
 */
void dofor(int m1, struct sem_rec *e2, int m2, struct sem_rec *n1,
           int m3, struct sem_rec *n2, int m4)
{
   backpatch(e2->back.s_true, m3);
   backpatch(e2->s_false, m4);
   backpatch(n1, m1);
   backpatch(n2, m2);
}

/*
 * dogoto - goto statement
 * TODO: see comments below.
 */
void dogoto(char *id)
{
   struct id_entry *look_up = lookup(id, 0);
   if (look_up)
   {
     printf("br L%d\n", look_up->i_width);
     return;
   }

   gotolist[gotosize] = id;
   gotosize++;
   //TODO: do we need some number associated with this? or is it another backpatch?
}

/*
 *  doif - one-arm if statement
 *  TODO: check for correctness.
 */
void doif(struct sem_rec *e, int m1, int m2)
{
   backpatch(e->back.s_true, m1);
   backpatch(e->s_false, m2);
}

/*
 * doifelse - if then else statement
 * TODO: check for correctness.
 */
void doifelse(struct sem_rec *e, int m1, struct sem_rec *n,
                         int m2, int m3)
{
   backpatch(e->back.s_true, m1);
   backpatch(e->s_false, m2);
   backpatch(n, m3);
}

/*
 * doret - return statement
 * TODO: check for correctness.
 */
void doret(struct sem_rec *e)
{
  printf("ret%c t%d\n", type_char(e->s_mode), currtemp());
}

/*
 * dowhile - while statement
 * TODO: check for correctness.
 */
void dowhile(int m1, struct sem_rec *e, int m2, struct sem_rec *n,
             int m3)
{
   backpatch(e->back.s_true, m2);
   backpatch(e->s_false, m3);
   backpatch(n, m1);
}

/*
 * endloopscope - end the scope for a loop
 * TODO: check for correctness.
 */
void endloopscope(int m)
{
   leaveblock();
}

/*
 * exprs - form a list of expressions
 * TODO: check for correctness !important
 */
struct sem_rec *exprs(struct sem_rec *l, struct sem_rec *e)
{
   return merge(l, e);
}

/*
 * fhead - beginning of function body - correct
 */
void fhead(struct id_entry *p)
{
   int i;
   for(i = 0; i < formalnum; i++)
   {
     if (formaltypes[i] == i)
     {
       printf("formal 4\n");
     }
     else
     {
       printf("formal 8\n");
     }
   }
   for(i = 0; i < localnum; i++)
   {
     if (localtypes[i] == i)
     {
       printf("local 4\n");
     }
     else
     {
       printf("local 8\n");
     }
   }
}

/*
 * fname - function declaration - correct
 */
struct id_entry *fname(int t, char *id)
{
  printf("func %s\n", id);
  enterblock();
  return dclr(id, t, 4);
}

/*
 * ftail - end of function body - correct
 */
void ftail()
{
  printf("fend");
  //localnums = 0; --might be the solution to multiple function problems.
  leaveblock();
}

/*
 * id - variable reference
 */
struct sem_rec *id(char *x)
{
   struct id_entry *p;

   if ((p = lookup(x, 0)) == NULL) {
      yyerror("undeclared identifier");
      p = install(x, -1);
      p->i_type = T_INT;
      p->i_scope = LOCAL;
      p->i_defined = 1;
   }
   if (p->i_scope == GLOBAL)
      printf("t%d := global %s\n", nexttemp(), x);
   else if (p->i_scope == LOCAL)
      printf("t%d := local %d\n", nexttemp(), p->i_offset);
   else if (p->i_scope == PARAM) {
      printf("t%d := param %d\n", nexttemp(), p->i_offset);
      if (p->i_type & T_ARRAY) {
         (void) nexttemp();
         printf("t%d := @i t%d\n", currtemp(), currtemp()-1);
      }
   }

   /* add the T_ADDR to know that it is still an address */
   return (node(currtemp(), p->i_type|T_ADDR, (struct sem_rec *) NULL,
                (struct sem_rec *) NULL));
}

/*
 * index - subscript
 */
struct sem_rec *tom_index(struct sem_rec *x, struct sem_rec *i)
{
  return (gen("[]", x, cast(i, T_INT), x->s_mode&~(T_ARRAY)));
}

/*
 * labeldcl - process a label declaration
 * TODO: see comments below.
 */
void labeldcl(char *id)
{
   printf("label L%d\n", nextnum());

   struct id_entry *temp;
   temp = dclr(id, T_INT, 4);
   temp->i_width = numlabels;

   int i;
   for (i = 0; i < gotosize; i++)
   {
     if (id == gotolist[i])
     {
       struct id_entry *t2;
       t2 = lookup(id, 0);
       printf("B%d=L%d\n", nextnumb(), t2->i_width); //TODO: are the numbers being printed here correct?
       //TODO: do I need to then backpatch after I find label in goto list?
     }
   }
}

/*
 * m - generate label and return next temporary number - correct
 *
 */
int m()
{
   printf("label L%d\n", nextnum());
   return(numlabels-1);
}

/*
 *  n - generate goto and return backpatch pointer - correct
 */
struct sem_rec *n()
{
   printf("br B%d\n", nextnumb());
   return node(numblabels, 0, 0, 0);
}

/*
 * op1 - unary operators
 * TODO: check for correctness
 */
struct sem_rec *op1(char *op, struct sem_rec *y)
{
  if (*op == '@' && !(y->s_mode&T_ARRAY)){
    /* get rid of T_ADDR if it is being dereferenced so can handle
       T_DOUBLE types correctly */
    y->s_mode &= ~T_ADDR;
    return (gen(op, (struct sem_rec *) NULL, y, y->s_mode));
  }
  else if ((y->s_mode == T_DOUBLE) && (*op == '~'))
  {
    y = cast(y, T_INT);
    return (gen(op, 0, y, T_INT));
  }

  return (gen(op, (struct sem_rec *) NULL, y, y->s_mode));
}

/*
 * op2 - arithmetic operators
 * TODO: check for correctness
 */
struct sem_rec *op2(char *op, struct sem_rec *x, struct sem_rec *y)
{
  struct sem_rec *cast_y;
  cast_y = recast_y(x,y);
  return (gen(op, x, cast_y, cast_y->s_mode));
}

/*
 * opb - bitwise operators
 * TODO: check for correctness
 */
struct sem_rec *opb(char *op, struct sem_rec *x, struct sem_rec *y)
{
  cast(x, T_INT);
  cast(y, T_INT);
  return (gen(op, x, y, T_INT));
}

/*
 * rel - relational operators
 * TODO: how does this need to be different than op2??
 */
struct sem_rec *rel(char *op, struct sem_rec *x, struct sem_rec *y)
{
   struct sem_rec *temp;
   recast_y(x, y);
   temp = gen(op, x, y, x->s_mode);
   printf("bt t%d B%d\n", temp->s_place, nextnumb());
   printf("br B%d\n", nextnumb());

   temp->back.s_true = node(numblabels-1, temp->s_mode,0,0);
   temp->s_false = node(numblabels, temp->s_mode,0,0);

   return temp;
}

/*
 * set - assignment operators
 * TODO: check for correctness.
 */
struct sem_rec *set(char *op, struct sem_rec *x, struct sem_rec *y)
{
  /* assign the value of expression y to the lval x */
  struct sem_rec *p, *cast_y;

  if(x==NULL || y==NULL)
  {
    printf("Arguments to set cannot be null\n");
    return NULL;
  }

  if(*op!='\0'){
    struct sem_rec *temp = op1("@", x);
    y = gen(op, temp, y, x->s_mode);
  }

  /* if for type consistency of x and y */
  cast_y = recast_y(x, y);

  /*output quad for assignment*/
  if(x->s_mode & T_DOUBLE)
    printf("t%d := t%d =f t%d\n", nexttemp(),
	   x->s_place, cast_y->s_place);
  else
    printf("t%d := t%d =i t%d\n", nexttemp(),
	   x->s_place, cast_y->s_place);

  /*create a new node to allow just created temporary to be referenced later */
  return(node(currtemp(), (x->s_mode&~(T_ARRAY)),
	      (struct sem_rec *)NULL, (struct sem_rec *)NULL));
}

/*
 * startloopscope - start the scope for a loop
 * TODO: check for correctness.
 */
void startloopscope()
{
   enterblock();
}

/*
 * string - generate code for a string
 * TODO: check for correctness.
 */
struct sem_rec *string(char *s)
{
   printf("t%d := %s\n", nexttemp(), s);
   return (node(currtemp(), T_STR, 0, 0));
}



/************* Helper Functions **************/
int type_width(int type)
{
  if (type & T_INT)
  {
    return 4;
  }
  else
  {
    return 8;
  }
}

/*
* nextnumb - returns next numblabel
*/
int nextnumb()
{
    return ++numblabels;
}

/*
* nextnum - returns next numlabel
*/
int nextnum()
{
    return ++numlabels;
}

/*
* recast_y - casts sem_rec y to appropriate type.
*/
struct sem_rec *recast_y(struct sem_rec *x, struct sem_rec *y)
{
  struct sem_rec *casted_y;
  /* if for type consistency of x and y */
  casted_y = y;
  if((x->s_mode & T_DOUBLE) && !(y->s_mode & T_DOUBLE)){

    /*cast y to a double*/
    printf("t%d := cvf t%d\n", nexttemp(), y->s_place);
    casted_y = node(currtemp(), T_DOUBLE, (struct sem_rec *) NULL,
		  (struct sem_rec *) NULL);
  }
  else if((x->s_mode & T_INT) && !(y->s_mode & T_INT)){

    /*convert y to integer*/
    printf("t%d := cvi t%d\n", nexttemp(), y->s_place);
    casted_y = node(currtemp(), T_INT, (struct sem_rec *) NULL,
		  (struct sem_rec *) NULL);
  }

  return casted_y;
}

/*
* del_goto - removes id from the goto list.
*/
void del_goto(int index)
{
  if (index < gotosize-1)
  {
      int i;
      for (i = index; i < gotosize-1; i++)
      {
        gotolist[index] = gotolist[index+1];
      }
  }
  //remove last item which is now duplicated.
  gotolist[gotosize-1] = NULL;
}

/*
*  type_char - return the correct character based on type int.
*/
char type_char(int type)
{
  char var = '?';
  if (type == T_INT)
  {
    return 'i';
  }
  else if (type == T_DOUBLE)
  {
    return 'f';
  }
  return var;
}

/*
 * cast - force conversion of datum y to type t
 */
struct sem_rec *cast(struct sem_rec *y, int t)
{
   if (t == T_DOUBLE && y->s_mode != T_DOUBLE)
      return (gen("cv", (struct sem_rec *) NULL, y, t));
   else if (t != T_DOUBLE && y->s_mode == T_DOUBLE)
      return (gen("cv", (struct sem_rec *) NULL, y, t));
   else
      return (y);
}

/*
 * gen - generate and return quadruple "z := x op y"
 */
struct sem_rec *gen(char *op, struct sem_rec *x, struct sem_rec *y, int t)
{
   if (strncmp(op, "arg", 3) != 0 && strncmp(op, "ret", 3) != 0)
      printf("t%d := ", nexttemp());
   if (x != NULL && *op != 'f')
      printf("t%d ", x->s_place);
   printf("%s", op);
   if (t & T_DOUBLE && (!(t & T_ADDR) || (*op == '[' && *(op+1) == ']'))) {
      printf("f");
      if (*op == '%')
         yyerror("cannot %% floating-point values");
   }
   else
      printf("i");
   if (x != NULL && *op == 'f')
      printf(" t%d %d", x->s_place, y->s_place);
   else if (y != NULL)
      printf(" t%d", y->s_place);
   printf("\n");
   return (node(currtemp(), t, (struct sem_rec *) NULL,
           (struct sem_rec *) NULL));
}
