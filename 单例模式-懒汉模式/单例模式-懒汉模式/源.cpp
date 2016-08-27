#include <iostream>
#include <mutex>
#include<windows.h>
using namespace std;


class Singleton
{
public:
	static Singleton *GetObject()
	{
		if (NULL == s)
		{
			lock_guard<mutex> lock(mx);
			if (NULL == s)
			{
				//return new Singleton();
				Singleton *tmp = new Singleton();
				MemoryBarrier();
				s = tmp;
			}
		}
		return s;
	}
	void Print()
	{
		cout << _data << endl;
	}
private:
	int _data;
	static mutex mx;
	static Singleton *s;
	Singleton()
		:_data(0)
	{}
	Singleton(Singleton &) 
	{}
	Singleton &operator=(Singleton &) 
	{}
};
mutex Singleton::mx;
Singleton *Singleton::s = NULL;

int main()
{
	Singleton *test = Singleton::GetObject();

	return 0;
}

