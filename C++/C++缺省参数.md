## C++缺省参数的介绍

大家好，今天给大家带来关于 C++的一个小知识点：缺省参数。

缺省参数是 C++语法中比较重要的一环，学好它对我们编写 C++程序有很大的帮助。

1. 缺省参数的概念：缺省参数是缺省参数是**声明或定义函数时**为函数的参数指定**一个缺省值**。在调用该函数时，如果没有指定实
   参则采用该形参的缺省值，否则使用指定的实参。

2. 缺省参数的分类：

   - 全缺省参数：
     ```
     void Testfunc1(int a = 10, int b = 20, int c = 30)
     {
     	cout << "a = " << a << endl;
     	cout << "b = " << b << endl;
     	cout << "c = " << c << endl;
     }
     ```
   - 半缺省参数
     ```
     void TestFunc2(int a, int b = 10, int c = 20)  // 必须从右往左缺省，不能间隔
     {
     	cout << "a = " << a << endl;
     	cout << "b = " << b << endl;
     	cout << "c = " << c << endl;
     }
     ```

3. 缺省参数的规则：

   - 缺省参数必须**从右往左**缺省，不能间隔
   - **调用**缺省参数时必须**从左往右**进行传参，不能间隔

4. 代码演示

   ```
   int main()
   {
   	TestFunc1();
   	TestFunc1(1);  // 从左往右给
   	TestFunc(1, , 3); // Error
   	TestFunc1(1, 2);
   	TestFunc1(1, 2, 3);

   	TestFunc2(1);
   	TestFunc2(1, 2);
   	TestFunc2(1, 2, 3);
   }
   ```

5. 缺省参数的应用

   在未知函数参数具体大小的时候，缺省参数是一个很好的选择。

   在我们模拟实现顺序表的时候，一定实现过以下函数：

   ```
   void Init(SeqList* psl)
   {
   	assert(psl);
   	if (psl->size == psl->capacity) {
   		SLDataType newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
   		SLDataType* tmp = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * newCapacity);
   		if (tmp == NULL) {
   			printf("realloc is falied\n");
   	}
   		else {
   		psl->a = tmp;
   		psl->capacity = newCapacity;
   		}
   	}
   }
   ```

   问题在于，每次当我们初始化或者插入数据时候，都需要调用这个函数来判断当前空间的容量，很容易造成空间浪费和效率的损耗，但是当我们用缺省函数进行实现的时候，问题就迎刃而解了。

   ```
   void Init(SeqList* psl, int capacity = 4)
   {
   	assert(psl);
   	if (psl->size == psl->capacity) {
   		SLDataType newCapacity = psl->capacity * 2;
   		SLDataType* tmp = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * newCapacity);
   		if (tmp == NULL) {
   			printf("realloc is falied\n");
   		}
   		else {
   			psl->a = tmp;
   			psl->capacity = newCapacity;
   		}
   	}
   }
   ```
