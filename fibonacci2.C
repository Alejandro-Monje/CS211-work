#include <time.h>
#include <iostream>
clock_t start, end;

using namespace std;
int fib(int N);
int main()
{
  int pos;
  int N;
  cout << "Enter position for recursive: " << endl;
  cin >> pos;
  N = pos;
  fib(N);
  cout << "Elapsed time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
  // CLOCKS_PER_SEC is the number of clock ticks per second
  cout << "Fibonnaci number at position " << pos << " is " << fib(N - 1) + fib(N-2) << endl;
  return 0;
}
int fib(int N)
{
  start = clock();
  if(N == 1)
    {
      return 1;
    }
  else if(N <= 0)
    {
      return 0;
    }
  else
    {
      return N + fib(N-1);
    }
  //stop timing
  end = clock();
}
