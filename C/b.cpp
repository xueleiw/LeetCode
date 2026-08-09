#include <cstdio>
class Base{
	public:
		Base(){
			Init();
		}
		virtual void Init(){
			printf("Base Init\n");
		}
		void func(){
			printf("Base func\n");
		}
	};
class Derived: public Base{
	public:
		virtual void Init(){
			printf("Derived Init\n");
		}
		void func(){
			printf("Derived fun\n");
		}
	};
int main(){
	Derived d;
	//printf("hello\n");
	((Base *)&d) ->func();
	return 0;
}
