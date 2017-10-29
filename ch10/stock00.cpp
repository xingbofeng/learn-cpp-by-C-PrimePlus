#include <iostream>
#include <string>

using namespace std;

class Stock
{
private:
  string company;
  long shares;
  double share_val;
  double total_val;
  void set_tot();
public:
  Stock(const string& co, long n = 0, double pr = 0.0);
  Stock();
  void acquire(const string& co, long n, double pr);
  void buy(long num, double price);
  void sell(long num, double price);
  void update(double price);
  void show();
};

void Stock::acquire(const string& co, long n, double pr)
{
  company = co;
  if (n < 0) {
    cout << "Number of shares can't be negative; " << company << " shares set to 0." << endl;
    shares = 0;
  }
  else
  {
    shares = n;
  }
  share_val = pr;
  set_tot();
}

void Stock::buy(long num, double price)
{
  if (num < 0)
  {
    cout << "Number of shares purchased can't be negative. " << "Transaction is aborted." << endl;
  }
  else
  {
    shares += num;
    share_val = price;
    set_tot();
  }
}

void Stock::sell(long num, double price)
{
  if (num < 0)
  {
    cout << "Number of shares sold can't be negative. " << "Transaction is aborted." << endl;
  }
  else if (num > shares)
  {
    cout << "You can't sell more than you have! " << "Transaction is aborted." << endl;
  }
  else
  {
    shares -= num;
    share_val = price;
    set_tot();
  }
}

void Stock::update(double price)
{
  share_val = price;
  set_tot();
}

void Stock::show()
{
  ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
  streamsize prec = cout.precision(3); // 设定cout定点表示法时，显示三位小数
  cout << "Company: " << company << " Shares: " << shares << endl;
  cout << "Shares Price: $" << share_val;
  // Total保留两位小数
  cout.precision(2);
  cout << " Total Worth: $" << total_val << endl;
  // 之后还原标准cout
  cout.setf(orig, ios_base::floatfield);
  cout.precision(prec);
}

inline void Stock::set_tot()
{
  total_val = shares * share_val;
}

Stock::Stock(const string& co, long n, double pr)
{
  company = co;
  if (n < 0)
  {
    cerr << "Number of shares can't be negative; " << company << " shares set to 0." << endl;
    shares = 0;
  }
  else
  {
    shares = n;
  }
  share_val = pr;
  set_tot();
}

/**
 * overloading constructor
 */
Stock::Stock()
{
  company = "no name";
  shares = 0;
  share_val = 0.0;
  total_val = 0.0;
}

int main(int argc, char const *argv[])
{
  Stock kate("Kate"), joe("Joe"), noName;// 创建对象隐式调用构造函数
  kate.show();
  joe.show();
  noName.show();
  return 0;
}