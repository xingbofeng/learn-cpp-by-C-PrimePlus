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
  cout << "Company: " << company << "Shares: " << shares << endl << "Shares Price: $" << share_val << " Total Worth: $" << total_val << endl;
}

inline void Stock::set_tot()
{
  total_val = shares * share_val;
}

int main(int argc, char const *argv[])
{
  Stock kate, joe;
  kate.show();
  joe.show();
  return 0;
}