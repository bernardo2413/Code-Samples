// The MIT License (MIT)
//
// Copyright (c) 2017 Trevor Bakker
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// Purpose: Set a handler for SIGALRM 

static void handle_alarm (int sig )
{
  printf ("Caught alarm %d\n", sig );
  alarm(1);
}

int main (int argc, char *argv[])
{
  struct sigaction act;
 
  /*
    Zero out the sigaction struct
  */ 
  memset (&act, '\0', sizeof(act));
 
  /*
    Set the handler to use the function handle_alarm()
  */ 
  act.sa_handler = &handle_alarm;
 
  /* 
    Install the handler and check the return value.
  */ 
  if (sigaction(SIGALRM, &act, NULL) < 0) {
    perror ("sigaction: ");
    return 1;
  }
 
  alarm(1);
 
  while (1)
    sleep (10);
  
  return 0;
}
