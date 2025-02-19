/*======================================================================
                      S <- SUBST(c,k,M,b,B)

Substitute the sample point into the projection factors.

\Input
  \parm{c} is a cell.
  \parm{k} is a positive $\beta$--integer.
  \parm{M} is the integral minimal polynomial of an algebraic number $\alpha$.
  \parm{b} is the $k$-tuple coordinates of a sample point.
  \parm{B} is a list~$(B_1,\ldots,B_m)$ of 
           $(k+1)$--variate integral polynomials.

\Output
  \parm{S} is the list~$(S_1,\ldots,,S_m)
            where $S_i = B_i(b_1,\ldots,b_k,x_{k+1})$.
======================================================================*/
#include "qepcad.h"

Word QepcadCls::SUBST(Word c, Word k, Word M, Word b, Word B)
{
       Word B1,Bp,S,S1;
       Word P,L,Sp,T1,T2,G,Q,f,i;

Step1: /* Substitute. */
        f = UNDET;
        L = NIL;
        S = NIL;
        Bp = B;
	i = 0;
        while (Bp != NIL)
	{
	  i++;
	  ADV(Bp,&B1,&Bp);
	  S1 = IPAFME(k + 1,M,B1,b);
	  
	  /* This is just to warn me that previously we'd be in trouble! */
	  if (PCVERBOSE && S1 == 0 && k + 1 != GVNV) {
	    SWRITE("@A");
	  }

Step2: /* Check if S1 vanishes and, if so, whether this invalidates McCallum's projection*/
	  if (S1 == 0 && (PCPROPEC == TRUE ||  
			  MEMBER('m',REDI(PCPROJOP,k)) ||
			  MEMBER('p',REDI(PCPROJOP,k))) 
	      && PFPRDQ(LELTI(LELTI(GVPF,k + 1),i))) {
	    if (CELLDIM(c) > 0) {
	      f = ACCCVBC(k,c,M,B1,b);
	      if (f != TRUE && !NZFOPQ(c,k,M,b,B1) && PFCOICQ(k+1,B1,c,GVPF,GVPC) != TRUE) {
		SWRITE("WARNING! Projection factor ");
		IPDWRITE(k+1,B1,GVVL);
		SWRITE("\nis everywhere zero");
		SWRITE(" in the cylinder ");
		SWRITE("over the cell ");
		LWRITE(LELTI(c,INDX));
		SWRITE(" of positive dimension.  The McCallum projection ");
		SWRITE("may not be valid.\n"); }
	    }
	    if (f == TRUE || CELLDIM(c) == 0) {
	      P = DELINPOL(k,B1,M,b);
	      if (P != NIL && CELLDIM(c) == 0) {
		L = COMP(P,L); }
	      else if (P != NIL && CELLDIM(c) > 0) {
		SWRITE("WARNING! A projection factor is everywhere zero");
		SWRITE(" in the cylinder \n");
		SWRITE("over the cell ");
		LWRITE(LELTI(c,INDX));
		SWRITE(" of poistive dimension.  The McCallum projection \n");
		SWRITE("may not be valid.\n");
	      }
	    }
	  }
	  
	  S = COMP(S1,S);
	}
	
Step3: /* Searches non-zero substituted projection factors to see if the factors
          of necessary delineating polynomials are included. ONLY IN 0-dim case! */
	while(L != NIL) {
	  ADV(L,&P,&L);
	  P = AFUPGS(M,P); /* gets squarefree part */
	  for(Sp = S; Sp != NIL && PDEG(P) > 0; Sp = RED(Sp)) {
	    Q = FIRST(Sp);
	    if (Q != 0) {
	      AFUPGC(M,P,Q,&G,&T1,&T2);
	      if (PDEG(G) != 0)
		P = T1; }
	  }
	  if (PDEG(P) > 0) {
	    SWRITE("Error! Delineating polynomial should be added over cell");
	    OWRITE(LELTI(c,INDX));
	    SWRITE("!\n");
	  }	
	  else {
	    if (GVNFV > k+1) {
	      SWRITE("Warning! Some ");
	      IWRITE(k+1);
	      SWRITE("-level projection factor is acting as a \n");
	      SWRITE("delineating polynomial for another!  CAD Simplification does not\n");
	      SWRITE("take this into account!\n");
	      GVPFASDPFLAG = TRUE;
	    }
	  }		
	}
	
	
	S = INV(S);
	goto Return;
	
Return: /* Prepare for return. */
	return(S);
}

