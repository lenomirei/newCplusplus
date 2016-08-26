#include <iostream>
#include <mutex>
using namespace std;

mutex mx;

class Singleton
{
public:
	static Singleton *GetObject()
	{
		if (NULL == s);
		{
			mx.lock();
			template<mutex>lock_guard(mx);
			if (NULL == s)
			{
				//return new Singleton();
				Singleton *tmp = new Singleton();
				MemoryBarrier();
			}
			mx.unlock();
		}
		return s;
	}
	void Print()
	{
		cout << _data << endl;
	}
private:
	int _data;
	static Singleton *s;
	Singleton()
		:_data(0)
	{}
	Singleton(Singleton &);
	Singleton &operator=(Singleton &);
};


int main()
{
	Singleton *test = Singleton::GetObject();

	return 0;
}

