#include <matplot/matplot.h>
#include <vector>

int main()
{
  using namespace matplot;

  std::vector<double> x = {1, 2, 3, 4, 5};
  std::vector<double> y = {1, 4, 9, 16, 25};

  plot(x, y);

  show();
}