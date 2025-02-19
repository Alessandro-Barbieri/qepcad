/*======================================================================
                      INITCTRL()

Initialize Program/Trace Control.
======================================================================*/
#include "qepcad.h"

void INITCTRL()
{
Step1: /* Initialize program control */
       PCDBUSE = 'y';
       PCDBLIMIT = 10;

Step2: /* Initialize Algorithm Trace Control Variables. */
       TCPROJ = NIL;
       TCIPLFAC = NIL;

Step3: /* Initialize Data Trace Control Variables. */
       TCPC = 'n';
       TCPROD = 'n';
       TCPIMP = 'n';
       TCPIMPTBL = 'n';
       TCEPIMP = 'n';
       TCSTAT = 'y';
       TCDSTAT = 'n';

Return: /* Prepare for return. */
       return;
}
