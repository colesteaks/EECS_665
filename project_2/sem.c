# include <stdio.h>
# include "cc.h"
# include "semutil.h"
# include "sem.h"
# include "sym.h"

extern int formalnum;
extern char formaltypes[];
extern int localnum;
extern char localtypes[];
extern int localwidths[];

int numlabels = 0;                      /* total labels in file */
int numblabels = 0;                     /* toal backpatch labels in file */

char ret_char(int type);
/*
 * TODO: backpatch - backpatch list of quadruples starting at p with k
 */
void backpatch(struct sem_rec *p, int k)
{
   fprintf(stderr, "sem: backpatch not implemented\n");
}

/*
 * TODO: bgnstmt - encountered the beginning of a statement
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
    print("arg%c t%d", ret_char(arg->s_mode), arg->s_place);
    arg = arg->back.s_link;
    arg_count++;
  }

  struct id_entry *p;
  printf("t%d := global %s", nexttemp(), f);
  int ret_type = T_INT;
  if((p = lookup(f, 2)) != NULL) {
    ret_type = p->i_type;
  }
  int t = currtemp();
  printf("t%d := f%c t%d %d", nexttemp(), ret_char(ret_type), t, arg_count);
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
 * ccexpr - convert arithmetic expression to logical expression
 */
struct sem_rec *ccexpr(struct sem_rec *e)
{
   struct sem_rec *t1;

   if(e){

     t1 = gen("!=", e, cast(con("0"), e->s_mode), e->s_mode);

     printf("bt t%d B%d\n", t1->s_place, ++numblabels);
     printf("br B%d\n", ++numblabels);
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
 * ccor - logical or
 * TODO: check for correctness.
 */
struct sem_rec *ccor(struct sem_rec *e1, int m, struct sem_rec *e2)
{
  backpatch(e1->s_false, m);  
  return (node(,,merge(e1->back.s_true, e2->back.s_true), ))
   //potentially merge false or true depending on result
}

/*
 * con - constant reference in an expression
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
  printf("t%d = %s\n", nexttemp(), x);

  /* construct a new node corresponding to this constant generation
     into a temporary. This will allow this temporary to be referenced
     in an expression later*/
  return(node(currtemp(), p->i_type, (struct sem_rec *) NULL,
	      (struct sem_rec *) NULL));
}

/*
 * TODO: dobreak - break statement
 */
void dobreak()
{
   fprintf(stderr, "sem: dobreak not implemented\n");
}

/*
 * TODO: docontinue - continue statement
 */
void docontinue()
{
   fprintf(stderr, "sem: docontinue not implemented\n");
}

/*
 * TODO: dodo - do statement
 */
void dodo(int m1, int m2, struct sem_rec *e, int m3)
{
   fprintf(stderr, "sem: dodo not implemented\n");
}

/*
 * TODO: dofor - for statement
 */
void dofor(int m1, struct sem_rec *e2, int m2, struct sem_rec *n1,
           int m3, struct sem_rec *n2, int m4)
{
   fprintf(stderr, "sem: dofor not implemented\n");
}

/*
 * TODO: dogoto - goto statement
 */
void dogoto(char *id)
{
   lookup(id, 0);
}

/*
 * TODO: doif - one-arm if statement
 */
void doif(struct sem_rec *e, int m1, int m2)
{
   fprintf(stderr, "sem: doif not implemented\n");
}

/*
 * doifelse - if then else statement
 * TODO: incomplete
 */
void doifelse(struct sem_rec *e, int m1, struct sem_rec *n,
                         int m2, int m3)
{
   backpatch(e->back.s_true, m1);
   backpatch(n, m2);
   if (e != NULL)
   {
     backpatch(e->s_false, m1);
   }
}

/*
 * doret - return statement
 * TODO: check for correctness.
 */
void doret(struct sem_rec *e)
{
  if (e->s_mode & T_DOUBLE)
  {
      printf("retf t%d",currtemp());
  }
  else if (e->s_mode & T_INT)
  {
      printf("reti t%d",currtemp());
  }
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
 * TODO: endloopscope - end the scope for a loop
 */
void endloopscope(int m)
{
   fprintf(stderr, "sem: endloopscope not implemented\n");
}

/*
 * exprs - form a list of expressions
 * TODO: check for correctness
 */
struct sem_rec *exprs(struct sem_rec *l, struct sem_rec *e)
{
   //concatenate lists of exprs.
   return merge(l, r);
}

/*
 * fhead - beginning of function body - correct
 */
void fhead(struct id_entry *p)
{
   for(int i = 0; i < formalnum; i++)
   {
      printf("formal %d", formaltypes[i]);
   }
   for(int i = 0; i < localnum; i++)
   {
      printf("localloc %d", localtypes[i]);
   }
}

/*
 * fname - function declaration - correct
 */
struct id_entry *fname(int t, char *id)
{
  printf("func %s", id);
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
 * TODO: labeldcl - process a label declaration
 */
void labeldcl(char *id)
{
   fprintf(stderr, "sem: labeldcl not implemented\n");
}

/*
 * m - generate label and return next temporary number
 *  TODO: check for correctness.
 */
int m()
{
   printf("t%d", nexttemp());
   return (curtemp());
}

/*
 * TODO: n - generate goto and return backpatch pointer
 */
struct sem_rec *n()
{
   fprintf(stderr, "sem: n not implemented\n");
   return ((struct sem_rec *) NULL);
}

/*
 * op1 - unary operators
 * TODO: how does this differ for other unary ops besides "@"
 */
struct sem_rec *op1(char *op, struct sem_rec *y)
{
  if (*op == '@' && !(y->s_mode&T_ARRAY)){
    /* get rid of T_ADDR if it is being dereferenced so can handle
       T_DOUBLE types correctly */
    y->s_mode &= ~T_ADDR;
    return (gen(op, (struct sem_rec *) NULL, y, y->s_mode));
  }
  else{
    return (gen(op, (struct sem_rec *) NULL, y, y->s_mode));
  }
}

/*
 * op2 - arithmetic operators
 * TODO: check for correctness.
 */
struct sem_rec *op2(char *op, struct sem_rec *x, struct sem_rec *y)
{
  struct sem_rec *cast_y;
  /* if for type consistency of x and y */
  cast_y = y;
  if((x->s_mode & T_DOUBLE) && !(y->s_mode & T_DOUBLE)){

    /*cast y to a double*/
    printf("t%d = cvf t%d\n", nexttemp(), y->s_place);
    cast_y = node(currtemp(), T_DOUBLE, (struct sem_rec *) NULL,
		  (struct sem_rec *) NULL);
  }
  else if((x->s_mode & T_INT) && !(y->s_mode & T_INT)){

    /*convert y to integer*/
    printf("t%d = cvi t%d\n", nexttemp(), y->s_place);
    cast_y = node(currtemp(), T_INT, (struct sem_rec *) NULL,
		  (struct sem_rec *) NULL);
  }

  /*return gen op for with type casted result.*/
  return (gen(op, x, cast_y, cast_y->s_mode));
}

/*
 * opb - bitwise operators
 * TODO: check for correctness.
 */
struct sem_rec *opb(char *op, struct sem_rec *x, struct sem_rec *y)
{
  return (gen(op, x, y, T_INT));
}

/*
 * rel - relational operators
 * TODO: how does this need to be different than op2??
 */
struct sem_rec *rel(char *op, struct sem_rec *x, struct sem_rec *y)
{
   fprintf(stderr, "sem: rel not implemented\n");
   return ((struct sem_rec *) NULL);
}

/*
 * set - assignment operators
 * TODO: null cases.
 */
struct sem_rec *set(char *op, struct sem_rec *x, struct sem_rec *y)
{
  /* assign the value of expression y to the lval x */
  struct sem_rec *p, *cast_y;

  if(*op!='\0' || x==NULL || y==NULL){
    fprintf(stderr, "sem: set not implemented\n");
    return((struct sem_rec *) NULL);
  }

  /* if for type consistency of x and y */
  cast_y = y;
  if((x->s_mode & T_DOUBLE) && !(y->s_mode & T_DOUBLE)){

    /*cast y to a double*/
    printf("t%d = cvf t%d\n", nexttemp(), y->s_place);
    cast_y = node(currtemp(), T_DOUBLE, (struct sem_rec *) NULL,
		  (struct sem_rec *) NULL);
  }
  else if((x->s_mode & T_INT) && !(y->s_mode & T_INT)){

    /*convert y to integer*/
    printf("t%d = cvi t%d\n", nexttemp(), y->s_place);
    cast_y = node(currtemp(), T_INT, (struct sem_rec *) NULL,
		  (struct sem_rec *) NULL);
  }

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
 * TODO: startloopscope - start the scope for a loop
 */
void startloopscope()
{
   fprintf(stderr, "sem: startloopscope not implemented\n");
}

/*
 * TODO: string - generate code for a string
 */
struct sem_rec *string(char *s)
{
   printf("t%d := %s", nexttemp(), s);
   //TODO: return a sem rec?
   return (struct sem_rec *) NULL;
}



/************* Helper Functions **************/

/*
*  TODO: ret_char - return the correct charactyer based on type int.
*/
char ret_char(int type) {
  char var = '?';


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
